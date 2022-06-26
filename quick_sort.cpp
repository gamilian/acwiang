#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &nums, int l, int r) {
    swap(nums[l], nums[l + ((r - l) >> 1)]);
    int pivot = nums[l];
    while (l < r) {
        while (l < r && nums[r] > pivot) r--;
        nums[l] = nums[r];
        while (l < r && nums[l] <= pivot) l++;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
}

void quick_sort2(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    if (l < r) {
        int pivot = partition(nums, l, r);
        quick_sort2(nums, l, pivot - 1);
        quick_sort2(nums, pivot + 1, r);
    }
}

void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, pivot = nums[l + ((r - l) >> 1)];
    //pivot = nums[rand() % (r - l + 1) + l]
    while (i < j) {
        while (nums[++i] < pivot);
        while (nums[--j] > pivot);
        if (i < j) swap(nums[i], nums[j]);
    }
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

int main() {
    vector<int> nums = {3, 4, 2, 1, 5};
    quick_sort2(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}