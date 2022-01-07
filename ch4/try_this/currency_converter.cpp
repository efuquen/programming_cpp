#include <string>
#include <iostream>
#include <fstream>

#include <boost/algorithm/string.hpp>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;

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
  string response_string;
  auto curl = curl_easy_init();
  if (curl) {
    auto api_key = read_file(string(getenv("HOME")).append("/.freecurrencyapi.key"));
    boost::trim_right(api_key);

    auto api_url = string("https://freecurrencyapi.net/api/v2/latest?apikey=");
    api_url.append(api_key);

    // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    
    auto res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl = NULL;

    return json::parse(response_string)["data"];
  }
}

int main() {
  auto j = get_conversion_rates();
  cout << "j: " << j;
  return 0;	
}
