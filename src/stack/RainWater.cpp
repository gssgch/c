#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream>
#include <stack>
#include<vector>

using namespace std;
/**
 * ֱ��ͼ��������
 * ����n���Ǹ���������ʾֱ��ͼ�ķ����ĸ߶ȣ�ͬʱ��ÿ�������Ŀ�ȼٶ���Ϊ1��
 * ��ʹ��������״�������ռ���ˮ������ʢ����ˮ��
 * ������ 0 1 0 2 1 0 1 3 2 1 2 1 ����6
 */

//    ��������
int TrappingRainWater(int A[],int n);

int _tmain(int argc, _TCHAR *argv[]) {

    return 0;
}

int TrappingRainWater(int A[],int n){
    int secHight = 0; // ��ǰ�ҵ��ĵڶ������
    int left=0;
    int right = n-1;
    int trap=0; // ���α���ÿ��������װˮ������
    while(left<right){
        if(A[left]<A[right]){
            secHight=max(A[left],secHight);
            trap +=(secHight-A[left]);
            left++;
        }else{
            secHight=max(A[right],secHight);
            trap += (secHight-A[right]);
            right--;
        }
    }
    return  trap;
}
