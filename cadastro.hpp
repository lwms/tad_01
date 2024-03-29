#ifndef CADASTRO_HPP_INCLUDED
#define CADASTRO_HPP_INCLUDED

typedef struct _cad {
    int id;
    char doc[20];
    char name[251];
    char nickname[151];
    char phone[21];
    char street[201];
    char neighborhood[151];
    char city[151];
    char cep[11];
    int age;
    float height;
    char timestamp[20];
} cad;

/**
 *  @param field
 *   0 - nickname
 *   1 - name
 *   2 - phone
 *   3 - street
 *   4 - neighborhood
 *   5 - city
 *   6 - cep | zip code
 *   7 - age
 *   8 - height
    @return
    0 if equal else < 0 or > 0
 */
int compare_field(int field, void * val_01, void * val_02);

void print_data(void * val);

#endif // CADASTRO_HPP_INCLUDED
