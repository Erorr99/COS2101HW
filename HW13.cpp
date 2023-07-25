//ป้อน เปลี่ยน postfix เป็น infix

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string postfix;
    stack<string> s;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op2 + postfix[i] + op1 + ")";
            s.push(temp);
        }
        else
        {
            string temp = "";
            temp += postfix[i];
            s.push(temp);
        }
    }
    cout << "Infix expression: " << s.top() << endl;
    return 0;
}
