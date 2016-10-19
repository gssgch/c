#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * KMPӦ�ã�PowerString����
 * �����ַ���S����С����

 */

//    ��������
void Print(const int *p, int size);
int MinPeriod(char* p);

//
int _tmain(int argc, _TCHAR *argv[]) {
    char p[]="abcabcabcabc";
    std::cout << MinPeriod(p)<< std::endl;
    return 0;
}

// �������
int MinPeriod(char* p){
    int nLen=(int)strlen(p);
    if(nLen==0){
        return -1;
    }
    int* next = new int[nLen]; // ����KMP��αnext��
    next[0]=-1;// �ڱ������ױ�־
    int k=-1;
    int j=0;
    while(j<nLen-1){
        if((k==-1)||(p[j+1]==p[k])){
            ++k;
            ++j;
            next[j]=k;
        } else{
            k=next[k];
        }
    }
    next[0]=0; // �ָ����߼��ϵ�0
    int nLast=next[nLen-1];
    delete[] next;
    if(nLast==0){
        return -1;
    }
    if(nLen %(nLen-nLast)==0){
        return nLen-nLast;
    }
    return -1;
}
void Print(const int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}