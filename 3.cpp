#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr));
    int wylosowana = rand() % 11;

    while (true) {
        try {
            cout << "Podaj liczbę całkowitą: ";
            int x;
            if (!(cin >> x)) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw string("Podaj liczbę całkowitą!");
            }

            if (x == wylosowana) {
                cout << "Zgadłeś!\n";
                break;
            } else {
                throw string("Nie odgadłeś – spróbuj ponownie");
            }

        } catch (string& msg) {
            cout << msg << endl;
        }
    }

    return 0;
}
