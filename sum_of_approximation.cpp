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
    int res = 1;
    for (auto item: hash) {
        int p = item.first, i = item.second;
        long long temp = 1;
        while (i--) temp = (temp * p + 1) % N;
        res = res * temp % N;
    }
    cout << res;
    return 0;
}