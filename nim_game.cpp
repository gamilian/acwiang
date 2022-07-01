#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    while (n--) {
        int x;
        cin >> x;
        res ^= x;
    }
    if (res) cout << "Yes";
    else cout << "No";
    return 0;
}