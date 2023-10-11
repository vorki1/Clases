#include <iostream>
#include <stack>
#include "Camion.hpp"
using namespace std;

int main()
{
    Camion* c1 = new Camion(20,"1");
    Camion* c2 = new Camion(13,"2");
    Camion* c3 = new Camion(3,"3");
    Camion* c4 = new Camion(7,"4");
    Camion l = Camion(2,"1");//Asi se crea un objeto estatico
    stack<Camion*> pila;
    pila.push(c1);
    pila.push(c2);
    pila.push(c3);
    pila.push(c4);
    stack<Camion*> sAux1;
    stack<Camion*> sAux2;


    
    if(pila.empty())
    {
        cout<<"la pila esta vacia";
    }
    else
    {
    while(!pila.empty())
    {
        if(sAux1.empty())
        {
            sAux1.push((pila.top()));
            pila.pop();
        }
        else
        {
            if(pila.top()->getPeso()<sAux1.top()->getPeso())
            {
                sAux1.push((pila.top()));
                pila.pop();
            }
            else
            {
                while(pila.top()->getPeso()<sAux1.top()->getPeso() || sAux1.empty())
                {
                    sAux2.push(sAux1.top());
                    sAux1.pop();
                }
                sAux1.push(pila.top());
                pila.pop();
                while(!sAux2.empty())
                {
                    sAux1.push(sAux2.top());
                    sAux2.pop();
                }
            }
        }
    }
    
    }
    
    return 0;
}