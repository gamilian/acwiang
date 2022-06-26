#include <iostream>

using namespace std;

const double eps = 1e-8;

double cubic_root(double x, double l, double r) {
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    return l;
}

int main() {
    double x;
    cin >> x;
    cout << cubic_root(x, -1 * x * 100, x * 100);
    return 0;
}