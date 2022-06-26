#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);
    vector<int> sums(n + 1);
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    for (int i = 1; i <= n; ++i) sums[i] = sums[i - 1] + nums[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << sums[r] - sums[l - 1] << endl;
    }
    return 0;
}