#include <tchar.h>
#include<stdlib.h>

#ifndef GSSGC_CBINARYTREE_H
#define GSSGC_CBINARYTREE_H

typedef struct tagSTreeNode {
    int value;
    tagSTreeNode *pLeft;
    tagSTreeNode *pRight;

    tagSTreeNode(int v) : value(v), pLeft(NULL), pRight(NULL) {};
} STreeNode;

typedef void (*VISIT)(int value);

class CBinaryTree {
private:
    STreeNode *m_pRoot;
private:
    void Destroy();

    bool _Insert(STreeNode *&pRoot, int value); // �ݹ�
    bool _Insert2(int value); // �ǵݹ�
    bool _PreOrder(STreeNode *pRoot, VISIT visit) const; // �ݹ�
    void _PreOrder2(VISIT visit) const; // �ǵݹ�
    bool _InOrder(STreeNode *pRoot, VISIT visit) const; // �ݹ�
    void _InOrder2(VISIT visit) const; // �ǵݹ�
    void _InOrder3(VISIT visit) const; // �ǵݹ�
    bool _PostOrder(STreeNode *pRoot, VISIT visit) const; // �ݹ�
    void _PostOrder2(VISIT visit) const; // �ǵݹ�
    bool _DeleteChindIess(STreeNode *pParent, STreeNode *pNode) const; // pNode����
    bool _DeleteSingleSon(STreeNode *pParent, STreeNode *pNode) const; // pNode��pParentΨһ���


public:
    CBinaryTree();

    ~CBinaryTree();

    bool Insert(int value);

    bool Delete(int value);

    STreeNode* Find(int value) const;

    void PreOrder(VISIT visit) const;

    void InOrder(VISIT visit) const;

    void PostOrder(VISIT visit) const;

};

#endif //GSSGC_CBINARYTREE_H
