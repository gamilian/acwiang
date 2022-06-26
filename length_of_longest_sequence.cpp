#include <bits/stdc++.h>

using namespace std;

int length_of_longest_sequence(string s) {
    int res = 0;
    vector<int> hashTable(128);
    for (int i = 0, j = 0; i < s.size(); i++) {
        if (hashTable[s[i]] > 0) j = max(j, hashTable[s[i]]);
        hashTable[s[i]] = i + 1;
        res = max(res, i - j + 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    string str;
    str.assign(nums.begin(), nums.end());
    cout << length_of_longest_sequence(str);
    return 0;
}