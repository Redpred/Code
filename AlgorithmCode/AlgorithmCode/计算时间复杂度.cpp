#include<iostream>

using namespace std;

/*
master公式：计算 子问题等规模 的递归算法 的时间复杂度
T(N) = a * T(N/b) + O(N^d);
a:
b:
d:
结果为：
log(b^a) < d  >>  O(N^d)
log(b^a) > d  >>  O(N^log(b^a))
log(b^a) = d  >>  O(N^d * log N)
*/

