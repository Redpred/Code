#include<iostream>

using namespace std;

/*
master��ʽ������ ������ȹ�ģ �ĵݹ��㷨 ��ʱ�临�Ӷ�
T(N) = a * T(N/b) + O(N^d);
a:
b:
d:
���Ϊ��
log(b^a) < d  >>  O(N^d)
log(b^a) > d  >>  O(N^log(b^a))
log(b^a) = d  >>  O(N^d * log N)
*/

