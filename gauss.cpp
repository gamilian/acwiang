#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 110;
const double eps = 1e-9;

int n;
double a[N][N];

int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; ++c) {
        // t为绝对值最大的行
        int t = r;
        for (int i = r; i < n; i++) {
            if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
        }
        // 绝对值最大行首位为0
        if (fabs(a[t][c]) < eps) continue;
        // 将当前行与绝对值最大行交换
        for (int i = c; i <= n; ++i) swap(a[r][i], a[t][i]);
        // 将当前行首位变成1
        for (int i = n; i >= c; --i) a[r][i] /= a[r][c];
        // 将当前行下面的列都变成0
        for (int i = r + 1; i < n; ++i) {
            if (fabs(a[i][c]) > 0) {
                for (int j = n; j >= c; --j) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }

    if (r < n) {
        for (int i = r; i < n; ++i)
            if (fabs(a[i][n]) > eps) return 0;
        return 2;
    }
    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j < n; ++j)
            a[i][n] -= a[i][j] * a[j][n];
    return 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0) cout << "No solution";
    else if (t == 2) cout << "Infinite group solutions";
    else {
        for (int i = 0; i < n; ++i) {
            if (fabs(a[i][n]) < eps) a[i][n] = 0;
            cout << fixed << setprecision(2) << a[i][n] << endl;
        }
    }
    return 0;
}
