// Inteligentne wskaźniki
#include <memory>
#include <iostream>

struct Foo {
    int x;
    Foo(int v) : x(v) { std::cout << "Foo(" << x << ")\n"; }
    ~Foo() { std::cout << "~Foo(" << x << ")\n"; }
};

int main() {
    auto p1 = std::make_unique<Foo>(1);
    auto sp1 = std::make_shared<Foo>(10);
    auto sp2 = sp1;
    std::cout << "use_count=" << sp1.use_count() << "\n";
    return 0;
}
