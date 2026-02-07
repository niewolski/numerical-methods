// Kontenery sekwencyjne: vector, list, deque, array
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <algorithm>
#include <iostream>

void seq_containers_demo() {
    // vector – dynamiczna tablica
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    // dostępy
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";

    for (auto x : v)
        std::cout << x << " ";
    std::cout << "\n";

    // iteratory
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "front=" << v.front()
              << " back=" << v.back() << "\n";

    // sortowanie
    std::sort(v.begin(), v.end());

    // list – lista dwukierunkowa
    std::list<int> lst;
    lst.push_back(1);
    lst.push_front(0);
    lst.push_back(2);

    for (int x : lst) std::cout << x << " ";
    std::cout << "\n";

    // deque – kolejka dwukierunkowa
    std::deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(0);

    // array – stała tablica (rozmiar w czasie kompilacji)
    std::array<int, 3> arr = {{1, 2, 3}};
    for (auto x : arr) std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    seq_containers_demo();
    return 0;
}
