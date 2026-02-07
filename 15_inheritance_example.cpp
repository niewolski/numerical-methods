// DZIEDZICZENIE - kompletny przykład (Person -> Teacher)
#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    std::string surname;
    int age;

public:
    Person(std::string n, std::string s, int a) 
        : name(n), surname(s), age(a) {
        std::cout << "Person(" << name << ")\n";
    }

    Person() : age(0) {
        std::cout << "Person()\n";
    }

    virtual ~Person() {
        std::cout << "~Person()\n";
    }

    void setAge(int a) { age = a; }
    std::string getSurname() const { return surname; }

    bool is_18() const { return age >= 18; }

    virtual void showInfo() const {
        std::cout << "Person: " << name << " " << surname 
                  << ", age=" << age << "\n";
    }
};

class Teacher : public Person {
private:
    int experience;
    std::string title;

public:
    Teacher(std::string n, std::string s, int a, int exp, std::string t)
        : Person(n, s, a), experience(exp), title(t) {
        std::cout << "Teacher(" << name << ")\n";
    }

    Teacher() : experience(0) {
        std::cout << "Teacher()\n";
    }

    ~Teacher() override {
        std::cout << "~Teacher()\n";
    }

    void setTitle(std::string t) { title = t; }
    int getExperience() const { return experience; }

    bool is_Phd() const { return title == "PhD"; }

    void showInfo() const override {
        std::cout << "Teacher: " << name << " " << surname 
                  << ", age=" << age 
                  << ", exp=" << experience 
                  << ", title=" << title << "\n";
    }
};

int main() {
    std::cout << "=== Test Person ===\n";
    Person p1("Jan", "Kowalski", 25);
    p1.showInfo();
    std::cout << "Is 18+: " << p1.is_18() << "\n";

    std::cout << "\n=== Test Teacher ===\n";
    Teacher t1("Anna", "Nowak", 35, 10, "PhD");
    t1.showInfo();
    std::cout << "Is PhD: " << t1.is_Phd() << "\n";
    t1.setAge(36);

    std::cout << "\n=== Test polimorfizmu ===\n";
    Person* ptr = &t1;
    ptr->showInfo();  // wywołanie Teacher::showInfo()

    return 0;
}
