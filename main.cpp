#include <iostream>
#include <vector>

using namespace std;

int temp[50010];
int cnt = 0;

int mergeSelect(vector<int> &nums, int l, int r, int lower, int upper) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    mergeSelect(nums, l, mid, lower, upper);
    mergeSelect(nums, mid + 1, r, lower, upper);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        while (nums[i] < lower || nums[i] > upper) i++;
        while (nums[j] < lower || nums[j] > upper) j++;
        cnt += (mid - i + 1) * (r - j + 1);
        break;
    }
    i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];
    for (int i = 0, j = l; j <= r; i++, j++) nums[j] = temp[i];
    return cnt;
}

int countRangeSum(vector<int> &nums, int lower, int upper) {
    return mergeSelect(nums, 0, nums.size() - 1, lower, upper);
}

int main() {
    vector<int> nums = {-2, 5, -1};
    vector<long long> sums = {0};
    for (int i = 0; i < nums.size(); ++i) sums.push_back(sums[i] + nums[i]);

    cout << countRangeSum(nums, -2, 2);

    return 0;
}
