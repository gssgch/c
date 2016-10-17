#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout

using namespace std;
/** �ַ���ѭ������
 * ���abcdef ǰ��ab�ƶ����ַ���β�������õ�cdefab
 * ѭ������n+kλ��kλ��Ч����ͬ
 * ѭ������kλ�ȼ���ѭ������n-kλ
 *
 * ������
 * ������λ��
 * ÿ��ѭ������1λ������k�μ��ɣ�ʱ�临�Ӷ�ΪO(kN) �ռ临�Ӷ�ΪO(1)
 *
 * ���ο�����
 *ʱ�临�Ӷ�ΪO(N) �ռ临�Ӷ�ΪO(k)
 *
 * ���η�ת��
 * ��x'y'��'=yx
 *  ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(1)

 */

//    ��������
void ReverseString(char *s, int from, int to);
void LeftRotateString(char *s, int n, int m);
//
int _tmain(int argc, _TCHAR *argv[]) {
    string  s("abcde");
//    char* s = {"a","b","c","d","e"};
//    printf("before��%s",s);
    ReverseString(s, 1, 3);
//    std:cout<<
//    LeftRotateString(s, 5, 2);
//            << std::endl;
    printf("end��%s",s);
    return 0;
}

void ReverseString(char *s, int from, int to) {
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void LeftRotateString(char *s, int n, int m) {
    m %= n;
    ReverseString(s, 0, m - 1);
    ReverseString(s, m, n - 1);
    ReverseString(s, 0, n - 1);

}
