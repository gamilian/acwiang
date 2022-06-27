#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> A, vector<int> B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; --i)
        if (A[i] != B[i]) return A[i] > B[i];
    return true;

}

vector<int> sub(vector<int> A, vector<int> B) {
    if (!cmp(A, B)) return sub(B, A);
    int cnt = 0;
    vector<int> C;
    for (int i = 0; i < A.size(); ++i) {
        cnt = A[i] - cnt;
        if (i < B.size()) cnt -= B[i];
        C.emplace_back((cnt + 10) % 10);
        cnt = cnt < 0 ? 1 : 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) A.emplace_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i) B.emplace_back(b[i] - '0');
    auto C = sub(A, B);
    if (!cmp(A, B)) cout << '-';
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    return 0;
}