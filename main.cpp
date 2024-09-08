#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <fstream>
#include <filesystem>
#include "./datastructures/heap.cpp"
#include "./datastructures/Lista/lista.cpp"
#include "./datastructures/minheap.cpp"
using namespace std;

int prioridadLista(Lista<int>* lista) {
    int prioridad;
    auto iterador = lista->obtenerIterador();
    if (iterador->HayElemento()) {
        prioridad = iterador->Elemento();  // Asigna el valor del elemento actual
        iterador->Avanzar();
    }
    delete iterador; 
    return prioridad;
}
void mostrar(Heap<Lista<int>*>& heap) {
        Lista<int>* lista = heap.ObtenerMin();
        lista->MostrarI(); // Assuming MostrarI prints the list contents
   
}

int main()
{
    ifstream myFile("C:/Algoritmos2/Practico/heapList/Tests/kmerge10e2.in.txt");
    cin.rdbuf(myFile.rdbuf());
    int k;
    cin >> k;
    //cout << k << std::endl; 

    Heap<Lista<int>*>*heap = new Heap<Lista<int>*>(k);
    
   for (int i = 0; i < k; i++)
   {
    int n;
    cin >> n;
    Lista<int>* lista = new Lista<int>();
    for (int j = 0; j < n; j++)
    {
        int element;
        cin >> element;
        lista->InsertarPpio(element);
    }
    heap -> Insertar(prioridadLista(lista),lista);
    heap ->Mostrar();
   }
    // while (!heap->EsVacia()) {
    //     Lista<int>* minLista = heap->ObtenerMin();
    //     cout << minLista << std::endl;
    //     minLista ->MostrarI();
    //     heap->BorrarMin();
    //     delete minLista;  
    //     heap ->Mostrar();
    // }
    delete heap;
    return 0;
}

// int prioridadLista(Lista<int>* lista) {
//     // Ensure the list is not empty before accessing elements
//     if (lista->EsVacia()) {
//         throw runtime_error("List is empty; cannot determine priority.");
//     }

//     int prioridad = lista->ObtenerPpio();
//     auto iterador = lista->obtenerIterador();
//     if (iterador->HayElemento()) {
//         iterador->Avanzar();
//     }
//     delete iterador; // Clean up the iterator to prevent memory leaks
//     return prioridad;
// }



// PRUEBAS NO TOCAR

// int main() {
    
//     ifstream myFile("C:/Algoritmos2/Practico/heapList/Tests/kmerge10.in.txt");
    
//     // Check if the file opened successfully
//     if (!myFile.is_open()) {
//         cerr << "Error: Could not open the file." << endl;
//         return 1; // Return an error code
//     }
    
//     // Redirect standard input to read from the file
//     cin.rdbuf(myFile.rdbuf());
    
//     int k;
//     cin >> k;

//     // Ensure k is a valid size
//     if (k <= 0) {
//         cerr << "Error: Invalid value of k." << endl;
//         return 1;
//     }

//     Heap<Lista<int>*>* heap = new Heap<Lista<int>*>(k);
    
//     try {
//         for (int i = 0; i < k; i++) {
//             int n;
//             cin >> n;

//             if (n < 0) {
//                 throw runtime_error("Invalid size of list read from file.");
//             }

//             Lista<int>* lista = new Lista<int>();
//             for (int j = 0; j < n; j++) {
//                 int element;
//                 cin >> element;
//                 lista->InsertarPpio(element);
//             }
//             heap->Insertar(prioridadLista(lista), lista);
//         }

//         while (!heap->EsVacia()) {
//             Lista<int>* minLista = heap->ObtenerMin();
//             minLista->MostrarI(); // Assuming MostrarI prints the list contents
//             heap->BorrarMin();
            
//             // Optionally delete minLista only if it is not managed by the heap
//             delete minLista;
//             heap->Mostrar();
//         }
//     } catch (const exception& e) {
//         cerr << "Exception caught: " << e.what() << endl;
//         delete heap; // Clean up memory
//         return 1;
//     }

//     delete heap; // Clean up memory
//     return 0;
// }

