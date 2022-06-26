#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int temp[50010];

int reverse_pair_recursion(vector<int> &nums, int l, int r) {
    if (l >= r) return 0;
    int mid = l + ((r - l) >> 1);
    long long cnt = reverse_pair_recursion(nums, l, mid) + reverse_pair_recursion(nums, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else {
            cnt += mid - i + 1;
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];
    copy(temp, temp + k, nums.begin() + l);
    return cnt;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << reverse_pair_recursion(nums, 0, n - 1);
}