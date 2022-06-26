#include <iostream>

using namespace std;

//不带头节点的静态单链表, 不考虑内存泄漏， 边界情况
//e[i]表示节点i的值
//ne[i]表示节点i的next指针，记录next节点所在的下标
//head表示首节点所在下标
//idx存储节点编号
int e[100010], ne[100010], head, idx;

//初始化
void init() {
    head = -1;
    idx = 0;
}

//头插法
void insert_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}

//在k节点后插入一个节点
void insert(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

//删除首节点
void remove_head() {
    head = ne[head];
}

//删除k节点后的节点
void remove(int k) {
    ne[k] = ne[ne[k]];
}

//打印链表
void print() {
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
}

int main() {
    int m;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> m;
    init();
    while (m--) {
        char op;
        int k, x;
        cin >> op;
        if (op == 'H') {
            cin >> x;
            insert_head(x);
        } else if (op == 'D') {
            cin >> k;
            if (k == 0) remove_head(); //插入的是首节点
            else remove(k - 1);
        } else {
            cin >> k >> x;
            insert(k - 1, x);
        }
    }
    print();
    return 0;
}




