#include <string>
#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>
#include <curl/curl.h>

using namespace std;

using json = nlohmann::json;

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

string read_file(const string& filepath) {
  ifstream t(filepath);
  stringstream buffer;
  buffer << t.rdbuf();
  return buffer.str();
}

json get_conversion_rates() {
  string response_string;
  auto curl = curl_easy_init();
  if (curl) {
    auto api_key = read_file(string(getenv("HOME")).append("/.freecurrencyapi.key"));
    auto api_url = string("https://freecurrencyapi.net/api/v2/latest?apikey=");
    api_url.append(api_key);
    cout << api_url.c_str() << "\n"; 

    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_URL, api_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    
    auto res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl = NULL;

    cout << "res: " << res << "\n";
    cout << "reponse_string: " << response_string << "\n";
    return json::parse(response_string)["data"];
  }
}

int main() {
  auto j = get_conversion_rates();
  cout << "\n\nj: " << j;
  return 0;	
}
