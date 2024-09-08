#include <iostream>
using namespace std;

template<class T>
class NodoHeap {
    public:
        int prioridad;
        T dato;

        NodoHeap(int prioridad, T dato) : prioridad(prioridad), dato(dato) {}
};

template<class T>
class Heap {
    private:
        NodoHeap<T>** heap;
        int cantidad;
        int largoMax;

        int padre(int pos)
        {
            return (pos-1)/2;
        }

        int hijoIzq(int pos)
        {
            return 2*pos+1;
        }

        int hijoDer(int pos)
        {
            return 2*pos+2;
        }

        void intercambiar(int a, int b){
            NodoHeap<T>* aux = heap[a];
            heap[a] = heap[b];
            heap[b] = aux;
        }

        void flotar(int pos){
            int miPadre = padre(pos);
            if(pos > 0 && heap[miPadre]->prioridad > heap[pos]->prioridad){
                intercambiar(pos, miPadre);
                flotar(miPadre);
            }
        }

        void hundir(int pos){
            int miHijoIzq = hijoIzq(pos), miHijoDer = miHijoIzq+1;
            if(miHijoIzq<cantidad){
                int minHijo = miHijoIzq;
                if(miHijoDer<cantidad && heap[miHijoDer]->prioridad<heap[miHijoIzq]->prioridad){
                    minHijo++;
                }
                if(heap[minHijo]->prioridad <= heap[pos]->prioridad){ 
                    intercambiar(pos, minHijo);
                    hundir(minHijo);
                }
            }
        }

    public:
        Heap(int largoMax) {
            this->largoMax = largoMax;
            this->cantidad = 0;
            this->heap = new NodoHeap<T>*[largoMax]();
        }

        ~Heap() {
            for (int i = 0; i < cantidad; i++)
            {
                delete heap[i];
            }
            
            delete []heap;
        }

        int Largo() {
            return cantidad;
        }

        bool EsVacia() {
            return cantidad == 0;
        }

        void Insertar(int prioridad, T dato){
            heap[cantidad++]=new NodoHeap<T>(prioridad, dato);
            flotar(cantidad-1);
        }

        // Pre: !EsVacia()
        void BorrarMin() {
            NodoHeap<T>* aBorrar = heap[0];
            heap[0] = heap[--cantidad];
            heap[cantidad] = NULL;
            delete aBorrar;
            hundir(0);
        }

        // Pre: !EsVacia()
        T ObtenerMin() {
            return heap[0]->dato;
        }

        void Mostrar(){
            cout << "[";
            for (int i = 0; i < cantidad-1; i++)
            {
                cout << heap[i]->dato << ", ";
            }
            if(cantidad>0){
                cout << heap[cantidad-1]->dato;
            }
            cout << "]" << endl;
        }
};

//int main() {

    // Heap<string>* h= new Heap<string>(10);
    // h->Insertar(10, "J");
    // h->Mostrar();
    // h->Insertar(8, "H");
    // h->Mostrar();
    // h->Insertar(12, "L");
    // h->Mostrar();
    // h->Insertar(5, "E");
    // h->Mostrar();
    // h->Insertar(1891, "P");
    // h->Mostrar();
    // h->Insertar(3, "C");
    // h->Mostrar();
    
    // while(!h->EsVacia()){
    //     cout << h->ObtenerMin() << endl;
    //     h->BorrarMin();
    //     h->Mostrar();
    // }    

    // delete h;

    // Heap<Lista<int>*>*heap = new Heap<Lista<int>*>(5);

    //return 0;
//}