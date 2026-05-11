/// Monotonia unui poligon: https://cms.fmi.unibuc.ro/problem/l6pb3

#include <iostream>

using namespace std;

struct Punct { long long x, y; } puncte[1000007];

int main() {
    /// Citeste numarul de puncte al poligonului
    int n;
    cin >> n;

    /// Citest punctele poligonului
    for (int i = 0; i < n; i++) {
        cin >> puncte[i].x >> puncte[i].y;
    }

    /// Afla indicele celui mai stang, drept, de sus, de jos punct din poligon
    int stang = 0, drept = 0, sus = 0, jos = 0;
    for (int i = 1; i < n; i++) {
        if (puncte[i].x < puncte[stang].x) {
            stang = i;
        }
        if (puncte[i].x > puncte[drept].x) {
            drept = i;
        }
        if (puncte[i].y < puncte[jos].y) {
            jos = i;
        }
        if (puncte[i].y > puncte[sus].y) {
            sus = i;
        }
    }

    /// Verificam monotonia pe OX stang-drept si drept-stang
    bool eMonoton = true;
    if (puncte[stang].x - puncte[stang+1].x < 0) {
        for (int i = stang + 1; i < drept; i++) {
            if (puncte[i].x - puncte[i+1].x > 0) {
                eMonoton = false;
                break;
            }
        }
    } else {
        for (int i = stang + 1; i < drept; i++) {
            if (puncte[i].x - puncte[i+1].x < 0) {
                eMonoton = false;
                break;
            }
        }
    }

    if (eMonoton) {
        if (puncte[drept].x - puncte[drept+1].x < 0) {
            for (int i = drept + 1; i % n < stang; i++) {
                if (puncte[i].x - puncte[i+1].x > 0) {
                    eMonoton = false;
                    break;
                }
            }
        } else {
            for (int i = drept + 1; i % n < stang; i++) {
                if (puncte[i].x - puncte[i+1].x < 0) {
                    eMonoton = false;
                    break;
                }
            }
        }
    }
    if (eMonoton) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    /// Verificam monotonia pe OY jos-sus si sus-jos
    eMonoton = true;
    if (puncte[jos].y - puncte[jos+1].y < 0) {
        for (int i = jos + 1; i < sus; i++) {
            if (puncte[i].y - puncte[i+1].y > 0) {
                eMonoton = false;
                break;
            }
        }
    } else {
        for (int i = jos + 1; i < sus; i++) {
            if (puncte[i].y - puncte[i+1].y < 0) {
                eMonoton = false;
                break;
            }
        }
    }

    if (eMonoton) {
        if (puncte[sus].y - puncte[sus+1].y < 0) {
            for (int i = sus + 1; i % n < jos; i++) {
                if (puncte[i].y - puncte[i+1].y > 0) {
                    eMonoton = false;
                    break;
                }
            }
        } else {
            for (int i = sus + 1; i % n < jos; i++) {
                if (puncte[i].y - puncte[i+1].y < 0) {
                    eMonoton = false;
                    break;
                }
            }
        }
    }
    if (eMonoton) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
