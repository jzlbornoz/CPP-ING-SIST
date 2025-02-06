#include <iostream>
#include <queue>

class Cola {
private:
    std::queue<int> elementos;

public:
    // Método para agregar un elemento a la cola (enqueue)
    void enqueue(int elemento) {
        elementos.push(elemento);
    }

    // Método para eliminar y retornar el elemento al frente de la cola (dequeue)
    int dequeue() {
        if (elementos.empty()) {
            std::cerr << "Error: La cola está vacía." << std::endl;
            return -1; // Retorna -1 si la cola está vacía
        }
        int elemento = elementos.front();
        elementos.pop();
        return elemento;
    }

    // Método para obtener el elemento al frente de la cola sin eliminarlo (front)
    int front() const {
        if (elementos.empty()) {
            std::cerr << "Error: La cola está vacía." << std::endl;
            return -1; // Retorna -1 si la cola está vacía
        }
        return elementos.front();
    }

    // Método para verificar si la cola está vacía
    bool estaVacia() const {
        return elementos.empty();
    }

    // Método para obtener el tamaño de la cola
    size_t tamaño() const {
        return elementos.size();
    }
};
