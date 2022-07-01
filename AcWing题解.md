

# AcWing题解

[TOC]

## 第一章：基础算法

### 1.1 排序

#### AcWing 785. 快速排序

给定你一个长度为 $ n $ 的整数数列。

请你使用快速排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

**输入格式**

输入共两行，第一行包含整数 $ n $。

第二行包含 $ n $ 个整数（所有整数均在 $ 1 \sim 10^9 $ 范围内），表示整个数列。

**输出格式**

输出共一行，包含 $ n $ 个整数，表示排好序的数列。

**数据范围**

$ 1 \le n \le 100000 $

**输入样例**：

```
5
3 1 2 4 5
```

**输出样例**：

```
1 2 3 4 5
```

**acwing版本快排**

```c++
#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, pivot = nums[rand() % (r - l + 1) + l];
    //pivot = nums[l + ((r - l) >> 1)];
    while (i < j) {
        while (nums[++i] < pivot);
        while (nums[--j] > pivot);
        if (i < j) swap(nums[i], nums[j]);
    }
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}


int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    quick_sort(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}
```

**严蔚敏版本快排（会TLE）**

```c++
#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    swap(nums[l], nums[rand() % (r - l + 1) + l]);
    int pivot = nums[l];
    int i = l, j = r;
    while (l < r) {
        while (l < r && nums[r] > pivot) r--;
        nums[l] = nums[r];
        while (l < r && nums[l] <= pivot) l++;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    quick_sort(nums, i, l - 1);
    quick_sort(nums, l + 1, j);
}


int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    quick_sort(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}
```

**严蔚敏版本快排改进版（不会TLE，可AC）**

```c++
#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    swap(nums[l], nums[rand() % (r - l + 1) + l]);
    int pivot = nums[l];
    int i = l, j = r;
    while (l < r) {
        while (l < r) {
            if (nums[r] > pivot) r--;
            else {
                nums[l++] = nums[r];
                break;
            }
        }
        while (l < r) {
            if (nums[l] < pivot) l++;
            else {
                nums[r--] = nums[l];
                break;
            }
        }
    }
    nums[l] = pivot;
    quick_sort(nums, i, l - 1);
    quick_sort(nums, l + 1, j);
}


int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    quick_sort(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}
```

#### AcWing 786. 第k个数

给定一个长度为 $ n $ 的整数数列，以及一个整数 $ k $，请用快速选择算法求出数列从小到大排序后的第 $ k $ 个数。

**输入格式**

第一行包含两个整数 $ n $ 和 $ k $。

第二行包含 $ n $ 个整数（所有整数均在 $ 1 \sim 10^9 $ 范围内），表示整数数列。

**输出格式**

输出一个整数，表示数列的第 $ k $ 小数。

**数据范围**

$ 1 \le n \le 100000 $,  
$ 1 \le k \le n $

**输入样例**：

```
5 3
2 4 1 5 3
```

**输出样例**：

```
3
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int findKthRecursion(vector<int> &nums, int l, int r, int k) {
    if (l >= r) return nums[l];
    int i = l - 1, j = r + 1, pivot = nums[l + ((r - l) >> 1)];
    while (i < j) {
        while (nums[++i] < pivot);
        while (nums[--j] > pivot);
        if (i < j) swap(nums[i], nums[j]);
    }
    if (j - l + 1 >= k) return findKthRecursion(nums, l, j, k);
    else return findKthRecursion(nums, j + 1, r, k - (j - l + 1));
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << findKthRecursion(nums, 0, n - 1, k);
    return 0;
}
```

#### AcWing 787. 归并排序

给定你一个长度为 $ n $ 的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

**输入格式**

输入共两行，第一行包含整数 $ n $。

第二行包含 $ n $ 个整数（所有整数均在 $ 1 \sim 10^9 $ 范围内），表示整个数列。

**输出格式**

输出共一行，包含 $ n $ 个整数，表示排好序的数列。

**数据范围**

$ 1 \le n \le 100000 $

**输入样例**：

```
5
3 1 2 4 5
```

**输出样例**：

```
1 2 3 4 5
```

**acwing版本**

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res[100010];

void merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    else {
        int mid = l + ((r - l) >> 1);
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        int i = l, j = mid + 1, cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) res[cnt++] = nums[i++];
            else res[cnt++] = nums[j++];
        }
        while (i <= mid) res[cnt++] = nums[i++];
        while (j <= r) res[cnt++] = nums[j++];
        for (int k = 0; k < cnt; k++) nums[l++] = res[k];
    }
}

int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i< n; i++) cin >> nums[i];
    merge_sort(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}
```

**stl版本**

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res[100010];

void merge_sort(vector<int> &nums, int l, int r) {
    if (l >= r) return;
    else {
        int mid = l + ((r - l) >> 1);
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        inplace_merge(nums.begin() + l, nums.begin() + mid + 1, nums.begin() + r + 1);
    }
}

int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i< n; i++) cin >> nums[i];
    merge_sort(nums, 0, nums.size() - 1);
    for (auto const &num: nums)
        cout << num << ' ';
    return 0;
}
```

#### AcWing 788. 逆序对的数量

给定一个长度为 $ n $ 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 $ i $ 个和第 $ j $ 个元素，如果满足 $ i < j $ 且 $ a[i] > a[j] $，则其为一个逆序对；否则不是。

**输入格式**

第一行包含整数 $ n $，表示数列的长度。

第二行包含 $ n $ 个整数，表示整个数列。

**输出格式**

输出一个整数，表示逆序对的个数。

**数据范围**

$ 1 \le n \le 100000 $，  
数列中的元素的取值范围 $ [1,10^9] $。

**输入样例**：

```
6
2 3 4 5 6 1
```

**输出样例**：

```
5
```

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll cnt, temp[100010];

void reverse_pair_recursion(vector<ll> &nums, int l, int r) {
    if (l >= r) return;
    int mid = l + ((r - l) >> 1);
    reverse_pair_recursion(nums, l, mid);
    reverse_pair_recursion(nums, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else {
            cnt += mid - i + 1;
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];
    copy(temp, temp + k, nums.begin() + l);
}


int main() {
    int n;
    cin.tie(0);
    cin >> n;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    reverse_pair_recursion(nums, 0, n - 1);
    cout << cnt;
}
```



### 1.2 二分

#### AcWing 789. 数的范围

给定一个按照升序排列的长度为 $ n $ 的整数数组，以及 $ q $ 个查询。

对于每个查询，返回一个元素 $ k $ 的起始位置和终止位置（位置从 $ 0 $ 开始计数）。

如果数组中不存在该元素，则返回 `-1 -1`。

**输入格式**

第一行包含整数 $ n $ 和 $ q $，表示数组长度和询问个数。

第二行包含 $ n $ 个整数（均在 $ 1 \sim 10000 $ 范围内），表示完整数组。

接下来 $ q $ 行，每行包含一个整数 $ k $，表示一个询问元素。

**输出格式**

共 $ q $ 行，每行包含两个整数，表示所求元素的起始位置和终止位置。

如果数组中不存在该元素，则返回 `-1 -1`。

**数据范围**

$ 1 \le n \le 100000 $  
$ 1 \le q \le 10000 $  
$ 1 \le k \le 10000 $

**输入样例**：

```
6 3
1 2 2 3 3 4
3
4
5
```

**输出样例**：

```diff
3 4
5 5
-1 -1
```

**acwing版本，必须用数组，vector会TLE**

```c++
#include <iostream>
#include <vector>

const int N = 100010;
int nums[N];

using namespace std;

int find_lower(int nums[], int l, int r, int k) {
    while (l < r) {
        int mid = l + r >> 1;
        if (nums[mid] >= k) r = mid;
        else l = mid + 1;
    }
    return l;
}

int find_upper(int nums[], int l, int r, int k) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (nums[mid] <= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    int n, q;
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    while (q--) {
        int k;
        cin >> k;
        if (nums[find_lower(nums, 0, n - 1, k)] != k) cout << "-1 -1" << endl;
        else cout << find_lower(nums, 0, n - 1, k) << ' ' << find_upper(nums, 0, n - 1, k) << endl;
    }
    return 0;
}
```

**stl，lower_bound与upper_bound版本**

```c++
#include <bits/stdc++.h>
using namespace std;

void solve(int k, vector<int> &nums) {
    int l = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
    int r = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
    if(nums[l] == k) cout << l << ' ';
    else cout << "-1 ";
    if(nums[r - 1] == k) cout << r - 1 << endl;
    else cout << "-1" << endl;
}

int main(){
    int n, q, k, tmp;
    cin.tie(0);
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; i ++) cin >> nums[i];
    while(q --) {
        cin >> k;
        solve(k, nums);
    }
    return 0;
}
```

#### AcWing 790. 数的三次方

给定一个浮点数 $ n $，求它的三次方根。

**输入格式**

共一行，包含一个浮点数 $ n $。

**输出格式**

共一行，包含一个浮点数，表示问题的解。

注意，结果保留 $ 6 $ 位小数。

**数据范围**

$ -10000 \le n \le 10000 $

**输入样例**：

```css
1000.00
```

**输出样例**：

```css
10.000000
```

**acwing版本**

```c++
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

double cubic_root(double x, double l, double r) {
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    return l;
}

int main() {
    double x;
    cin >> x;
    cout<<fixed<<setprecision(6);
    cout << cubic_root(x, -1100, 1100);
    return 0;
}
```

**牛顿迭代法**

```c++
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

//牛顿迭代法
//等价于求f(x) = x^3 - c = 0的根
//t = t - f/(df/dt) = t - (t^3 - c)/(3t^2) = (2t^3 + c)/(3t^2)
double cubic_root(double num){
    double t = num;
    for (int i = 0; i < 100; i++)
        t = (2 * t * t * t + num) / (3 * t * t);
    return t;
}

