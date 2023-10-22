#include <iostream>

using namespace std;

class Figura
{
    private:
        
        int numLados;
    public:
        Figura(int numLados)
        {
            this->numLados=numLados;
        }
        int getNumLados()
        {
            return numLados;
        }
        void setNumLados(int numLados)
        {
            this->numLados=numLados;
        }
};

class Nodo
{
    private:
        Figura* figura;
        Nodo* next;
    public:
        Nodo(int numLados)
        {
            figura = new Figura(numLados);
            next = nullptr;
        }
        Figura* getFigura()
        {
            return figura;
        }
        Nodo* getNext()
        {
            return next;
        }
        void setNext(Nodo* nodo)
        {
            next = nodo;
        }
        
};
class Lista
{
    private:
        Nodo* first,*last;
    public:
        Lista()
        {
            first = nullptr;
            last = nullptr;
        }
        void insertar(int lados)
        {
            Nodo* nuevo = new Nodo(lados);
            if(first == nullptr)
            {
                first = nuevo;
                last = nuevo;
                first->setNext(last);
                last->setNext(first);
                return;
            }
            else
            {
                nuevo->setNext(first);
                last->setNext(nuevo);
                last = nuevo;
                return;
            }
        }
        void insertar2(int lados)
        {
            Nodo*nuevo = new Nodo(lados);
            if(first==nullptr)
            {
                first=nuevo;
                last=nuevo;
                first->setNext(last);
                last->setNext(first);
            }
            else
            {
                if(nuevo->getFigura()->getNumLados()<first->getFigura()->getNumLados())
                {
                    nuevo->setNext(first);
                    last->setNext(nuevo);
                    first=nuevo;
                }
                else
                {
                    Nodo* actual = first;
                    Nodo* anterior = actual;
                    while(lados>=actual->getFigura()->getNumLados() && actual->getNext()!=first)
                    {
                        anterior = actual;
                        actual = actual->getNext();
                    }
                    if(lados>=actual->getFigura()->getNumLados())
                    {
                        actual->setNext(nuevo);
                        nuevo->setNext(first);
                        last=nuevo;
                    }
                    else
                    {
                        anterior->setNext(nuevo);
                        nuevo->setNext(actual);
                    }
                }
            }
        }
        void mostrarDatos()
        {
            Nodo* actual = first;
            if(actual == nullptr)
            {
                cout<<"No hay datos que mostrar"<<endl;
                return;
            }
            do
            {
                cout<<actual->getFigura()->getNumLados()<<endl;
                actual=actual->getNext();
            } while (actual!=first);
            
        }
        void ordenarDatos()
        {
            Nodo* actual = first;
            Nodo* siguiente;
            int num;
            do
            {
                siguiente= actual->getNext();

                do
                {
                    if(actual->getFigura()->getNumLados()>siguiente->getFigura()->getNumLados())
                    {
                        int num =actual->getFigura()->getNumLados();
                        actual->getFigura()->setNumLados(siguiente->getFigura()->getNumLados());
                        siguiente->getFigura()->setNumLados(num);   
                    }
                    siguiente = siguiente->getNext();
                } while (siguiente!=first);
                actual = actual->getNext();
                siguiente = actual->getNext();
                
            } while (actual!=first);
            if(first->getFigura()->getNumLados()>last->getFigura()->getNumLados())
            {
                int num =first->getFigura()->getNumLados();
                    first->getFigura()->setNumLados(last->getFigura()->getNumLados());
                    last->getFigura()->setNumLados(num);   
            }
            
        }
};



int main()
{
    Lista* lista = new Lista();
    lista->insertar(5);
    lista->insertar(3);
    lista->insertar(7);
    lista->insertar(9);
    int option;
    do
    {
        int lados;
        cout<<"Ingrese una opcion: "<<endl;
        cout<<"Opción 1 insertar: "<<endl;
        cout<<"Opción 2 mostrar datos: "<<endl;
        cout<<"Opción 3 ordenar: "<<endl;
        cout<<"Opción 5 salir: "<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Ingrese los lados de la figura: "<<endl;cin>>lados;
            lista->insertar2(lados);
            break;
        case 2:
            cout<<"Los datos son:"<<endl;
            lista->mostrarDatos();
            break;
        case 3:
            lista->ordenarDatos();
            break;
        case 5:
            cout<<"Termino el programa"<<endl;
            break;
        default:
            cout<<"Ingresa un valor valido!!"<<endl;
            break;
        }
    } while (option != 5);
    
    
    
    return 0;
}