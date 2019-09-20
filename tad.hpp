#ifndef TAD_HPP_INCLUDED
#define TAD_HPP_INCLUDED

typedef struct _tad {
    int id;
    int max_size;
    int current_size;
    void ** value;
} tad;

// adiciona um item
int add_item(void * val);
// busca um item
void * get_item(void * val, int field, int (*ptf)(int , void *, void *));
// remove um item
void * del_item(int index);
// impime item
void print_item(void *);
// imprimir itens
void print_all();
// remove todos
void clear_all();

#endif // TAD_HPP_INCLUDED
