#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
/**
 *  �������
 *  ���� ����洢��
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;
    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;
// �����SNode �൱��struct tagSNode�ı�����������������ʱ��Ϳɣ�SNode s1;
// ���û��typedef�ͱ����� struct tagSNode SNode;

//    ��������
void Print(SNode *pHead1);
SNode *Add(SNode *pHead1, SNode *pHead2);

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
    SNode *pSum = Add(pHead1, pHead2);
    Print(pSum);
//    Destroy(pHead1);
//    Destroy(pHead2);
//    Destroy(pSum);
    return 0;
}

void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
        printf("PrintList����ִ�У�����Ϊ��\n");
    } else {

        while (NULL != pHead) {
            printf("%d ", pHead->value);

            pHead = pHead->pNext;
            if (pHead != NULL){
                printf("%s ", "->");
            }
        }
        printf("\n");
    }
}

SNode *Add(SNode *pHead1, SNode *pHead2) {
    SNode *pSum = new SNode(0);
    SNode *pTail = pSum;// �½����뵽pTail����
    SNode *p1 = pHead1->pNext;
    SNode *p2 = pHead2->pNext;
    SNode *pCur;
    int carry = 0; // ��λ
    int value = 0;
    while (p1 && p2) {
        value = p1->value + p2->value + carry;
        carry = value / 10;
        value %= 10;
        pCur = new SNode(value);
        pTail->pNext = pCur; // �½�����ӵ�pTail����
        pTail = pCur;

        p1 = p1->pNext;// ������һλ
        p2 = p2->pNext;

    }

// ����ϳ�����
    SNode *p = p1 ? p1 : p2;
    while (p) {
        value = p->value + carry;
        carry = value / 10;
        pCur = new SNode(value);
        pTail->pNext = pCur;
        pTail = pCur;
        p = p->pNext;
    }

// ������ܴ��ڵĽ�λ
    if (carry != 0) {
        pTail->pNext = new SNode(carry);
    }
    return pSum;

}
