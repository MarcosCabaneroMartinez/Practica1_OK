#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
    public:
        virtual void insert(int pos, const T& e) = 0;

        virtual void append(const T& e);

        virtual void prepend(const T& e);

        virtual T remove(int pos) = 0;

        virtual T get(int pos) const = 0;

        virtual int search(const T& e) const = 0;

        virtual int size() = 0;

        virtual bool Empty() const = 0;

};

#endif






























