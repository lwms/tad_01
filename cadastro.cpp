#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.hpp"

int compare_field(int field, void * val_01, void * val_02) {
    cad * aux = (cad *) val_02;
    switch (field) {
        case 1:{ // name
            return strcmp((char *) val_01, aux->name);
        }
        case 2:{ // nickname
            return strcmp((char *) val_01, aux->nickname);
        }
    }
    return 0;
}

void print_data(void * val) {
    if (val != NULL) {

        cad * aux = (cad *) val;

        printf("\t[\n");
        printf("\t\tData Id: %d\n", aux->id);
        printf("\t\tDoc: %s\n",aux->doc);
        printf("\t\tName: %s\n",aux->name);
        printf("\t\tNickname: %s\n",aux->nickname);
        printf("\t\tAge: %d\n", aux->age);
        printf("\t\tHeight: %.2f\n", aux->height);
        printf("\t\tPhone: %s\n", aux->phone);
        printf("\t\tStreet: %s\n",aux->street);
        printf("\t\tNeighborhood: %s\n",aux->neighborhood);
        printf("\t\tCity: %s\n",aux->city);
        printf("\t\tCEP: %s\n",aux->cep);
        printf("\t\tCreated: %s\n", aux->timestamp);
        printf("\t]\n");

    }
}
