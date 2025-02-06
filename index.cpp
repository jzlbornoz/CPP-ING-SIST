#include <iostream>

// ALUMNO JAVIER ALBORNOZ 30372851 47
// Estructura de un nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

// Clase para la lista circular doblemente enlazada
class ListaCircular {
private:
    Nodo* cabeza;

public:
    ListaCircular() : cabeza(nullptr) {}

    // Método para insertar un nodo al final de la lista
    void insertar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        } else {
            Nodo* ultimo = cabeza->anterior;
            nuevoNodo->siguiente = cabeza;
            nuevoNodo->anterior = ultimo;
            ultimo->siguiente = nuevoNodo;
            cabeza->anterior = nuevoNodo;
        }
    }

    // Método para extraer un nodo por su valor
    void extraer(int valor) {
        if (!cabeza) return;

        Nodo* actual = cabeza;
        do {
            if (actual->dato == valor) {
                if (actual == cabeza && cabeza->siguiente == cabeza) {
                    delete cabeza;
                    cabeza = nullptr;
                    return;
                }
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
                if (actual == cabeza) {
                    cabeza = cabeza->siguiente;
                }
                delete actual;
                return;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
    }

    // Método para buscar un elemento en la lista
    bool buscar(int valor) {
        if (!cabeza) return false;

        Nodo* actual = cabeza;
        do {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return false;
    }

    // Método para unir dos listas circulares
    void unir(ListaCircular& otraLista) {
        if (!cabeza) {
            cabeza = otraLista.cabeza;
            return;
        }
        if (!otraLista.cabeza) return;

        Nodo* ultimoEstaLista = cabeza->anterior;
        Nodo* ultimoOtraLista = otraLista.cabeza->anterior;

        ultimoEstaLista->siguiente = otraLista.cabeza;
        otraLista.cabeza->anterior = ultimoEstaLista;
        ultimoOtraLista->siguiente = cabeza;
        cabeza->anterior = ultimoOtraLista;

        otraLista.cabeza = nullptr; // Evitar que la otra lista siga apuntando a los nodos
    }

    // Método para interceptar dos listas (intersección)
    ListaCircular interceptar(ListaCircular& otraLista) {
        ListaCircular listaInterceptada;
        if (!cabeza || !otraLista.cabeza) return listaInterceptada;

        Nodo* actual = cabeza;
        do {
            if (otraLista.buscar(actual->dato)) {
                listaInterceptada.insertar(actual->dato);
            }
            actual = actual->siguiente;
        } while (actual != cabeza);

        return listaInterceptada;
    }

    // Método para imprimir la lista
    void imprimir() {
        if (!cabeza) {
            std::cout << "Lista vacía." << std::endl;
            return;
        }

        Nodo* actual = cabeza;
        do {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        } while (actual != cabeza);
        std::cout << std::endl;
    }
};

int main() {
    // Crear lista 1
    ListaCircular lista1;
    lista1.insertar(10);
    lista1.insertar(20);
    lista1.insertar(30);
    std::cout << "Lista 1: ";
    lista1.imprimir();

    // Crear lista 2
    ListaCircular lista2;
    lista2.insertar(20);
    lista2.insertar(40);
    lista2.insertar(50);
    std::cout << "Lista 2: ";
    lista2.imprimir();

    // Buscar un elemento en la lista 1
    std::cout << "Buscar 20 en Lista 1: " << (lista1.buscar(20) ? "Encontrado" : "No encontrado") << std::endl;

    // Extraer un nodo de la lista 1
    lista1.extraer(20);
    std::cout << "Lista 1 después de extraer 20: ";
    lista1.imprimir();

    // Unir lista 1 y lista 2
    lista1.unir(lista2);
    std::cout << "Lista 1 después de unir con Lista 2: ";
    lista1.imprimir();

    // Crear lista 3 para interceptar
    ListaCircular lista3;
    lista3.insertar(30);
    lista3.insertar(40);
    lista3.insertar(60);
    std::cout << "Lista 3: ";
    lista3.imprimir();

    // Interceptar lista 1 y lista 3
    ListaCircular listaInterceptada = lista1.interceptar(lista3);
    std::cout << "Intersección de Lista 1 y Lista 3: ";
    listaInterceptada.imprimir();

    return 0;
}