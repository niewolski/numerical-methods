// Kontenery asocjacyjne: set, map, unordered_map, unordered_set
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <iostream>

template<typename T>
void show_set(const std::set<T> &s) {
    for (auto it = s.begin(); it != s.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

void assoc_containers_demo() {
    // SET - posortowany zbiór
    std::set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);        // drugi raz się nie doda

    show_set(s);

    // usuwanie < 2
    s.erase(s.begin(), s.find(2));
    show_set(s);

    // sprawdzenie obecności
    std::cout << "count(2)=" << s.count(2) << "\n";

    // MAP – słownik klucz->wartość (posortowany)
    std::map<std::string, int> m;
    m["ala"] = 1;
    m["kot"] = 2;

    for (auto const &p : m) {
        std::cout << p.first << " -> " << p.second << "\n";
    }

    // UNORDERED_MAP - hash mapa (C++11, szybszy dostęp)
    std::unordered_map<std::string, int> um;
    um["fast"] = 1;
    um["lookup"] = 2;

    std::cout << "unordered_map lookup: " << um["fast"] << "\n";

    // UNORDERED_SET - hash set
    std::unordered_set<int> us{1, 2, 3, 4, 5};
    std::cout << "unordered_set contains 3: " << (us.count(3) > 0) << "\n";

    // algorytmy na zbiorach
    std::set<int> s1{1,2,3,7};
    std::set<int> s2{-2,4,1,7,6};
    std::set<int> sunion, sinter, sdiff;

    std::set_union(s1.begin(), s1.end(),
                   s2.begin(), s2.end(),
                   std::inserter(sunion, sunion.begin()));

    std::set_intersection(s1.begin(), s1.end(),
                          s2.begin(), s2.end(),
                          std::inserter(sinter, sinter.begin()));

    std::set_difference(s1.begin(), s1.end(),
                        s2.begin(), s2.end(),
                        std::inserter(sdiff, sdiff.begin()));

    std::cout << "union: ";  show_set(sunion);
    std::cout << "inter: ";  show_set(sinter);
    std::cout << "diff : ";  show_set(sdiff);
}

int main() {
    assoc_containers_demo();
    return 0;
}
