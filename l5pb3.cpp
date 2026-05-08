#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Punct {
    long long x, y;
};

/// Determinantul (produsul vectorial al vectorilor AB si AC)
long long cross_product(Punct a, Punct b, Punct c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool compare(Punct a, Punct b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Punct> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    /// Cauta punctul minim
    sort(p.begin(), p.end(), [](Punct a, Punct b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<Punct> hull;

    /// Partea de jos
    for (int i = 0; i < n; i++) {
        /// In caz de viraj dreapta (< 0) sau in caz de coliniaritate (= 0)
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    /// Partea de sus
    size_t lower_size = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > lower_size && cross_product(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    /// Elimina duplicatul
    hull.pop_back();

    /// Cauta punctul minim, intai dupa y, apoi dupa x
    int start = 0;
    for (size_t i = 1; i < hull.size(); i++) {
        if (hull[i].y < hull[start].y || (hull[i].y == hull[start].y && hull[i].x < hull[start].x)) {
            start = i;
        }
    }

    /// Afiseaza rezultatul
    cout << hull.size() << "\n";
    for (size_t i = 0; i < hull.size(); i++) {
        int idx = (start + i) % hull.size();
        cout << hull[idx].x << " " << hull[idx].y << "\n";
    }

    return 0;
}
