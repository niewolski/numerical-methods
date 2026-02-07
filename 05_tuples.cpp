// Krotki (std::tuple)
#include <tuple>
#include <string>
#include <iostream>

std::tuple<int, std::string, double> make_person_tuple() {
    return std::make_tuple(1, "Ala", 3.5);
}

int main() {
    auto t = make_person_tuple();
    int id;
    std::string name;
    double grade;

    std::tie(id, name, grade) = t;
    std::cout << id << " " << name << " " << grade << "\n";
    std::cout << "Name: " << std::get<1>(t) << "\n";
    return 0;
}
