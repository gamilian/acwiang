#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> A, int b) {
    int cnt = 0;
    vector<int> C;
    for (int i = 0; i < A.size(); ++i) {
        cnt += A[i] * b;
        C.emplace_back(cnt % 10);
        cnt /= 10;
    }
    while (cnt) {
        C.emplace_back(cnt % 10);
        cnt /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) A.emplace_back(a[i] - '0');
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    return 0;
}