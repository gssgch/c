#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  ���������������
 *  ����������������������������ĵ�һ��������㣬��û�й�����㣬���ؿա�
 *  ������
 *  ����m��n,m>=n  ǰ��m-n�����һ����û�й�������
 *
 *  �㷨���ȷֱ������������õ����ȣ��������ת|m-n|�Σ�ͬ������������ֱ���ҵ���ͬ�������������
 *
 *  ʱ�临�Ӷ���O(m+n)
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    ��������
int CalcLength(SNode *p);
SNode* FindFirstSameNode(SNode *p1,SNode *p2);
void Print(SNode *pHead);
void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {

    return 0;
}

int CalcLength(SNode *p) {
int nLen =0;
    while(p){
        p=p->pNext;
        nLen++;
    }
    return nLen;
}
// ��ӡ����
SNode FindFirstSameNode(SNode *pA,SNode *pB) {
    // ��Ϊ��ͷָ�룬����ָ���һ����Ч���
    pA=pA->pNext;
    pB=pB->pNext;

    // ������������ĳ���
    int nA = CalcLength(pA);
    int nB = CalcLength(pB);
    if(nA>nB){
        swap(pA,pB);
        swap(nA,nB);
    }

    // ��תnB-nA��
    for(int i =0;i<nB-nA;i++){
        pB=pB->pNext;
    }

    // ��ͷ����
    while(pA){
        if(pA==pB){
            return pA;
        }
        pA=pA->pNext;
        pB=pB->pNext;
        return NULL;
    }

}

void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}
