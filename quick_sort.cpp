#include <iostream>
#include <vector>

using namespace std;

//void quick_sort(vector<int> &nums, int l, int r) {
//    if (l >= r) return;
//    swap(nums[l], nums[rand() % (r - l + 1) + l]);
//    int pivot = nums[l];
//    int i = l, j = r;
//    while (l < r) {
//        while (l < r) {
//            if (nums[r] > pivot) r--;
//            else {
//                nums[l++] = nums[r];
//                break;
//            }
//        }
//        while (l < r) {
//            if (nums[l] < pivot) l++;
//            else {
//                nums[r--] = nums[l];
//                break;
//            }
//        }
//    }
//    nums[l] = pivot;
//    quick_sort(nums, i, l - 1);
//    quick_sort(nums, l + 1, j);
//}

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
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    quick_sort(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}