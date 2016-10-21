#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 *  ������������
 *  �������飬Ԫ��ֻ��ȡ0 1 2 ����ֵ������㷨��ʹ�����鰴������ֵ����
 *  eg:00...0011...1122...22
 */

//    ��������
void Print(int *p, int size);

void Holland1(int *a, int length);

void Holland2(int *a, int length);

void Holland3(int *a, int length);
void HollandRe(int *a, int length);

//
int _tmain(int argc, _TCHAR *argv[]) {
    int a[] = {0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2,};
    int size = sizeof(a) / sizeof(int);
    Print(a, size);
//    Holland1(a, size);
//    Holland2(a, size);
//    Holland3(a, size);
    HollandRe(a, size);
    Print(a, size);
    return 0;
}

void Holland1(int *a, int length) {
    int begin = 0;
    int current = 0;
    int end = length - 1;
    while (current <= end) {
        if (a[current] == 2) {
            swap(a[end], a[current]);
            end--;
        } else if (a[current] == 1) {
            current++;
        } else { // if(a[current==0])
            if (begin == current) {
                begin++;
                current++;
            } else {
                swap(a[current], a[begin]);
                begin++;
            }
        }
    }
}

// ������ģ�
void Holland2(int *a, int length) {
    int begin = 0;
    int current = 0;
    int end = length - 1;
    while (current <= end) {
        if (a[current] == 2) {
            swap(a[end], a[current]);
            end--;
        } else if (a[current] == 1) {
            current++;
        } else { // if(a[current==0])
            if (begin == current) {
                begin++;
                current++;
            } else {
                swap(a[current], a[begin]);
                begin++;
                current++;
            }
        }
    }
}

// ���յ�
void Holland3(int *a, int length) {
    int begin = 0;
    int current = 0;
    int end = length - 1;
    while (current <= end) {
        if (a[current] == 2) {
            swap(a[end], a[current]);
            end--;
        } else if (a[current] == 1) {
            current++;
        } else { // if(a[current==0])
            // 1, ʹ�� if�ж�
            // 2,��Ϊ���ȵĴ���ԶԶ������ȵĴ���������ֱ��ɾ��if�жϣ���Ϊ��ȵ�ʱ��Ҳ����ֱ�ӽ���
            if (current != begin) {
                swap(a[current], a[begin]);
            }
            begin++;
            current++;
        }
    }
}

// ��ת current��end����ʼ�ƶ�
void HollandRe(int *a, int length) {
    int begin = 0;
    int end = length - 1;
    int current = end;
    while (current >= begin) {
        if (a[current] == 2) {
            swap(a[end], a[current]);
            end--;
            current--;
        } else if (a[current] == 1) {
            current--;
        } else { // if(a[current==0])
            swap(a[current], a[begin]);
            begin++;
        }
    }
}

void Print(int *p, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << p[i] << ' ';
    }
    std::cout << std::endl;
}