#include <iostream>

using namespace std;

//q[i] 记录队列元素在原数组的下标
int a[100010], q[100010];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, head = 0, tail = -1; i < n; ++i) {
        //i为滑动窗口尾部下标， q[head]为滑动窗口首部下标
        if (head <= tail && i - q[head] + 1 > k) head++;
        while (head <= tail && a[q[tail]] >= a[i]) tail--;
        q[++tail] = i;
        if (i >= k - 1) cout << a[q[head]] << ' ';
    }
    cout << endl;
    for (int i = 0, head = 0, tail = -1; i < n; ++i) {
        if (head <= tail && i - q[head] + 1 > k) head++;
        while (head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;
        if (i >= k - 1) cout << a[q[head]] << ' ';
    }
    return 0;
}
