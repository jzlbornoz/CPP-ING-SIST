#include <iostream>
using namespace std;

// Definición de la estructura NODO, que representa cada elemento de la lista.
struct NODO {
    int valor;    // Valor almacenado en el nodo.
    NODO *sig;    // Puntero al siguiente nodo en la lista.

    // Constructor que inicializa el puntero al siguiente nodo como NULL.
    NODO() {
        sig = NULL;
    }
};

// Clase LISTASIMPLE, que implementa una lista enlazada simple.
class LISTASIMPLE {
    NODO *cab;    // Puntero al primer nodo de la lista.

public:
    // Constructor que inicializa la lista como vacía.
    LISTASIMPLE() {
        cab = NULL;
    }

    // Inserta un nodo en la cabeza de la lista.
    void insertar(NODO *n) {
        if (cab == NULL) {
            cab = n;  // Si la lista está vacía, el nodo se convierte en el primero.
        } else {
            n->sig = cab;  // El nuevo nodo apunta al actual primer nodo.
            cab = n;       // El nuevo nodo se convierte en el primero.
        }
    }

    // Inserta un valor en la cabeza de la lista, creando un nuevo nodo.
    void insertar(int n) {
        NODO *aux = new NODO();
        aux->valor = n;
        if (cab == NULL) {
            cab = aux;
        } else {
            aux->sig = cab;
            cab = aux;
        }
    }

    // Inserta un valor en orden ascendente dentro de la lista.
    void insertarOrd(int n) {
        NODO *aux = new NODO();
        NODO *aux1 = cab;
        aux->valor = n;

        if (cab == NULL) {  // Si la lista está vacía, el nodo se convierte en el primero.
            cab = aux;
        } else if (n < cab->valor) {  // Caso especial: insertar antes del primer nodo.
            aux->sig = cab;
            cab = aux;
        } else {
            // Recorremos la lista buscando la posición adecuada.
            while (aux1->sig != NULL && aux1->sig->valor < n) {
                aux1 = aux1->sig;
            }
            aux->sig = aux1->sig;  // Insertamos el nodo en la posición correcta.
            aux1->sig = aux;
        }
    }

    // Inserta un valor al final de la lista.
    void InsertarFinal(int n) {
        NODO *aux = new NODO();
        aux->valor = n;

        if (cab == NULL) {  // Si la lista está vacía, el nodo se convierte en el primero.
            cab = aux;
        } else {
            NODO *temp = cab;
            while (temp->sig != NULL) {  // Recorremos la lista hasta el final.
                temp = temp->sig;
            }
            temp->sig = aux;  // El último nodo apunta al nuevo nodo.
        }
    }

    // Elimina el primer nodo que contenga el valor dado.
    void eliminar(int n) {
        if (cab == NULL) {  // Si la lista está vacía, no se puede eliminar nada.
            cout << "La lista está vacía." << endl;
            return;
        }

        NODO *aux = cab;
        NODO *prev = NULL;

        // Recorremos la lista buscando el nodo a eliminar.
        while (aux != NULL && aux->valor != n) {
            prev = aux;
            aux = aux->sig;
        }

        if (aux == NULL) {  // Si no se encontró el valor, mostramos un mensaje.
            cout << "El valor " << n << " no se encontró en la lista." << endl;
            return;
        }

        if (prev == NULL) {  // Si el nodo a eliminar es el primero.
            cab = aux->sig;
        } else {  // Si el nodo está en medio o al final.
            prev->sig = aux->sig;
        }

        delete aux;  // Liberamos la memoria del nodo eliminado.
    }

    // Busca un valor en la lista y retorna true si lo encuentra.
    bool buscar(int n) {
        NODO *aux = cab;
        while (aux != NULL) {
            if (aux->valor == n) {
                return true;  // Se encontró el valor.
            }
            aux = aux->sig;
        }
        return false;  // No se encontró el valor.
    }

    // Inserta un valor permitiendo repeticiones.
    void insertarconRepeticion(int n) {
        insertar(n);
    }

    // Inserta un valor sin permitir repeticiones.
    void insertarsinRepeticion(int n) {
        if (!buscar(n)) {  // Solo inserta si el valor no está en la lista.
            insertar(n);
        } else {                         
            cout << "El valor " << n << " ya existe en la lista." << endl;
        }
    }

    // Ordena la lista en orden ascendente.
    void Ordenar() {
        LISTASIMPLE *AUXP = new LISTASIMPLE();  // Lista auxiliar para guardar los nodos ordenados.
        NODO *aux = cab;
        while (aux != NULL) {
            AUXP->insertarOrd(aux->valor);  // Insertamos los valores ordenados.
            aux = aux->sig;
        }

        // Liberamos la memoria de la lista original.
        limpiarNodos(cab);
        cab = AUXP->cab;  // Reasignamos la cabeza de la lista ordenada.
        delete AUXP;
    }

    // Imprime todos los valores de la lista.
    void imprimir() {
        NODO *aux = cab;
        while (aux != NULL) {
            cout << aux->valor << " ";
            aux = aux->sig;
        }
        cout << endl;
    }

private:
    // Limpia todos los nodos de la lista.
    void limpiarNodos(NODO *&nodo) {
        while (nodo != NULL) {
            NODO *aux = nodo;
            nodo = nodo->sig;
            delete aux;  // Liberamos la memoria del nodo actual.
        }
    }
};                                                        