int main() {
    double x;
    cin >> x;
    cout<<fixed<<setprecision(6);
    cout << cubic_root(x);
    return 0;
}
```



### 1.3 高精度

#### AcWing 791. 高精度加法

给定两个正整数（不含前导 $ 0 $），计算它们的和。

**输入格式**

共两行，每行包含一个整数。

**输出格式**

共一行，包含所求的和。

**数据范围**

$ 1 \le 整数长度 \le 100000 $

**输入样例**：

```
12
23
```

**输出样例**：

```
35
```

```c++
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
```

#### AcWing 792. 高精度减法

给定两个正整数（不含前导 $ 0 $），计算它们的差，计算结果可能为负数。

**输入格式**

共两行，每行包含一个整数。

**输出格式**

共一行，包含所求的差。

**数据范围**

$ 1 \le 整数长度 \le 10^5 $

**输入样例**：

```
32
11
```

**输出样例**：

```
21
```

```c++
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> A, vector<int> B) {
    if (A.size() != B.size()) return A.size() >= B.size();
    for (int i = A.size() - 1; i >= 0; --i)
        if (A[i] != B[i]) return A[i] >= B[i];
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
    cin.tie(0);
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; --i) A.emplace_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i) B.emplace_back(b[i] - '0');
    auto C = sub(A, B);
    if (!cmp(A, B)) cout << '-';
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    return 0;
}
```

#### AcWing 793. 高精度乘法

给定两个非负整数（不含前导 $ 0 $） $ A $ 和 $ B $，请你计算 $ A \times B $ 的值。

**输入格式**

共两行，第一行包含整数 $ A $，第二行包含整数 $ B $。

**输出格式**

共一行，包含 $ A \times B $ 的值。

**数据范围**

$ 1 \le A 的长度 \le 100000 $,  
$ 0 \le B \le 10000 $

**输入样例**：

```
2
3
```

**输出样例**：

```
6
```

```c++
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
```

#### AcWing 794. 高精度除法

给定两个非负整数（不含前导 $ 0 $） $ A，B $，请你计算 $ A / B $ 的商和余数。

**输入格式**

共两行，第一行包含整数 $ A $，第二行包含整数 $ B $。

**输出格式**

共两行，第一行输出所求的商，第二行输出所求余数。

**数据范围**

$ 1 \le A的长度 \le 100000 $,  
$ 1 \le B \le 10000 $,  
$ B $ 一定不为 $ 0 $

**输入样例**：

```
7
2
```

**输出样例**：

```
3
1
```

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> A, int b, int &r) {
    vector<int> C;
    for (int i = 0; i < A.size(); ++i) {
        r = r * 10 + A[i];
        C.emplace_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
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
```



### 1.4 前缀和与差分

#### AcWing 795. 前缀和

输入一个长度为 $ n $ 的整数序列。

接下来再输入 $ m $ 个询问，每个询问输入一对 $ l, r $。

对于每个询问，输出原序列中从第 $ l $ 个数到第 $ r $ 个数的和。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

第二行包含 $ n $ 个整数，表示整数数列。

接下来 $ m $ 行，每行包含两个整数 $ l $ 和 $ r $，表示一个询问的区间范围。

**输出格式**

共 $ m $ 行，每行输出一个询问的结果。

**数据范围**

$ 1 \le l \le r \le n $,  
$ 1 \le n,m \le 100000 $,  
$ -1000 \le 数列中元素的值 \le 1000 $

**输入样例**：

```
5 3
2 1 3 6 4
1 2
1 3
2 4
```

**输出样例**：

```
3
6
10
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n + 1);
    vector<int> sums(n + 1);
    for (int i = 1; i <= n; ++i) cin >> nums[i];
    for (int i = 1; i <= n; ++i) sums[i] = sums[i - 1] + nums[i];
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << sums[r] - sums[l - 1] << endl;
    }
    return 0;
}
```

#### AcWing 796. 子矩阵的和

输入一个 $ n $ 行 $ m $ 列的整数矩阵，再输入 $ q $ 个询问，每个询问包含四个整数 $ x_1, y_1, x_2, y_2 $，表示一个子矩阵的左上角坐标和右下角坐标。

对于每个询问输出子矩阵中所有数的和。

**输入格式**

第一行包含三个整数 $ n，m，q $。

接下来 $ n $ 行，每行包含 $ m $ 个整数，表示整数矩阵。

接下来 $ q $ 行，每行包含四个整数 $ x_1, y_1, x_2, y_2 $，表示一组询问。

**输出格式**

共 $ q $ 行，每行输出一个询问的结果。

**数据范围**

$ 1 \le n,m \le 1000 $,  
$ 1 \le q \le 200000 $,  
$ 1 \le x_1 \le x_2 \le n $,  
$ 1 \le y_1 \le y_2 \le m $,  
$ -1000 \le 矩阵内元素的值 \le 1000 $

**输入样例**：

```
3 4 3
1 7 2 4
3 6 2 8
2 1 2 3
1 1 2 2
2 1 3 4
1 3 3 4
```

**输出样例**：

```
17
27
21
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > nums(n + 1, vector<int>(m + 1));
    vector<vector<int> > sums(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> nums[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + nums[i][j];
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sums[x2][y2] - sums[x2][y1 - 1] - sums[x1 - 1][y2] + sums[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
```

#### AcWing 797. 差分

输入一个长度为 $ n $ 的整数序列。

接下来输入 $ m $ 个操作，每个操作包含三个整数 $ l, r, c $，表示将序列中 $ [l, r] $ 之间的每个数加上 $ c $。

请你输出进行完所有操作后的序列。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

第二行包含 $ n $ 个整数，表示整数序列。

接下来 $ m $ 行，每行包含三个整数 $ l，r，c $，表示一个操作。

**输出格式**

共一行，包含 $ n $ 个整数，表示最终序列。

**数据范围**

$ 1 \le n,m \le 100000 $,  
$ 1 \le l \le r \le n $,  
$ -1000 \le c \le 1000 $,  
$ -1000 \le 整数序列中元素的值 \le 1000 $

**输入样例**：

```
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
```

**输出样例**：

```
3 4 5 3 4 2
```

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        insert(i, i, a[i]);
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for (int i = 1; i <= n; ++i) b[i] += b[i - 1]; //此时b[i]为前缀和
    for (int i = 1; i <= n; ++i) cout << b[i] << ' ';
    return 0;
}
```

#### AcWing 798. 差分矩阵

输入一个 $ n $ 行 $ m $ 列的整数矩阵，再输入 $ q $ 个操作，每个操作包含五个整数 $ x_1, y_1, x_2, y_2, c $，其中 $ (x_1, y_1) $ 和 $ (x_2, y_2) $ 表示一个子矩阵的左上角坐标和右下角坐标。

每个操作都要将选中的子矩阵中的每个元素的值加上 $ c $。

请你将进行完所有操作后的矩阵输出。

**输入格式**

第一行包含整数 $ n,m,q $。

接下来 $ n $ 行，每行包含 $ m $ 个整数，表示整数矩阵。

接下来 $ q $ 行，每行包含 $ 5 $ 个整数 $ x_1, y_1, x_2, y_2, c $，表示一个操作。

**输出格式**

共 $ n $ 行，每行 $ m $ 个整数，表示所有操作进行完毕后的最终矩阵。

**数据范围**

$ 1 \le n,m \le 1000 $,  
$ 1 \le q \le 100000 $,  
$ 1 \le x_1 \le x_2 \le n $,  
$ 1 \le y_1 \le y_2 \le m $,  
$ -1000 \le c \le 1000 $,  
$ -1000 \le 矩阵内元素的值 \le 1000 $

**输入样例**：

```
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
```

**输出样例**：

```
2 3 4 1
4 3 4 1
2 2 2 2
```

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]);
        }
    }
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; j++) {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
```



### 1.5 双指针算法

#### AcWing 799. 最长连续不重复子序列

给定一个长度为 $ n $ 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

**输入格式**

第一行包含整数 $ n $。

第二行包含 $ n $ 个整数（均在 $ 0 \sim 10^5 $ 范围内），表示整数序列。

**输出格式**

共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

**数据范围**

$ 1 \le n \le 10^5 $

**输入样例**：

```
5
1 2 2 3 5
```

**输出样例**：

```
3
```

```c++
#include <bits/stdc++.h>

using namespace std;

int length_of_longest_sequence(vector<int> nums) {
    int res = 0;
    vector<int> hashTable(100010);
    for (int i = 0, j = 0; i < nums.size(); i++) {
        if (hashTable[nums[i]] > 0) j = max(j, hashTable[nums[i]]);
        hashTable[nums[i]] = i + 1;
        res = max(res, i - j + 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << length_of_longest_sequence(nums);
    return 0;
}
```

#### AcWing 800. 数组元素的目标和

给定两个升序排序的有序数组 $ A $ 和 $ B $，以及一个目标值 $ x $。

数组下标从 $ 0 $ 开始。

请你求出满足 $ A[i] + B[j] = x $ 的数对 $ (i, j) $。

数据保证有唯一解。

**输入格式**

第一行包含三个整数 $ n,m,x $，分别表示 $ A $ 的长度，$ B $ 的长度以及目标值 $ x $。

第二行包含 $ n $ 个整数，表示数组 $ A $。

第三行包含 $ m $ 个整数，表示数组 $ B $。

**输出格式**

共一行，包含两个整数 $ i $ 和 $ j $。

**数据范围**

数组长度不超过 $ 10^5 $。  
同一数组内元素各不相同。  
$ 1 \le 数组元素 \le 10^9 $

**输入样例**：

```
4 5 6
1 2 4 7
3 4 6 8 9
```

**输出样例**：

```
1 1
```

```c++
#include <bits/stdc++.h>

using namespace std;

vector<int> sum_of_target(vector<int> nums1, vector<int> nums2, int target) {
    int i = 0, j = nums2.size() - 1;
    while (i < nums1.size() && j >= 0) {
        while (nums1[i] + nums2[j] > target) j--;
        if (nums1[i] + nums2[j] == target) return {i, j};
        i++;
    }
    return {-1, -1};
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; ++i) cin >> nums1[i];
    for (int i = 0; i < m; ++i) cin >> nums2[i];
    vector<int> res = sum_of_target(nums1, nums2, x);
    for (int i = 0; i < 2; ++i) cout << res[i] << ' ';
    return 0;
}
```

#### AcWing 2816. 判断子序列

给定一个长度为 $ n $ 的整数序列 $ a_1,a_2,…,a_n $ 以及一个长度为 $ m $ 的整数序列 $ b_1,b_2,…,b_m $。

请你判断 $ a $ 序列是否为 $ b $ 序列的子序列。

