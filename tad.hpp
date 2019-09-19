#ifndef TAD_HPP_INCLUDED
#define TAD_HPP_INCLUDED

typedef struct _tad {
    int id;
    void * value;
    char timestamp[20];
} tad;

// adiciona um item
int add_item(void * val);
// busca um item
void * get_item(void * val, int field, int (*ptf)(int , void *, void *));
// remove um item
void * del_item(int index);
// imprimir itens
void print_all();
// remove todos
void clear_all();

#endif // TAD_HPP_INCLUDED
