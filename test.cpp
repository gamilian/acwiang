#include "bits/stdc++.h"

using namespace std;

int lengthOfLongestSubstring(string s) {
    int res = 0;
    map<char, int> mmp;
    for (int i = 0, j = 0; i < s.size(); i++) {
        if (mmp[s[i]] > 0) j = max(j, mmp[s[i]]);
        mmp[s[i]] = i + 1;
        res = max(res, i - j + 1);
    }
    return res;
}

int main() {
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s);



    cout << -1 % 3;


    return 0;
}