// POLIMORFIZM DYNAMICZNY - metody wirtualne (przykład kompletny)
#include <iostream>
#include <vector>
#include <memory>

// Klasa bazowa (abstrakcyjna)
class Figure {
protected:
    float area;
public:
    Figure() : area(0) {
        std::cout << "Figure()\n";
    }

    virtual ~Figure() {
        std::cout << "~Figure()\n";
    }

    // Metoda czysto wirtualna
    virtual void calculateArea() = 0;

    // Metoda wirtualna z domyślną implementacją
    virtual void show() {
        std::cout << "Area: " << area << "\n";
    }

    float getArea() const { return area; }
};

// Klasa pochodna - Kwadrat
class Square : public Figure {
private:
    float side;
public:
    explicit Square(float s) : side(s) {
        std::cout << "Square(" << s << ")\n";
    }

    ~Square() override {
        std::cout << "~Square()\n";
    }

    void calculateArea() override {
        area = side * side;
    }

    void show() override {
        std::cout << "Square side=" << side << ", area=" << area << "\n";
    }
};

// Klasa pochodna - Koło
class Circle : public Figure {
private:
    float radius;
public:
    explicit Circle(float r) : radius(r) {
        std::cout << "Circle(" << r << ")\n";
    }

    ~Circle() override {
        std::cout << "~Circle()\n";
    }

    void calculateArea() override {
        area = 3.14159f * radius * radius;
    }

    void show() override {
        std::cout << "Circle radius=" << radius << ", area=" << area << "\n";
    }
};

int main() {
    std::cout << "=== Test 1: Wskaźniki ===\n";
    Figure* f1 = new Square(4.0f);
    Figure* f2 = new Circle(3.0f);

    f1->calculateArea();
    f1->show();

    f2->calculateArea();
    f2->show();

    delete f1;
    delete f2;

    std::cout << "\n=== Test 2: Tablica polimorficzna ===\n";
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Square>(5.0f));
    figures.push_back(std::make_unique<Circle>(2.0f));
    figures.push_back(std::make_unique<Square>(3.0f));

    for (auto& fig : figures) {
        fig->calculateArea();
        fig->show();
    }

    return 0;
}
