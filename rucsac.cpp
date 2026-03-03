/// AA | 2026-03-03 | 17:35

///////////////
/// Cerinta ///
///////////////

/// Se da o multime formata din N obiecte, fiecare fiind caracterizat de o greutate si un profit. Sa se gaseasca o submultime de obiecte astfel incat suma profiturilor lor sa fie maxima, iar suma greutatilor lor sa nu depaseasca o valoare G.

/////////////////
/// rucsac.in ///
/////////////////

/// 6 10
/// 3 7
/// 3 4
/// 1 2
/// 1 9
/// 2 4
/// 1 5

//////////////////
/// rucsac.out ///
//////////////////

/// 29

////////////////////////
/// Cum am gandit-o? ///
////////////////////////

/// numarul de obiecte, N = 6
/// greutatea maxima, G = 10

/// Greutate    Profit      Raport    
/// 3           7           7/3 = 2.33
/// 3           4           4/3 = 1.33
/// 1           2           2/1 = 2
/// 1           9           9/1 = 9
/// 2           4           4/2 = 2
/// 1           5           5/1 = 5

/// Perechile (greutate, profit) sortate descrecator dupa raportul profit/greutate
/// (1, 9) /// 1 <= 10 ok
/// (1, 5) /// 2 <= 10 ok
/// (3, 7) /// 5 <= 10 ok
/// (1, 2) /// 6 <= 10 ok
/// (2, 4) /// 8 <= 10 ok
/// (3, 4) /// 11 <= 10 neh

/// profitMaxim = 9 + 5 + 7 + 2 + 4 = 27 ... hmmm, pe infoarena este 29, nu 27

/// Asta e gandirea pentru varianta in care putem lua fractiuni dintr-un obiect

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    /// Deschide fisierele
    ifstream fin("rucsac.in");
    ofstream fout("rucsac.out");

    /// Declara
    int numarulDeObiecte;
    int greutateaMaxima;

    /// Initializeaza
    fin >> numarulDeObiecte >> greutateaMaxima;

    vector<int> greutate;
    vector<int> profit;

    for (int i = 0; i <  numarulDeObiecte; i++) {
        int w, p;
        fin >> w >> p;

        greutate.push_back(w);
        profit.push_back(p);
    }

    vector<int> dp(greutateaMaxima + 1, 0);

    /// Ia fiecare obiect
    for (int i = 0; i < numarulDeObiecte; i++) {
        int g = greutate[i];
        int p = profit[i];
        
        /// Parcurge greutatile invers
        for (int w = greutateaMaxima; w >= g; w--) {
            dp[w] = max(dp[w], dp[w - g] + p);
        }
    }

    /// Scrie raspunsul
    fout << dp[greutateaMaxima] << "\n";

    /// Inchide fisierele
    fin.close();
    fout.close();

    return 0;
}
