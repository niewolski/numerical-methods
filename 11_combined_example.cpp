// Przykład łączący kilka technik
#include <vector>
#include <memory>
#include <algorithm>
#include <regex>
#include <iostream>

struct Person {
    std::string name;
    int age;
    Person(std::string n, int a) : name(n), age(a) {}
};

int main() {
    std::vector<std::shared_ptr<Person>> people;
    people.push_back(std::make_shared<Person>("Anna", 25));
    people.push_back(std::make_shared<Person>("Bartek123", 30));

    std::regex digit_re("\\d");
    for (const auto &p : people) {
        if (std::regex_search(p->name, digit_re)) {
            std::cout << p->name << " has digits\n";
        }
    }
    return 0;
}
