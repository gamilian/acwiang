#include <iostream>
#include <vector>

const int N = 100010;
int nums[N];

using namespace std;

int find_lower(int nums[], int l, int r, int k) {
    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] >= k) r = mid;
        else l = mid + 1;
    }
    return l;
}

int find_upper(int nums[], int l, int r, int k) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (nums[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int n, q;
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    while (q--) {
        int k;
        cin >> k;
        if (nums[find_lower(nums, 0, n - 1, k)] != k) cout << "-1 -1" << endl;
        else cout << find_lower(nums, 0, n - 1, k) << ' ' << find_upper(nums, 0, n - 1, k) << endl;
    }
    return 0;
}





//#include <bits/stdc++.h>
//using namespace std;
//
//void solve(int k, vector<int> &nums) {
//    int l = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
//    int r = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
//    if(nums[l] == k) cout << l << ' ';
//    else cout << "-1 ";
//    if(nums[r - 1] == k) cout << r - 1 << endl;
//    else cout << "-1" << endl;
//}
//
//int main(){
//    int n, q, k, tmp;
//    cin.tie(0);
//    cin >> n >> q;
//    vector<int> nums(n);
//    for(int i = 0; i < n; i ++) cin >> nums[i];
//    while(q --) {
//        cin >> k;
//        solve(k, nums);
//    }
//    return 0;
//}
