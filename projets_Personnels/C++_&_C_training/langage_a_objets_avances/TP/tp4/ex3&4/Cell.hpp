#ifndef CELL_HPP
#define CELL_HPP

class Cell {
    private :
        int     contenu;
        Cell    *pred;
        Cell    *next;
    public :
        Cell();
        Cell(int value);
        void    connect(Cell& second);
        friend void    connect(Cell& first, Cell& second);
        void    disconnect_next();
        void    disconnect_previous();
        int     getContenu();
        Cell*   getNext();
        void    setContenu(int val);
        void    setNext(Cell *c);
        void    setPred(Cell *c);
};

#endif
