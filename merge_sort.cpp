#include <iostream>
#include <vector>

using namespace std;

int res[100010];

void merge(vector<int> &nums, int l1, int r1, int l2, int r2) {
    int cnt = 0, begin = l1;
    while (l1 <= r1 && l2 <= r2) {
        if (nums[l1] < nums[l2]) res[cnt++] = nums[l1++];
        else res[cnt++] = nums[l2++];
    }
    while (l1 <= r1) res[cnt++] = nums[l1++];
    while (l2 <= r2) res[cnt++] = nums[l2++];
    for (int i = 0; i < cnt; ++i) nums[begin++] = res[i];
}

void merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    else {
        int mid = l + ((r - l) >> 1);
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        ////inplace_merge(nums.begin() + l, nums.begin() + mid + 1, nums.begin() + r + 1);
        merge(nums, l, mid, mid + 1, r);
    }
}

void merge_sort2(vector<int> &nums, int l, int r) {
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
    vector<int> nums = {3, 4, 2, 1, 5};
    merge_sort2(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}