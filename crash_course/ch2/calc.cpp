#include<iostream>

using namespace std;

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Operation op;
public:
    Calculator(Operation _op):op(_op) {}

    int calculate(int a, int b) {
        switch(op) {
            case Operation::Add: return a + b;
            case Operation::Subtract: return a - b;
            case Operation::Multiply: return a * b;
            case Operation::Divide: return a / b;
        }
    }
};

int main() {
    char op_raw;
    int a, b;

    cout << "Enter an arthimetic operation (+, -, *, /) followed by "
            "two integers to perform that operation on:\n";
    cin >> op_raw >> a >> b;

    Operation op;
    switch(op_raw) {
        case '+': {
            op = Operation::Add;
        } break;
        case '-': {
            op = Operation::Subtract;
        } break;
        case '*': {
            op = Operation::Multiply;
        } break;
        case '/': {
            op = Operation::Divide;
        } break;
    }

    auto res = Calculator(op).calculate(a, b);
    cout << "Result: " << res << "\n";

    return 0;
}
