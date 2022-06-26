#include <bits/stdc++.h>

using namespace std;

int binary_of_kth(int num, int k) {
    return num >> k & 1;
}


int main() {
    int num, k;
    cin >> num >> k;
    cout << binary_of_kth(num, k);
    return 0;
}