#include "List.hpp"

List::List(){
    last    = nullptr;
    first   = nullptr;
}
/*Not good*/
List::~List(){
    /* Cell *tmp = first->getNext();
    while (tmp != last){
        Cell *t = tmp;
        tmp = tmp->getNext();
        delete t;
    } */
}
int     List::lenght(){
    Cell *tmp = first;
    int count = 0;
    while (tmp != nullptr){
        count++;
        tmp = tmp->getNext();
    }
    return count;
}


int     List::get(int idx){
    if (idx <= 0){
        return -1;
    }
    Cell *tmp = first;
    
    while (tmp != nullptr){
        if (idx == 1){
            return tmp->getContenu();
        }
        idx--;
        tmp = tmp->getNext();
    }
    return -1;
}

int     List::find(int val){
    Cell *tmp = first;
    int index = 1;
    
    while (tmp != nullptr){
        if (val == tmp->getContenu()){
            return index;
        }
        index++;
        tmp = tmp->getNext();
    }
    return -1;
}

void    List::set(int idx, int val){
    Cell *tmp = first;
    
    while (tmp != nullptr){
        if (idx == 1){
            tmp->setContenu(val);
            return;
        }
        idx--;
        tmp = tmp->getNext();
    }
}

void    List::insert(int idx, int val){
    if (first == nullptr && idx == 1){
        first = new Cell(val);
    }

    if (first != nullptr && idx == 1){
        
        Cell *e = new Cell(val);
        e->setNext(first);
        this->first->setPred(e);
        this->first = e;
    }

    Cell    *prev = nullptr;
    Cell    *curr = first;
    while (idx != 1){
        prev = curr;
        curr = curr->getNext();
        if (curr == nullptr){
            break;
        }
        idx--;
    }
    Cell *e = new Cell(val);
    e->setNext(curr);
    prev->setNext(e);
}

void    List::del(int idx){

}

void    List::setLast(Cell *c){
    last = c;
}
void    List::setFirst(Cell *c){
    first = c;
}