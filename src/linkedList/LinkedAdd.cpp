#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  ���������ϰ
 *  ����������ʾ�����Ǹ���������������洢�������У�ÿ�����洢һ�����֣������������ĺͣ����غ͵�����ͷָ�롣
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

//    ��������൱�ڹ��캯��
    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;
// �����SNode �൱��struct tagSNode�ı�����������������ʱ��Ϳɣ�SNode s1;
// ���û��typedef�ͱ����� struct tagSNode SNode;

//    ��������
SNode *Add(SNode *pHead1, SNode *pHead2);

void Print(SNode *pHead1);

void Destroy(SNode *pHead1);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead1 = new SNode(0);
    int i;
    for (i = 0; i < 6; i++) {
        SNode *p = new SNode(rand() % 10);
        /* ����ʹ�õ���ͷ�巨   ͷ�巨 ����һ���ڵ��ʱ�临�Ӷ���O(1)
         *  �ٶ�pHead1�Ѿ������ɽڵ㣬��p��nextָ��pHead��next��
         *  Ȼ���phead������next�ϵ���ָ��p
         *  �������൱����ǰ�������һ���ڵ�p
         *  ��java�﷨���Ǹ�ֵ����������ָָ���ָ�򣬾���ǰ��ָ����档
         * */
        p->pNext = pHead1->pNext;
        pHead1->pNext = p; // ���½��p���뵽��pHead1�У���pHeadָ��p�ڵ�
    }
    SNode *pHead2 = new SNode(0); // ���ﴴ����ͷ����Ψһ��������õ�pNextָ��
    for (i = 0; i < 9; i++) {
        SNode *p = new SNode(rand() % 10);
        p->pNext = pHead2->pNext;
        pHead2->pNext = p;
    }
    Print(pHead1);
    Print(pHead2);
    SNode *pSum = Add(pHead1, pHead2);
    Print(pSum);
    Destroy(pHead1);
    Destroy(pHead2);
    Destroy(pSum);
    return 0;
}


SNode *Add(SNode *pHead1, SNode *pHead2) {
    SNode *pSum = new SNode(0);
    SNode *pTail = pSum;// �½����뵽pTail����
    SNode *p1 = pHead1->pNext;
    SNode *p2 = pHead2->pNext;
    SNode *pCur;
    int carry = 0; // ��λ
    int value;
    while (p1 && p2) {
        value = p1->value + p2->value + carry;
        carry = value / 10; // ��λ�Ľ�λ
        value %= 10; // ��ǰλ��ֵ
        pCur = new SNode(value);
        pTail->pNext = pCur; // �½�����ӵ�pTail����
        pTail = pCur; // βָ��ָ��ǰ�ڵ�

        p1 = p1->pNext;// ������һλ
        p2 = p2->pNext;

    }

// ����ϳ���������ʱ����Ϊ���ˣ������ǿգ�
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
//    printf("11111\n");
//    Print(pTail);
//    printf("111112\n");
//    Print(pSum);
    return pSum; // ��ʱpsum��pTailһ����

}

// ��ӡ����
void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
        printf("PrintList����ִ�У�����Ϊ��\n");
    } else {
        pHead= pHead->pNext; // ȥ����ͷ���
        while (NULL != pHead) {

            printf("%d ", pHead->value);
            pHead = pHead->pNext;
            if (pHead != NULL) {
                printf("%s ", "->");
            }
        }
        printf("\n");
    }
}

void Destroy(SNode *head) {
    SNode *p, *q;
    p = head;
    while (p->pNext != NULL) {
        q = p->pNext;
        p->pNext = q->pNext;
        free(q);
    }
    free(p);
}

// ��ʦ��destroy
/*
void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p=next;
    }
}*/
