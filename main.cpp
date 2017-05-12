#include <cstdio>
#include <cstdlib>
#include <ctime>


class Procesos{

    int s = 0;

    Procesos *Frente;
    Procesos *Actual;
    Procesos *Final;
    Procesos *_anterior, *_siguiente, *_lista;
    int numero;
    int tam;


public:


    Procesos(int x): numero(x){_anterior = NULL; _siguiente = NULL; Frente = NULL; Actual = NULL; Final=NULL;}
    Procesos(){_lista = NULL;};
    Procesos* crearLista(int x);
    //void crearServicios(Procesos *_a, Procesos *_b,  int n);
    Procesos* Insertar(Procesos *_b, int x);
    void MostrarLista(Procesos *_a, int tm);

    Procesos* Lista(Procesos* _a){return _a ->_lista;}

    int Tamanio(int x){return s =x;}
    bool vacia(){return (this ->Frente == NULL);}
    bool vacia2(Procesos *f){return (f == NULL);}


    //friend class Bicola;
};

    class Servicios{
    public:
        void crearServicios(Procesos *_a, Procesos *_b,  int n);
    };



Procesos pr;

void Procesos::MostrarLista(Procesos *_a, int tm){

    int ind, t;
    Procesos *aux;
    aux = _a;
    ind= _a ->numero;
    t = tm;
    for(int j = 1; j<=tm; j++){//for para servicios
        //printf("Cuando ind vale: %i j vale: %i: \n\n", ind, j);
        printf("[%i] -->", ind);
        //t = aux ->tam;
        for(int i = 1; i <= tm; i++){//for para Procesos
            (aux) ? printf("[%i] ",aux->_lista) : printf("hola");// al terminar este for
        }
        printf("\n \n");
        aux = aux ->_siguiente;
        (aux) ? ind = aux ->numero : printf(" ") ;
    }


}

Procesos* Procesos::crearLista(int x){

    Procesos *aux;

    for(int i = x; i >0 ; i-- ){
    Procesos *nuevoP = new Procesos(i);

    if(vacia()){
        Frente = nuevoP;
        Final = nuevoP;
    }
    else{

        aux = Frente;
        Frente = nuevoP;
        nuevoP->_siguiente = aux;
        aux ->_anterior = nuevoP;
        nuevoP = Actual;//creo que este no lo voy a ocupar
        }
    }
        Actual->_lista = NULL;

    return Frente;
}

void Servicios::crearServicios(Procesos *_a, Procesos *_b, int n){

    int Contador = 1;
    int rnd1, rnd2, j=1;

    Procesos *aux;
    Procesos *aux2;
    Procesos *aux3;

    aux = _a;
    aux2 = _b;

    printf("_b Vale: %d \n",_b);
    if(vacia2(_b)){

        for(int i = 0; i<=50;){

        rnd1 = rand()%n +1;
        printf("Rnd1 vale: %i  i Vale: %i \n", rnd1, i);

       // j++;
        while (j == rnd1){
                j++;
        printf("J Vale:%i \n", j);
            rnd2 = rand()%100;
            printf("El que se debe de insertar: %i \n", rnd2);
            aux ->_lista = Insertar(_b, rnd2);
            printf("_b: %i", _b->numero);
            aux->tam +=1;
            i++;
            //Tamanio(Contador++);
        }
    }
    }

}

Procesos* Procesos::Insertar(Procesos *_b, int x){

    Procesos *nuevoP = new Procesos(x);
    Procesos* NFrente;
    Procesos *aux1;
    NFrente = NULL;
    _b = NFrente;

    if(vacia2(_b)){
        _b = nuevoP;
        printf("Dentro del if se inserto: %i \n", nuevoP->numero);
        return _b;
    }
    else{

        aux1 = _b;
        _b = nuevoP;
        nuevoP->_siguiente = aux1;
        aux1 ->_anterior = nuevoP;
        printf("Dentro del else se inserto: %i \n", nuevoP->numero);
        return _b;
    }
}

int main()
{
    /*int z;
    srand(time(NULL));
    int n;
    for(int i = 0; i <50; i++){
       z = rand() % 100;
        bi.insFrente(z);
    }*/
    srand(time(NULL));
    int num, num2;
    printf("Numero de Procesos: ");
    scanf("%i", &num);
    //pr.crearLista(num);
    Procesos *_a;
    Procesos *_b;
    _b = NULL;
    _a = pr.crearLista(num);

    printf("_b Valdria:%i \n", pr.Lista(_a));
    _b = pr.Lista(_a);
    pr.crearServicios(_a, _b, num);
    pr.MostrarLista(_a, num);
    scanf("%i", &num2);
    //Procesos::Mostrar(Procesos *_a, num);


    system("pause");
    return 0;
}
