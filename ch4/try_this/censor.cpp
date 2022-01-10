#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto disallow_words = {"foo", "bar", "barred"};

int main() {
    vector<string> cout_words = {};
    for (string word; cin >> word;) {
        auto disallow_iter = find(disallow_words.begin(), disallow_words.end(), word);
        if (disallow_iter != disallow_words.end()) {
            cout_words.push_back(
                    string("").insert(0, string(*disallow_iter).size(), '*'));
        } else {
            cout_words.push_back(word);
        }
    }

    cout << "\n";
    for (string word : cout_words) {
       cout << word << " ";
    }
    cout << "\n";

    return 0;
}
