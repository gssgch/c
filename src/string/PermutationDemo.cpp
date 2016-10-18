#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * �ݹ����ظ�ȫ����

 */

//    ��������
void Print(const int *p, int size);
void Permutation(int *p, int size, int n);

//
int _tmain(int argc, _TCHAR *argv[]) {
    int a[] = {1, 2,3}; // , 3, 4
    Permutation(a, sizeof(a) / sizeof(int), 0);

    return 0;
}
// ��εݹ�û��ô������
void Permutation(int *a, int size, int n) {
        if (n == size - 1) {  // �����һλ�ˣ�ȫ���е�һ���ڣ���ӡ����
            Print(a, size);
            return;
        }
    for (int i = n; i < size; i++) {
        swap(a[i], a[n]);
        printf("\ni=%d,ai=%d,n=%d,an=%d\n",i,a[i],n,a[n]);
        Permutation(a, size, n + 1);
        printf("\n2222i=%d,ai=%d,n=%d,an=%d\n",i,a[i],n,a[n]);
        swap(a[i], a[n]);
    }
}

void Print(const int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}