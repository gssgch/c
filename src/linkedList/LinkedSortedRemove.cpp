#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  ��������ȥ��
 *  ��������������ɾ���ظ�Ԫ�أ�ֻ�����ظ�Ԫ�ص�һ�γ��ֵĽ�㡣
 *
 *  ��ȫδ�������������ȥ��ʱ�临�Ӷ���O(N*logN)
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    ��������
void DeleteDuplicateNode(SNode *pHead);

void Print(SNode *pHead);

void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead = new SNode(0);
    int data[] = {2, 3, 3, 4, 5, 5, 7, 8, 8, 8, 9, 9, 100};
    int size = sizeof(data) / sizeof(int);
    for (int i = size - 1; i >= 0; i--) {
        SNode *p = new SNode(data[i]);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    DeleteDuplicateNode(pHead);
    Print(pHead);
    Destroy(pHead);
    return 0;
}

// �ظ�Ԫ��ȥ�� ������һ���ظ�������
void DeleteDuplicateNode(SNode *pHead) {
    SNode *pPre = pHead->pNext;
    SNode *pCur;
    while (pPre) {
        pCur = pPre->pNext;
        if (pCur && pCur->value == pPre->value) {
            pPre->pNext = pCur->pNext;
            delete pCur;
        } else {
            pPre = pCur;
        }
    }
}

// �ظ�Ԫ��ȥ�� �������һ���ظ�������
void DeleteDuplicateNode2(SNode *pHead) {
    SNode *pPre = pHead->pNext;
    SNode *pCur;
    SNode *pNext;
    while (pCur) {
        pNext = pCur->pNext;
        while (pNext && (pCur->value == pNext->value)) {
            pPre->pNext = pNext;
            delete pCur;
            pCur = pNext;
            pNext = pCur->pNext;
        }
        pPre = pCur;
        pCur = pNext;
    }
}
// �ظ�Ԫ��ȥ�� ɾ�������ظ���Ԫ��
void DeleteDuplicateNode3(SNode *pHead) {
    SNode *pPre = pHead;
    SNode *pCur = pPre->pNext;
    SNode *pNext;
    bool  bDup;
    while (pCur) {
        pNext = pCur->pNext;
        bDup= false;
        while (pNext && (pCur->value == pNext->value)) {
            pPre->pNext = pNext;
            delete pCur;
            pCur = pNext;
            pNext = pCur->pNext;
            bDup= true;
        }
        if(bDup){// ��ʱpCur��ԭ�����ظ���ɾ��
            pPre->pNext=pNext;
            delete pCur;
        }else{ // pCurδ�����ظ�����pPre����
            pPre=pCur;
        }
        pPre = pCur;
        pCur = pNext;
    }
}

// ��ӡ����
void Print(SNode *pHead) {
    if (NULL == pHead) {
        printf("PrintList����ִ�У�����Ϊ��\n");
    } else {
        pHead = pHead->pNext; // ȥ����ͷ���
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

void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}
