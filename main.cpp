#include "Lista.hpp"

int main() {
    LISTASIMPLE lista;

    // Inserción de valores en la lista.
    cout << "Insertando valores en la lista..." << endl;
    lista.insertar(5);
    lista.insertar(3);
    lista.insertar(8);
    lista.insertarOrd(6);  // Inserción ordenada.
    lista.InsertarFinal(10);  // Inserción al final.

    // Imprimimos la lista actual.
    cout << "Lista actual: ";
    lista.imprimir();

    // Búsqueda de un valor.
    cout << "\nBuscando el valor 8: ";
    if (lista.buscar(8)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "No encontrado" << endl;
    }

    // Eliminación de un valor.
    cout << "Eliminando el valor 3..." << endl;
    lista.eliminar(3);

    // Imprimimos la lista actual.
    cout << "Lista actual: ";
    lista.imprimir();

    // Inserción sin repeticiones.
    cout << "\nInsertando sin repetición el valor 8..." << endl;
    lista.insertarsinRepeticion(8);
    cout << "Insertando sin repetición el valor 12..." << endl;
    lista.insertarsinRepeticion(12);

    // Imprimimos la lista final.
    cout << "Lista final: ";
    lista.imprimir();

    // Ordenamos la lista.
    cout << "Ordenando la lista..." << endl;
    lista.Ordenar();

    // Imprimimos la lista ordenada.
    cout << "Lista ordenada: ";
    lista.imprimir();

    return 0;
}