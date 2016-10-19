#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * �ǵݹ�ȫ����
 * ʹ�������з�  ���������ң�С�󣬽�������ת
 */

//    ��������
void Print(int *p, int size);

void Reverse(int *from, int *to);

bool GetNextPermutation(int *a, int size);

// �������� ʱ�临�Ӷ� O(N*N!)
int _tmain(int argc, char *argv[]) {
    int a[] = {1, 2, 2, 3}; // , 3, 4
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
    while (GetNextPermutation(a, size)) {
        Print(a, size);
    }
    return 0;
}

void Reverse(int *from, int *to) {
    int t;
    while (from < to) {
        t = *from;
        *from = *to;
        *to = t;
        from++;
        to--;
    }
}

// O(N)
bool GetNextPermutation(int *a, int size) {
    // ����  O(N)
    int i = size - 2; // �����ڶ�λ��ʼ�����翪ʼ�ȽϺ���λ
    while ((i >= 0) && (a[i] >= a[i + 1])) { // ����ǽ��򣬽�����ǰ��
        i--;
    }
    if (i < 0) { // �����ˣ�û���ҵ�
        return false;
    }
    // С�� O(N)
    int j = size - 1;
    while (a[j] <= a[i]) { // �ҵ�һ����ģ������Ǵ��������С��
        j--;
    }
    // ����  O(1)
    swap(a[j], a[i]);

    // ��ת  O(N)
    Reverse(a + i + 1, a + size - 1);
    return true;
}
void Print(int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}