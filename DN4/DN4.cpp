#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main() {
    const std::string vhodnaDatoteka = "poly.txt";
    const std::string izhodnaDatoteka = "diff_poly.txt";

    std::ifstream vhodnaDatotekaObjekt(vhodnaDatoteka);
    std::ofstream izhodnaDatotekaObjekt(izhodnaDatoteka);

    int stTock;
    vhodnaDatotekaObjekt >> stTock;

    std::vector<double> x(stTock);
    std::vector<double> f(stTock);

    for (int i = 0; i < stTock; ++i) {
        double ID, vrednost1, vrednost2;
        char dvopicje;

        vhodnaDatotekaObjekt >> ID >> dvopicje >> vrednost1 >> vrednost2;

        x[i] = vrednost1;
        f[i] = vrednost2;
    }

    vhodnaDatotekaObjekt.close();

    double h = std::abs(x[1] - x[2]);
    double odvodNaprej = (-3 * f[0] + 4 * f[1] - f[2]) / std::abs(x[2] - x[0]);

    std::vector<double> odvodi = {odvodNaprej};

    for (int i = 1; i < (stTock - 1); ++i) {
        double sredina = (f[i + 1] - f[i - 1]) / (2 * h);
        odvodi.push_back(sredina);
    }

    double odvodNazaj = (3 * f[stTock - 1] - 4 * f[stTock - 2] + f[stTock - 3]) / (2 * std::abs(x[stTock - 1] - x[stTock - 2]));
    odvodi.push_back(odvodNazaj);

    for (double vrednost : odvodi) {
        izhodnaDatotekaObjekt << vrednost << '\n';
    }

    izhodnaDatotekaObjekt.close();

    return 0;
}
