#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.hpp"

int compare_field(int field, void * val_01, void * val_02) {
    switch (field) {
        case 1:{ // name
            return strcmpi((char *) val_01, (char *) val_02);
        }
        case 2:{ // nickname
            return strcmpi((char *) val_01, (char *) val_02);
        }
    }
    return 0;
}

void print_data(void * val) {
    if (val != NULL) {

        cad * aux = (cad *) val;

        printf("\t\tDoc: %s\n",aux->doc);
        printf("\t\tName: %s\n",aux->name);
        printf("\t\tNickname: %s\n",aux->nickname);
        printf("\t\tAge: %d\n", aux->age);
        printf("\t\tHeight: %f\n", aux->height);
        printf("\t\tPhone: %s\n", aux->phone);
        printf("\t\tStreet: %s\n",aux->street);
        printf("\t\tNeighborhood: %s\n",aux->neighborhood);
        printf("\t\tCity: %s\n",aux->city);
        printf("\t\tCEP: %s\n",aux->cep);

    }
}
