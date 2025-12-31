#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

//NIM: f1d02410107
//Nama: Ayra Aulia Saputri Hidayat
double Lagrange(const vector<double>& x, const vector<double>& y, double titik, int n) { double total = 0.0;
    for (int i = 0; i <= n; i++) { double basis = 1.0;
for (int j = 0; j <= n; j++) { if (i != j) { basis *= (titik - x[j]) / (x[i] - x[j]);}}total += y[i] * basis;} return total;}
int main() {
    vector<double> X = {1,2,3,4,5,6,7,8}; vector<double> Y = {1.5577,1.2131,0.9447,0.7358,0.5730,0.4462,0.3476,0.2706};
    cout << "Hasil Interpolasi Lagrange (data penuh):\n";
    cout << fixed << setprecision(7) << Lagrange(X, Y, 5.5, 7) << endl;
    vector<double> X2 = {5,6,7,8};
    vector<double> Y2 = {0.5730,0.4462,0.3476,0.2706};
    cout << "\nHasil Interpolasi Lagrange (data setengah):\n";
 cout << fixed << setprecision(7) << Lagrange(X2, Y2, 5.5, 3) << endl;
return 0;}
