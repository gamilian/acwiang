#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1010;

int n, m, f[N][N];

char a[M][N];

int min_edit_dis(char a[], char b[]) {
    memset(f, 0, sizeof f);
    int len1 = strlen(a + 1), len2 = strlen(b + 1);
    for (int i = 0; i <= len1; i++) f[i][0] = i;
    for (int j = 0; j <= len2; j++) f[0][j] = j;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    }
    return f[len1][len2];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i] + 1;
    while (m--) {
        char b[N];
        int q;
        cin >> b + 1 >> q;
        int res = 0;
        for (int i = 0; i < n; i++)
            if (min_edit_dis(a[i], b) <= q) res++;
        cout << res << endl;
    }
    return 0;
}