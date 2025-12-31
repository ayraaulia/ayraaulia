#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>   
using namespace std;

//NIM: f1d02410107
//Nama: Ayra Aulia Saputri Hidayat

int main() {
    const int N = 10;
    const int nimDigit = 7;    
    const double tolerance = 1e-4;
    const int max_iter = 50;

    double A[N][N] = {
        {10, 1, 0, 2, 0, 1, 0, 0, 0, 0},
        {1, 10, 2, 0, 1, 0, 0, 0, 1, 0},
        {0, 2, 10, 1, 0, 0, 1, 0, 0, 0},
        {2, 0, 1, 10, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 10, 2, 0, 1, 0, 0},
        {1, 0, 0, 0, 2, 10, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1, 10, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 10, 2, 0},
        {0, 1, 0, 0, 0, 0, 1, 2, 10, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 10}
    };

    double b[N]      = { 1, -1,  1, -1,  1, -1,  1, -1,  1, -nimDigit };
    double x[N]      = {};  
    double xOld[N]   = {};  

    cout << fixed << setprecision(4);
    cout << "~~~ PENYELESAIAN SISTEM PERSAMAAN LINEAR SIMULTAN ~~~\n";
    cout << "         ~~~ METODE GAUSS-SEIDEL (10x10) ~~~         \n\n";

    cout << "Matriks A:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << setw(6) << A[i][j] << ' ';
        cout << '\n';
    }

    cout << "\nVektor b:\n";
    for (int i = 0; i < N; ++i) cout << "b" << i+1 << " = " << setw(6) << b[i] << '\n';

    cout << "\nIterasi maksimum: " << max_iter;
    cout << "\nToleransi error : " << tolerance;
    cout << "\nNilai awal x = 0\n\n";

    bool converged = false;
    int iterCount;

    for (iterCount = 0; iterCount < max_iter; ++iterCount) {
        std::copy(x, x + N, xOld);

        for (int i = 0; i < N; ++i) {
            double sum = 0.0;
            for (int j = 0; j < N; ++j) {
                if (j != i) sum += A[i][j] * x[j]; 
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double maxError = 0.0;
        for (int i = 0; i < N; ++i) {
            double err = fabs(x[i] - xOld[i]);
            if (err > maxError) maxError = err;
        }

        cout << "Iterasi ke-" << setw(2) << (iterCount + 1) << " | | ";
        for (int i = 0; i < N; ++i) cout << "x" << i+1 << "=" << setw(8) << x[i] << ' ';
        cout << " | | Error Max = " << maxError << '\n';

        if (maxError < tolerance) { converged = true; break; }
    }

    cout << "\n~~~~~~~~ HASIL AKHIR ~~~~~~~~\n";
    if (converged) {
        cout << "Konvergen setelah " << (iterCount + 1) << " iterasi.\n\n";
        for (int i = 0; i < N; ++i) cout << "x" << i+1 << " = " << x[i] << '\n';
    } else {
        cout << "Tidak konvergen setelah " << max_iter << " iterasi.\n";
    }

    return 0;
}