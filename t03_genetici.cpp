//////////////////////////////////////////////////
/// Tema laborator: Algoritmi Genetici         ///
/// Nume: Irimia David                         ///
/// Grupa: 241                                 ///
/// Attempt #1: Mon, 13 Apr, 2026, 11:22-13:17 ///
/// Attempt #2: Mon, 13 Apr, 2026, 13:51-14:28 ///
/// Attempt #3: Mon, 13 Apr, 2026, 14:33-14:50 ///
/// Attempt #4: Tue, 14 Apr, 2026, 13:25-13:40 ///
/// Attempt #5: Tue, 14 Apr, 2026, 22:35-23:58 ///
/// Attempt #6: Wed, 15 Apr, 2026, 15:00-16:00 ///
/// Attempt #7: Wed, 15 Apr, 2026, 17:00-todoo ///
//////////////////////////////////////////////////

#include <iostream> /// cin, cout, of course :)
#include <fstream> /// ifstream, ofstream
#include <cmath> /// log(), pow()
#include <cstdlib> /// rand()
#include <vector> /// vector<>

using namespace std;

struct Individ { vector<int> reprezentare_binara; double reprezentare_reala, fitness; };

int cautare_binara(double prob_cumulate[], int stanga, int dreapta, double numar_aleator) {
    if (stanga == dreapta) {
        return dreapta;
    }
    
    int mijloc = (stanga + dreapta) / 2;
    if (numar_aleator < prob_cumulate[mijloc]) {
        return cautare_binara(prob_cumulate, stanga, mijloc, numar_aleator);
    } else {
        return cautare_binara(prob_cumulate, mijloc + 1, dreapta, numar_aleator);
    }
}

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
    vector<Individ> individ(numar_cromozomi);
    for (int i = 0; i < numar_cromozomi; i++) {
        for (int j = 0; j < numar_biti; j++) {
            individ[i].reprezentare_binara.push_back(rand() % 2);
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
        for (int bit : individ[i].reprezentare_binara) {
            fout << bit;
        }
        fout << "\n";
    }

    /// Afiseaza valoarea corespunzatoare cromozomului in domeniu
    fout << "\n";
    fout << "--> Valoarea corespunzatoare cromozomului in domeniu";
    fout << "\n";

    /// Converteste din binar in zecimal si mai apoi numarul zecimal calculat intr-un numar din intervalul dat
   
    for (int i = 0; i < numar_cromozomi; i++) {
        long long cromozom_zecimal = 0, putere = numar_biti - 1;
        for (int bit : individ[i].reprezentare_binara) {
            if (bit == 1) {
                cromozom_zecimal += pow(2, putere);
            }
            putere--;
        }

        individ[i].reprezentare_reala = capat_stang + cromozom_zecimal * (capat_drept - capat_stang) / double(pow(2, numar_biti) - 1);

        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << ": " << individ[i].reprezentare_reala << "\n";
    }

    /// Afiseaza valoarea corespunzatoare cromozomului in domeniu
    fout << "\n";
    fout << "--> Valoarea functiei in punctul cromozomului";
    fout << "\n";

    for (int i = 0; i < numar_cromozomi; i++) {
        individ[i].fitness = a * pow(individ[i].reprezentare_reala, 2) + b * individ[i].reprezentare_reala + c;

        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << ": " << individ[i].fitness << "\n";
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
        for (int bit : individ[i].reprezentare_binara) {
            fout << bit;
        }
        fout << "; x = " << individ[i].reprezentare_reala << "; f = " << individ[i].fitness << "\n";
    }

    ///////////////////////////////////
    /// Probabilitatile de selectie ///
    ///////////////////////////////////

    double suma_fitnessurilor = 0;
    for (int i = 0; i < numar_cromozomi; i++) {
        suma_fitnessurilor += individ[i].fitness;
    }

    double prob_selectie[numar_cromozomi];
    for (int i = 0; i < numar_cromozomi; i++) {
        prob_selectie[i] = individ[i].fitness / suma_fitnessurilor;
    }

    fout << "\n";
    fout << "###############################\n";
    fout << "# Probabilitatile de selectie #\n";
    fout << "###############################\n";
    fout << "\n";

    for (int i = 0; i < numar_cromozomi; i++) {
        fout << "cromozom ";
        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << " probabilitate " << prob_selectie[i] << "\n";
    }

    ///////////////////////////////////
    /// Intervalele pentru selectie ///
    ///////////////////////////////////

    double prob_cumulate[numar_cromozomi + 1];
    prob_cumulate[0] = 0;
    for (int i = 1; i <= numar_cromozomi; i++) {
        prob_cumulate[i] = prob_cumulate[i - 1] + prob_selectie[i - 1];
    }

    fout << "\n";
    fout << "####################################\n";
    fout << "# Intervale probabilitati selectie #\n";
    fout << "####################################\n";
    fout << "\n";

    for (int i = 0; i <= numar_cromozomi; i++) {
        fout << prob_cumulate[i] << " ";
    }
    fout << "\n";

    ///////////////////////////////////////////
    /// Evidentierea procesului de selectie ///
    ///////////////////////////////////////////

    fout << "\n";
    fout << "#######################################\n";
    fout << "# Evidentierea procesului de selectie #\n";
    fout << "#######################################\n";
    fout << "\n";

    int selectat[numar_cromozomi];

    for (int i = 0; i < numar_cromozomi; i++) {
        double numar_aleator = rand() % 10000 / 10000.0; /// acel u din pdf
        selectat[i] = cautare_binara(prob_cumulate, 0, numar_cromozomi, numar_aleator);

        fout << "u = " << numar_aleator << " -> selectam cromozomul " << selectat[i] << "\n";
    }

    /////////////////////
    /// Dupa selectie ///
    /////////////////////

    int index_fitness_maxim = 0;
    for (int i = 1; i < numar_cromozomi; i++) {
        if (individ[i].fitness > individ[index_fitness_maxim].fitness) {
            index_fitness_maxim = i;
        }
    }

    vector<Individ> individ_dupa_selectie;
    individ_dupa_selectie.push_back(individ[index_fitness_maxim]);
    for (int i = 1; i < numar_cromozomi; i++) {
        individ_dupa_selectie.push_back(individ[selectat[i] - 1]);
    }

    fout << "\n";
    fout << "#################\n";
    fout << "# Dupa selectie #\n";
    fout << "#################\n";
    fout << "\n";

    for (int i = 0; i < numar_cromozomi; i++) {
        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << ": ";
        for (int bit : individ_dupa_selectie[i].reprezentare_binara) {
            fout << bit;
        }
        fout << "; x = " << individ_dupa_selectie[i].reprezentare_reala << "; f = " << individ_dupa_selectie[i].fitness << "\n";
    }

    /////////////////////////////////////
    /// Probabilitatea de incrucisare ///
    /////////////////////////////////////

    fout << "\n";
    fout << "#################################\n";
    fout << "# Probabilitatea de incrucisare #\n";
    fout << "#################################\n";
    fout << "\n";

    fout << "prob_recombinare: " << prob_recombinare << "\n";

    ///////////////////////////////////////////////////////////////
    /// Evidentierea cromozomilor care participa la recombinare ///
    ///////////////////////////////////////////////////////////////

    fout << "\n";
    fout << "###########################################################\n";
    fout << "# Evidentierea cromozomilor care participa la recombinare #\n";
    fout << "###########################################################\n";
    fout << "\n";

    /// Afiseaza cromozomul cu fitnessul cel mai mare (elitist)
    fout << " 1: ";
    for (int bit : individ_dupa_selectie[0].reprezentare_binara) {
        fout << bit;
    }
    fout << " u = " << rand() % 10000 / 10000.0 << " -> \"individul cu fitness-ul cel mai mare va trece automat in generatia urmatoare\"\n";

    for (int i = 1; i < numar_cromozomi; i++) {
        double numar_aleator = rand() % 10000 / 10000.0;
        if (i < 9) {
            fout << " ";
        }
        fout << i + 1 << ": ";
        for (int bit : individ_dupa_selectie[i].reprezentare_binara) {
            fout << bit;
        }
        fout << " u = " << numar_aleator;
        if (numar_aleator < prob_recombinare) {
            fout << " < " << prob_recombinare << " -> participa";
        }
        fout << "\n";
    }

    return 0;
}
