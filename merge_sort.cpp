#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res[100010];

//void merge_sort(vector<int> &nums, int l, int r) {
//    if (l >= r) return;
//    else {
//        int mid = l + ((r - l) >> 1);
//        merge_sort(nums, l, mid);
//        merge_sort(nums, mid + 1, r);
//        inplace_merge(nums.begin() + l, nums.begin() + mid + 1, nums.begin() + r + 1);
//    }
//}

void merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    else {
        int mid = l + ((r - l) >> 1);
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        int i = l, j = mid + 1, cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) res[cnt++] = nums[i++];
            else res[cnt++] = nums[j++];
        }
        while (i <= mid) res[cnt++] = nums[i++];
        while (j <= r) res[cnt++] = nums[j++];
        for (int k = 0; k < cnt; k++) nums[l++] = res[k];
    }
}

int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i< n; i++) cin >> nums[i];
    merge_sort(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}