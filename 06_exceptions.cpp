// Obsługa błędów i wyjątków
#include <stdexcept>
#include <iostream>

int safe_div(int a, int b) {
    if (b == 0) throw std::runtime_error("division by zero");
    return a / b;
}

struct MyError : std::exception {
    std::string msg;
    explicit MyError(std::string m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

int main() {
    try {
        safe_div(10, 0);
    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
