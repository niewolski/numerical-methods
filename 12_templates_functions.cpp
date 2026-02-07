// SZABLONY FUNKCJI (polimorfizm statyczny)
#include <iostream>
#include <vector>
#include <string>

// Prosty szablon funkcji
template<typename T>
T max_val(T a, T b) {
    return (a > b) ? a : b;
}

// Szablon z wieloma typami
template<typename T, typename U>
void print_pair(T first, U second) {
    std::cout << "(" << first << ", " << second << ")\n";
}

// Szablon funkcji - suma elementów kontenera
template<typename Container>
typename Container::value_type sum(const Container &c) {
    typename Container::value_type result = 0;
    for (const auto &elem : c) {
        result += elem;
    }
    return result;
}

// Specjalizacja szablonu dla konkretnego typu
template<typename T>
void show(T value) {
    std::cout << "Generic: " << value << "\n";
}

// Specjalizacja dla const char*
template<>
void show<const char*>(const char* value) {
    std::cout << "String specialization: " << value << "\n";
}

int main() {
    // Użycie szablonu funkcji
    std::cout << "max(3, 7) = " << max_val(3, 7) << "\n";
    std::cout << "max(3.5, 2.1) = " << max_val(3.5, 2.1) << "\n";
    std::cout << "max(a, z) = " << max_val('a', 'z') << "\n";

    print_pair(1, "hello");
    print_pair(3.14, 42);

    std::vector<int> v{1, 2, 3, 4, 5};
    std::cout << "sum(vector) = " << sum(v) << "\n";

    show(42);
    show("test");

    return 0;
}
