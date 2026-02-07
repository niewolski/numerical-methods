// Boost.Fusion – iteracja po polach struktury
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <iostream>
#include <string>

struct Point {
    int x;
    int y;
    std::string name;
};

BOOST_FUSION_ADAPT_STRUCT(Point, (int, x)(int, y)(std::string, name))

struct PrintField {
    template<typename T>
    void operator()(const T &v) const {
        std::cout << v << " ";
    }
};

int main() {
    Point p{1, 2, "P1"};
    boost::fusion::for_each(p, PrintField());
    return 0;
}
