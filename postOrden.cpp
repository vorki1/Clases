#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int evalPost(vector<string> postFix)
{
    stack<int> resultado;
    stack<string> operacion;
    for (string elemento:postFix)
    {
        /* code */
    }
    
    
}

int main()
{
    vector<string> postfix = {"3","4","+","5","*"};
    int result = evalPost(postfix);
}