#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

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


    while (NULL != pHead1) {
        printf("%d ", pHead1->value);
        printf("%s ", "->");
        pHead1 = pHead1->pNext;
    }
    printf("\n");

    Print(pHead1);
    Print(pHead2);
    SNode* pSum = Add(pHead1, pHead2);
    Print(pSum);
//    Destroy(pHead1);
//    Destroy(pHead2);
//    Destroy(pSum);
    return 0;
}

void Print(SNode *pHead) {
    if (NULL == pHead)   //???????
    {
        printf("PrintList����ִ�У�����Ϊ��\n");
    } else {
/*        while (NULL != pHead) {
            printf("%d ", pHead->value);
            pHead = pHead->pNext;
        }
        printf("\n");*/
    }
    /*SNode p = p1->pNext;                            //???????????????????p
    while(NULL != p)                                //???p?????????

    {
        printf("%d ",p->value);
        p = p->pNext;
    }
    printf("\n");
    return ;*/
//    int cout;
//    for(SNode* i=p; i != p; i=i->pNext)
//    {
//        cout << i->value;
//    }
//    printf("%d",cout);
//    int endl;
//    cout << endl;
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