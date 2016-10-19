#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * ���ظ�����ľֲ����ֵ   �ҵ�һ������
 * ����ҵ����еģ�����Ҫ����

 */

//    ��������
int LocalMaximum(const int* p,int size);

//
int _tmain(int argc, _TCHAR *argv[]) {
    int p[]={1,3,4,5,2,112,3,5,6,79,2,4};
    printf("maxvalue:\n");
    std::cout <<LocalMaximum(p, sizeof(p)/ sizeof(int))
              << std::endl;
    return 0;
}
// ʱ�临�Ӷ�O(logN)
int LocalMaximum(const int* A,int size){
    int left =0;
    int right=size-1;
    int mid;
    while(left<right){
        mid = (left+right)/2;
//        printf("mid:\n");
//        std::cout<<mid<<std::endl;
        if(A[mid]>A[mid+1]){ // ����midһ����С��size-1��
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return A[left];
}
