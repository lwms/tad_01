#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "timestamp.hpp"
#include "tad.hpp"
#include "cadastro.hpp"
#define LEN 100

static tad * cofo = NULL;
static int fail = 0;

int add_item(void * val) {
    if (val != NULL) {
        if(cofo == NULL) {
            cofo = (tad *) malloc(sizeof(tad));
            if(cofo == NULL) {
                fail = 2;
            } else {
                srand(100);
                cofo->id = rand();
                cofo->max_size = LEN;
                cofo->current_size = 0;
                cofo->value = (void **)malloc(sizeof(void *));
                if(cofo->value == NULL) {
                    fail = 3; // sem espaço para guardar os dados
                    free(cofo);
                    cofo = NULL;
                } else {
                    cofo->value[cofo->current_size++] = val;
                }
            }
        } else if (cofo->current_size < LEN) {
            cofo->value[cofo->current_size++] = val;
        } else {
            fail = 5; // armazenamento cheio | sem espaço
        }
    } else {
        fail = 1; // sem dados à armazenar
    }
    return fail;
}

void * get_item(void * val, int field, int (*ptf)(int , void *, void *)) {
    if (val != NULL && ptf != NULL && cofo !=  NULL) {
        for (int i = 0; i < cofo->current_size; i++) {
            if (ptf(field, val, cofo->value[i]) == 0) {
                return cofo->value[i];
            }
        }
    }
    return NULL;
}

void * del_item(int index) {
    if (cofo != NULL && index >= 0 && index < cofo->current_size) {
        void * temp = cofo->value[index];
        for (int i = index; i < cofo->current_size - 1; i++) {
            cofo->value[i] = cofo->value[i + 1];
            cofo->value[i + 1] = NULL;
        }
        cofo->current_size--;
        return temp;
    }
    return NULL;
}

void print_item(void * val) {
    if(cofo != NULL && val != NULL) {
        puts("Data item:");
        printf("[\n");
        printf("\tTAD Id: %i\n", cofo->id);
        printf("\tMax size: %i\n", cofo->max_size);
        printf("\tCurrent size: %i\n", cofo->current_size);
        print_data(val);
        printf("]\n");
    }
}

void print_all() {
    if(cofo != NULL && cofo->current_size > 0) {
        puts("listing:");
        printf("[\n");
        printf("\tTAD Id: %i\n", cofo->id);
        printf("\tMax size: %i\n", cofo->max_size);
        printf("\tCurrent size: %i\n", cofo->current_size);
        for (int i = 0; i < cofo->current_size; i++) {
            print_data(cofo->value[i]);
        }
        printf("]\n");
    }
}

void clear_item(void * val){
    if(val != NULL) {
        free(val);
    }
}

void clear_all() {
    if(cofo != NULL) {
        if(cofo->current_size > 0) {
            for(int i = 0; i < cofo->current_size; i++) {
                clear_item(cofo->value[i]);
            }
        }
        free(cofo);
        cofo = NULL;
    }
}

