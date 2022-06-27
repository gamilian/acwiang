#include <bits/stdc++.h>

using namespace std;

vector<int> sum_of_target(vector<int> nums1, vector<int> nums2, int target) {
    int i = 0, j = nums2.size() - 1;
    while (i < nums1.size() && j >= 0) {
        while (nums1[i] + nums2[j] > target) j--;
        if (nums1[i] + nums2[j] == target) return {i, j};
        i++;
    }
    return {-1, -1};
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; ++i) cin >> nums1[i];
    for (int i = 0; i < m; ++i) cin >> nums2[i];
    vector<int> res = sum_of_target(nums1, nums2, x);
    for (int i = 0; i < 2; ++i) cout << res[i] << ' ';
    return 0;
}