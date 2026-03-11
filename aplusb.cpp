/// https://cms.fmi.unibuc.ro/problem/aplusb

///////////////
/// Exemplu ///
///////////////

/// in

// 2
// 1 1
// -1 0

/// out

// 2
// -1

#include <iostream>
#include <string>

using namespace std;

int main() {
    int N; /// numarul de operatii
    string rezultat;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int stang, drept;
        cin >> stang >> drept;

        rezultat += to_string(stang + drept) + "\n";
    }

    cout << rezultat;

    return 0;
}
