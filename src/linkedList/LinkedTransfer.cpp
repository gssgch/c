#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>

/**
 *  �����ַ�ת
 *  ����һ��������ת�������m��n��λ�ã�Ҫ��ֱ�ӷ�ת���������¿ռ䡣
 *   ʱ�临�Ӷ� O(n)  �ռ临�Ӷ� O(1)
 *   ������
 *   ��תm-1�Σ��ҵ���m-1����㣬����ʼ��ת�ĵ�һ������ǰ������סhead
 *   ��headΪ��ʼ������n-m�Σ���i��ʱ�����ҵ��Ľ����뵽head��next�м��ɡ� ��ͷ�巨
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;
    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

// ��������
void Reverse(SNode *pHead, int a, int b);

void Print(SNode *pHead);

void Destroy(SNode *pHead);

int _tmain(int argc, _TCHAR *argv[]) {

    SNode *pHead = new SNode(0);
    int i;
    for (i = 0; i < 10; i++) {
        SNode *p = new SNode(rand() % 100);
        p->pNext = pHead->pNext;
        pHead->pNext = p;
    }
    Print(pHead);
    Reverse(pHead, 4, 7); //���߶�����
    Print(pHead);
    Destroy(pHead);
    return 0;
}

/**
 * ��ת����
 * @param pHead
 * @param from
 * @param to
 * @return
 */
void Reverse(SNode *pHead, int from, int to) {
    SNode *pCur = pHead->pNext;
    int i;
    for (i = 0; i < from - 1; i++) { // ��ת m-1��
        pHead = pCur;
        pCur = pCur->pNext;
    }
    // ��ת������pCur��m��λ��
    // pHead��λ����m-1��λ�ã���m��ǰһλ

    SNode *pPre = pCur;
    SNode *pNext;
    printf("\n000,pHead=%d,pPre=%d,pCur=%d,pNext=%d",  pHead->value,pPre->value,pCur->value,pNext->value);
    // ѭ��ǰ��pPre��pCur����m�������滻�ĵ�һλ��
    pCur = pCur->pNext; // pCur����һ������Ϊ��Ҫ��m����һλ����ʼ��ǰ��
    to--; // n-m-1���滻����

    /** ������滻n-m-1�Σ�����˵��ת����������ѭ���滻����
     *  ����toҪ��-- ���Ա�֤ѭ���Ĵ�����ȷ
     */

    for (; i < to; i++) {
        pNext = pCur->pNext;  // pNextָ����һλ�� ��һ��ʱ��pPre��m��,pCur��m+1��,pNext��m+2������pCur��ת��pPre��ǰ��
        printf("\n111,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pCur->pNext = pHead->pNext; // ��pCur��ָ��ָ��pHead
        printf("\n222,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pHead->pNext = pCur; // ��ֵ
        printf("\n333,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pPre->pNext = pNext; // pPre��ָ��ָ��pNext
        printf("\n444,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
        pCur = pNext; // pNext��ֵ��pCur
        printf("\n555,pHead=%d %d,pPre=%d,pCur=%d,pNext=%d",pHead->value,pHead->pNext,pPre->value,pCur->value,pNext->value);
    }
}

// ��ӡ����
void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
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

// ��ʦ��destroy
void Destroy(SNode *p) {
    SNode *next;
    while (p) {
        next = p->pNext;
        delete p;
        p = next;
    }
}