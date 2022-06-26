#include <iostream>
#include <vector>

using namespace std;

int find_lower(vector<int> nums, int l, int r, int k) {
    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] >= k) r = mid;
        else l = mid + 1;
    }
    return l;
}

int find_upper(vector<int> nums, int l, int r, int k) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (nums[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        if (nums[find_lower(nums, 0, n - 1, k)] != k) cout << "-1 -1" << endl;
        else cout << find_lower(nums, 0, n - 1, k) << ' ' << find_upper(nums, 0, n - 1, k) << endl;
    }
    return 0;
}
