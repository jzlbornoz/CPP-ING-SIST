#include <iostream>
#include <vector>

class Pila {
private:
    std::vector<int> elementos;

public:
    // Método para agregar un elemento a la pila (push)
    void push(int elemento) {
        elementos.push_back(elemento);
    }

    // Método para eliminar y retornar el elemento en la cima de la pila (pop)
    int pop() {
        if (elementos.empty()) {
            std::cerr << "Error: La pila está vacía." << std::endl;
            return -1; // Retorna -1 si la pila está vacía
        }
        int elemento = elementos.back();
        elementos.pop_back();
        return elemento;
    }

    // Método para obtener el elemento en la cima de la pila sin eliminarlo (top)
    int top() const {
        if (elementos.empty()) {
            std::cerr << "Error: La pila está vacía." << std::endl;
            return -1; // Retorna -1 si la pila está vacía
        }
        return elementos.back();
    }

    // Método para verificar si la pila está vacía
    bool estaVacia() const {
        return elementos.empty();
    }

    // Método para obtener el tamaño de la pila
    size_t tamaño() const {
        return elementos.size();
    }
};