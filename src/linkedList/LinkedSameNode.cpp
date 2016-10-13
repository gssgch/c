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
 *
 *  ����������������У����������ڻ�������Ҫʹ�ÿ���ָ��ķ�ʽ���㹫�����
 *      ����ָ�룬ÿ�ηֲ��ƶ�һ��/�������
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
void swap(void *a,void *b);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead1 = new SNode(0);
    int i;
    for (i = 0; i < 6; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead1->pNext;
        pHead1->pNext = p;
    }
    SNode *pHead2 = new SNode(0);
    for (i = 0; i < 9; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead2->pNext;
        pHead2->pNext = p;
    }

    Print(pHead1);
    Print(pHead2);
    FindFirstSameNode(pHead1,pHead2);
    Print(pHead1);
    Print(pHead2);
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
SNode *FindFirstSameNode(SNode *pA,SNode *pB) {
    // ��Ϊ��ͷָ�룬����ָ���һ����Ч���
    pA=pA->pNext;
    pB=pB->pNext;

    // ������������ĳ���
    int nA = CalcLength(pA);
    int nB = CalcLength(pB);
     // �������ת��ֻ��Ϊ�� ȷ��B��A���� ��д���룬û��ʵ�����壬 �� swap�Ĵ���������
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
    }
        return NULL;
}
// ��֪�����swap������ôд
void swap(void *a,void *b,size_t size)
{
    unsigned char *p1=(unsigned char *)a;          //ǿ������ת��
    unsigned char *p2=(unsigned char *)b;
    Unsigned char temp;                         //�ֽ��͵ļ���
    while(size--)
    {
        temp=*p1;
        *p1=*p2;
        *p2=temp;
        p1++;
        p2++;
    }
}
//void swap(int &a, int &b) {
//    //����һ��
//    int tmp = 0;
//    tmp = b;
//    b = a;
//    a = tmp;
//    //��������
//    //a = a+b;
//    //b = a-b;
//    //a = a -b;
//    //��������
//    //a ^= b ^= a ^= b;
//    //�����ģ�
//    //a = a+b-(b=a);
//}


void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}
