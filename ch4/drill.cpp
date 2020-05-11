#include "std_lib_facilities.h"

int main() {
    int first;
    int second;
    cout << "Enter two integers or a non-integer character to exit:  ";
    while(cin >> first && cin >> second) {
        int larger;
        if (first >= second) {
            cout << "The smaller value is: " << second << "\n";
            larger = first;
        } else {
            cout << "The smaller value is: " << first << "\n";
            larger = second;
        }
        cout << "The larger value is : " << larger << "\n";
        cout << "Enter two integers or a non-integer character to exit: ";
    }
    return 0;
}