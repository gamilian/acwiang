#include "bits/stdc++.h"

using namespace std;


int main() {
    int a[3] = {1, 2,  3};
    //此时定义指针p，*p可以理解是指针，其实本质上int*，是一种指针类型，实际上p是指针
    //定义指针p时，p指向a[0] = 1所在的内存，即p存放a[0]的地址
    int *p = a;
    //指针p的指针指向改变 p指向a[1] = 2所在的内存，即p存放a[1]的地址
    p = p + 1;
    //修改p所指向内存内的值，即修改2所在空间；
    *p = 8;
    //访问p指向内存的值
    cout << "*p = " << *p  << " a[1] = " << a[1];


    return 0;
}