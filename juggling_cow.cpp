#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010, INF = 1e9 + 10;

struct Cow {
    int w, s;

    bool operator<(const Cow &t) const {
        return w + s < t.w + t.s;
    }
} cow[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, s;
        cin >> w >> s;
        cow[i] = {w, s};
    }
    sort(cow, cow + n);
    int res = -INF, sum = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, sum - cow[i].s);
        sum += cow[i].w;
    }
    cout << res;
    return 0;
}