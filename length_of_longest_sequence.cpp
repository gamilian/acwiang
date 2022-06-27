#include <bits/stdc++.h>

using namespace std;

int length_of_longest_sequence(vector<int> nums) {
    int res = 0;
    vector<int> hashTable(100010);
    for (int i = 0, j = 0; i < nums.size(); i++) {
        if (hashTable[nums[i]] > 0) j = max(j, hashTable[nums[i]]);
        hashTable[nums[i]] = i + 1;
        res = max(res, i - j + 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << length_of_longest_sequence(nums);
    return 0;
}