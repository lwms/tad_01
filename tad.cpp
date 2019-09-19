#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timestamp.hpp"
#include "tad.hpp"
#include "cadastro.hpp"
#define LEN 100

tad cofo[LEN];
tad * tmp;
static int fail = 0;
static int qtd = 0;

int add_item(void * val) {
    if (val != NULL) {
        if (qtd < LEN) {
            tmp = (tad *) malloc(sizeof(tad));
            if (tmp == NULL) {
                fail = 2; // falha ao criar elemento
            }
            tmp->id = qtd;
            tmp->value =  val;
            strcpy (tmp->timestamp, get_timestamp());
            cofo[qtd] = *(tmp);
            qtd++;
        } else {
            fail = 3; // armazenamento cheio | sem espaço
        }
    } else {
        fail = 1; // sem dados à armazenar
    }
    return fail;
}

void * get_item(void * val, int field, int (*ptf)(int , void *, void *)) {
    if (val != NULL && ptf != NULL) {
        for (int i = 0; i < qtd; i++) {
            if (ptf(field, val, cofo[i].value) == 0) {
                return cofo[i].value;
            }
        }
    }
    return NULL;
}

void * del_item(int index) {
    if (qtd > 0 && index >= 0 && index < qtd) {
        void * temp = cofo[index].value;
        for (int i = index; i < qtd - 1; i++) {
            cofo[i] = cofo[i + 1];
            //free(cofo[i + 1]);
        }
        qtd--;
        return temp;
    }
    return NULL;
}


void print_all() {
    if(qtd > 0) {
        puts("listing:");
        for (int i = 0; i < qtd; i++) {
            printf("\tId: %i\n", cofo[i].id);
            printf("\tCreated: %s\n", cofo[i].timestamp);
            print_data(cofo[i].value);
        }
    }
}
