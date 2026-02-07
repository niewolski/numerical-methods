// BOOST - Optional i Variant
// Kompilacja: g++ -std=c++11 16_boost_optional_variant.cpp -o test

#include <boost/optional.hpp>
#include <boost/variant.hpp>
#include <iostream>
#include <string>

// Boost.Optional - wartość która może nie istnieć
boost::optional<int> divide_safe(int a, int b) {
    if (b == 0) {
        return boost::none;
    }
    return a / b;
}

// Visitor dla Boost.Variant
class VariantPrinter : public boost::static_visitor<> {
public:
    void operator()(int i) const {
        std::cout << "int: " << i << "\n";
    }

    void operator()(double d) const {
        std::cout << "double: " << d << "\n";
    }

    void operator()(const std::string& s) const {
        std::cout << "string: " << s << "\n";
    }
};

int main() {
    std::cout << "=== Boost.Optional ===\n";

    auto result1 = divide_safe(10, 2);
    if (result1) {
        std::cout << "Result: " << *result1 << "\n";
    }

    auto result2 = divide_safe(10, 0);
    if (!result2) {
        std::cout << "Division by zero!\n";
    }

    // get_value_or
    std::cout << "Result or default: " 
              << result2.get_value_or(-1) << "\n";

    std::cout << "\n=== Boost.Variant ===\n";

    // Variant może przechowywać jeden z kilku typów
    boost::variant<int, double, std::string> v;

    v = 42;
    boost::apply_visitor(VariantPrinter(), v);

    v = 3.14;
    boost::apply_visitor(VariantPrinter(), v);

    v = std::string("hello");
    boost::apply_visitor(VariantPrinter(), v);

    // Dostęp przez get
    if (auto* str = boost::get<std::string>(&v)) {
        std::cout << "Got string: " << *str << "\n";
    }

    return 0;
}
