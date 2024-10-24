#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
    public:
        // Destructor de la calse
        virtual ~List() {}

        virtual void insert(const T& element) = 0;

        virtual bool remove(const T& element) = 0;

        // Obtiene el elemento en una posición específica
        virtual T get(int index) const = 0;

        // Devuelve el tamaño actual de la lista
        virtual int size() const = 0;

        // Elimina la lista
        virtual void clear() = 0;

        // Verifica si la lista está vacía
        virtual bool isEmpty() const = 0;

        virtual int find(const T& element) const = 0;
};

#endif
