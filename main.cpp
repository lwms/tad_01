#include <stdio.h>
#include <stdlib.h>
#include "TAD.hpp"
#include "Cadastro.hpp"


int main()
{
    printf("okkk");
    int exit_loop =  1;
    int option = 0;

    for (;exit_loop;) {
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Deletar\n");
        printf("4 - Limpar\n");
        printf("5 - Sair\n");

        scanf("%[^\r\n]i", option);

        switch (option) {
            case 5:{
                exit_loop = 0;
                break;
            }
        }

    }

    return 0;
}
