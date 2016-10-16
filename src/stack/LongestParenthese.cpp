#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include <cstring>  // memset�������
#include <stack>

using namespace std;
/**
 * �����ƥ��
 * �����ַ��� �����������ź������ţ����ܲ�������ƥ��ģ�����㷨
 * �ҳ��ƥ��������Ӵ������ظ��Ӵ�����
 * ������
 * ����ʼƥ��λ��start=-1 ���ƥ�䳤��ml=0
 * �����iλ�ַ�c
 * ���cΪ�����ţ�ѹջ
 * ���cΪ�����ţ���һ����ջ��������ƥ�䣬
 *      ���ջΪ�գ���ʾû��ƥ��������ţ�start=i��Ϊ��һ�ο��ܵ�ƥ����׼��
 *      ���ջ���գ���ջ��ƥ�����ˣ�
 *          ���ջΪ�գ�i-start��Ϊ��ǰ�ҵ���ƥ�䳤�ȣ����i-start�Ƿ��ml����ʹ��ml���Ը���
 *          ���ջ���գ���ǰջ��Ԫ��t���ϴ�ƥ������λ�ã����i-t�Ƿ��ml��ʹ��ml���Ը���
 *
 * ��Ϊ��ջ��һ���������ţ�����Ҫ��������ջ����ջ�ַ��������ͺ���

 */

//    ��������
int GetLongestParenthese(const char *p);
int GetLongestParenthese2(const char *p);

int _tmain(int argc, _TCHAR *argv[]) {
    const char *wang = "()()()";
    std::cout << GetLongestParenthese(wang) << std::endl;
    return 0;
}

// �ռ临�Ӷ�ΪO(N) ʱ�临�Ӷ�ΪO(N)
int GetLongestParenthese(const char *p) {
    int size = (int) strlen(p);
    stack<int> s;
    int answer = 0; // ���ս��
    int start = -1; // �����ŵ�ǰһ��λ��

    for (int i = 0; i < size;i++) {
        if (p[i] == '(') {
            s.push(i);
        } else { // p[i] == ')'
            if (s.empty()) {
                start = i;
            } else {
                s.pop();
                if (s.empty()) {
                    answer = max(answer, i - start);
                } else {
                    answer = max(answer, i - s.top());
                }
            }
        }
    }
        return answer;
}

 // �ռ临�Ӷ�O(1) ʱ�临�Ӷ�ΪO(N)
int GetLongestParenthese2(const char *p) {
    int size = (int) strlen(p);
    int answer = 0; // ���ս��
    int deep = 0; // �����˶���������
    int start = -1; // �����deep==0ʱ�����ŵ�λ��
    // ��ʵΪ�˷�����㳤�ȣ��ñ��������������ŵ�ǰһ��λ��
    int i;
    for (int i = 0; i < size; i++) {
        if (p[i] == '(') {
            deep++;
        } else { // p[i] == ')'
            deep--;
            if (deep == 0) {
                answer = max(answer, i - start);
            } else if (deep < 0) { // ˵����������Ŀ���������ţ���ʼ��Ϊforѭ��ǰ
                deep = 0;
                start = i;
            }
        }
    }
    deep = 0; // �����˶���������
    start = size; // ����ģ�deep==0ʱ�������ŵ�λ��
    // Ϊ�˷�����㳤�ȣ��ñ��������������ŵĺ�һ��λ��
    for (i = size - 1; i >= 0; i--) {
        if (p[i] == ')') {
            deep++;
        } else { // p[i] == ')'
            deep--;
            if (deep == 0) {
                answer = max(answer, i - start);
            } else if (deep < 0) { // ˵����������Ŀ���������ţ���ʼ��Ϊforѭ��ǰ
                deep = 0;
                start = i;
            }
        }
    }
    return answer;
}
