#ifndef LIST_HPP
#define LIST_HPP
#include "Cell.hpp"

class List {
    Cell *last;
    Cell *first;

    public:
    List();
    ~List();
    int     lenght();
    int     get(int idx);
    int     find(int val);
    void    set(int idx, int val);
    void    insert(int idx, int val);
    void    del(int idx);
    void    setLast(Cell *c);
    void    setFirst(Cell *c);
};
#endif