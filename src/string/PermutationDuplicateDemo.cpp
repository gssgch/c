#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * ���ظ���ȫ���У���Ҫȥ��

 */

//    ��������
void Print(const int *p, int size);

void Permutation(int *p, int size, int n);

bool IsDuplicate(const int *a, int n, int t);

//
int _tmain(int argc, _TCHAR *argv[]) {
//    int a[] = {1, 2, 2, 3};
    Permutation(a, sizeof(a) / sizeof(int), 0);

    // ʱ�任�ռ�
    char str[] = "abbc";
    Permutation(str, sizeof(str) / sizeof(char), 0);
    return 0;
}
// �ظ��ַ���ȫ���еݹ��㷨ʱ�临�Ӷ� O((n+1)!)
void Permutation(int *a, int size, int n) {
    if (n == size - 1) {  // �����һλ�ˣ�ȫ���е�һ���ڣ���ӡ����
        Print(a, size);
        return;
    }
    for (int i = n; i < size; i++) {
        if (!IsDuplicate(a, n, i)) {// a[i]�Ƿ���[n,i) �ظ�
            continue;
        }
        swap(a[i], a[n]);
        Permutation(a, size, n + 1);
        swap(a[i], a[n]);
    }
}

// ʱ�任�ռ�  �ж��ظ���ʱ��ΪO(1)
void Permutation2(char *a, int size, int n) {
    if (n == size - 1) {
        Print(a, size);
        return;
    }
    int dup[256] = {0};
    for (int i = n; i < size; i++) {
        if (dup[a[i]]==1) {
            continue;
        }
        dup[a[i]]=1;
        swap(a[i], a[n]);
        Permutation(a, size, n + 1);
        swap(a[i], a[n]);
    }
}
// �Ƿ��ظ����ֹ�
bool IsDuplicate(const int *a, int n, int t) {
    while (n < t) {
        if (a[n] == a[t]) {
            return false;
        }
        n++;
    }
        return true;
}

void Print(const int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}