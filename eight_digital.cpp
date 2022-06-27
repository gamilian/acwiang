#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string state) {
    unordered_map<string, int> d;
    queue<string> q;
    d[state] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    string end = "12345678x";
    q.push(state);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        if (t == end) return d[t];
        int dis = d[t];
        int k = t.find('x');
        int px = k / 3, py = k % 3;
        for (int i = 0; i < 4; ++i) {  
            int x = px + dx[i], y = py + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                swap(t[x * 3 + y], t[k]);
                if (!d.count(t)) {
                    d[t] += dis + 1;
                    q.push(t);
                }
                swap(t[x * 3 + y], t[k]);
            }
        }
    }
    return -1;
}

int main() {
    string state;
    for (int i = 0; i < 9; ++i) {
        char ch;
        cin >> ch;
        state += ch;
    }
    cout << bfs(state);
    return 0;
}