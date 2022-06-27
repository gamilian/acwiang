#include <bits/stdc++.h>

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
//牛顿迭代法
//等价于求f(x) = x^3 - c = 0的根
//t = t - f/(df/dt) = t - (t^3 - c)/(3t^2) = (2t^3 + c)/(3t^2)

double cubic_root(double num){
    double t = num;
    for (int i = 0; i < 100; i++)
        t = (2 * t * t * t + num) / (3 * t * t);
    return t;
}

int main() {
    double x;
    cin >> x;
    cout<<fixed<<setprecision(6);
    cout << cubic_root(x, -1100, 1100);
    return 0;
}