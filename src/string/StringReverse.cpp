#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<cstring>
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
// ʵ�����н������
int _tmain(int argc, _TCHAR *argv[]) {
    char str[] = "abcde";
//    char *str = "abcde";
    printf("before:%s",str);
    LeftRotateString(str, sizeof(str) / sizeof(char), 2);
//    cout << str.c_str() << std::endl;
    printf(str);
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
