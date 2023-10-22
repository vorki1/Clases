#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Plato
{
    private:
        int nOrden,preferencia,prioridad;
    public:
        Plato(int nOrden,int preferencia)
        {
            this->nOrden=nOrden;
            this->preferencia=preferencia;
            prioridad = 0;
        }
        int getNOrden()
        {
            return nOrden;
        }
        int getPreferencia()
        {
            return preferencia;
        }
        int getPrioridad()
        {
            return prioridad;
        }
        void setPrioridad(int p)
        {
            prioridad=p;
        }
};

stack<Plato> calcularPrioridad(stack<Plato> src)
{
    stack<Plato> aux;
    int cantP1 = 0;
    int cantP2 = 0;
    while (!src.empty())
    {
        if(src.top().getNOrden()==1)
        {
            aux.push(src.top());
            src.pop();
            cantP1++;
        }
        else if(src.top().getNOrden()==2)
        {
            aux.push(src.top());
            src.pop();
            cantP2++;
        }
    }
    while (!aux.empty())
    {
        if(aux.top().getNOrden()==1)
        {
            aux.top().setPrioridad(cantP1*aux.top().getPreferencia());
            src.push(aux.top());
            aux.pop();
        }
        else if(aux.top().getNOrden()==2)
        {
            aux.top().setPrioridad(cantP2*aux.top().getPreferencia());
            src.push(aux.top());
            aux.pop();
        }
    }
    return src;
    
    
}

int main()
{
    stack<Plato> src,s1,s2;
    queue<Plato> salida;
//                       prioridad
    src.push(Plato(1,2));//4
    src.push(Plato(2,2));//2
    src.push(Plato(1,3));//6
    src = calcularPrioridad(src);

    s1.push(src.top());
    src.pop();
    while (!src.empty())
    {
        if(src.top().getPrioridad()<s1.top().getPrioridad())
        {
            s1.push(src.top());
            src.pop();
        }
        else
        {
            while (!s1.empty()) //src.top().getPrioridad()<s1.top().getPrioridad()
            {
                if(src.top().getPrioridad()>s1.top().getPrioridad())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                else
                {
                    break;
                }               
            }
            s1.push(src.top());
            src.pop();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            
        }
        
    }
    while (!s1.empty())
    {
        salida.push(s1.top());
        s1.pop();
    }
    while(!salida.empty())
    {
        cout<<salida.front().getPrioridad()<<endl;
        salida.pop();
    }
    
    return 0;
}