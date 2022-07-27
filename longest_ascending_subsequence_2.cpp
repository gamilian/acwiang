#include <iostream>

using namespace std;

const int N = 100010;

int n, hh = 0, tt = -1, a[N], q[N];

int find(int x) {
    int l = 0, r = tt;
    while (l < r) {
        int mid = l + r >> 1;
        if (q[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r;
}

int main() {
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (hh <= tt && x <= q[tt]) q[find(x)] = x;
        else q[++tt] = x;
    }
    cout << tt + 1;
    return 0;
}