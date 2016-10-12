#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  ������룬ͷ�巨��β�巨
 */

typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

// ��������
void Print(SNode *pHead);

void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {

    // ͷ�巨
    SNode *pHead;
    int i;
    pHead = NULL;
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(i);
        if (pHead == NULL) {
            pHead = p;
        } else {
            p->pNext = pHead->pNext;
            pHead->pNext = p;
        }
    }
    printf("ͷ�巨��\n");
    Print(pHead);

    // ����Ǽ򵥵Ĳ��ԣ����Ե���ѭ����ʹ��ͷ�巨���õ���β�巨һ���Ľ����
/*    SNode *pHead = new SNode(0);
    for (i = 10; i >0; i--) {
    SNode *p = new SNode(i);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);*/

    // β�巨
    pHead = NULL;
    SNode *end;
    end = NULL; // βָ����Ϊ��
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(i);
        if (pHead == NULL) {
            pHead = p;
        } else {
            end->pNext = p;
        }
        end = p;
    }
    if (end != NULL){
        end->pNext = NULL;
    }
    Print(pHead);
    return 0;
}

// ��ӡ����
void Print(SNode *pHead) {
    if (NULL == pHead)
    {
        printf("PrintList����ִ�У�����Ϊ��\n");
    } else {
        pHead = pHead->pNext; // ȥ����ͷ���0
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
