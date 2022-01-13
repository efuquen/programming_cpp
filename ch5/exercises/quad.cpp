#include<math.h>
#include<string.h>

#include<iostream>
#include <tuple>

using namespace std;

tuple<double, double> solve_quad(double a, double b, double c) {
    if (a == 0.0) {
        throw runtime_error("'a' must not be equal to zero. This command does not handle linear equations.");
    }

    auto b24ac = b * b - 4 * a * c;
    if (b24ac < 0.0) {
        throw runtime_error(
                "'b^2 - 4ac' must be positive or zero, not " + to_string(b24ac) + ". This command does not handle imaginary results.");
    }

    return {(-b + sqrt(b24ac))/(2*a), (-b - sqrt(b24ac))/(2*a)};
}

int main() {
    double a, b, c;
    cout << "Enter a, b, c values for a quadratic equation of the form ax^2 + bx + c.\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;

    cout << "Will attempt to solve the quadratic equation of " << a << "x^2 + " << b << "x + " << c << ".\n";

    try {
        auto[x1, x2] = solve_quad(a, b, c);
        cout << "Solutions to the quadratic equation are " << x1 << " and " << x2 << ".\n";
    } catch(runtime_error& e) {
        cerr << "Error computing quadratic equation solutions: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
