#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string rezultat;
    float a, b; /// capetele intervalului [a, b]
    unsigned int p; /// precizia
    unsigned int m; /// numarul de teste

    cin >> a >> b;
    cin >> p;
    cin >> m;
    cin.get();

    int l = ((float)(log2((b - a) * pow(10, p))) == (int)(log2((b - a) * pow(10, p)))) ? (log2((b - a) * pow(10, p))) : (log2((b - a) * pow(10, p))) + 1; /// rotunjire prin adaos, 3 daca e 3.0 si 4 daca e 3.01

    float d = (b - a) / pow(2, l);

    for (int i = 0; i < m; i++) {
        string directie; /// fie TO, fie FROM
        getline(cin, directie);
        
        if (directie == "TO") {
            float x_i; /// numar real
            cin >> x_i;
            cin.get();

            /// Cauta indexul adica in al catelea interval se afla x_i
            bool caut = true;
            int contor = 1, index = 0;
            while (caut && a + contor * d <= b) {
                if (x_i < a + contor * d) {
                    index = contor;
                    caut = false;
                } else {
                    contor++;
                }
            }
            index--;

            /// Converteste index din baza 10 in baza 2
            // 3/2 = 1 rest 1 si 1/2 = 0 rest 1 de unde rezulta (3)10 = (11)2
            int index_binar = 0;
            int putere = 1;
            while (index) {
                index_binar = index_binar + putere * (index % 2);
                index /= 2;
                putere *= 10;
            }
            string str_index_binar = to_string(index_binar);
            while (str_index_binar.length() < l) {
                str_index_binar = "0" + str_index_binar;
            }
            rezultat += str_index_binar + "\n";
        } else if (directie == "FROM") {
            string sir_binar; /// sir_binar are lungime l
            getline(cin, sir_binar);

            /// Converteste sir_binar intr-un numar in baza 10
            reverse(sir_binar.begin(), sir_binar.end());
            int putere = 1;
            int numar = 0;
            for (char cifra : sir_binar) {
                numar += putere * (cifra - '0');
                putere *= 2;
            }
            rezultat += to_string(a + numar * d) + "\n";
        } else {
            cout << "Nu ai scris nici TO, nici FROM. Poate ai scris altceva sau nu ai scris cu majuscule.\n";
        }
    }

    cout << rezultat;
    
    return 0;
}
