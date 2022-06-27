#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;
int n, h[N];

//开方定址法解决冲突
//返回x在哈希表中的位置，或者x需要插入在哈希表位置
int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N) k = 0;
    }
    return k;
}

int main(void) {
    // cin超时需要scanf
    memset(h, 0x3f, sizeof h);
    scanf("%d", &n);
    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I') h[find(x)] = x;
        else
        {
            if (h[find(x)] == null) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}