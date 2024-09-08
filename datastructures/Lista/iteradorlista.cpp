#include "nodolista.cpp"

template<class T>
class IteradorLista {
    private:
        nodoLista<T>* ppio;
        nodoLista<T>* actual;

    public:
        IteradorLista(nodoLista<T>* ppio): ppio(ppio), actual(ppio) {}

        ~IteradorLista() {
            // Destructor to clean up memory if necessary
            nodoLista<T>* temp;
            while (ppio != nullptr) {
                temp = ppio;
                ppio = ppio->sig;
                delete temp;
            }
        }
        
        // Pre: HayElemento()
        T Elemento() {
            return actual->dato;
        }

        // Pre: HayElemento()
        void Avanzar() {
            actual = actual->sig;
        }

        void Reiniciar() {
            actual = ppio;
        }

        bool HayElemento() {
            return actual != NULL;
        }

};