#include <iostream>
#include <unordered_map>

const int N = 1e9 + 7;

using namespace std;

int main() {
    int n;
    unordered_map<int, int> hash;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; ++i)
            while (x % i == 0) x /= i, hash[i]++;
        if (x > 1) hash[x]++;
    }
    long long res = 1;
    for (auto item: hash) {
        res = res * (item.second + 1) % N;
    }
    cout << res;
    return 0;
}