#include <cstdio>
#include <ctime>


class node{

    int _data;
    node *_Siguiente;
    node *_Anterior;

public:

    node(int x): _data(x) { _Siguiente = NULL; _Anterior = NULL;};

    node *Siguiente(node *_a);
    node *Anterior(node *_a);

      friend class Bicola;

};

class Servicios{

    int s = 0;
    int n = s;

    node *Frente;
    node *Final;
    node *Actual;

    public:

    node *p = NULL;//estos dos deberian de estar en el main creo
    node *q = NULL;//este tambien

    Servicios(){

    this ->Frente = NULL;
    this ->Final = NULL;
    this ->Actual = NULL;
    int Tamanio();

    }


    int Tamanio(int x){return s =x;}
    int cap(){return n;}

    bool insFrente(int x);
    bool insFinal(int x);

    void CrearServicios(node *_a);//Para crear servicios
    void InsertarServicio(int x);

    bool full() {return s==n;}
    bool vacia(){return (this ->Frente == NULL);}

       friend class node;
};

class Procesos{

    Procesos *Frente;
    Procesos *Final;
    node* Servicios;

public:

    Procesos();

    void CrearProcesos(int x);
    void InsertarProceso(int x);

};
Servicios se;

bool Servicios::insFrente(int x){

    node *nuevo = new node(x);
    if(vacia()){
        printf("Primer dato: %i\n", x);
        Frente = nuevo;
    }
    node *aux;
    aux = Frente;
    Frente = nuevo;
    nuevo ->_Siguiente = aux;
    aux ->_Anterior = nuevo;
    printf("Se inserto: %i \n", x );
}


node* node::Siguiente(node *_a){

    bi.Actual ->_Siguiente = _a;
    _a ->_Anterior = bi.Actual;//como accedo al nodo al que esta apuntanndo _a

}

node* node::Anterior(node *_a){//pasarle el nodo del que va a ir enlazado despues o por el apuntador anterior

    bi.Actual -> _Anterior = _a;
    _a -> _Siguiente = bi.Actual;

}

bool  Servicios::insFinal(int x){

    node *nuevo = new node(x);

    if(full()){
        return "Lista Llena /n";
    }
    else{
        node *aux;
        aux = Final;
        Final = nuevo;
        nuevo ->_Anterior = aux;
    }

    }



