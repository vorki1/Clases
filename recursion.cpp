#include <iostream>
#include <stack>
using namespace std;

void moverPila(stack<int> pila)
{
    if(!pila.empty())
    {
        cout<<pila.top()<<endl;
        pila.pop();
        moverPila(pila);
    }
}

int main()
{
    stack<int> pila,aux1,aux2;
    pila.push(10);
    pila.push(7);
    pila.push(4);
    pila.push(3);
    pila.push(1);
    moverPila(pila);
    return 0;
}