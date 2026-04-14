//////////////////////////////////////////////////
/// Tema laborator: Algoritmi Genetici         ///
/// Nume: Irimia David                         ///
/// Grupa: 241                                 ///
/// Attempt #1: Mon, 13 Apr, 2026, 11:22-13:17 ///
/// Attempt #2: Mon, 13 Apr, 2026, 13:51-14:28 ///
/// Attempt #3: Mon, 13 Apr, 2026, 14:33-14:50 ///
/// Attempt #4: Mon, 14 Apr, 2026, 13:25-13:40 ///
//////////////////////////////////////////////////

#include <iostream> /// cin, cout, of course :)
#include <fstream> /// ifstream, ofstream
#include <cmath> /// log(), pow()
#include <cstdlib> /// rand()

using namespace std;

int main() {
    /// Datele de intrare
    int numar_cromozomi; /// dimensiunea populatiei
    int capat_stang, capat_drept; /// domeniul de definitie al functiei
    int a, b, c; /// coeficientii polinomului a * x^2 + b * x + c
    int precizie; /// precizia cu care se lucreaza, cu care se discretizeaza intervalul
    double prob_recombinare; /// probabilitatea de recombinare la incrucisare
    double prob_mutatie; /// probabilitatea de mutatie
    int numar_etape; /// numarul de etape al algoritmului

    /// Citim din fisier pentru viteza si afisam in fisier pentru ca s-a cerut
    ifstream fin("t04_genetici.in");
    ofstream fout("t05_genetici.out");

    fin >> numar_cromozomi >> capat_stang >> capat_drept >> a >> b >> c >> precizie >> prob_recombinare >> prob_mutatie >> numar_etape;

    fout << "--> Date de intrare";
    fout << "\n";
    fout << "Numar cromozomi: " << numar_cromozomi << "\n";
    fout << "Interval: [" << capat_stang << ", " << capat_drept << "]\n";
    fout << "Coeficienti polinom: " << a << ", " << b << ", " << c << "\n";
    fout << "Precizie: " << precizie << "\n";
    fout << "Probabilitate recombinare: " << prob_recombinare << "\n";
    fout << "Probabilitate mutatie: " << prob_mutatie << "\n";
    fout << "Numar etape: " << numar_etape << "\n";

    //////////////////////////
    /// Populatia initiala ///
    //////////////////////////

    /// Calculeaza numarul de biti al unui cromozom 
    /// Pentru intervalul [capat_stang, capat_drept] si o precizie de precizie zecimale:
    double l = log2((capat_drept - capat_stang) * pow(10, precizie));
    int numar_biti = ceil(l);
    fout << "\n";
    fout << "--> Date aditionale";
    fout << "\n";
    fout << "Numar biti: " << numar_biti << "\n";

    /// Genereaza cromozomii la nimereala
    int cromozom_binar[numar_cromozomi][numar_biti]; /// reprezentarea binara
    for (int i = 0; i < numar_cromozomi; i++) {
        for (int j = 0; j < numar_biti; j++) {
            cromozom_binar[i][j] = rand() % 2;
        }
    }

    /// Afiseaza reprezentarea pe biti a cromozomului
    fout << "\n";
    fout << "--> Reprezentarea pe biti a cromozomului";
    fout << "\n";

    for (int i = 0; i < numar_cromozomi; i++) {
        if (i < 9) {
            fout << " "; /// pentru o mai buna aliniere :)
        }
        fout << i + 1 << ": ";
        for (int j = 0; j < numar_biti; j++) {
            fout << cromozom_binar[i][j];
        }
        fout << "\n";
    }

    /// Afiseaza valoarea corespunzatoare cromozomului in domeniu
    fout << "\n";
    fout << "--> Valoarea corespunzatoare cromozomului in domeniu";
    fout << "\n";

    /// Converteste din binar in zecimal
    long long cromozom_zecimal;

    /// Converteste numarul zecimal calculat intr-un numar din intervalul dat
    double cromozom_real[numar_cromozomi];
   
    for (int i = 0; i < numar_cromozomi; i++) {
        cromozom_zecimal = 0;
        for (int j = numar_biti - 1; j >= 0; j--) {
            cromozom_zecimal += cromozom_binar[i][j] * pow(2, abs(numar_biti - j - 1));
        }

        cromozom_real[i] = capat_stang + cromozom_zecimal * (capat_drept - capat_stang) / (pow(2, numar_biti) - 1);

        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << ": " << cromozom_real[i] << "\n";
    }

    /// Afiseaza valoarea corespunzatoare cromozomului in domeniu
    fout << "\n";
    fout << "--> Valoarea functiei in punctul cromozomului";
    fout << "\n";

    double fitness[numar_cromozomi]; /// valoarea functiei in punctul din domeniu care corespunde cromozomului
    for (int i = 0; i < numar_cromozomi; i++) {
        fitness[i] = a * pow(cromozom_real[i], 2) + b * cromozom_real[i] + c;

        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << ": " << fitness[i] << "\n";
    }
    
    fout << "\n";
    fout << "######################\n";
    fout << "# Populatia initiala #\n";
    fout << "######################\n";
    fout << "\n";

    for (int i = 0; i < numar_cromozomi; i++) {
        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << ": ";
        for (int j = 0; j < numar_biti; j++) {
            fout << cromozom_binar[i][j];
        }
        fout << "; x = " << cromozom_real[i] << "; f = " << fitness[i] << "\n";
    }

    return 0;
}
