#include <bits/stdc++.h>

using namespace std;

int lowbit(int num) {
    return num & (-num);
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int num, res = 0;
        cin >> num;
        while (num) {
            num -= lowbit(num);
            res++;
        }
        cout << res << ' ';
    }
    return 0;
}