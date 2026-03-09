#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
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
        } else if (directie == "FROM") {
            string sir_binar; /// sir_binar are lungime l
            getline(cin, sir_binar);
            int l = sir_binar.length();
        } else {
            cout << "Nu ai scris nici TO, nici FROM. Poate ai scris altceva sau nu ai scris cu majuscule.\n";
        }
    }
    
    return 0;
}