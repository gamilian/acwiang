#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> A, vector<int> B) {
    if (A.size() < B.size()) return add(B, A);
    int cnt = 0;
    vector<int> C;
    for (int i = 0; i < A.size(); ++i) {
        if (i < B.size()) cnt += B[i];
        cnt += A[i];
        C.emplace_back(cnt % 10);
        cnt /= 10;
    }
    if (cnt) C.emplace_back(cnt);
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) A.emplace_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i) B.emplace_back(b[i] - '0');
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    return 0;
}