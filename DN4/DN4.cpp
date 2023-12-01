#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::string poly = "poly.txt";
    std::string diff_poly = "diff_poly.txt";

    std::ofstream outdata(diff_poly);
    std::ifstream indata(poly);

    int N = 0;
    indata >> N;

    std::vector<double> x(N);
    std::vector<double> f(N);

    for (int i = 0; i < N; ++i) {
        double value1, value2;
        char colon;
        indata >> value1 >> colon >> value2;
        x[i] = value1;
        f[i] = value2;
    }//for zanko po vrsticah

    indata.close();

    double h = std::abs(x[1] - x[0]);
    double naprej = (-3 * f[0] + 4 * f[1] - f[2]) / std::abs(x[2] - x[0]);//shema naprej

    std::vector<double> odvodi = {naprej};

    for (int i = 1; i < N - 1; ++i) {
        double centralna = (f[i + 1] - f[i - 1]) / (2 * h);
        odvodi.push_back(centralna);
    }//centralna diferenčna shema

    double nazaj = (3 * f[N - 1] - 4 * f[N - 2] + f[N - 3]) / (2 * std::abs(x[N - 1] - x[N - 2]));//shema nazaj
    odvodi.push_back(nazaj);

    //zapišemo v novo datoteko
    for (double value : odvodi) {
        outdata << value << '\n';
    }

    outdata.close();//zapremo datoteko

    return 0;
}
