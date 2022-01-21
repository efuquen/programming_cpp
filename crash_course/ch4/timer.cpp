#include <chrono>
#include <iostream>
#include <optional>
#include <cstring>

using namespace std;

struct TimerClass {
    TimerClass(const char* tag): tag{tag}, timestamp{chrono::system_clock::now()} {}
    TimerClass(const TimerClass& other) {
        timestamp = other.timestamp;
        tag = strdup(other.tag);
    }
    TimerClass(TimerClass&& other) noexcept {
        timestamp = other.timestamp;
        tag = strdup(other.tag);
        other.timestamp = nullopt;
        other.tag = nullptr;
    }
    TimerClass& operator=(const TimerClass& other) {
        timestamp = other.timestamp;
        tag = strdup(other.tag);
        return *this;
    }
    TimerClass& operator=(TimerClass&& other) noexcept {
        timestamp = other.timestamp;
        tag = strdup(other.tag);
        other.timestamp = nullopt;
        other.tag = nullptr;
        return *this;
    }
    ~TimerClass() {
        if (timestamp.has_value()) {
            auto current = chrono::system_clock::now();
            std::chrono::duration<double> diff = current - timestamp.value();
            cout << tag << " time: " << diff.count() << "s\n";
            timestamp = nullopt;
        }
    }

private:
    const char* tag;
    optional<chrono::time_point<chrono::system_clock>> timestamp;
};

int factorial(int num) {
    auto time = TimerClass("factorial");
    int res = 1;
    for(auto i = 2; i < num; i++) {
        res *= i;
    }
    return res;
}

int main() {
    auto copy_time = TimerClass("main_copy");
    auto dest_time = copy_time;

    auto move_time = TimerClass("main_move");
    auto time = move(move_time);
    factorial(1000000);
}