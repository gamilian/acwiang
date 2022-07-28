#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, INF = 2e9 + 10;

struct Range {
    int l, r;

    bool operator<(const Range &w) const {
        return l < w.l;
    }
} range[N];

int main() {
    int s, t, n;
    cin >> s >> t >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n);
    int res = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int j = i, r = -INF;
        while (j < n && range[j].l <= s) r = max(r, range[j].r), j++;
        if (r < s) {
            res = -1;
            break;
        }
        res++;
        if (r >= t) {
            flag = true;
            break;
        }
        s = r;
        i = j - 1;
    }
    if (!flag) res = -1;
    cout << res;
    return 0;
}