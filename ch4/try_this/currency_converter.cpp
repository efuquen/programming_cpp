#include <string>
#include <iostream>
#include <fstream>

#include <boost/algorithm/string.hpp>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/URI.h"

using namespace std;

using Poco::URI;
using Poco::Net::HTTPClientSession;
using Poco::Net::HTTPMessage;
using Poco::Net::HTTPRequest;
using Poco::Net::HTTPResponse;

using json = nlohmann::json;

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

string read_file(const string& filepath) {
  std::ifstream ifs(filepath);
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
  return content;
}

json get_conversion_rates() {
    auto api_key = read_file(string(getenv("HOME")).append("/.freecurrencyapi.key"));
    boost::trim_right(api_key);

    auto api_url = string("https://freecurrencyapi.net/api/v2/latest?apikey=");
    api_url.append(api_key);
    URI uri(api_url);
    std::string path(uri.getPathAndQuery());

    HTTPClientSession session(uri.getHost(), uri.getPort());
    HTTPRequest request(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_1);
    HTTPResponse response;

    session.sendRequest(request);
    std::istream& rs = session.receiveResponse(response);
    std::string response_string(std::istreambuf_iterator<char>(rs), {});

    return json::parse(response_string)["data"];
}

int main() {
  double amount = 1.00;
  char currency = '$';
  cout << "Please enter an amount followed by a currency ('y' for yen, 'k' for kroner, 'p' for pounds):\n";
  cin >> amount >> currency;

  auto j = get_conversion_rates();
  switch (currency) {
      case 'y':
          cout << amount << " yen is " << j["JPY"].get<double>() * amount << " dollars.\n";
          break;
      case 'k':
          cout << amount << " kroner is " << j["NOK"].get<double>() * amount << " dollars.\n";
          break;
      case 'p':
          cout << amount << " pound is " << j["GBP"].get<double>() * amount << " dollars.\n";
          break;
      default:
          cout << currency << " is not a handled currency.\n";
          break;
  }
  return 0;	
}
