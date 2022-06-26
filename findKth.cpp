#include <iostream>
#include <vector>

using namespace std;

int findKthRecursion(vector<int> &nums, int l, int r, int k) {
    if (l >= r) return nums[l];
    int i = l - 1, j = r + 1, pivot = nums[l + ((r - l) >> 1)];
    while (i < j) {
        while (nums[++i] < pivot);
        while (nums[--j] > pivot);
        if (i < j) swap(nums[i], nums[j]);
    }
    if (j - l + 1 >= k) return findKthRecursion(nums, l, j, k);
    else return findKthRecursion(nums, j + 1, r, k - (j - l + 1));
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << findKthRecursion(nums, 0, n - 1, k);
    return 0;
}