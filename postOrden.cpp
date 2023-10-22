#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool op(string op)
{
    if(op=="+" || op=="-" || op=="*" || op=="/")
    {
        return true;
    }
    return false;
}

int evalPost(vector<string> postFix)
{
    stack<int> valores;
    int num1,num2;
    stack<string> operacion;
    for (string elemento:postFix)
    {
        if(op(elemento))
        {
            num2 = valores.top();
            valores.pop();
            num1 = valores.top();
            valores.pop();

            if(elemento=="+")
            {
                valores.push(num1+num2);
            }
            else if(elemento=="-")
            {
                valores.push(num1-num2);
            }
            else if(elemento=="*")
            {
                valores.push(num1*num2);
            }
            else if(elemento=="/")
            {
                valores.push(num1/num2);
            }

        }
        else
        {
            valores.push(stoi(elemento));
        }
    }
    return valores.top();
    
}

int main()
{
    vector<string> postfix = {"3","4","+","5","*"};
    int result = evalPost(postfix);
    cout<<result<<endl;
}