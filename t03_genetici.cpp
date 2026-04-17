///////////////////////////////////////////////////
/// Tema laborator: Algoritmi Genetici          ///
/// Nume: Irimia David                          ///
/// Grupa: 241                                  ///
/// Attempt #01: Mon, 13 Apr, 2026, 11:22-13:17 ///
/// Attempt #02: Mon, 13 Apr, 2026, 13:51-14:28 ///
/// Attempt #03: Mon, 13 Apr, 2026, 14:33-14:50 ///
/// Attempt #04: Tue, 14 Apr, 2026, 13:25-13:40 ///
/// Attempt #05: Tue, 14 Apr, 2026, 22:35-23:58 ///
/// Attempt #06: Wed, 15 Apr, 2026, 15:00-16:00 ///
/// Attempt #07: Wed, 15 Apr, 2026, 17:00-19:11 ///
/// Attempt #08: Wed, 15 Apr, 2026, 20:15-21:45 ///
/// Attempt #09: Wed, 15 Apr, 2026, 21:45-22:00 ///
/// Attempt #10: Thu, 16 Apr, 2026, 16:00-16:15 ///
/// Attempt #11: Thu, 16 Apr, 2026, 16:15-16:50 ///
/// Attempt #12: Thu, 16 Apr, 2026, 17:00-18:00 ///
/// Attempt #13: Thu, 17 Apr, 2026, 08:50-09:58 ///
/// Attempt #14: Thu, 17 Apr, 2026, 21:45-22:00 ///
///////////////////////////////////////////////////

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
    vector<double> fitness_maxim, fitness_mediu;

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

    ///////////////////////////////////////////////////
    /// Calculeaza numarul de biti al unui cromozom ///
    ///////////////////////////////////////////////////

    /// Pentru intervalul [capat_stang, capat_drept] si o precizie de precizie zecimale:
    double l = log2((capat_drept - capat_stang) * pow(10, precizie));
    int numar_biti = ceil(l);
    fout << "\n";
    fout << "--> Date aditionale";
    fout << "\n";
    fout << "Numar biti: " << numar_biti << "\n";

    //////////////////////////
    /// Populatia initiala ///
    //////////////////////////

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

    for (int etapa = 0; etapa < numar_etape; etapa++) {
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

        if (etapa == 0) {
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
        }

        ///////////////////////////////////
        /// Intervalele pentru selectie ///
        ///////////////////////////////////

        double prob_cumulate[numar_cromozomi + 1];
        prob_cumulate[0] = 0;
        for (int i = 1; i <= numar_cromozomi; i++) {
            prob_cumulate[i] = prob_cumulate[i - 1] + prob_selectie[i - 1];
        }

        if (etapa == 0) {
            fout << "\n";
            fout << "####################################\n";
            fout << "# Intervale probabilitati selectie #\n";
            fout << "####################################\n";
            fout << "\n";

            for (int i = 0; i <= numar_cromozomi; i++) {
                fout << prob_cumulate[i] << " ";
            }
            fout << "\n";
        }

        ///////////////////////////////////////////
        /// Evidentierea procesului de selectie ///
        ///////////////////////////////////////////

        if (etapa == 0) {
            fout << "\n";
            fout << "#######################################\n";
            fout << "# Evidentierea procesului de selectie #\n";
            fout << "#######################################\n";
            fout << "\n";
        }

        int selectat[numar_cromozomi];

        for (int i = 0; i < numar_cromozomi; i++) {
            double numar_aleator = rand() % 10000 / 10000.0; /// acel u din pdf
            selectat[i] = cautare_binara(prob_cumulate, 0, numar_cromozomi, numar_aleator);

            if (etapa == 0) {
                fout << "u = " << numar_aleator << " -> selectam cromozomul " << selectat[i] << "\n";
            }
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

        if (etapa == 0) {
            fout << "\n";
            fout << "#################\n";
            fout << "# Dupa selectie #\n";
            fout << "#################\n";
            fout << "\n";
        }

        if (etapa == 0) {
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
        }

        /////////////////////////////////////
        /// Probabilitatea de incrucisare ///
        /////////////////////////////////////

        if (etapa == 0) {
            fout << "\n";
            fout << "#################################\n";
            fout << "# Probabilitatea de incrucisare #\n";
            fout << "#################################\n";
            fout << "\n";

            fout << "prob_recombinare: " << prob_recombinare << "\n";
        }

        ///////////////////////////////////////////////////////////////
        /// Evidentierea cromozomilor care participa la recombinare ///
        ///////////////////////////////////////////////////////////////

        if (etapa == 0) {
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
        }

        vector<int> index_participanti;
        int numar_indivizi_participanti = 0;

        for (int i = 1; i < numar_cromozomi; i++) {
            double numar_aleator = rand() % 10000 / 10000.0;
            
            if (etapa == 0) {
                if (i < 9) {
                    fout << " ";
                }
                fout << i + 1 << ": ";
            
                for (int bit : individ_dupa_selectie[i].reprezentare_binara) {
                    fout << bit;
                }
                fout << " u = " << numar_aleator;
            }
            if (numar_aleator < prob_recombinare) {
                if (etapa == 0) {
                    fout << " < " << prob_recombinare << " -> participa";
                }
                index_participanti.push_back(i);
                numar_indivizi_participanti++;
            }
            if (etapa == 0) {
                fout << "\n";
            }
        }

        /////////////////////////////////////////////
        /// Recombinari / Incrucisari / Crossover ///
        /////////////////////////////////////////////

        if (etapa == 0) {
            fout << "\n";
            fout << "#########################################\n";
            fout << "# Recombinari / Incrucisari / Crossover #\n";
            fout << "#########################################\n";
            fout << "\n";
        }

        vector<Individ> individ_dupa_recombinare;
        for (auto individ : individ_dupa_selectie) {
            individ_dupa_recombinare.push_back(individ);
        }

        if (numar_indivizi_participanti % 2 == 1) {
            numar_indivizi_participanti--;
        }
        int numar_recombinari = numar_indivizi_participanti / 2;

        for (int i = 0; i < numar_recombinari; i++) {
            int punct_rupere = rand() % numar_biti;
            
            if (etapa == 0) {
                fout << "Recombinare dintre cromozomul " << index_participanti[i] + 1 << " cu cromozomul " << index_participanti[numar_indivizi_participanti - i - 1] + 1 << ":\n";
                for (auto bit : individ_dupa_selectie[index_participanti[i]].reprezentare_binara) {
                    fout << bit;
                }
                fout << " ";
                for (auto bit : individ_dupa_selectie[index_participanti[numar_indivizi_participanti - i - 1]].reprezentare_binara) {
                    fout << bit;
                }
                fout << " punct " << punct_rupere << "\nRezultat ";
            }

            for (int k = 0; k < punct_rupere; k++) {
                individ_dupa_recombinare[index_participanti[i]].reprezentare_binara[k] = individ_dupa_selectie[index_participanti[numar_indivizi_participanti - i - 1]].reprezentare_binara[k];

                individ_dupa_recombinare[index_participanti[numar_indivizi_participanti - i - 1]].reprezentare_binara[k] = individ_dupa_selectie[index_participanti[i]].reprezentare_binara[k];
            }

            if (etapa == 0) {
                for (auto bit : individ_dupa_recombinare[index_participanti[i]].reprezentare_binara) {
                    fout << bit;
                }
                fout << " ";
                for (auto bit : individ_dupa_recombinare[index_participanti[numar_indivizi_participanti - i - 1]].reprezentare_binara) {
                    fout << bit;
                }
                fout << "\n\n";
            }
        }

        //////////////////////// 
        /// Dupa recombinare ///
        ////////////////////////

        if (etapa == 0) {
            fout << "####################\n";
            fout << "# Dupa recombinare #\n";
            fout << "####################\n\n";
        }

        for (int i = 0; i < numar_indivizi_participanti; i++) {
            /// Recalculeaza reprezentare reala
            long long cromozom_zecimal = 0, putere = numar_biti - 1;
            for (int bit : individ_dupa_recombinare[index_participanti[i]].reprezentare_binara) {
                if (bit == 1) {
                    cromozom_zecimal += pow(2, putere);
                }
                putere--;
            }
            individ_dupa_recombinare[index_participanti[i]].reprezentare_reala = capat_stang + cromozom_zecimal * (capat_drept - capat_stang) / double(pow(2, numar_biti) - 1);

            /// Recalculeaza fitness
            individ_dupa_recombinare[index_participanti[i]].fitness = a * pow(individ_dupa_recombinare[index_participanti[i]].reprezentare_reala, 2) + b * individ_dupa_recombinare[index_participanti[i]].reprezentare_reala + c;
        }

        if (etapa == 0) {
            for (int i = 0; i < numar_cromozomi; i++) {
                if (i < 9) {
                    fout << " ";
                }
                fout << i + 1 << ": ";
                for (int bit : individ_dupa_recombinare[i].reprezentare_binara) {
                    fout << bit;
                }
                fout << "; x = " << individ_dupa_recombinare[i].reprezentare_reala << "; f = " << individ_dupa_recombinare[i].fitness << "\n";
            }
            fout << "\n";
        }

        ///////////////////////////////////////////////////// 
        /// Probabilitatea de mutatie pentru fiecare gena ///
        /////////////////////////////////////////////////////

        if (etapa == 0) {
            fout << "#################################################\n";
            fout << "# Probabilitatea de mutatie pentru fiecare gena #\n";
            fout << "#################################################\n\n";

            fout << "prob_mutatie: " << prob_mutatie << "\n\n";
        }

        //////////////////////////// 
        /// Cromozomi modificati ///
        ////////////////////////////
        
        if (etapa == 0) {
            fout << "########################\n";
            fout << "# Cromozomi modificati #\n";
            fout << "########################\n\n";
        }

        vector<Individ> individ_dupa_mutatie;

        for (auto individ : individ_dupa_recombinare) {
            individ_dupa_mutatie.push_back(individ);
        }

        if (etapa == 0) {
            fout << "Au fost modificati cromozomii:\n";
        }

        for (int i = 1; i < numar_cromozomi; i++) {
            bool cromozom_modificat = false;
            for (int j = 0; j < numar_biti; j++) {
                double numar_aleator = double(rand() % 1000) / 1000;
                if (numar_aleator < prob_mutatie) {
                    cromozom_modificat = true;
                    if (individ_dupa_mutatie[i].reprezentare_binara[j] == 0) {
                        individ_dupa_mutatie[i].reprezentare_binara[j] = 1;
                    } else {
                        individ_dupa_mutatie[i].reprezentare_binara[j] = 0;
                    }
                }
            }
            if (cromozom_modificat) {
                if (etapa == 0) {
                    fout << i + 1 << "\n";
                }

                /// Recalculeaza reprezentare reala
                long long cromozom_zecimal = 0, putere = numar_biti - 1;
                for (int bit : individ_dupa_mutatie[i].reprezentare_binara) {
                    if (bit == 1) {
                        cromozom_zecimal += pow(2, putere);
                    }
                    putere--;
                }
                individ_dupa_mutatie[i].reprezentare_reala = capat_stang + cromozom_zecimal * (capat_drept - capat_stang) / double(pow(2, numar_biti) - 1);

                /// Recalculeaza fitness
                individ_dupa_mutatie[i].fitness = a * pow(individ_dupa_mutatie[i].reprezentare_reala, 2) + b * individ_dupa_mutatie[i].reprezentare_reala + c;
            }
        }
        if (etapa == 0) {
            fout << "\n";
        }

        ////////////////////
        /// Dupa mutatie ///
        ////////////////////

        if (etapa == 0) {
            fout << "################\n";
            fout << "# Dupa mutatie #\n";
            fout << "################\n\n";

            for (int i = 0; i < numar_cromozomi; i++) {
                if (i < 9) {
                    fout << " ";
                }
                fout << i + 1 << ": ";
                for (int bit : individ_dupa_mutatie[i].reprezentare_binara) {
                    fout << bit;
                }
                fout << "; x = " << individ_dupa_mutatie[i].reprezentare_reala << "; f = " << individ_dupa_mutatie[i].fitness << "\n";
            }
            fout << "\n";
        }

        //////////////////////////////////////////
        /// Actualizeaza populatia de indivizi ///
        //////////////////////////////////////////

        for (int i = 0; i < numar_cromozomi; i++) {
            for (int j = 0; j < numar_biti; j++) {
                individ[i].reprezentare_binara[j] = individ_dupa_mutatie[i].reprezentare_binara[j];
            }
            individ[i].reprezentare_reala = individ_dupa_mutatie[i].reprezentare_reala;
            individ[i].fitness = individ_dupa_mutatie[i].fitness;
        }

        /// Salveaza fitness-ul mediu din etapa curenta in array
        fitness_mediu.push_back(suma_fitnessurilor / numar_cromozomi);

        /// Salveaza fitnessul maxim din etapa curenta in array
        fitness_maxim.push_back(individ[index_fitness_maxim].fitness); 
    }

    //////////////////////////
    /// Evolutia maximului ///
    //////////////////////////

    fout << "######################\n";
    fout << "# Evolutia maximului #\n";
    fout << "######################\n\n";

    for (double fitness : fitness_maxim) {
        fout << fitness << "\n";
    }
    fout << "\n";

    /////////////////////////
    /// Evolutia mediului ///
    /////////////////////////

    fout << "######################\n";
    fout << "# Evolutia mediului #\n";
    fout << "######################\n\n";

    for (double fitness : fitness_mediu) {
        fout << fitness << "\n";
    }

    return 0;
}
