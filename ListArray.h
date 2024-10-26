#include <ostream>
#include "List.h"
using namespace std
template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;        // Puntero al array dinámico que almacena los elementos
        int max;       // Capacidad máxima del array
        int n;    // Número de elementos en la lista
        static const int MINSIZE = 2;
        // Método que redimensiona el array si es demasiado pequeño
        void resize(int new_size) {
            if (new_size < MINSIZE) {
                new_size = MINSIZE;
            }

            T* newArray = new T[new_size];
            for (int i = 0; i < n; ++i) {
                newArray[i] = arr[i];
            }
            delete[] arr;

            // Actualizar tamaño máximo
            arr = newArray;
            max = new_size;
        }

    public:
        // Constructor
        ListArray(int initialCapacity = 10) : capacity(initialCapacity), numElements(0) {
            elements = new T[capacity];
        }
        // Destructor
        ~ListArray() {
            delete[] elements;
        }

        // Implementación de los métodos de List<T>

        // Inserta el elemento en pos
        void insert(int pos, const T& e) override {
            if (pos < 0 || pos > numElements) {
                throw std::out_of_range("Posición inválida");
            }
            if (numElements == capacity) {
                resize(capacity * 2);  // Duplicar el tamaño si está lleno
            }
            // Mover los elementos a la derecha para hacer espacio
            for (int i = numElements; i > pos; --i) {
                elements[i] = elements[i - 1];
            }
            elements[pos] = e;
            ++numElements;
        }

        // Añade el elemento al final de la lista
        void append(const T& e) override {
            if (numElements == capacity) {
                resize(capacity * 2);  // Redimensionar si está lleno
            }
            elements[numElements++] = e;
        }

        // Añade el elemento al principio de la lista
        void prepend(const T& e) override {
            insert(0, e);  // Llama a insert en la posición 0
        }

        // Elimina y devuelve el elemento en la posición pos
        T remove(int pos) override {
            if (pos < 0 || pos >= numElements) {
                throw std::out_of_range("Posición inválida");
            }
            T removedElement = elements[pos];
            // Mover los elementos hacia la izquierda para llenar el hueco
            for (int i = pos; i < numElements - 1; ++i) {
                elements[i] = elements[i + 1];
            }
            --numElements;
            return removedElement;
        }

        // Devuelve el elemento en la posición pos
        T get(int pos) const override {
            if (pos < 0 || pos >= numElements) {
                throw std::out_of_range("Posición inválida");
            }
            return elements[pos];
        }

        // Busca el elemento e y devuelve la posición de su primera ocurrencia, o -1 si no se encuentra
        int search(const T& e) const override {
            for (int i = 0; i < numElements; ++i) {
                if (elements[i] == e) {
                    return i;
                }
            }
            return -1;  // No encontrado
        }

        // Indica si la lista está vacía
        bool empty() const override {
            return numElements == 0;
        }

        // Devuelve el número de elementos en la lista
        int size() const override {
            return numElements;
        }

        // Sobrecarga del operador de salida para mostrar el contenido de la lista
        friend ostream& operator<<(ostream& os, const ListArray<T>& list) {
            os << "[";
            for (int i = 0; i < list.numElements; ++i) {
                os << list.elements[i];
                if (i < list.numElements - 1) {
                    os << ", ";
                } 
            }
            os << "]";
            return os;
        }
    
        T operator[](int pos) const {
            if (pos < 0 || pos >= size()-1) {
                throw out_of_range("Posición fuera de rango");
            }
            return arr[pos];
        }

};
