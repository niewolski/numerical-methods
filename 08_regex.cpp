// Wyrażenia regularne
#include <regex>
#include <iostream>

int main() {
    std::string text = "ala ma kota 123";
    std::regex re("[0-9]+");

    std::smatch m;
    if (std::regex_search(text, m, re)) {
        std::cout << "found: " << m.str() << "\n";
    }

    std::string replaced = std::regex_replace(text, re, "#");
    std::cout << replaced << "\n";
    return 0;
}
