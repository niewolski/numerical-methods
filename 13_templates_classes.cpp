// SZABLONY KLAS (polimorfizm statyczny)
#include <iostream>
#include <stdexcept>

// Prosty szablon klasy - dynamiczna tablica
template<typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    explicit Stack(int size = 10) : top(-1), capacity(size) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const T& item) {
        if (top >= capacity - 1) {
            throw std::overflow_error("Stack overflow");
        }
        arr[++top] = item;
    }

    T pop() {
        if (top < 0) {
            throw std::underflow_error("Stack underflow");
        }
        return arr[top--];
    }

    bool empty() const {
        return top < 0;
    }

    int size() const {
        return top + 1;
    }
};

// Szablon klasy z wieloma parametrami
template<typename K, typename V>
class Pair {
public:
    K key;
    V value;

    Pair(K k, V v) : key(k), value(v) {}

    void show() const {
        std::cout << key << " -> " << value << "\n";
    }
};

// Częściowa specjalizacja dla wskaźników
template<typename T>
class SmartPtr {
private:
    T* ptr;
public:
    explicit SmartPtr(T* p = nullptr) : ptr(p) {}
    ~SmartPtr() { delete ptr; }

    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};

int main() {
    // Stack dla różnych typów
    Stack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Stack size: " << intStack.size() << "\n";
    std::cout << "Popped: " << intStack.pop() << "\n";

    Stack<std::string> strStack(3);
    strStack.push("hello");
    strStack.push("world");

    // Pair
    Pair<int, std::string> p1(1, "one");
    p1.show();

    Pair<std::string, double> p2("pi", 3.14159);
    p2.show();

    return 0;
}
