#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 *  ��������
 *  ������������ĺ���ӽ�0��ֵ
 */

//    ��������
int MinSubarray(const int *p, int size);
//
int _tmain(int argc, _TCHAR *argv[]) {
    const int a[] = {3, 5, -8,  7, 14, 18};
    int m = MinSubarray(a, sizeof(a) / sizeof(int));
    std::cout << m << std::endl;
    return 0;
}
// ʱ�临�Ӷ�O(N*logN) �ռ临�Ӷ�O(N)
int MinSubarray(const int *a, int size) {
    int* sum=new int[size+1]; // sum[i]:a[0...i-1]�ĺ�
    sum[0]=0;
    int i;
    // ��ǰi������ĺ�
    for (i = 0; i <size ; i++) {
        sum[i+1]=sum[i]+a[i];
    }
    // ����  ���������ʱ����O(N^2),�������ȥ����
    sort(sum,sum+size+1);
    int difference = abs(sum[1]-sum[0]); // ��ʼ��
    int result = difference;
    for (i = 0;  i< size; i++) {
        difference=abs(sum[i+1]-sum[i]);
        result=min(difference,result);
    }
    delete[] sum;
    return result;
}
