#include <iostream>
using namespace std;

template <typename T>
class Ulamek {
    T licznik;
    T mianownik;

public:
    Ulamek(T l, T m) {
        if (m == 0) {
            cout << "Mianownik nie może być zerem\n";
            mianownik = 1;
        } else {
            mianownik = m;
        }
        licznik = l;
    }

    float dziesietny() const {
        return static_cast<float>(licznik) / static_cast<float>(mianownik);
    }

    void wyswietl() const {
        cout << licznik << "/" << mianownik << endl;
    }
};

int main() {
    Ulamek<int> u1(1, 2);
    Ulamek<float> u2(3.5f, 2.0f);

    u1.wyswietl();
    cout << u1.dziesietny() << endl;

    u2.wyswietl();
    cout << u2.dziesietny() << endl;

    return 0;
}