子序列指序列的一部分项按**原有次序排列**而得的序列，例如序列 $ \{a_1,a_3,a_5\} $ 是序列 $ \{a_1,a_2,a_3,a_4,a_5\} $ 的一个子序列。

**输入格式**

第一行包含两个整数 $ n,m $。

第二行包含 $ n $ 个整数，表示 $ a_1,a_2,…,a_n $。

第三行包含 $ m $ 个整数，表示 $ b_1,b_2,…,b_m $。

**输出格式**

如果 $ a $ 序列是 $ b $ 序列的子序列，输出一行 `Yes`。

否则，输出 `No`。

**数据范围**

$ 1 \le n \le m \le 10^5 $,  
$ -10^9 \le a_i,b_i \le 10^9 $

**输入样例**：

```
3 5
1 3 5
1 2 3 4 5
```

**输出样例**：

```nginx
Yes
```

```c++
#include <iostream>

using namespace std;

const int N = 100010;

int n, m, a[N], b[N];

bool cmp_subsequence(int a[], int b[]) {
    int i = 0, j = 0;
    for (; i < n && j < m; j++) {
        if (a[i] == b[j]) i++;
    }
    if (i == n) return true;
    else return false;
}

int main() {
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    cout << (cmp_subsequence(a, b) ? "Yes" : "No");
    return 0;
}
```



### 1.6 位运算

#### AcWing 801. 二进制中1的个数

给定一个长度为 $ n $ 的数列，请你求出数列中每个数的二进制表示中 $ 1 $ 的个数。

**输入格式**

第一行包含整数 $ n $。

第二行包含 $ n $ 个整数，表示整个数列。

**输出格式**

共一行，包含 $ n $ 个整数，其中的第 $ i $ 个数表示数列中的第 $ i $ 个数的二进制表示中 $ 1 $ 的个数。

**数据范围**

$ 1 \le n \le 100000 $,  
$ 0 \le 数列中元素的值 \le 10^9 $

**输入样例**：

```
5
1 2 3 4 5
```

**输出样例**：

```
1 1 2 1 2
```

```c++
#include <bits/stdc++.h>

using namespace std;

int lowbit(int num) {
    return num & (-num);
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int num, res = 0;
        cin >> num;
        while (num) {
            num -= lowbit(num);
            res++;
        }
        cout << res << ' ';
    }
    return 0;
}
```



### 1.7 离散化

#### AcWing 802. 区间和 

假定有一个无限长的数轴，数轴上每个坐标上的数都是 $ 0 $。

现在，我们首先进行 $ n $ 次操作，每次操作将某一位置 $ x $ 上的数加 $ c $。

接下来，进行 $ m $ 次询问，每个询问包含两个整数 $ l $ 和 $ r $，你需要求出在区间 $ [l, r] $ 之间的所有数的和。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

接下来 $ n $ 行，每行包含两个整数 $ x $ 和 $ c $。

再接下来 $ m $ 行，每行包含两个整数 $ l $ 和 $ r $。

**输出格式**

共 $ m $ 行，每行输出一个询问中所求的区间内数字和。

**数据范围**

$ -10^9 \le x \le 10^9 $,  
$ 1 \le n,m \le 10^5 $,  
$ -10^9 \le l \le r \le 10^9 $,  
$ -10000 \le c \le 10000 $

**输入样例**：

```
3 3
1 2
3 6
7 5
1 3
4 6
7 8
```

**输出样例**：

```
8
0
5
```

```c++
#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
int a[N], s[N];
vector<pair<int, int> > add;   //存放所有的坐标上加的数
vector<pair<int, int> > query; //存放所有需查询的坐标对
vector<int> alls; //存放所有的坐标位置，将离散化的坐标映射为连续化的坐标

int find(int target) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}


int main() {
    cin >> n >> m;
    while (n--) {
        int x, c;
        cin >> x >> c;
        add.emplace_back(x, c);
        alls.emplace_back(x);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        query.emplace_back(l, r);
        alls.emplace_back(l);
        alls.emplace_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //使用vector会TLE，改用数组
    //vector<int> a(alls.size() + 1), s(alls.size() + 1); //a存放映射后坐标上的数； s存放映射后坐标上的数的前缀和
    for (auto const &pair: add) a[find(pair.first)] += pair.second;
    for (int i = 1; i <= alls.size(); ++i) s[i] += s[i - 1] + a[i];
    for (auto const &pair: query) {
        int l = find(pair.first);
        int r = find(pair.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
```



### 1.8 区间合并

#### AcWing 803. 区间合并

给定 $ n $ 个区间 $ [l_i, r_i] $，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如：$ [1,3] $ 和 $ [2,6] $ 可以合并为一个区间 $ [1,6] $。

**输入格式**

第一行包含整数 $ n $。

接下来 $ n $ 行，每行包含两个整数 $ l $ 和 $ r $。

**输出格式**

共一行，包含一个整数，表示合并区间完成后的区间个数。

**数据范围**

$ 1 \le n \le 100000 $,  
$ -10^9 \le l_i \le r_i \le 10^9 $

**输入样例**：

```
5
1 2
2 4
5 6
7 8
7 9
```

**输出样例**：

```
3
```

```c++
#include <bits/stdc++.h>

using namespace std;

int interval_merge(vector<pair<int, int> > &segs) {
    sort(segs.begin(), segs.end());
    vector<pair<int, int> > res;
    int st = -2e9, ed = -2e9;
    for (auto const &seg: segs) {
        if (seg.first > ed) {
            if (st != -2e9) res.emplace_back(st, ed);
            st = seg.first;
            ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }
    if (st != -2e9) res.emplace_back(st, ed);
    segs = res;
    return res.size();
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > segs;
    while (n--) {
        int l, r;
        cin >> l >> r;
        segs.emplace_back(l, r);
    }
    cout << interval_merge(segs) << endl;
    return 0;
}
```



## 第二章：数据结构

### 2.1 链表与邻接表：树与图的存储

#### AcWing 826. 单链表

实现一个单链表，链表初始为空，支持三种操作：

1.  向链表头插入一个数；
2.  删除第 $ k $ 个插入的数后面的数；
3.  在第 $ k $ 个插入的数后插入一个数。

现在要对该链表进行 $ M $ 次操作，进行完所有操作后，从头到尾输出整个链表。

**注意**:题目中第 $ k $ 个插入的数并不是指当前链表的第 $ k $ 个数。例如操作过程中一共插入了 $ n $ 个数，则按照插入的时间顺序，这 $ n $ 个数依次为：第 $ 1 $ 个插入的数，第 $ 2 $ 个插入的数，…第 $ n $ 个插入的数。

**输入格式**

第一行包含整数 $ M $，表示操作次数。

接下来 $ M $ 行，每行包含一个操作命令，操作命令可能为以下几种：

1.  `H x`，表示向链表头插入一个数 $ x $。
2.  `D k`，表示删除第 $ k $ 个插入的数后面的数（当 $ k $ 为 $ 0 $ 时，表示删除头结点）。
3.  `I k x`，表示在第 $ k $ 个插入的数后面插入一个数 $ x $（此操作中 $ k $ 均大于 $ 0 $）。

**输出格式**

共一行，将整个链表从头到尾输出。

**数据范围**

$ 1 \le M \le 100000 $  
所有操作保证合法。

**输入样例**：

```
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
```

**输出样例**：

```
6 4 6 5
```

```c++
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
```

#### AcWing 827. 双链表

实现一个双链表，双链表初始为空，支持 $ 5 $ 种操作：

1.  在最左侧插入一个数；
2.  在最右侧插入一个数；
3.  将第 $ k $ 个插入的数删除；
4.  在第 $ k $ 个插入的数左侧插入一个数；
5.  在第 $ k $ 个插入的数右侧插入一个数

现在要对该链表进行 $ M $ 次操作，进行完所有操作后，从左到右输出整个链表。

**注意**:题目中第 $ k $ 个插入的数并不是指当前链表的第 $ k $ 个数。例如操作过程中一共插入了 $ n $ 个数，则按照插入的时间顺序，这 $ n $ 个数依次为：第 $ 1 $ 个插入的数，第 $ 2 $ 个插入的数，…第 $ n $ 个插入的数。

**输入格式**

第一行包含整数 $ M $，表示操作次数。

接下来 $ M $ 行，每行包含一个操作命令，操作命令可能为以下几种：

1.  `L x`，表示在链表的最左端插入数 $ x $。
2.  `R x`，表示在链表的最右端插入数 $ x $。
3.  `D k`，表示将第 $ k $ 个插入的数删除。
4.  `IL k x`，表示在第 $ k $ 个插入的数左侧插入一个数。
5.  `IR k x`，表示在第 $ k $ 个插入的数右侧插入一个数。

**输出格式**

共一行，将整个链表从左到右输出。

**数据范围**

$ 1 \le M \le 100000 $  
所有操作保证合法。

**输入样例**：

```
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
```

**输出样例**：

```
8 7 7 3 2 9
```

```c++
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
```



### 2.2 栈与队列：单调队列、单调栈

#### AcWing 828. 模拟栈

实现一个栈，栈初始为空，支持四种操作：

1.  `push x` – 向栈顶插入一个数 $ x $；
2.  `pop` – 从栈顶弹出一个数；
3.  `empty` – 判断栈是否为空；
4.  `query` – 查询栈顶元素。

现在要对栈进行 $ M $ 个操作，其中的每个操作 $ 3 $ 和操作 $ 4 $ 都要输出相应的结果。

**输入格式**

第一行包含整数 $ M $，表示操作次数。

接下来 $ M $ 行，每行包含一个操作命令，操作命令为 `push x`，`pop`，`empty`，`query` 中的一种。

**输出格式**

对于每个 `empty` 和 `query` 操作都要输出一个查询结果，每个结果占一行。

其中，`empty` 操作的查询结果为 `YES` 或 `NO`，`query` 操作的查询结果为一个整数，表示栈顶元素的值。

**数据范围**

$ 1 \le M \le 100000 $,  
$ 1 \le x \le 10^9 $  
所有操作保证合法。

**输入样例**：

```perl
10
push 5
query
push 6
pop
query
pop
empty
push 4
query
empty
```

**输出样例**：

```objectivec
5
5
YES
4
NO
```

