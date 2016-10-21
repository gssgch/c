#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * ����������
 */

typedef struct tagSBucket{
    bool bValid; // �Ƿ���ЧͰ
    int nMin;
    int nMax;
    tagSBucket():bValid(false){}
    // ����n���뵽Ͱ��
    void Add(int n){
        if(!bValid){
            nMax=nMin=n;
            bValid=true;
        }else{
            if(n>nMax){
                nMax=n;
            }else if(n<nMin){
                nMin=n;
            }
        }
    }
}SBucket;
//    ��������
int CalcMaxGap(const int *p, int size);

int _tmain(int argc, _TCHAR *argv[]) {
    const int a[] = {3, 5, -8,  7, 14, 18};
    int m = CalcMaxGap(a, sizeof(a) / sizeof(int));
    std::cout << m << std::endl;
    return 0;
}

int CalcMaxGap(const int *A, int size){
    // ����ֵ �����õ���������ֵ����Сֵ
    SBucket* pBucket = new SBucket[size];
    int nMax=A[0];
    int nMin=A[0];
    int i;
    for (i = 0; i < size; i++) {
        if(nMax<A[i]){
            nMax=A[i];
        }else if(nMin>A[i]){
            nMin=A[i];
        }
    }
    // ���ν����ݷ���Ͱ��
    int delta=nMax-nMin;
    int nBucket; // ĳ��Ӧ�����ĸ�Ͱ��
    for (i = 0; i < size; ++i) {
        // ���������˶Ե���ˣ���Ϊ (A[i]-nMin)/Ͱ�� = (nMax-nMin) / size(���size������Ͱ��)
        nBucket=(A[i]-nMin)*size/delta;
        if(nBucket>=size){
            nBucket=size-1;
        }
        pBucket[nBucket].Add(A[i]);
    }

    // ������ЧͰ�ļ��
    i=0; // �׸�Ͱһ������Ч��
    int nGap=delta/size; // ��С���
    int gap;
    for (int j = 1; j < size; ++j) {// i��ǰһ��Ͱ��j�Ǻ�һ��Ͱ
        if(pBucket[j].bValid){
            gap=pBucket[j].nMin-pBucket[i].nMax;
            if(nGap<gap){
                nGap=gap;
            }
            i=j;
        }
    }
    return nGap;
}