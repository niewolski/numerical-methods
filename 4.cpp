#include <iostream>
#include <regex>
#include <vector>
using namespace std;

int main() {
    vector<string> dane = {
        "Alicja Nowak, 20-34, 666 999 000",
        "Jan Boruta-Rokita, 00-950, +48 999 666 111",
        "Stanislaw Aniol, 11-123, +01 234 567 890",
        "Alicja Nowak, 203-34, 666 999 000",
        "Jan Boruta-Rokita, +48 999 666 111",
        "Stanislaw Aniol, 11-123, 01 234 567 890"
    };

    regex wzorzec(
        R"(^[A-Z][a-z]{1,14} [A-Z][a-z]{2,24}(-[A-Z][a-z]{2,24})?, \d{2}-\d{3}, (\+?\d{1,3} )?\d{3} \d{3} \d{3}$)"
    );

    for (const auto& linia : dane) {
        if (regex_match(linia, wzorzec)) {
            cout << linia << endl;
        }
    }

    return 0;
}