```c++
#include <iostream>

using namespace std;

int stk[100010], top = -1;

int main() {
    int m;
    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x, stk[++top] = x;
        } else if (op == "pop") {
            top--;
        } else if (op == "empty") {
            if (top == -1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << stk[top] << endl;
        }

    }
    return 0;
}
```

#### AcWing 3302. 表达式求值

给定一个表达式，其中运算符仅包含 `+,-,*,/`（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

**注意：**

*   数据保证给定的表达式合法。
*   题目保证符号 `-` 只作为减号出现，不会作为负号出现，例如，`-1+2`,`(2+2)*(-(1+1)+2)` 之类表达式均不会出现。
*   题目保证表达式中所有数字均为正整数。
*   题目保证表达式在中间计算过程以及结果中，均不超过 $ 2^{31}-1 $。
*   题目中的整除是指向 $ 0 $ 取整，也就是说对于大于 $ 0 $ 的结果向下取整，例如 $ 5/3=1 $，对于小于 $ 0 $ 的结果向上取整，例如 $ 5/(1-4) = -1 $。
*   C++和Java中的整除默认是向零取整；Python中的整除`//`默认向下取整，因此Python的`eval()`函数中的整除也是向下取整，在本题中不能直接使用。

**输入格式**

共一行，为给定表达式。

**输出格式**

共一行，为表达式的结果。

**数据范围**

表达式的长度不超过 $ 10^5 $。

**输入样例**：

```
(2+2)*(1+1)
```

**输出样例**：

```
8
```

```c++
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> ops;
stack<int> nums;
//定义运算符的优先级
unordered_map<char, int> pr{{'+', 1},
                            {'-', 1},
                            {'*', 2},
                            {'/', 2}};

//中缀表达式求值
void eval() {
    auto num1 = nums.top();
    nums.pop();
    auto num2 = nums.top();
    nums.pop();
    auto op = ops.top();
    ops.pop();
    int res = 0;
    if (op == '+') res = num2 + num1;
    else if (op == '-') res = num2 - num1;
    else if (op == '*') res = num2 * num1;
    else res = num2 / num1;
    nums.push(res);
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (isdigit(ch)) {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j])) x = x * 10 + str[j++] - '0';
            nums.push(x);
            i = j - 1;
        } else if (ch == '(') {
            ops.push(ch);
        } else if (ch == ')') {
            while (ops.top() != '(') eval();
            ops.pop();
        } else {
            while (ops.size() && ops.top() != '(' && pr[ops.top()] >= pr[ch]) eval();
            ops.push(ch);
        }
    }
    while (ops.size()) eval();
    cout << nums.top();
    return 0;
}
```

#### AcWing 829. 模拟队列 

实现一个队列，队列初始为空，支持四种操作：

1.  `push x` – 向队尾插入一个数 $ x $；
2.  `pop` – 从队头弹出一个数；
3.  `empty` – 判断队列是否为空；
4.  `query` – 查询队头元素。

现在要对队列进行 $ M $ 个操作，其中的每个操作 $ 3 $ 和操作 $ 4 $ 都要输出相应的结果。

**输入格式**

第一行包含整数 $ M $，表示操作次数。

接下来 $ M $ 行，每行包含一个操作命令，操作命令为 `push x`，`pop`，`empty`，`query` 中的一种。

**输出格式**

对于每个 `empty` 和 `query` 操作都要输出一个查询结果，每个结果占一行。

其中，`empty` 操作的查询结果为 `YES` 或 `NO`，`query` 操作的查询结果为一个整数，表示队头元素的值。

**数据范围**

$ 1 \le M \le 100000 $,  
$ 1 \le x \le 10^9 $,  
所有操作保证合法。

**输入样例**：

```perl
10
push 6
empty
query
pop
empty
push 3
push 4
pop
query
push 6
```

**输出样例**：

```objectivec
NO
6
YES
4
```

```c++
#include <iostream>

using namespace std;

int q[100010], head, tail = -1;

int main() {
    int m;
    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x, q[++tail] = x;
        } else if (op == "pop") {
            ++head;
        } else if (op == "empty") {
            if (head <= tail) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else {
            cout << q[head] << endl;
        }

    }
    return 0;
}
```

#### AcWing 830. 单调栈

给定一个长度为 $ N $ 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 $ -1 $。

**输入格式**

第一行包含整数 $ N $，表示数列长度。

第二行包含 $ N $ 个整数，表示整数数列。

**输出格式**

共一行，包含 $ N $ 个整数，其中第 $ i $ 个数表示第 $ i $ 个数的左边第一个比它小的数，如果不存在则输出 $ -1 $。

**数据范围**

$ 1 \le N \le 10^5 $  
$ 1 \le 数列中元素 \le 10^9 $

**输入样例**：

```
5
3 4 2 7 5
```

**输出样例**：

```diff
-1 3 -1 2 2
```

```c++
#include <iostream>

using namespace std;

int stk[100010], top = -1;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        while (top > -1 && stk[top] >= x) top--;
        if (top == -1) cout << "-1 ";
        else cout << stk[top] << ' ';
        stk[++top] = x;
    }
    return 0;
}
```

#### AcWing 154. 滑动窗口

给定一个大小为 $ n \le 10^6 $ 的数组。

有一个大小为 $ k $ 的滑动窗口，它从数组的最左边移动到最右边。

你只能在窗口中看到 $ k $ 个数字。

每次滑动窗口向右移动一个位置。

以下是一个例子：

该数组为 `[1 3 -1 -3 5 3 6 7]`，$ k $ 为 $ 3 $。

|       窗口位置        | 最小值 | 最大值 |
| :-------------------: | :----: | :----: |
| \[1 3 -1\] -3 5 3 6 7 |  \-1   |   3    |
| 1 \[3 -1 -3\] 5 3 6 7 |  \-3   |   3    |
| 1 3 \[-1 -3 5\] 3 6 7 |  \-3   |   5    |
| 1 3 -1 \[-3 5 3\] 6 7 |  \-3   |   5    |
| 1 3 -1 -3 \[5 3 6\] 7 |   3    |   6    |
| 1 3 -1 -3 5 \[3 6 7\] |   3    |   7    |

你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。

**输入格式**

输入包含两行。

第一行包含两个整数 $ n $ 和 $ k $，分别代表数组长度和滑动窗口的长度。

第二行有 $ n $ 个整数，代表数组的具体数值。

同行数据之间用空格隔开。

**输出格式**

输出包含两个。

第一行输出，从左至右，每个位置滑动窗口中的最小值。

第二行输出，从左至右，每个位置滑动窗口中的最大值。

**输入样例**：

```
8 3
1 3 -1 -3 5 3 6 7
```

**输出样例**：

```diff
-1 -3 -3 -3 3 3
3 3 5 5 6 7
```

```c++
#include <iostream>

using namespace std;

//q[i] 记录队列元素在原数组的下标
int a[1000010], q[1000010];

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
```



### 2.3 KMP

#### AcWing 831. KMP字符串

给定一个模式串 $ S $，以及一个模板串 $ P $，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模板串 $ P $ 在模式串 $ S $ 中多次作为子串出现。

求出模板串 $ P $ 在模式串 $ S $ 中所有出现的位置的起始下标。

**输入格式**

第一行输入整数 $ N $，表示字符串 $ P $ 的长度。

第二行输入字符串 $ P $。

第三行输入整数 $ M $，表示字符串 $ S $ 的长度。

第四行输入字符串 $ S $。

**输出格式**

共一行，输出所有出现位置的起始下标（下标从 $ 0 $ 开始计数），整数之间用空格隔开。

**数据范围**

$ 1 \le N \le 10^5 $  
$ 1 \le M \le 10^6 $

**输入样例**：

```
3
aba
5
ababa
```

**输出样例**：

```
0 2
```

```c++
#include <bits/stdc++.h>

using namespace std;

char s[1000010], p[1000010];
int ne[1000010], n, m;


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> s[i];
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        // 若ne[i] = j, 表示以i为结尾的, 长度是j的串 和 从1开始, 长度为j的串相等, 即p[1, j] = p[i - j + 1, i]
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; ++i) {
        // j初始等于0, 每次匹配p[j + 1]
        // p[j]及之前为已经匹配成功的节点, p[j + 1]为正在匹配的节点
        // ne[j]表示j + 1匹配失败时, 需要j回退到哪里开始匹配(匹配ne[j] + 1)
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
    return 0;
}
```



### 2.4 Trie

#### AcWing 835. Trie字符串统计

维护一个字符串集合，支持两种操作：

1.  `I x` 向集合中插入一个字符串 $ x $；
2.  `Q x` 询问一个字符串在集合中出现了多少次。

共有 $ N $ 个操作，输入的字符串总长度不超过 $ 10^5 $，字符串仅包含小写英文字母。

**输入格式**

第一行包含整数 $ N $，表示操作数。

接下来 $ N $ 行，每行包含一个操作指令，指令为 `I x` 或 `Q x` 中的一种。

**输出格式**

对于每个询问指令 `Q x`，都要输出一个整数作为结果，表示 $ x $ 在集合中出现的次数。

每个结果占一行。

**数据范围**

$ 1 \le N \le 2*10^4 $

**输入样例**：

```
5
I abc
Q abc
Q ab
I ab
Q ab
```

**输出样例**：

```
1
0
1
```

```c++
#include <iostream>

using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string str) {
    int p = 0;
    for (auto const &ch: str) {
        int u = ch - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string str) {
    int p = 0;
    for (auto const &ch: str) {
        int u = ch - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}


int main() {
    int n;
    string str;
    cin >> n;
    while (n--) {
        char op;
        cin >> op >> str;
        if (op == 'I') insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}
```

#### AcWing 143. 最大异或对 

在给定的 $ N $ 个整数 $ A_1，A_2……A_N $ 中选出两个进行 $ xor $（异或）运算，得到的结果最大是多少？

**输入格式**

第一行输入一个整数 $ N $。

第二行输入 $ N $ 个整数 $ A_1 $～$ A_N $。

**输出格式**

输出一个整数表示答案。

**数据范围**

$ 1 \le N \le 10^5 $,  
$ 0 \le A_i < 2^{31} $

**输入样例**：

```
3
1 2 3
```

**输出样例**：

```
3
```

