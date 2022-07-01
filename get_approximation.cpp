#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_approximation(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i != n / i) res.emplace_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        auto res = get_approximation(x);
        for (auto item: res) cout << item << ' ';
        cout << endl;
    }
    return 0;
}