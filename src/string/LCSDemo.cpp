#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include<vector>
#include<cstring>
#include <algorithm>

using namespace std;
/**
 *  �����������(Subsequence)   ��Ҫ����������Ҫ��˳��
 *
 *  ����������Ӵ�����Longest Common SubString��
 *  ������Ӵ�Ҫ������
 */

//    ��������
void LCS(const char *s1, const char *s2, string &str);

//
int _tmain(int argc, _TCHAR *argv[]) {
    const char *str1 = "TCGGATCGACTT";
    const char *str2 = "AGCCTACGTA";
    string str;
    LCS(str1, str2, str);
    std:
    cout << str.c_str() << std::endl;
    return 0;
}

void LCS(const char *str1, const char *str2, string &str) {
    int size1 = (int) strlen(str1);
    int size2 = (int) strlen(str2);
    const char *s1 = str1 - 1; // ��1 ��ʼ�����������Ĵ����д
    const char *s2 = str2 - 1;
    vector<vector<int>> chess(size1 + 1, vector<int>(size2 + 1));
    int i, j;
    for (i = 0; i < size1; i++) { // ��0��
        chess[i][0] = 0;
    }
    for (j = 0; j < size2; j++) { // ��0��
        chess[0][j] = 0;
    }
    for (i = 1; i <= size1; i++) {
        for (j = 1; j <= size2; j++) {
            if (s1[i] == s2[j]) { // ���  ���Ͻ�+1
                chess[i][j] = chess[i - 1][j - 1] + 1;
            } else {  // �����  // ȡ��ߺ��ϱ߽ϴ���
                chess[i][j] = max(chess[i][j - 1], chess[i - 1][j]);
            }
        }
    }
    i = size1;
    j = size2;
    while ((i != 0) && (j != 0)) {  // ���ݣ�һֱ����0�л��ߵ�0��
        if (s1[i] == s2[j]) {
            str.push_back(s1[i]);
            i--;
            j--;
        } else {
            if (chess[i][j - 1] > chess[i - 1][j]) { // ��ߴ����ϱߣ��м�
                j--;
            } else {
                i--;
            }
        }
    }
    // ��ת���ݽ������
    reverse(str.begin(), str.end());
}