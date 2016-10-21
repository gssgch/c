#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 *  ����������
 */

//    ��������
int MaxSubarray(const int *p, int size);
int MaxSubarray2(const int *p, int size,int& a,int& b);
//
int _tmain(int argc, _TCHAR *argv[]) {
    const int a[] = {3, 5, -8,  7, 14, 18};
    int start,end;
    int m = MaxSubarray(a, sizeof(a) / sizeof(int));
    int m2 = MaxSubarray2(a, sizeof(a) / sizeof(int),start,end);
//    std::cout << m << std::endl;
    std::cout << m2 << std::endl;
    printf("\nstart=%d,end=%d",start,end);
    return 0;
}
// ����������������
// ʱ�临�Ӷ�O(N)  �ռ临�Ӷ�O(1)
int MaxSubarray(const int *a, int size) {
    if(!a || (size<=0)){
        return 0;
    }
    int sum=a[0]; // ��ǰ�Ӵ��ĺ�
    int result =sum; // ��ǰ�ҵ������Ž�
    for (int i = 1; i < size; i++) {
        if(sum>0){
            sum+=a[i];
        }else{ // С��0��������Ϊ�Ӻͺ��С
            sum=a[i];
        }
        result= max(sum,result);
    }
    return result;
}

// ������������ĺͣ��Լ����������
int MaxSubarray2(const int *a, int size,int& from,int& to) {
    if(!a || (size<=0)){
        from =to = -1;
        return 0;
    }
    from = to =0;
    int sum=a[0];
    int result =sum;
    int fromNew; // �µ����������
    for (int i = 1; i < size; i++) {
        if(sum>0){
            sum+=a[i];
        }else{
            sum=a[i];
            fromNew=i;
        }
        if(result<sum){
            result=sum;
            from =fromNew;
            to = i;
        }
    }
    return result;
}