```c++
#include <iostream>

using namespace std;

const int N = 100010, M = 31 * N;
int son[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (son[p][!u]) {
            res = 2 * res + 1;
            p = son[p][!u];
        } else {
            res *= 2;
            p = son[p][u];
        }
    }
    return res;
}


int main(void) {
    cin.tie(0);
    int n, a[N];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, query(a[i]));
    cout << res << endl;
    return 0;
}
```



### 2.5 并查集

#### AcWing 836. 合并集合 

一共有 $ n $ 个数，编号是 $ 1 \sim n $，最开始每个数各自在一个集合中。

现在要进行 $ m $ 个操作，操作共有两种：

1.  `M a b`，将编号为 $ a $ 和 $ b $ 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
2.  `Q a b`，询问编号为 $ a $ 和 $ b $ 的两个数是否在同一个集合中；

**输入格式**

第一行输入整数 $ n $ 和 $ m $。

接下来 $ m $ 行，每行包含一个操作指令，指令为 `M a b` 或 `Q a b` 中的一种。

**输出格式**

对于每个询问指令 `Q a b`，都要输出一个结果，如果 $ a $ 和 $ b $ 在同一集合内，则输出 `Yes`，否则输出 `No`。

每个结果占一行。

**数据范围**

$ 1 \le n,m \le 10^5 $

**输入样例**：

```
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
```

**输出样例**：

```nginx
Yes
No
Yes
```

```c++
#include <iostream>

using namespace std;

const int N = 100010;
int n, m, fa[N], Rank[N];

int find(int x) {
    //while (p[x] != x) x = p[x];

    //路径压缩
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    else {
        //按秩合并
        if (Rank[x] < Rank[y]) fa[x] = y;
        else if (Rank[x] == Rank[y]) fa[x] = y, Rank[y]++;
        else fa[y] = x;
    }
}

int main() {
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i, Rank[i] = 1;
    while (m--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') merge(a, b);
        else cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    }
    return 0;
}
```

#### AcWing 837. 连通块中点的数量

给定一个包含 $ n $ 个点（编号为 $ 1 \sim n $）的无向图，初始时图中没有边。

现在要进行 $ m $ 个操作，操作共有三种：

1.  `C a b`，在点 $ a $ 和点 $ b $ 之间连一条边，$ a $ 和 $ b $ 可能相等；
2.  `Q1 a b`，询问点 $ a $ 和点 $ b $ 是否在同一个连通块中，$ a $ 和 $ b $ 可能相等；
3.  `Q2 a`，询问点 $ a $ 所在连通块中点的数量；

**输入格式**

第一行输入整数 $ n $ 和 $ m $。

接下来 $ m $ 行，每行包含一个操作指令，指令为 `C a b`，`Q1 a b` 或 `Q2 a` 中的一种。

**输出格式**

对于每个询问指令 `Q1 a b`，如果 $ a $ 和 $ b $ 在同一个连通块中，则输出 `Yes`，否则输出 `No`。

对于每个询问指令 `Q2 a`，输出一个整数表示点 $ a $ 所在连通块中点的数量

每个结果占一行。

**数据范围**

$ 1 \le n,m \le 10^5 $

**输入样例**：

```
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
```

**输出样例**：

```nginx
Yes
2
3
```

```c++
#include <iostream>

using namespace std;

const int N = 100010;
int n, m, fa[N], Rank[N], Size[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    else {
        if (Rank[x] < Rank[y]) fa[x] = y, Size[y] += Size[x];
        else if (Rank[x] == Rank[y]) fa[x] = y, Size[y] += Size[x], Rank[y]++;
        else fa[y] = x, Size[x] += Size[y];
    }
}

int main(void) {
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i, Rank[i] = 1, Size[i] = 1;
    while (m--) {
        string op;
        int a, b;
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            merge(a, b);
        } else if (op == "Q1") {
            cin >> a >> b;
            cout << (find(a) == find(b) ? "Yes" : "No") << endl;
        } else {
            cin >> a;
            cout << Size[find(a)] << endl;
        }
    }

    return 0;
}
```

#### AcWing 240. 食物链

动物王国中有三类动物 $ A,B,C $，这三类动物的食物链构成了有趣的环形。

$ A $ 吃 $ B $，$ B $ 吃 $ C $，$ C $ 吃 $ A $。

现有 $ N $ 个动物，以 $ 1 \sim N $ 编号。

每个动物都是 $ A,B,C $ 中的一种，但是我们并不知道它到底是哪一种。

有人用两种说法对这 $ N $ 个动物所构成的食物链关系进行描述：

第一种说法是 `1 X Y`，表示 $ X $ 和 $ Y $ 是同类。

第二种说法是 `2 X Y`，表示 $ X $ 吃 $ Y $。

此人对 $ N $ 个动物，用上述两种说法，一句接一句地说出 $ K $ 句话，这 $ K $ 句话有的是真的，有的是假的。

当一句话满足下列三条之一时，这句话就是假话，否则就是真话。

1.  当前的话与前面的某些真的话冲突，就是假话；
2.  当前的话中 $ X $ 或 $ Y $ 比 $ N $ 大，就是假话；
3.  当前的话表示 $ X $ 吃 $ X $，就是假话。

你的任务是根据给定的 $ N $ 和 $ K $ 句话，输出假话的总数。

**输入格式**

第一行是两个整数 $ N $ 和 $ K $，以一个空格分隔。

以下 $ K $ 行每行是三个正整数 $ D，X，Y $，两数之间用一个空格隔开，其中 $ D $ 表示说法的种类。

若 $ D=1 $，则表示 $ X $ 和 $ Y $ 是同类。

若 $ D=2 $，则表示 $ X $ 吃 $ Y $。

**输出格式**

只有一个整数，表示假话的数目。

**数据范围**

$ 1 \le N \le 50000 $,  
$ 0 \le K \le 100000 $

**输入样例**：

```
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
```

**输出样例**：

```
3
```

**扩展并查集：**

```c++
#include <iostream>

using namespace std;
const int N = 160010;

// 扩展域并查集
// x + n为x的食物
// x + n + n为x的天敌

int n, k, res, fa[N];

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

int main(void) {
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; ++i) fa[i] = i;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            res++;
            continue;
        }
        if (d == 1) {
            // y的食物是x || y的天敌是x
            if (find(x) == find(y + n) || find(x) == find(y + n + n)) {
                res++;
                continue;
            }
            fa[find(x)] = find(y); // x与y同类
            fa[find(x + n)] = find(y + n); // x的食物与y的食物是同类
            fa[find(x + n + n)] = find(y + n + n); // x的天敌与y的天敌是同类
        } else {
            // x与y是同类 || x的天敌与y是同类
            if (find(x) == find(y) || find(x + n + n) == find(y)) {
                res++;
                continue;
            }
            fa[find(x + n)] = find(y); // x的食物与y同类
            fa[find(x + n + n)] = find(y + n); // x的天敌与y的食物是同类
            fa[find(x)] = find(y + n + n); //x与y的天敌是同类
        }
    }
    cout << res << endl;
    return 0;
}
```

**带权并查集：**

```c++
#include <iostream>

using namespace std;

const int N = 50010;
// 带权并查集(有向带权图)
// x与y的距离%3等于0时,说明x和y是同类
// x与y的距离%3等于1时,说明x捕食y
// x与y的距离%3等于2时,说明y是x的天敌
// dis[x]表示x到其父节点的距离：
// 1、压缩路径后即为到跟节点的距离
// 2、未merge时候为到父节点的距离
int n, k, res, fa[N], dis[N];

int find(int x) {
    if (fa[x] != x) {
        int root = find(fa[x]);
        dis[x] = (dis[x] + dis[fa[x]] + 3) % 3;
        fa[x] = root;
    }
    return fa[x];
}

// t为x与y之间的关系
// 每次merge时fa[x]到fa[b]的距离未知
// (dis[x] + dis[px] - dis[y]) % 3 = t (有向图，经过路经压缩后dis[y]为y到py之间的距离，py到y的距离为-dis[y])
// => dis[px] = (t + dis[y] - dis[x]) % 3
bool merge(int x, int y, int t) {
    int px = find(x), py = find(y);
    if (px == py) return dis[x] % 3 == (t + dis[y]) % 3;
    fa[px] = py;
    dis[px] = (t + dis[y] - dis[x] + 3) % 3;
    return true;
}

int main() {
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) fa[i] = i;
    while (k--) {
        int d, x, y;
        cin >> d >> x >> y;
        if (x > n || y > n) {
            res++;
            continue;
        }
        if (d == 1) {
            if (!merge(x, y, 0)) res++;
        } else {
            if (!merge(x, y, 1)) res++;
        }
    }
    cout << res << endl;
    return 0;
}
```



### 2.6 堆

#### AcWing 838. 堆排序

输入一个长度为 $ n $ 的整数数列，从小到大输出前 $ m $ 小的数。

**输入格式**

第一行包含整数 $ n $ 和 $ m $。

第二行包含 $ n $ 个整数，表示整数数列。

**输出格式**

共一行，包含 $ m $ 个整数，表示整数数列中前 $ m $ 小的数。

**数据范围**

$ 1 \le m \le n \le 10^5 $，  
$ 1 \le 数列中元素 \le 10^9 $

**输入样例**：

```
5 3
4 5 1 3 2
```

**输出样例**：

```
1 2 3
```

```c++
#include <iostream>

using namespace std;

const int N = 100010;
int n, m, Size, h[N];


void down(int u) {
    //t存放当前节点，及其左右孩子的最小值节点的下标
    int t = u;
    if (u * 2 <= Size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= Size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) swap(h[t], h[u]), down(t);
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) swap(h[u], h[u / 2]), u /= 2;
}

int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    Size = n;
    for (int i = n / 2; i > 0; --i) down(i);
    while (m--) {
        swap(h[1], h[Size]);
        cout << h[Size--] << ' ';
        down(1);
    }
    return 0;
}
```

#### AcWing 839. 模拟堆

维护一个集合，初始时集合为空，支持如下几种操作：

1.  `I x`，插入一个数 $ x $；
2.  `PM`，输出当前集合中的最小值；
3.  `DM`，删除当前集合中的最小值（数据保证此时的最小值唯一）；
4.  `D k`，删除第 $ k $ 个插入的数；
5.  `C k x`，修改第 $ k $ 个插入的数，将其变为 $ x $；

