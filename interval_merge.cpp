#include <bits/stdc++.h>

using namespace std;

int interval_merge(vector<pair<int, int> > &segs) {
    sort(segs.begin(), segs.end());
    vector<pair<int, int> > res;
    int st = -2e9, ed = -2e9;
    for (auto const &seg: segs) {
        if (seg.first > ed) {
            if (st != -2e9) res.emplace_back(st, ed);
            st = seg.first;
            ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }
    if (st != -2e9) res.emplace_back(st, ed);
    segs = res;
    return res.size();
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > segs;
    while (n--) {
        int l, r;
        cin >> l >> r;
        segs.emplace_back(l, r);
    }
    cout << interval_merge(segs) << endl;
    return 0;
}