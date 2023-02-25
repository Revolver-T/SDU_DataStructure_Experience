#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

int cuclt(int x, int y, char c){
    int result = 0;
    if(c == '*')
        result = x*y;
    if(c == '/')
        result = x/y;
    if(c == '+')
        result = x+y;
    if(c == '-')
        result = x-y;

    return result;
    
}

int main()
{
    stack<int> s1;
    stack<int> s2;

    map<int,int> m;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m['('] = 0;

    char obj[100];
    cout << "Input" << endl;
    cin >> obj;

    int len = strlen(obj), i = 0;
    while(i < len){
        if(obj[i] >='0' && obj[i] <='9'){//数字处理
            int num = 0;
            while(obj[i] >='0' && obj[i] <= '9'){
                num = num*10 + obj[i] -'0';
                i++;
            }
            s1.push(num);
        }
        else{//符号位处理
            if(obj[i] =='(')
                s2.push(obj[i]);

            else if(obj[i] == ')'){
                while(s2.top() != '('){
                    int t = s2.top();s2.pop();
                    int x = s1.top();s1.pop();
                    int y = s1.top();s1.pop();

                    s1.push(cuclt(y,x,t));
                }
                s2.pop();
            }
            else{
                while(s2.size() > 0 && m[s2.top()] >= m[obj[i]]){
                    int t = s2.top();s2.pop();
                    int x = s1.top();s1.pop();
                    int y = s1.top();s1.pop();
                    s1.push(cuclt(y,x,t));
                }
                s2.push(obj[i]);
            }
            i++;
        }
    }

    while(s2.size()){
        int t = s2.top();s2.pop();
        int x = s1.top();s1.pop();
        int y = s1.top();s1.pop();
        s1.push(cuclt(y,x,t));
    }

    cout << "Output" << endl;
    cout << s1.top() << endl;
    cout << "End";
    system("pause");
    return 0;
}