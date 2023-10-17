#include <iostream>
using namespace std;
struct Nodo
{
    int dato;
    Nodo* next;
}*primero,*ultimo;

void insertar();
void desplegarLista();
void buscarNodo();
void modificar();
void eliminar();
void ordenar();

int main()
{
    int option;
    do
    {
        cout<<"\n|-------------------------|";
        cout<<"\n|----Ingrese una opcion:--|";
        cout<<"\n|------------|------------|";
        cout<<"\n| 1.Ingresar | 4.Eliminar |";
        cout<<"\n| 2.Buscar   | 5.Desplegar|";
        cout<<"\n| 3.Modificar| 6.Salir    |";
        cout<<"\n|------------|------------|";
        cout<<"\nEscoja una opcion: ";cin>>option;

        switch (option)
        {
        case 1:
            insertar();
            break;
        case 2:
            buscarNodo();
            break;
        case 3:
            modificar();
            break;
        case 4:
            eliminar();
            break;
        case 5:
            desplegarLista();
            break;
        case 6:
            option = 6;
            cout<<"\nHas salido del programa"<<endl;
            break;
        default:
            cout<<"Ingrese una opción valida"<<endl;
            break;
        }
    } while (option!=6);
    
    return 0;
}



void insertar()
{
    Nodo* nuevo = new Nodo();
    cout<<"Ingrese un dato para el nuevo nodo: ";cin>>nuevo->dato;
    if(primero==nullptr)
    {
        primero = nuevo;
        primero->next = primero;
        ultimo = primero;
    }
    else
    {
        ultimo->next = nuevo;
        nuevo->next=primero;
        ultimo = nuevo;
    }
    cout<<"Nodo ingresado"<<endl;
}
void desplegarLista()
{
    Nodo * actual = new Nodo();
    actual = primero;
    if(actual!=nullptr)
    {
        do
        {
            cout<<actual->dato<<endl;
            actual=actual->next;
        } while (actual!=primero);
        
    }
    else
    {
        cout<<"La lista se encuentra vacia"<<endl;
    }
}

void buscarNodo()
{
    int valor;
    int posicion = 1;
    Nodo* actual = primero;
    if(actual==nullptr)
    {
        cout<<"La lista Esta vacia";
        return;
    }
    else
    {
        cout<<"Ingrese el valor que desea encontrar"<<endl;cin>>valor;
        do
        {
            if(valor==actual->dato)
            {
                cout<<"Dato: "<<actual->dato<<" En la posicion: "<<posicion<<endl;
                return;
            }
            
            actual=actual->next;
            posicion++;
        } while (actual!=primero);
        
    }
    cout<<"El valor no existe en la lista circular"<<endl;
}

void modificar()
{
    int datoBuscar,datoModificar;
    Nodo* actual = primero;
    if(actual ==nullptr)
    {
        cout<<"La lista esta vacia"<<endl;
    }
    else
    {
        cout<<"Ingrese el valor que desea buscar"<<endl;cin>>datoBuscar;
        do
        {
            if(actual->dato==datoBuscar)
            {
                cout<<"Ingrese el nuevo dato"<<endl;cin>>datoModificar;
                actual->dato=datoModificar;
                return;
            }  
            actual = actual->next;
        } while (actual!=primero);
        cout<<"El dato ingresado no existe"<<endl;
    }
}

void eliminar()
{
    Nodo* actual,*anterior;
    actual = primero;
    int datoEliminar;
    if(actual==nullptr)
    {
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    else
    {
        cout<<"Ingrese el valor que desea eliminar"<<endl;cin>>datoEliminar;
        do
        {
            if(actual->dato==datoEliminar)
            {
                if(actual==primero)
                {
                    primero=primero->next;
                    ultimo->next=actual->next;
                    cout<<"El valor estaba de los primeros"<<endl;
                    return;
                }
                else if(actual==ultimo)
                {
                    ultimo=anterior;
                    anterior->next=primero;
                    cout<<"El valor estaba al final"<<endl;
                    return;
                }
                else
                {
                    anterior->next=actual->next;
                    cout<<"El valor estaba al medio"<<endl;
                    return;
                }
            }
            anterior = actual;
            actual = actual->next;
        } while (actual!=primero);
        
    }
}
void ordenar()
{
    Nodo* actual = primero;
    
}