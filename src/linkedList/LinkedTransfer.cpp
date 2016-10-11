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
//    ��������
SNode *Reverse(pHead,4,8);
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
void Reverse(SNode *pHead,int from ,int to){
    SNode *pCur = pHead->pNext;
    int i;
    for (int j = 0; j <from-1 ; j++) {
        pHead=pCur;
        pCur = pCur->pNext;
    }
    SNode *pPre = pCur;
    pCur = pCur->pNext;
    to --;
    SNode *pNext;
    for (; k <to ; k++) {
        pNext = pCur->pNext;
        pCur-pNext = pHead->pNext;
        pHead->pNext=pCur;
        pPre->pNext=pNext;
        pCur=pNext;

    }

}

    /*SNode *head,*tail,*pnew;
    head->pNext=NULL;  //ͷ�ڵ�ָ������NULL
    tail=head;  // ��ʼʱβָ��ָ��ͷ�ڵ�
//    tail=pHead1;  // ��ʼʱβָ��ָ��ͷ�ڵ�
    int i;
    for (i = 0; i < 6; i++) {
        SNode *p = new SNode(i);
        tail->pNext=pnew;  //�½ڵ���뵽��β
        tail=pnew;   //Ϊָ��ָ��ǰ��β�ڵ�
    }*/



//    Print(pHead1);
//    Print(head);
    return 0;
}
// ��ӡ����
void Print(SNode *pHead) {
    if (NULL == pHead)   //
    {
        printf("PrintList����ִ�У�����Ϊ��\n");
    } else {
//        pHead= pHead->pNext; // ȥ����ͷ���
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
        p=next;
    }
}