#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > add;   //存放所有的坐标上加的数
vector<pair<int, int> > query; //存放所有需查询的坐标对
vector<int> alls; //存放所有的坐标位置，将离散化的坐标映射为连续化的坐标

int find(vector<int> nums, int l, int r, int target) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}


int main() {
    int n, m;
    cin >> n >> m;
    while (n--) {
        int x, c;
        cin >> x >> c;
        add.emplace_back(x, c);
        alls.emplace_back(x);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        query.emplace_back(l, r);
        alls.emplace_back(l);
        alls.emplace_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    vector<int> a(alls.size() + 1), s(alls.size() + 1); //a存放映射后坐标上的数； s存放映射后坐标上的数的前缀和
    for (auto const &pair: add) a[find(alls, 0, alls.size() - 1, pair.first)] += pair.second;
    for (int i = 1; i <= alls.size(); ++i) s[i] += s[i - 1] + a[i];
    for (auto const &pair: query) {
        int l = find(alls, 0, alls.size() - 1, pair.first);
        int r = find(alls, 0, alls.size() - 1, pair.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}