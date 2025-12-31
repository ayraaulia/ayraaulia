#include <iostream>
#include <iomanip>
#include <cmath>

//NIM: f1d02410107
//Nama: Ayra Aulia Saputri Hidayat

double zed(double, double, double z) {
    return z;
}

double result(double x, double y, double z) {
    return 0.25 * z - 64.0 * x * y;
}

int main() {
    std::cout << std::fixed << std::setprecision(8);

    double b, h;
    std::cin >> b >> h;

    int n = static_cast<int>(b / h);

    double x = 0.0;
    double y = 1.0;
    double z = -8.0;

    std::cout << "====================================================\n";
    std::cout << "          RUNGE-KUTTA ORDE 4 (RK4)\n";
    std::cout << "   y'' = 0.25 y' - 64 x y,  y(0)=1,  y'(0)=-8\n";
    std::cout << "----------------------------------------------------\n";
    std::cout << "b = " << b << "   h = " << h << "   langkah(n) = " << n << "\n";
    std::cout << "====================================================\n\n";

    std::cout << "Kondisi awal:\n";
    std::cout << "x0 = " << std::setw(12) << x
              << "   y0 = " << std::setw(14) << y
              << "   z0 = " << std::setw(14) << z << "\n\n";

    for (int i = 1; i <= n; ++i) {
        double k1 = h * zed(x, y, z);
        double l1 = h * result(x, y, z);

        double k2 = h * zed(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);
        double l2 = h * result(x + h / 2.0, y + k1 / 2.0, z + l1 / 2.0);

        double k3 = h * zed(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);
        double l3 = h * result(x + h / 2.0, y + k2 / 2.0, z + l2 / 2.0);

        double k4 = h * zed(x + h, y + k3, z + l3);
        double l4 = h * result(x + h, y + k3, z + l3);

        y += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        z += (l1 + 2.0 * l2 + 2.0 * l3 + l4) / 6.0;
        x += h;

        std::cout << "----------------- Langkah " << i << " -----------------\n";
        std::cout << "x" << i << " = " << std::setw(12) << x << "\n";
        std::cout << "y" << i << " = " << std::setw(12) << y << "\n";
        std::cout << "z" << i << " = " << std::setw(12) << z << "\n\n";
    }

    std::cout << "======================= SELESAI =====================\n";
    return 0;
}
