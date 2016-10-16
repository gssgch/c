#include <stdio.h>
#include <tchar.h>
#include<stdlib.h>
#include<iostream> // cout
#include <cstring>  // memset�������
#include <stack>

using namespace std;
/**
 * �����沨�����ʽ
 * ������
 *  �����ǰ�ַ��ǲ���������ѹջ
 *  �����ǰ�ַ��ǲ��������򵯳�ջ�е��������������������Ȼѹ��ջ
 *      ��ĳ�β�����ջ���޷��������������������ʽ����
 */

//    ��������
int ReversePolishNotation(const char *str[],int size);
bool IsOperator(const char* token);

int _tmain(int argc, _TCHAR *argv[]) {
    const char *str[] ={"2","1","+","3","*"};
    int value =ReversePolishNotation(str, sizeof(str)/ sizeof(const char*));
    std::cout << value << std::endl;
    return 0;
}

int ReversePolishNotation(const char *str[],int size){
stack<int> s;
    int a,b;
    const char* token;
    for (int i = 0; i <size ; i++) {
        token=str[i];
        if(!IsOperator(token)){
            s.push(atoi(token));
        }else{
            b=s.top();
            s.pop();
            a=s.top();
            s.pop();
            if(token[0]=='+'){
                s.push(a+b);
            }else if(token[0]=='-'){
                s.push(a-b);
            }else if(token[0]=='*'){
                s.push(a*b);
            }else{ //  if(token[0]=='-')
                s.push(a/b);
            }
        }
    }
    return s.top();
}
// �ж��Ƿ������
bool IsOperator(const char* token){
    return ((token[0]=='+')||(token[0]=='-')||(token[0]=='*')||(token[0]=='/'));
}
