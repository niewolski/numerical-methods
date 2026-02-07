#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Student {
    int numerIndeksu;
    pair<string, string> dane; // imię, nazwisko
};

class BazaStudentow {
    map<int, Student> studenci;

public:
    void dodajStudenta(int indeks, string imie, string nazwisko) {
        studenci[indeks] = {indeks, {imie, nazwisko}};
    }

    void szukajPoIndeksie(int indeks) const {
        auto it = studenci.find(indeks);
        if (it != studenci.end()) {
            cout << it->second.numerIndeksu << " "
                 << it->second.dane.first << " "
                 << it->second.dane.second << endl;
        } else {
            cout << "Nie znaleziono\n";
        }
    }

    void szukajPoNazwisku(string nazwisko) const {
        bool znaleziono = false;
        for (const auto& s : studenci) {
            if (s.second.dane.second == nazwisko) {
                cout << s.second.numerIndeksu << " "
                     << s.second.dane.first << " "
                     << s.second.dane.second << endl;
                znaleziono = true;
            }
        }
        if (!znaleziono) {
            cout << "Nie znaleziono\n";
        }
    }
};

int main() {
    BazaStudentow baza;

    baza.dodajStudenta(1001, "Jan", "Kowalski");
    baza.dodajStudenta(1002, "Jan", "Niezbedny");
    baza.dodajStudenta(1003, "Anna", "Zaradna");
    baza.dodajStudenta(1101, "Magda", "Nowak");
    baza.dodajStudenta(1102, "Tadeusz", "Zielinski");
    baza.dodajStudenta(1010, "Wojciech", "Nowak");

    baza.szukajPoIndeksie(1003);
    baza.szukajPoNazwisku("Nowak");

    return 0;
}