现在要进行 $ N $ 次操作，对于所有第 $ 2 $ 个操作，输出当前集合的最小值。

**输入格式**

第一行包含整数 $ N $。

接下来 $ N $ 行，每行包含一个操作指令，操作指令为 `I x`，`PM`，`DM`，`D k` 或 `C k x` 中的一种。

**输出格式**

对于每个输出指令 `PM`，输出一个结果，表示当前集合中的最小值。

每个结果占一行。

**数据范围**

$ 1 \le N \le 10^5 $  
$ -10^9 \le x \le 10^9 $  
数据保证合法。

**输入样例**：

```
8
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
```

**输出样例**：

```diff
-10
6
```

```c++
#include <iostream>

using namespace std;

const int N = 100010;
//idx表示第几个插入的节点
//ph[i]为idx为i的节点对应堆中的下标
//hp[i]为堆下标为i的节点的idx值
int n, Size, idx, h[N], ph[N], hp[N];

//交换堆中下标为x与y的两个节点
void swap_heap(int x, int y) {
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= Size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= Size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) swap_heap(t, u), down(t);
}

void up(int u) {
    while (u / 2 && h[u] < h[u / 2]) swap_heap(u, u / 2), u /= 2;
}

int main(void) {
    cin >> n;
    while (n--) {
        string op;
        int k, x;
        cin >> op;
        if (op == "I") {
            cin >> x;
            hp[++Size] = ++idx;
            h[Size] = x;
            ph[idx] = Size;
            up(Size);
        } else if (op == "PM") {
            cout << h[1] << endl;
        } else if (op == "DM") {
            swap_heap(1, Size--);
            down(1);
        } else if (op == "D") {
            cin >> k;
            // 必须先保存ph[k]，不然swap_heap之后ph[k]就变了，这样down与up时候的ph[k]就是修改过的值
            // 故，下面注释代码就是错误的
            // swap_heap(ph[k], Size--);
            // down(ph[k]), up(ph[k]);
            k = ph[k];
            swap_heap(k, Size--);
            down(k), up(k);
        } else {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}
```



### 2.7 哈希表

#### AcWing 840. 模拟散列表

维护一个集合，支持如下几种操作：

1.  `I x`，插入一个数 $ x $；
2.  `Q x`，询问数 $ x $ 是否在集合中出现过；

现在要进行 $ N $ 次操作，对于每个询问操作输出对应的结果。

**输入格式**

第一行包含整数 $ N $，表示操作数量。

接下来 $ N $ 行，每行包含一个操作指令，操作指令为 `I x`，`Q x` 中的一种。

**输出格式**

对于每个询问指令 `Q x`，输出一个询问结果，如果 $ x $ 在集合中出现过，则输出 `Yes`，否则输出 `No`。

每个结果占一行。

**数据范围**

$ 1 \le N \le 10^5 $  
$ -10^9 \le x \le 10^9 $

**输入样例**：

```
5
I 1
I 2
I 3
Q 2
Q 5
```

**输出样例**：

```nginx
Yes
No
```

**开方定址法：**

```c++
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
```

**拉链法：**

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], n, idx;

void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    while (n -- )
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);

        if (*op == 'I') insert(x);
        else
        {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
```

#### AcWing 841. 字符串哈希

给定一个长度为 $ n $ 的字符串，再给定 $ m $ 个询问，每个询问包含四个整数 $ l_1, r_1, l_2, r_2 $，请你判断 $ [l_1, r_1] $ 和 $ [l_2, r_2] $ 这两个区间所包含的字符串子串是否完全相同。

字符串中只包含大小写英文字母和数字。

**输入格式**

第一行包含整数 $ n $ 和 $ m $，表示字符串长度和询问次数。

第二行包含一个长度为 $ n $ 的字符串，字符串中只包含大小写英文字母和数字。

接下来 $ m $ 行，每行包含四个整数 $ l_1, r_1, l_2, r_2 $，表示一次询问所涉及的两个区间。

注意，字符串的位置从 $ 1 $ 开始编号。

**输出格式**

对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 `Yes`，否则输出 `No`。

每个结果占一行。

**数据范围**

$ 1 \le n, m \le 10^5 $

**输入样例**：

```
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2
```

**输出样例**：

```nginx
Yes
No
Yes
```

```c++
#include <iostream>

using namespace std;

typedef unsigned long long ULL;
const int N = 100010, P = 131;
int n, m;
char str[N];
ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    scanf("%d%d%s", &n, &m, str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}
```



## 第三章 搜索与图论

### 3.1 DFS与BFS

#### AcWing 842. 排列数字

给定一个整数 $ n $，将数字 $ 1 \sim n $ 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

**输入格式**

共一行，包含一个整数 $ n $。

**输出格式**

按字典序输出所有排列方案，每个方案占一行。

**数据范围**

$ 1 \le n \le 7 $

**输入样例**：

```
3
```

**输出样例**：

```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

```c++
#include <iostream>

using namespace std;

const int N = 10;

int n, path[N];
bool st[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; ++i)
            cout << path[i] << ' ';
        cout << endl;
        return;

    }
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            //path[u] = 0;
            st[i] = false;
        }
    }
}


int main() {
    cin >> n;
    dfs(0);
    return 0;
}
```

#### AcWing 843. n-皇后问题

$ n- $皇后问题是指将 $ n $ 个皇后放在 $ n \times n $ 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

![1_597ec77c49-8-queens.png](https://cdn.acwing.com/media/article/image/2019/06/08/19_860e00c489-1_597ec77c49-8-queens.png)

现在给定整数 $ n $，请你输出所有的满足条件的棋子摆法。

**输入格式**

共一行，包含整数 $ n $。

**输出格式**

每个解决方案占 $ n $ 行，每行输出一个长度为 $ n $ 的字符串，用来表示完整的棋盘状态。

其中 `.` 表示某一个位置的方格状态为空，`Q` 表示某一个位置的方格上摆着皇后。

每个方案输出完成后，输出一个空行。

**注意：行末不能有多余空格。**

输出方案的顺序任意，只要不重复且没有遗漏即可。

**数据范围**

$ 1 \le n \le 9 $

**输入样例**：

```
4
```

**输出样例**：

```css
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..
```

**全排列法：**

```c++
#include <iostream>

using namespace std;

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

// 全排列思想
void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; ++i) puts(g[i]);
        puts("");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!col[i] && !dg[u + i] && !udg[n + u - i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n + u - i] = true;
            dfs(u + 1);
            g[u][i] = '.';
            col[i] = dg[u + i] = udg[n + u - i] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
```

**逐个搜索法**：

```c++
#include <iostream>

using namespace std;

const int N = 20;
int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s) {
    if (y == n) y = 0, x++;
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n; ++i) puts(g[i]);
            puts("");
        }
        return;
    }
    // 不放皇后
    dfs(x, y + 1, s);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[n + y - x]) {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n + y - x] = true;
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[n + y - x] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}
```

#### AcWing 844. 走迷宫

给定一个 $ n \times m $ 的二维整数数组，用来表示一个迷宫，数组中只包含 $ 0 $ 或 $ 1 $，其中 $ 0 $ 表示可以走的路，$ 1 $ 表示不可通过的墙壁。

最初，有一个人位于左上角 $ (1, 1) $ 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角 $ (n, m) $ 处，至少需要移动多少次。

数据保证 $ (1, 1) $ 处和 $ (n, m) $ 处的数字为 $ 0 $，且一定至少存在一条通路。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

接下来 $ n $ 行，每行包含 $ m $ 个整数（$ 0 $ 或 $ 1 $），表示完整的二维数组迷宫。

**输出格式**

输出一个整数，表示从左上角移动至右下角的最少移动次数。

**数据范围**

$ 1 \le n, m \le 100 $

**输入样例**：

```
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
```

**输出样例**：

```
8
```

```c++
#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int n, m;
int g[N][N], d[N][N];
PII q[N * N];

int bfs() {
    int head = 0, tail = 0;
    q[0] = {0, 0};
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (head <= tail) {
        auto t = q[head++];
        for (int i = 0; i < 4; ++i) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !g[x][y] && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tail] = {x, y};
            }
        }
    }
    return d[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    cout << bfs();
    return 0;
}
```

**逆序输出路径：**

```c++
#include <iostream>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
const int N = 110;
int n, m;
int g[N][N], d[N][N];
PII q[N * N], Prev[N][N];

int bfs() {
    int head = 0, tail = 0;
    q[0] = {0, 0};
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (head <= tail) {
        auto t = q[head++];
        for (int i = 0; i < 4; ++i) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !g[x][y] && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tail] = {x, y};
                Prev[x][y] = t;
            }
        }
    }
    int x = n - 1, y = m - 1;
    while (x || y) {
        cout << x << ' ' << y << endl;
        auto t = Prev[x][y];
        x = t.first, y = t.second;
    }
    cout << "0 0" << endl;
    return d[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    cout << bfs();
    return 0;
}
```

#### AcWing 845. 八数码

在一个 $ 3×3 $ 的网格中，$ 1 \sim 8 $ 这 $ 8 $ 个数字和一个 `x` 恰好不重不漏地分布在这 $ 3 \times 3 $ 的网格中。

例如：

```
1 2 3
x 4 6
7 5 8
```

在游戏过程中，可以把 `x` 与其上、下、左、右四个方向之一的数字交换（如果存在）。

我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

```
1 2 3
4 5 6
7 8 x
```

例如，示例中图形就可以通过让 `x` 先后与右、下、右三个方向的数字交换成功得到正确排列。

交换过程如下：

```
1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
```

现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

**输入格式**

输入占一行，将 $ 3 \times 3 $ 的初始网格描绘出来。

例如，如果初始网格如下所示：

```
1 2 3 
x 4 6 
7 5 8
```

则输入为：`1 2 3 x 4 6 7 5 8`

**输出格式**

输出占一行，包含一个整数，表示最少交换次数。

如果不存在解决方案，则输出 $ -1 $。

**输入样例**：

```
2  3  4  1  5  x  7  6  8
```

**输出样例**

```
19
```

```c++
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
```



### 3.2 树与图的遍历：拓扑排序

#### AcWing 846. 树的重心

给定一颗树，树中包含 $ n $ 个结点（编号 $ 1 \sim n $）和 $ n-1 $ 条无向边。

请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

**输入格式**

第一行包含整数 $ n $，表示树的结点数。

接下来 $ n-1 $ 行，每行包含两个整数 $ a $ 和 $ b $，表示点 $ a $ 和点 $ b $ 之间存在一条边。

**输出格式**

输出一个整数 $ m $，表示将重心删除后，剩余各个连通块中点数的最大值。

**数据范围**

$ 1 \le n \le 10^5 $

**输入样例**

```
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
```

**输出样例**：

```
4
```

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = N * 2;

int n, h[N], e[M], ne[M], idx, ans = N;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    st[u] = true;
    int size = 0, sum = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        int s = dfs(j);
        size = max(size, s);
        sum += s;
    }
    size = max(size, n - sum);
    ans = min(ans, size);
    return sum;
}


