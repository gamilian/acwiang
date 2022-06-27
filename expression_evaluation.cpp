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