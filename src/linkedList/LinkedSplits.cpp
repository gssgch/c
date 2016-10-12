#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  ���򻮷�
 *  ����һ�������һ��ֵx���������ֳ������֣�ʹ�û��ֺ�С��x�Ľ����ǰ��
 *  ���ڵ���x�Ľ�����ң�������������Ҫ����ԭ�����еĳ���˳��
 *  ������
 *  ��������ָ��p1��p2��С��x����ӵ�p1����������ӵ�p2�����p2���ӵ�p��ĩ�˼��ɡ�
 *
 *  ʱ�临�Ӷ���O(N),�ռ临�Ӷ���O(1)
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    ��������
void Partition(SNode *pHead,int pivotKey);
void Print(SNode *pHead);
void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {
    SNode *pHead = new SNode(0);
    pHead->pNext=NULL;
    for (int i = 0; i < 10; i++) {
        SNode *p = new SNode(rand()%100);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    Partition(pHead,50);
    Print(pHead);
    Destroy(pHead);
    return 0;
}

//
void Partition(SNode *pHead,int pivotKey) {
    // ���������ͷָ��
    SNode *pLeftHead = new SNode(0);
    SNode *pRightHead = new SNode(0);

    // ��������ĵ�ǰ���һ��Ԫ��
    SNode* left = pLeftHead;
    SNode* right = pRightHead;
    SNode* p = pHead->pNext;
    while (p) { // ����ԭ����
        if(p->value<pivotKey){
            left->pNext=p;
            left=p;
        } else{
            right->pNext=p;
            right=p;
        }
        p=p->pNext;
        // ��right���ӵ�leftβ��
        left->pNext=pRightHead->pNext;
        right->pNext=NULL;

        // ������õ�����ֵ����ǰ����ͷ��
        pHead->pNext=pLeftHead->pNext;

        delete pLeftHead;
        delete pRightHead;
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
