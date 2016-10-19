#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * ������ת�������Сֵ
 */

//    ��������
int FindMin(int *p, int size);

//
int _tmain(int argc, _TCHAR *argv[]) {
    int a[] = {3, 5, 1, 2,7, 4, 8};
    int m = FindMin(a, sizeof(a) / sizeof(int));
    std::cout << m << std::endl;
    return 0;
}

int FindMin(int *num, int size) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low < high) {
        mid = (high + low) / 2;
        if (num[mid] < num[high]) { // ��Сֵ����벿��
            high = mid;
        } else if (num[mid] > num[high]) {// ��Сֵ���Ұ벿��
            low = mid + 1;
        }
    }
    return num[low];
}
