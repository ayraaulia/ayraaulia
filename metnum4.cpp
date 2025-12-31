#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//NIM: f1d02410107
//Nama: Ayra Aulia Saputri Hidayat

// Fungsi utama
double fungsi(double t) {
    return (4 * t - pow(t, 3)) * exp(pow(t, 2));
}

// Turunan analitik
double defungsi(double t) {
    return (-2 * pow(t, 4) + 5 * pow(t, 2) + 4) * exp(pow(t, 2));
}

// Nilai integral eksak
double intefungsi() {
    return 2.93656365691809;
}

// Selisih maju
void maju(double x, double h) {
    double ft = (fungsi(x + h) - fungsi(x)) / h;

    cout << "   f'(t)   = " << ft << endl;
    cout << "   Error   = " 
         << abs(defungsi(x) - ft) / defungsi(x) 
         << "\n" << endl;
}

// Selisih pusat
void pusat(double x, double h) {
    double ft = (fungsi(x + h) - fungsi(x - h)) / (2 * h);

    cout << "   f'(t)   = " << ft << endl;
    cout << "   Error   = " 
         << abs(defungsi(x) - ft) / defungsi(x) 
         << "\n" << endl;
}

// Newton-Cotes Simpson 1/3
void NCSimpson(double a, double b, double h) {
    int n = (b - a) / h;
    double* c  = new double[n + 1];
    double* fx = new double[n + 1];
    double res = 0;

    for (int i = 0; i <= n; i++) {
        c[i]  = a + i * h;
        fx[i] = fungsi(c[i]);
    }

    for (int i = 0; i <= n; i++) {
        if (i == 0 || i == n)
            res += fx[i];
        else if (i % 2 != 0)
            res += 4 * fx[i];
        else
            res += 2 * fx[i];
    }

    double hasil = res * h / 3.0;

    cout << "   Integral ≈ " << hasil << endl;
    cout << "   Error    = " 
         << abs(intefungsi() - hasil) / intefungsi() 
         << "\n" << endl;

    delete[] c;
    delete[] fx;
}

int main() {
    cout << fixed << setprecision(10);
    cout << " Kasus: f(t) = (4t - t^3) * exp(t^2)\n\n";

    cout << "=============================================================\n";
    cout << "1. Turunan pertama dari f(t) dengan selisih maju\n";
    cout << "-------------------------------------------------------------\n";
    cout << "- Untuk h = 0.01\n";
    maju(0.5, 0.01);
    cout << "- Untuk h = 0.001\n";
    maju(0.5, 0.001);
    cout << "- Untuk h = 0.0001\n";
    maju(0.5, 0.0001);

    cout << "=============================================================\n";
    cout << "2. Turunan pertama dari f(t) dengan selisih pusat\n";
    cout << "-------------------------------------------------------------\n";
    cout << "- Untuk h = 0.01\n";
    pusat(0.5, 0.01);
    cout << "- Untuk h = 0.001\n";
    pusat(0.5, 0.001);
    cout << "- Untuk h = 0.0001\n";
    pusat(0.5, 0.0001);

    cout << "=============================================================\n";
    cout << "3. Integral f(t) dengan NC 1/3 dari 0 s.d 1\n";
    cout << "-------------------------------------------------------------\n";
    cout << "- Untuk h = 0.01\n";
    NCSimpson(0, 1, 0.01);
    cout << "- Untuk h = 0.001\n";
    NCSimpson(0, 1, 0.001);
    cout << "- Untuk h = 0.0001\n";
    NCSimpson(0, 1, 0.0001);

    cout << "=============================================================\n";

    return 0;
}
