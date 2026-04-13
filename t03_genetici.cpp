/////////////////////////////////////////////////
/// Tema laborator: Algoritmi Genetici         //
/// Nume: Irimia David                         //
/// Grupa: 241                                 //
/// Attempt #1: Mon, 13 Apr, 2026, 11:22-13:17 //
/////////////////////////////////////////////////

#include <iostream> /// cin, cout, of course :)
#include <fstream> /// ifstream, ofstream
#include <cmath> /// log(), pow
#include <cstdlib> /// rand()

using namespace std;

int main() {
    /////////////////////////////////
    /// Declara datele de intrare ///
    /////////////////////////////////

    int numar_cromozomi; /// dimensiunea populatiei
    int capat_stang, capat_drept; /// domeniul de definitie al functiei
    int a, b, c; /// coeficientii polinomului a * x^2 + b * x + c
    int precizie; /// precizia cu care se lucreaza, cu care se discretizeaza intervalul
    double prob_recombinare; /// probabilitatea de recombinare la incrucisare
    double prob_mutatie; /// probabilitatea de mutatie
    int numar_etape; /// numarul de etape al algoritmului

    /////////////////////////////////
    /// Citeste datele de intrare ///
    /////////////////////////////////

    /// Citim din fisier pentru viteza si afisam in fisier pentru ca s-a cerut
    ifstream fin("t04_genetici.in");
    ofstream fout("t05_genetici.out");

    fin >> numar_cromozomi >> capat_stang >> capat_drept >> a >> b >> c >> precizie >> prob_recombinare >> prob_mutatie >> numar_etape;

    //////////////////////////////////
    /// Afiseaza datele de intrare ///
    //////////////////////////////////

    fout << "###################\n";
    fout << "# Date de intrare #\n";
    fout << "###################\n";
    fout << "\n";
    fout << "Numar cromozomi: " << numar_cromozomi << "\n";
    fout << "Interval: [" << capat_stang << ", " << capat_drept << "]\n";
    fout << "Coeficienti polinom: " << a << ", " << b << ", " << c << "\n";
    fout << "Precizie: " << precizie << "\n";
    fout << "Probabilitate recombinare: " << prob_recombinare << "\n";
    fout << "Probabilitate mutatie: " << prob_mutatie << "\n";
    fout << "Numar etape: " << numar_etape << "\n";

    ///////////////////////////////////////////////////
    /// Calculeaza numarul de biti al unui cromozom ///
    ///////////////////////////////////////////////////

    /// Pentru intervalul [capat_stang, capat_drept] si o precizie de precizie zecimale:
    double l = log2((capat_drept - capat_stang) * pow(10, precizie));
    int numar_biti = ceil(l);
    fout << "\n";
    fout << "###################\n";
    fout << "# Date aditionale #\n";
    fout << "###################\n";
    fout << "\n";
    fout << "Numar biti: " << numar_biti << "\n";

    ////////////////////////////////////////
    /// Genereaza populatia la nimereala ///
    ////////////////////////////////////////

    fout << "\n";
    fout << "######################\n";
    fout << "# Populatia initiala #\n";
    fout << "######################\n";
    fout << "\n";

    int cromozom[numar_cromozomi][numar_biti]; /// reprezentarea binara
    for (int i = 0; i < numar_cromozomi; i++) {
        for (int j = 0; j < numar_biti; j++) {
            cromozom[i][j] = rand() % 2;
        }
    }

    //////////////////////////
    /// Afiseaza populatia ///
    //////////////////////////

    for (int i = 0; i < numar_cromozomi; i++) {
        if (i < 9) {
            fout << " "; /// pentru o mai buna aliniere :)
        }
        fout << i + 1 << ": ";
        for (int j = 0; j < numar_biti; j++) {
            fout << cromozom[i][j];
        }
        fout << "\n";
    }

    return 0;
}
