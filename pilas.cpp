#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> pila,aux;
    pila.push("Cap");
    pila.push("batman");
    pila.push("Iron man");
    pila.push("Tanos");
    pila.push("Tanos");
    pila.push("Spiderman");
    pila.push("batman");
    pila.push("Cap");
    pila.push("Tanos");
    pila.push("Spiderman");
    pila.push("Iron man");
    pila.push("batman");
    pila.push("Iron man");
    pila.push("batman");
    pila.push("Cap");
    pila.push("Tanos");
    pila.push("Spiderman");
    pila.push("Spiderman");
    pila.push("Spiderman");
    pila.push("batman");
    pila.push("Cap");
    pila.push("Tanos");
    pila.push("Spiderman");
    pila.push("Iron man");
    pila.push("batman");
    int cantIron = 0;
    int cantCap = 0;
    int cantTanos = 0;
    int cantSpiderman = 0;
    int cantTotal = 0;
    int mayor = -10;
    string nameMayor;
    string superHero;
    while (!pila.empty())
    {
        superHero = pila.top();

        if(superHero.compare("batman")==0)
        {
            pila.pop();
            
            cantTotal++;
        }
        else
        {
            if(superHero.compare("Iron man")==0)
            {
                aux.push(superHero);
                pila.pop();
                cantIron++;
                if(cantIron>mayor)
                {
                    mayor = cantIron;
                    nameMayor = superHero;
                }
                cantTotal++;
            }
            else if(superHero.compare("Cap")==0)
            {
                aux.push(superHero);
                pila.pop();
                cantCap++;
                
                if(cantCap>mayor)
                {
                    mayor = cantCap;
                    nameMayor = superHero;
                }
                cantTotal++;
            }
            else if(superHero.compare("Tanos")==0)
            {
                aux.push(superHero);
                pila.pop();
                cantTanos++;
                
                if(cantTanos>mayor)
                {
                    mayor = cantTanos;
                    nameMayor = superHero;
                }
                cantTotal++;
            }
            else if(superHero.compare("Spiderman")==0)
            {
                aux.push(superHero);
                pila.pop();
                cantSpiderman++;
                
                if(cantSpiderman>mayor)
                {
                    mayor = cantSpiderman;
                    nameMayor = superHero;
                }
                cantTotal++;
            }
        }
    }
    cout<<"El super heroe más popular es: "<<nameMayor<<" con "<<mayor<<" votos"<<endl;
    cout<<"El superHero del primer fan es: "<<aux.top()<<endl;
    cout<<"La cantidad total de votos es: "<<cantTotal<<endl;
    
    return 0;
}