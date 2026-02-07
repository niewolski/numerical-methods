// Boost.MultiIndex – podstawowy przykład
// Kompilacja: g++ -std=c++11 03_boost_multi_index.cpp -o test

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <iostream>
#include <string>

struct Person {
    int id;
    std::string name;
    int age;
};

using namespace boost::multi_index;

typedef multi_index_container<
    Person,
    indexed_by<
        ordered_unique<member<Person, int, &Person::id>>,
        ordered_non_unique<member<Person, std::string, &Person::name>>
    >
> PersonContainer;

void boost_multi_index_demo() {
    PersonContainer people;
    people.insert({1, "Ala", 20});
    people.insert({2, "Ola", 22});
    people.insert({3, "Ala", 25});

    const auto &idx_id = people.get<0>();
    auto it = idx_id.find(2);
    if (it != idx_id.end())
        std::cout << "Found by id=2: " << it->name << "\n";

    const auto &idx_name = people.get<1>();
    auto range = idx_name.equal_range("Ala");
    for (auto i = range.first; i != range.second; ++i) {
        std::cout << "Found Ala, age=" << i->age << "\n";
    }
}

int main() {
    boost_multi_index_demo();
    return 0;
}
