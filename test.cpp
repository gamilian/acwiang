#include <iostream>

using namespace std;

int a[26];

void init() {
    for (int i = 0; i < 18; i++) a[i] = i / 3 + 2;
    a[18] = 7;
    a[19] = a[20] = a[21] = 8;
    a[22] = a[23] = a[24] = a[25] = 9;
}

int get_num(char ch) {
    int idx = ch - 'a';
    if (idx >= 0 && idx <= 17) return idx % 3 + 1;
    else {
        if (ch == 's' || ch == 'z') return 4;
        if (ch == 't' || ch == 'w') return 1;
        if (ch == 'u' || ch == 'x') return 2;
        if (ch == 'v' || ch == 'y') return 3;
    }
}

int main() {
    init();
    string s;
    while (cin >> s) {
        int cnt = 0;
        char pre = s[0];
        cnt += get_num(pre);
        for (int i = 1; i < s.size(); i++) {
            int idx1 = pre - 'a', idx2 = s[i] - 'a';
            if (a[idx1] == a[idx2]) cnt += 2;
            cnt += get_num(s[i]);
            pre = s[i];
        }
        cout << cnt << endl;
    }
    return 0;
}