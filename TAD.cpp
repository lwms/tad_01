#include <stdlib.h>
#include "TAD.hpp"
#define LEN 100

tad * tmp, cofo[LEN];
static short int fail = 0;
static int qtd = 0;

int add_item(void * val) {
    if (val != NULL) {
        if (qtd < LEN) {
            tmp = (tad *) malloc(sizeof(tad));
            if (tmp == NULL) {
                fail = 2; // falha ao criar elemento
            }
            tmp->index = qtd;
            tmp->value = val;
            tmp->timestamp = "2019-09-18 08:00:01";
            cofo[qtd++] = &tmp;
        } else {
            fail = 3; // armazenamento cheio | sem espaço
        }
    } else {
        fail = 1; // sem dados à armazenar
    }
    return fail;
}
