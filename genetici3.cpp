/// https://cms.fmi.unibuc.ro/problem/genetici3

//////////
/// IN ///
//////////

/// 5 (i.e. lungimea cromozomilor cu care lucram)
/// 10101 (i.e. primul cromozom)
/// 11000 (i.e. al doilea cromozom)
/// 2 (i.e. indicele de la care incepe incrucisarea)

///////////
/// OUT ///
///////////

/// 10000
/// 11101

//////////////////
/// EXPLICATIE ///
//////////////////

/// 10 de la primul cromozom si 000 de la al doilea
/// 11 de la cel de al doilea cromozom si 101 de la primul

#include <iostream>

using namespace std;

class Incrucisare {
private:
    int lungime_cromozomi, indice_incrucisare;
    char cromozom_1[105], cromozom_2[105];
protected:
public:
    void setLungimeCromozomi() {
        cin >> lungime_cromozomi;
    }

    void setCromozomi() {
        for(int i = 0; i < lungime_cromozomi; i++) {
            cin >> cromozom_1[i];
        }

        for(int i = 0; i < lungime_cromozomi; i++) {
            cin >> cromozom_2[i];
        }
    }

    void setIndiceIncrucisare() {
        cin >> indice_incrucisare;
    }

    void getCromozomiDupaIncrucisare() {
        cout << "\n";
        /// Afiseaza primul cromozom dupa incrucisare
        for (int i = 0; i < indice_incrucisare; i++) {
            cout << cromozom_1[i];
        }
        for (int i = indice_incrucisare; i < lungime_cromozomi; i++) {
            cout << cromozom_2[i];
        }
        cout << "\n";
        /// Afiseaza cel de al doilea cromozom dupa incrucisare
        for (int i = 0; i < indice_incrucisare; i++) {
            cout << cromozom_2[i];
        }
        for (int i = indice_incrucisare; i < lungime_cromozomi; i++) {
            cout << cromozom_1[i];
        }
        cout << "\n";
    }
};

int main() {
    Incrucisare i;
    i.setLungimeCromozomi();
    i.setCromozomi();
    i.setIndiceIncrucisare();
    i.getCromozomiDupaIncrucisare();

    return 0;
}
