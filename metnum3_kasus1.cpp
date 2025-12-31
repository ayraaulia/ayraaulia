#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

//NIM: f1d02410107
//Nama: Ayra Aulia Saputri Hidayat
const double Toleransi = 1e-10;
void CetakVector(const vector<double>& V) { for (double v : V)
cout << setw(12) << setprecision(7) << v;cout << endl;}
void CetakMatrix(const vector<vector<double>>& M) {
    for (const auto& baris : M) { for (double v : baris)
            cout << setw(12) << setprecision(7) << v;cout << endl;}}

vector<double> GaussPivot(vector<vector<double>>& A, vector<double>& B) {int n = B.size(); for (int k = 0; k < n; k++) {int pivot = k;
for (int i = k + 1; i < n; i++) {if (fabs(A[i][k]) > fabs(A[pivot][k]))
pivot = i;} swap(A[k], A[pivot]); swap(B[k], B[pivot]);
        if (fabs(A[k][k]) <= Toleransi)
        throw runtime_error("Matrix singular atau hampir singular");
    for (int i = k + 1; i < n; i++) {double rasio = A[i][k] / A[k][k];
            B[i] -= rasio * B[k];
            for (int j = k; j < n; j++) A[i][j] -= rasio * A[k][j];}}
    vector<double> solusi(n);
    for (int i = n - 1; i >= 0; i--) {double total = 0;
        for (int j = i + 1; j < n; j++) total += A[i][j] * solusi[j];
        solusi[i] = (B[i] - total) / A[i][i];}return solusi;}
vector<double> BangunSPL(vector<vector<double>>& data, int orde) {
    int jumlah = data.size();
    vector<vector<double>> A(orde, vector<double>(orde, 0.0));
    for (int i = 0; i < orde; i++) {for (int j = 0; j < orde; j++) {
    for (int k = 0; k < jumlah; k++)A[i][j] += pow(data[k][0], i + j);
        }}A[0][0] = jumlah; cout << "Matrix A:" << endl;
    CetakMatrix(A);cout << endl; vector<double> B(orde, 0.0);
    for (int i = 0; i < orde; i++) {for (int k = 0; k < jumlah; k++)
            B[i] += pow(data[k][0], i) * data[k][1];}
    cout << "Vector B:" << endl; CetakVector(B); cout << endl;
    return GaussPivot(A, B);}
int main() { vector<vector<double>> Data = {
        {1, 1.5577}, {2, 1.2131}, {3, 0.9447}, {4, 0.7358},
        {5, 0.5730}, {6, 0.4462}, {7, 0.3476}, {8, 0.2706}};
    cout << "Data:" << endl; CetakMatrix(Data);
vector<double> hasil; double error; cout << "\n(1) Model a + b x" << endl; hasil = BangunSPL(Data, 2);
 cout << "Persamaan: " << hasil[0] << " + " << hasil[1] << "x" << endl;
error = 0.0; for (auto& r : Data)
        error += pow((hasil[0] + hasil[1] * r[0]) - r[1], 2);
  error = sqrt(error / Data.size());cout << "Error: " << error << endl;
cout << "\n(2) Model ax^2 + bx + c" << endl;hasil = BangunSPL(Data, 3);
cout << "Persamaan: " << hasil[2] << "x^2 + " << hasil[1] << "x + "
<< hasil[0] << endl;error = 0.0; for (auto& r : Data)
        error += pow((hasil[2] * pow(r[0], 2) + hasil[1] * r[0] + hasil[0]) - r[1], 2);
error = sqrt(error / Data.size());cout << "Error: " << error << endl;
    cout << "\n(3) Model a e^(b x)" << endl;
    vector<vector<double>> logData(Data.size(), vector<double>(2));
    for (int i = 0; i < Data.size(); i++)
        logData[i][1] = log(Data[i][1]), logData[i][0] = Data[i][0];
hasil = BangunSPL(logData, 2);
cout << "Persamaan: " << hasil[0] << " e^(" << hasil[1] << "x)" << endl;error = 0.0;for (auto& r : Data)
        error += pow((hasil[0] * pow(r[0], hasil[1])) - r[1], 2);
 error = sqrt(error / Data.size());cout << "Error: " << error << endl;
return 0;}
