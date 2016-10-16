#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream>
#include <stack>
#include<vector>

using namespace std;
/**
 * ֱ��ͼ��������
 * ����n���Ǹ���������ʾֱ��ͼ�ķ����ĸ߶ȣ�ͬʱ��ÿ�������Ŀ�ȼٶ���Ϊ1��
 * ���ҳ�ֱ��ͼ�����ľ��������
 *
 * ������
 * �������
 * ʱ�临�Ӷ�ΪO(N^2)
 * ���a[i+1]>= a[i] ����a[i]Ϊ�ұ߽�ľ��Σ��ܿ������a[i+1]�����ľ��Σ�ʹ���������
 * ֻ��a[i+1]<a[i]ʱ���ż���a[i]Ϊ�ұ߽�ľ������
 *     Ϊ���㷨һ���ԣ���������a[size]=0,��֤a[size-1]Ϊ�ұ߽�ľ��εõ�����
 *
 */

//    ��������
int LargestRectangleArea(vector<int>& height);

// ������ԵĽ�����ԣ�����ԭ��δ֪��
int _tmain(int argc, _TCHAR *argv[]) {
    vector<int> ivec(5); //2,7,5,6,4
    ivec.push_back(2);
    ivec.push_back(7);
    ivec.push_back(5);
    ivec.push_back(6);
    ivec.push_back(4);
    int value =LargestRectangleArea(ivec);
    std::cout << value << std::endl;
    return 0;
}

int LargestRectangleArea(vector<int>& height){
    height.push_back(0);// ȷ��ԭ����height�����һλ�ܹ��õ�����

    stack<int> s;
    int answer=0;
    int temp;
    for (int  i = 0;  i < (int)height.size();) {
        printf("\n=%d",(int)height.size());
        if(s.empty()||height[i]>height[s.top()]){
            s.push(i);
            i++;
        }else{
            temp=s.top();
            s.pop();
            answer=max(answer,height[temp]*(s.empty()?i:i-s.top()-1));
        }
    }
    return answer;
}
