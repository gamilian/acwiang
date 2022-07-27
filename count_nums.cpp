#include <iostream>
#include <vector>

using namespace std;

/*

n = abcdefg
1-n中第四位为x的个数

1. 前三位小于adc，即000~abc-1, 第四位为x，后三位000~999任选，一共abc * 1000个

2.前三位等于abc，第四位为x
    1. d < x, 即n < adcxefg 0个
    2. d == x 后三位0~efg任选，共efg + 1个
    3. d > x, 后三位0~999，共1000个

*/


int get(vector<int> nums, int l, int r) {
    int res = 0;
    for (int i = r; i >= l; i--) res = res * 10 + nums[i];
    return res;
}

int power10(int x) {
    int res = 1;
    while (x--) res *= 10;
    return res;
}

int count_n(int n, int x) {
    if (!n) return 0;
    vector<int> nums;
    while (n) {
        nums.emplace_back(n % 10);
        n /= 10;
    }
    n = nums.size();
    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i--) {
        if (i < n - 1) {
            res += power10(i) * get(nums, i + 1, n - 1);
            if (!x) res -= power10(i);
        }
        if (nums[i] == x) res += get(nums, 0, i - 1) + 1;
        else if (nums[i] > x) res += power10(i);
    }
    return res;
}


int main() {
    int a, b;
    while (cin >> a >> b, a && b) {
        if (a > b) swap(a, b);
        for (int i = 0; i < 10; i++)
            cout << count_n(b, i) - count_n(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}