#include <iostream>
#include <vector>

using namespace std;

struct Punct {
    long long x, y;
};

/// Produsul vectorial al vectorilor AB si AC
long long cross_product(Punct a, Punct b, Punct c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    int n;
    cin >> n;

    vector<Punct> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    vector<int> stiva;

    /// Adauga primele doua puncte
    stiva.push_back(0);
    stiva.push_back(1);

    for (int i = 2; i < n; i++) {
        /// Elimina varfurile care fac viraj la dreapta sau sunt coliniare
        while (stiva.size() >= 2 && cross_product(p[stiva[stiva.size()-2]], p[stiva[stiva.size()-1]], p[i]) <= 0) {
            stiva.pop_back();
        }
        stiva.push_back(i);
    }

    /// Curata coada stivei (-2, -1, 0 face viraj dreapta => scoate -1)
    while (stiva.size() >= 2 && cross_product(p[stiva[stiva.size()-2]], p[stiva[stiva.size()-1]], p[stiva[0]]) <= 0) {
        stiva.pop_back();
    }

    /// Curata capul stivei (-1, 0, 1 face viraj dreapta => scoate 0)
    while (stiva.size() >= 2 && cross_product(p[stiva[stiva.size()-1]], p[stiva[0]], p[stiva[1]]) <= 0) {
        stiva.erase(stiva.begin());
    }

    /// Afiseaza rezultatul
    int k = stiva.size();
    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        cout << p[stiva[i]].x << " " << p[stiva[i]].y << "\n";
    }

    return 0;
}
