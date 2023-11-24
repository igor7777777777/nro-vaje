/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

double potenca(double osnova, int eksponent) {
    return pow(osnova, eksponent);
}

double izracunajFunkcijo(double x, int n) {
    double rezultat = 0;

    for (int i = 0; i < n; i++) {
        rezultat += potenca(-1, i) * potenca(x, 2 * i + 1) / (2 * i + 1);
    }

    return rezultat;
}

int main() {
    const double spodnjaMeja = 0;
    const double zgornjaMeja = M_PI_4;

    const int steviloTock = 10000;
    double tocke[steviloTock];

    for (int i = 0; i < steviloTock; i++) {
        tocke[i] = static_cast<double>(i) * M_PI / (4 * (steviloTock - 1));
    }

    double vsota = 0;
    for (int i = 1; i < steviloTock - 1; i++) {
        vsota += exp(3 * tocke[i]) * izracunajFunkcijo(tocke[i] / 2, 10);
    }

    double integral = (zgornjaMeja - spodnjaMeja) / (2 * steviloTock) *
                      (2 * vsota + exp(3 * spodnjaMeja) * izracunajFunkcijo(spodnjaMeja / 2, 10) +
                       exp(3 * zgornjaMeja) * izracunajFunkcijo(zgornjaMeja / 2, 10));

    cout << integral << endl;

    return 0;
}
