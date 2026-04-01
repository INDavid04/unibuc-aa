/// https://cms.fmi.unibuc.ro/problem/genetici4

//////////
/// IN ///
//////////

/// 8 6 (i.e. lungimea cromozomului si numarul de mutatii)
/// 10101101 (i.e. cromozomul initial)
/// 3 1 0 1 2 7 (i.e. pozitiile bitilor care trebuiesc inversati, 0->1 si 1->0)

///////////
/// OUT ///
///////////

/// 00011100

#include <iostream>

using namespace std;

class Mutatie {
private:
    int lungime_cromozom, numar_mutatii;
    char cromozom[107];
    int pozitii_biti[57];
protected:
public:
    void setLungimeCromozom() {
        cin >> lungime_cromozom;
    }

    void setNumarMutatii() {
        cin >> numar_mutatii;
    }

    void setCromozomInitial() {
        for (int i = 0; i < lungime_cromozom; i++) {
            cin >> cromozom[i];
        }
        cromozom[lungime_cromozom] = '\0';
    }

    void setPozitiiBiti() {
        for (int i = 0; i < numar_mutatii; i++) {
            cin >> pozitii_biti[i];
        }
    }

    const char* getCromozomDupaMutatii() {
        for (int i = 0; i < numar_mutatii; i++) {
            if (cromozom[pozitii_biti[i]] == '0') {
                cromozom[pozitii_biti[i]] = '1';
            } else if (cromozom[pozitii_biti[i]] == '1') {
                cromozom[pozitii_biti[i]] = '0';
            }
        }

        return cromozom;
    }
};

int main() {
    Mutatie m;

    m.setLungimeCromozom();
    m.setNumarMutatii();
    m.setCromozomInitial();
    m.setPozitiiBiti();
    cout << m.getCromozomDupaMutatii() << "\n";

    return 0;
}