int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}
```

#### AcWing 847. 图中点的层次

给定一个 $ n $ 个点 $ m $ 条边的有向图，图中可能存在重边和自环。

所有边的长度都是 $ 1 $，点的编号为 $ 1 \sim n $。

请你求出 $ 1 $ 号点到 $ n $ 号点的最短距离，如果从 $ 1 $ 号点无法走到 $ n $ 号点，输出 $ -1 $。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

接下来 $ m $ 行，每行包含两个整数 $ a $ 和 $ b $，表示存在一条从 $ a $ 走到 $ b $ 的长度为 $ 1 $ 的边。

**输出格式**

输出一个整数，表示 $ 1 $ 号点到 $ n $ 号点的最短距离。

**数据范围**

$ 1 \le n,m \le 10^5 $

**输入样例**：

```
4 5
1 2
2 3
3 4
1 3
1 4
```

**输出样例**：

```
1
```

```c++
#include <iostream>
#include <cstring>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, m, h[N], d[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int u) {
    memset(d, -1, sizeof d);
    d[1] = 0;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] != -1) continue;
            q.push(j);
            d[j] = d[t] + 1;
        }
    }
}

int main() {
    memset(h, -1, sizeof h);
    d[0] = 0;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    bfs(1);
    cout << d[n];
    return 0;
}
```

#### AcWing 848. 有向图的拓扑序列

给定一个 $ n $ 个点 $ m $ 条边的有向图，点的编号是 $ 1 $ 到 $ n $，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 $ -1 $。

若一个由图中所有点构成的序列 $ A $ 满足：对于图中的每条边 $ (x, y) $，$ x $ 在 $ A $ 中都出现在 $ y $ 之前，则称 $ A $ 是该图的一个拓扑序列。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

接下来 $ m $ 行，每行包含两个整数 $ x $ 和 $ y $，表示存在一条从点 $ x $ 到点 $ y $ 的有向边 $ (x, y) $。

**输出格式**

共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 $ -1 $。

**数据范围**

$ 1 \le n,m \le 10^5 $

**输入样例**：

```
3 3
1 2
2 3
1 3
```

**输出样例**：

```
1 2 3
```

```c++
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100010, M = 2 * N;

int n, m, h[N], q[N], d[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topological_sort() {
    int head = 0, tail = -1;
    for (int i = 1; i < n; ++i)
        if (!d[i]) q[++tail] = i;
    while (head <= tail) {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--d[j] == 0) q[++tail] = j;
        }
    }
    return tail == n - 1;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if (!topological_sort()) cout << "-1";
    else {
        for (int i = 0; i < n; ++i)
            cout << q[i] << ' ';
    }
}
```



### 3.3 最短路

#### AcWing 849. Dijkstra求最短路 I 

给定一个 $ n $ 个点 $ m $ 条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出 $ 1 $ 号点到 $ n $ 号点的最短距离，如果无法从 $ 1 $ 号点走到 $ n $ 号点，则输出 $ -1 $。

**输入格式**

第一行包含整数 $ n $ 和 $ m $。

接下来 $ m $ 行每行包含三个整数 $ x,y,z $，表示存在一条从点 $ x $ 到点 $ y $ 的有向边，边长为 $ z $。

**输出格式**

输出一个整数，表示 $ 1 $ 号点到 $ n $ 号点的最短距离。

如果路径不存在，则输出 $ -1 $。

**数据范围**

$ 1 \le n \le 500 $,  
$ 1 \le m \le 10^5 $,  
图中涉及边长均不超过10000。

**输入样例**：

```
3 3
1 2 2
2 3 1
1 3 4
```

**输出样例**：

```
3
```

**朴素Dijkstra算法(边权不能为负)，适用于稠密图，时间复杂度O(V^2)**

```c++
    #include <iostream>
    #include <cstring>
    
    using namespace std;
    
    const int N = 510;
    
    int n, m, g[N][N], d[N];
    bool st[N];
    
    int dijkstra() {
        memset(d, 0x3f, sizeof d);
        d[1] = 0;
        for (int i = 1; i <= n; ++i) {
            // t为未被访问中距离最小的一个点
            int t = -1;
            for (int j = 1; j <= n; ++j) {
                if (!st[j] && (t == -1 || d[j] < d[t])) t = j;
            }
            // 访问t，并更新所有以t为中介节点的最短距离
            st[t] = true;
            for (int j = 2; j <= n; ++j) 
                d[j] = min(d[j], d[t] + g[t][j]);
            if (t == n) break;
        }
        return d[n] == 0x3f3f3f3f ? -1 : d[n];
    }
    
    int main() {
        cin >> n >> m;
        memset(g, 0x3f, sizeof g);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a][b] = min(g[a][b], w);
        }
        cout << dijkstra();
        return 0;
    }
```

#### AcWing 850. Dijkstra求最短路 II

给定一个 $ n $ 个点 $ m $ 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

请你求出 $ 1 $ 号点到 $ n $ 号点的最短距离，如果无法从 $ 1 $ 号点走到 $ n $ 号点，则输出 $ -1 $。

**输入格式**

第一行包含整数 $ n $ 和 $ m $。

接下来 $ m $ 行每行包含三个整数 $ x,y,z $，表示存在一条从点 $ x $ 到点 $ y $ 的有向边，边长为 $ z $。

**输出格式**

输出一个整数，表示 $ 1 $ 号点到 $ n $ 号点的最短距离。

如果路径不存在，则输出 $ -1 $。

**数据范围**

$ 1 \le n,m \le 1.5 \times 10^5 $,  
图中涉及边长均不小于 $ 0 $，且不超过 $ 10000 $。  
数据保证：如果最短路存在，则最短路的长度不超过 $ 10^9 $。

**输入样例**：

```
3 3
1 2 2
2 3 1
1 3 4
```

**输出样例**：

```
3
```

**堆优化版Dijkstra(边权不能为负)，适合于稀疏图，时间复杂法O(ElogV)**

```c++
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 150010, M = 2 * N;

typedef pair<int, int> PII;
int n, m, d[N], h[N], e[M], w[M], ne[M], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({d[1], 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[ver] + w[i]) {
                d[j] = d[ver] + w[i];
                heap.push({d[j], j});
            }
        }
    }
    return d[n] == 0x3f3f3f3f ? -1 : d[n];
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra();
    return 0;
}
```

#### AcWing 853. 有边数限制的最短路

给定一个 $ n $ 个点 $ m $ 条边的有向图，图中可能存在重边和自环， **边权可能为负数**。

请你求出从 $ 1 $ 号点到 $ n $ 号点的最多经过 $ k $ 条边的最短距离，如果无法从 $ 1 $ 号点走到 $ n $ 号点，输出 `impossible`。

注意：图中可能 **存在负权回路** 。

**输入格式**

第一行包含三个整数 $ n,m,k $。

接下来 $ m $ 行，每行包含三个整数 $ x,y,z $，表示存在一条从点 $ x $ 到点 $ y $ 的有向边，边长为 $ z $。

**输出格式**

输出一个整数，表示从 $ 1 $ 号点到 $ n $ 号点的最多经过 $ k $ 条边的最短距离。

如果不存在满足条件的路径，则输出 `impossible`。

**数据范围**

$ 1 \le n,k \le 500 $,  
$ 1 \le m \le 10000 $,  
任意边长的绝对值不超过 $ 10000 $。

**输入样例**：

```
3 3 1
1 2 1
2 3 1
1 3 3
```

**输出样例**：

```
3
```

**Bellman-ford算法适合于存在负权边图，时间复杂度O(VE)**

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;
struct Edge {
    int a, b, w;
} edge[M];
int n, m, k, d[N], last_d[N];

void bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for (int i = 1; i <= k; ++i) {
        memcpy(last_d, d, sizeof d);
        for (int j = 0; j < m; ++j) {
            auto e = edge[j];
            d[e.b] = min(d[e.b], last_d[e.a] + e.w);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    bellman_ford();
    if (d[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << d[n];
    return 0;
}
```

#### AcWing 851. spfa求最短路 

给定一个 $ n $ 个点 $ m $ 条边的有向图，图中可能存在重边和自环， **边权可能为负数**。

请你求出 $ 1 $ 号点到 $ n $ 号点的最短距离，如果无法从 $ 1 $ 号点走到 $ n $ 号点，则输出 `impossible`。

数据保证不存在负权回路。

**输入格式**

第一行包含整数 $ n $ 和 $ m $。

接下来 $ m $ 行每行包含三个整数 $ x,y,z $，表示存在一条从点 $ x $ 到点 $ y $ 的有向边，边长为 $ z $。

**输出格式**

输出一个整数，表示 $ 1 $ 号点到 $ n $ 号点的最短距离。

如果路径不存在，则输出 `impossible`。

**数据范围**

$ 1 \le n,m \le 10^5 $,  
图中涉及边长绝对值均不超过 $ 10000 $。

**输入样例**：

```
3 3
1 2 5
2 3 -3
1 3 4
```

**输出样例**：

```
2
```

**spfa算法是bellman-ford算法的队列优化(适用于存在负权边图)，平均时间复杂度O(VlogE)，最坏时间复杂度O(VE)**

```c++
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m, d[N], h[N], e[N], w[N], ne[N], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        // 从队列中取出来之后该节点st被标记为false,代表之后该节点如果发生更新可再次入队
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if (st[j]) continue;
                q.push(j);
                st[j] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof d);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa();
    if (d[n] == 0x3f3f3f3f) cout << "impossible";
    else cout << d[n];
}
```

