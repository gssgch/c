#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 * KMP

 */

//    ��������
void Print(const int *p, int size);


//
int _tmain(int argc, _TCHAR *argv[]) {
    return 0;
}

void GetNext(char *p, int next[]) {
    int nLen = (int) strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < nLen - 1) {
        // �˿̣�k��next[j-1]����p[k]��ʾǰ׺��p[j]��ʾ��׺
        // ע��k==-1��ʾδ�ҵ�kǰ׺��k��׺��ȣ��״η������Ⱥ���
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            next[j] = k;
        } else { // p[j]��p[k]ʧ�䣬������ݹ����ǰ׺p[next[k]]
            k = next[k];
        }
    }
}

// ������ķ���  ���ֵ�KMP
void GetNext2(char *p, int next[]) {
    int nLen = (int) strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < nLen - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            // �������ȣ���һ����ֵ
            if (p[j] == p[k]) {
                next[j] = next[k];
            } else {
                next[j] = k;
            }
        } else {
            k = next[k];
        }
    }
}

int KMP(int k) {
    int ans = -1;
    int i = 0;
    int j = 0;
    int pattern_len = strlen(g_pattern);
    while (i < n) {
        if (j == -1 || g_s[i] == g_pattern[j]) {
            ++i;
            ++j;
        } else {
            j = g_next[j];
        }
        if (j == pattern_len) {
            ans = i - pattern_len;
            break;
        }
    }
    return ans;
}

// �������
int BruteForceSearch(const char *s, const char *p) {
    int i = 0; // ��ǰƥ�䵽��ԭʼ����λ
    int j = 0; // ģʽ����ƥ��λ��
    int size = (int) strlen(p);
    int nLast = (int) strlen(s) - size;
    while ((i < nLast) && (j < size)) {
        if (s[i + j] == p[j]) {// ƥ�䣬��ģʽ��ƥ��λ�ú���
            j++;
        } else {// ��ƥ�䣬��ȶ���һ��λ�ã�ģʽ�����ݵ���λ
            i++;
            j = 0;
        }
    }
    if (j >= size) {
        return i;
    }
    return -1;
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