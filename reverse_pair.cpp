#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll cnt, temp[100010];

void reverse_pair_recursion(vector<ll> &nums, int l, int r) {
    if (l >= r) return;
    int mid = l + ((r - l) >> 1);
    reverse_pair_recursion(nums, l, mid);
    reverse_pair_recursion(nums, mid + 1, r);
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
}


int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    reverse_pair_recursion(nums, 0, n - 1);
    cout << cnt;
}