#### AcWing 852. spfa判断负环

给定一个 $ n $ 个点 $ m $ 条边的有向图，图中可能存在重边和自环， **边权可能为负数**。

请你判断图中是否存在负权回路。

**输入格式**

第一行包含整数 $ n $ 和 $ m $。

接下来 $ m $ 行每行包含三个整数 $ x,y,z $，表示存在一条从点 $ x $ 到点 $ y $ 的有向边，边长为 $ z $。

**输出格式**

如果图中**存在**负权回路，则输出 `Yes`，否则输出 `No`。

**数据范围**

$ 1 \le n \le 2000 $,  
$ 1 \le m \le 10000 $,  
图中涉及边长绝对值均不超过 $ 10000 $。

**输入样例**：

```
3 3
1 2 -1
2 3 4
3 1 -4
```

**输出样例**：

```nginx
Yes
```

````c++
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n, m, d[N], cnt[N], h[N], e[N], w[N], ne[N], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (st[j]) continue;
                q.push(j);
                st[j] = true;
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof d);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << (spfa() ? "Yes" : "No");
    return 0;
}
````

#### AcWing 854. Floyd求最短路

给定一个 $ n $ 个点 $ m $ 条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定 $ k $ 个询问，每个询问包含两个整数 $ x $ 和 $ y $，表示查询从点 $ x $ 到点 $ y $ 的最短距离，如果路径不存在，则输出 `impossible`。

数据保证图中不存在负权回路。

**输入格式**

第一行包含三个整数 $ n,m,k $。

接下来 $ m $ 行，每行包含三个整数 $ x,y,z $，表示存在一条从点 $ x $ 到点 $ y $ 的有向边，边长为 $ z $。

接下来 $ k $ 行，每行包含两个整数 $ x,y $，表示询问点 $ x $ 到点 $ y $ 的最短距离。

**输出格式**

共 $ k $ 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 `impossible`。

**数据范围**

$ 1 \le n \le 200 $,  
$ 1 \le k \le n^2 $  
$ 1 \le m \le 20000 $,  
图中涉及边长绝对值均不超过 $ 10000 $。

**输入样例**：

```
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
```

**输出样例**：

```nginx
impossible
1
```

**floyd算法适合求多源最短路径， 时间复杂度O(V^3)**

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 210, INF = 1e9 + 10;
int n, m, q, d[N][N];

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) d[i][j] = INF;
        }
    }
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }
    floyd();
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (d[x][y] > INF / 2) cout << "impossible" << endl;
        else cout << d[x][y] << endl;
    }

    return 0;
}
```



### 3.4 最小生成树

#### AcWing 858. Prim算法求最小生成树

给定一个 $ n $ 个点 $ m $ 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。

给定一张边带权的无向图 $ G=(V, E) $，其中 $ V $ 表示图中点的集合，$ E $ 表示图中边的集合，$ n=|V| $，$ m=|E| $。

由 $ V $ 中的全部 $ n $ 个顶点和 $ E $ 中 $ n-1 $ 条边构成的无向连通子图被称为 $ G $ 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 $ G $ 的最小生成树。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

接下来 $ m $ 行，每行包含三个整数 $ u,v,w $，表示点 $ u $ 和点 $ v $ 之间存在一条权值为 $ w $ 的边。

**输出格式**

共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。

**数据范围**

$ 1 \le n \le 500 $,  
$ 1 \le m \le 10^5 $,  
图中涉及边的边权的绝对值均不超过 $ 10000 $。

**输入样例**：

```
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
```

**输出样例**：

```
6
```

**朴素prim算法，时间复杂度O(V^2)，适合于稠密图**

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m, d[N], g[N][N];
bool st[N];

int prim() {
    memset(d, 0x3f, sizeof d);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || d[t] > d[j])) t = j;
        if (i && d[t] == INF) return INF;
        if (i) res += d[t];
        st[t] = true;
        for (int j = 1; j <= n; ++j) d[j] = min(d[j], g[j][t]);
    }
    return res;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j) g[i][j] = INF;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int t = prim();
    if (t == INF) cout << "impossible";
    else cout << t;
}
```

#### AcWing 859. Kruskal算法求最小生成树

给定一个 $ n $ 个点 $ m $ 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。

给定一张边带权的无向图 $ G=(V, E) $，其中 $ V $ 表示图中点的集合，$ E $ 表示图中边的集合，$ n=|V| $，$ m=|E| $。

由 $ V $ 中的全部 $ n $ 个顶点和 $ E $ 中 $ n-1 $ 条边构成的无向连通子图被称为 $ G $ 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 $ G $ 的最小生成树。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

接下来 $ m $ 行，每行包含三个整数 $ u,v,w $，表示点 $ u $ 和点 $ v $ 之间存在一条权值为 $ w $ 的边。

**输出格式**

共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 `impossible`。

**数据范围**

$ 1 \le n \le 10^5 $,  
$ 1 \le m \le 2*10^5 $,  
图中涉及边的边权的绝对值均不超过 $ 1000 $。

**输入样例**：

```
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
```

**输出样例**：

```
6
```

**Kruskal算法时间复杂度O(ElogE)，适合于稀疏图**

```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

struct Edge {
    int u, v, w;

    bool operator<(const Edge &E) const {
        return w < E.w;
    }
} edges[N];

int n, m, fa[N];

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

int kruskal() {
    int res = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        u = find(u), v = find(v);
        if (u != v) fa[u] = v, res += w, cnt++;
    }
    if (cnt != n - 1) return INF;
    else return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v) continue;
        edges[i] = {u, v, w};
    }
    sort(edges, edges + m);
    int t = kruskal();
    if (t == INF) cout << "impossible";
    else cout << t;
    return 0;
}
```

**堆优化版prim算法时间复杂度O(ElogV)，适合于稀疏图，（算法实现复杂，推荐使用Kruskal）**

```c++
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

//考虑无向图M = 4 * N
const int N = 1e5 + 10, M = 4 * N, INF = 0x3f3f3f3f;

typedef pair<int, int> PII;
int n, m, h[N], e[M], w[M], ne[M], idx;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int prim() {
    int res = 0, cnt = 0;
    priority_queue<PII, vector<PII>, greater<> > heap;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int dis = t.first, ver = t.second;
        if (st[ver]) continue;
        st[ver] = true, res += dis, cnt++;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (st[j]) continue;
            heap.push({w[i], j});
        }
    }
    if (cnt != n) return INF;
    return res;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        // 最小生成树不考虑自环
        if (a == b) continue;
        add(a, b, c);
        add(b, a, c);
    }
    int t = prim();
    if (t == INF) cout << "impossible";
    else cout << t;
    return 0;
}
```



### 3.5 二分图：染色法、匈牙利算法

#### AcWing 860. 染色法判定二分图

给定一个 $ n $ 个点 $ m $ 条边的无向图，图中可能存在重边和自环。

请你判断这个图是否是二分图。

**输入格式**

第一行包含两个整数 $ n $ 和 $ m $。

接下来 $ m $ 行，每行包含两个整数 $ u $ 和 $ v $，表示点 $ u $ 和点 $ v $ 之间存在一条边。

**输出格式**

如果给定图是二分图，则输出 `Yes`，否则输出 `No`。

**数据范围**

$ 1 \le n,m \le 10^5 $

**输入样例**：

```
4 4
1 3
1 4
2 3
2 4
```

**输出样例**：

```nginx
Yes
```

**染色法判定二分图的原理：一个图是二分图，当且仅当图中不含有奇数环**

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, m, st[N], h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int c) {
    st[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            if (!dfs(j, 3 - c)) return false;
        } else if (st[j] == c) return false;
    }
    return true;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (st[i]) continue;
        if (!dfs(i, 1)) {
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes";
    else cout << "No";
}
```

#### AcWing 861. 二分图的最大匹配

给定一个二分图，其中左半部包含 $ n_1 $ 个点（编号 $ 1 \sim n_1 $），右半部包含 $ n_2 $ 个点（编号 $ 1 \sim n_2 $），二分图共包含 $ m $ 条边。

数据保证任意一条边的两个端点都不可能在同一部分中。

请你求出二分图的最大匹配数。

> 二分图的匹配：给定一个二分图 $ G $，在 $ G $ 的一个子图 $ M $ 中，$ M $ 的边集 $ \{E\} $ 中的任意两条边都不依附于同一个顶点，则称 $ M $ 是一个匹配。
>
> 二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。

**输入格式**

第一行包含三个整数 $ n_1 $、 $ n_2 $ 和 $ m $。

接下来 $ m $ 行，每行包含两个整数 $ u $ 和 $ v $，表示左半部点集中的点 $ u $ 和右半部点集中的点 $ v $ 之间存在一条边。

**输出格式**

输出一个整数，表示二分图的最大匹配数。

**数据范围**

$ 1 \le n_1,n_2 \le 500 $,  
$ 1 \le u \le n_1 $,  
$ 1 \le v \le n_2 $,  
$ 1 \le m \le 10^5 $

**输入样例**：

```
2 2 4
1 1
1 2
2 1
2 2
```

**输出样例**：

```
2
```

```c++
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n1, n2, m, match[N], h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        st[j] = true;
        if (!match[j] || find(match[j])) {
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n1 >> n2 >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n1; ++i) {
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }
    cout << res;
    return 0;
}
```



## 第四章 数学知识

### 1.1 质数

#### AcWing 866. 试除法判定质数

给定 $ n $ 个正整数 $ a_i $，判定每个数是否是质数。

**输入格式**

第一行包含整数 $ n $。

接下来 $ n $ 行，每行包含一个正整数 $ a_i $。

**输出格式**

共 $ n $ 行，其中第 $ i $ 行输出第 $ i $ 个正整数 $ a_i $ 是否为质数，是则输出 `Yes`，否则输出 `No`。

**数据范围**

$ 1 \le n \le 100 $,  
$ 1 \le a_i \le 2^{31}-1 $

**输入样例**：

```
2
2
6
```

**输出样例**：

```nginx
Yes
No
```

```c++
#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << (is_prime(x) ? "Yes" : "No") << endl;
    }
    return 0;
}
```

