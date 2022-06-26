#include <iostream>

using namespace std;

//带头节点的静态双向链表, 不考虑内存泄漏, 边界情况
//e[i]表示节点i的值
//r[i]表示节点i的next指针，记录next节点所在的下标
//l[i]表示节点i的prior指针，记录prior节点所在的下标
//head表示头节点所在下标(第一个数据节点之前)， tail表示尾节点(最后一个数据节点之后)，不存放数据
//idx存储节点编号
int e[100010], l[100010], r[100010], head, tail, idx;

//初始化
void init() {
    head = 0, tail = 1;
    r[head] = 1, l[tail] = 0;
    idx = 2;
}

//头插法
void insert_head(int x) {
    e[idx] = x, l[r[head]] = idx, r[idx] = r[head], l[idx] = head, r[head] = idx++;
}

//尾插法
void insert_tail(int x) {
    e[idx] = x, l[idx] = l[tail], r[l[tail]] = idx, l[tail] = idx, r[idx++] = tail;
}

//在k节点前插入一个节点
void insert_l(int k, int x) {
    e[idx] = x, l[idx] = l[k], r[l[k]] = idx, l[k] = idx, r[idx++] = k;
}

//在k节点后插入一个节点
void insert_r(int k, int x) {
    e[idx] = x, l[r[k]] = idx, r[idx] = r[k], l[idx] = k, r[k] = idx++;
}

//删除k节点
void remove(int k) {
    l[r[k]] = l[k], r[l[k]] = r[k];
}

//打印链表
void print() {
    for (int i = r[head]; i != tail; i = r[i]) cout << e[i] << ' ';
}

int main() {
    int m;
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    cin >> m;
    init();
    while (m--) {
        string op;
        int k, x;
        cin >> op;
        if (op == "L") {
            cin >> x;
            insert_head(x);
        } else if (op == "R") {
            cin >> x;
            insert_tail(x);
        } else if (op == "D") {
            cin >> k;
            remove(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            insert_l(k + 1, x);
        } else if (op == "IR") {
            cin >> k >> x;
            insert_r(k + 1, x);
        }
    }
    print();
    return 0;
}




