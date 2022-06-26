#include <iostream>
#include <vector>

using namespace std;

vector<int> div(vector<int> A, int b, int &r) {
    vector<int> C;
    for (int i = 0; i < A.size(); ++i) {
        r = r * 10 + A[i];
        C.emplace_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 0 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a;
    int b, r = 0;
    vector<int> A;
    cin >> a >> b;
    for (auto const &ch: a) A.emplace_back(ch - '0');
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    cout << endl << r;
    return 0;
}