#include <stdio.h>
#include <tchar.h>
#include<queue>

/**
 *  �������޻�ͼ������������  ��ͼ�����ж����������������
 *  ������
 *  ѡ��һ��û��ǰ�������Ϊ0���Ķ��㲢�������
 *  ������ɾȥ�ö��㣬����ɾȥ�Ӹö��㷢����ȫ�������
 *  �ظ�����������ֱ��ʣ������в��ٴ���û��ǰ���Ķ���Ϊֹ
 *
 *  ��������������
 */
typedef struct tagSNode {
    int value;
    tagSNode *pNext;

    tagSNode(int v) : value(v), pNext(NULL) {}
} SNode;

//    ��������


int _tmain(int argc, _TCHAR *argv[]) {

    return 0;
}
// �����Ϊn����������gragh[n][n] �洢��Ȩ��
// ��indegree[n]�洢ÿ���������
void topologic(int* toposort){
    int cnt =0; // ��ǰ���������б����ж��ٽ��
    queue<int> q;  // �������Ϊ0�Ľ�㣬��������ջ�������ȡ
    int i;
    for (i = 0;  i<n ; i++) {
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cur; // ��ǰ���Ϊ0�Ľ��
    while (!q.empty()){
        cur =q.front();
        q.pop();
        toposort[cnt++] = cur;
        for (i = 0;  i< n; i++) {
            if(gragh[cur][i]!=0){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
    }
}
