#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.hpp"
#include "tad.hpp"
#include "cadastro.hpp"
#include "timestamp.hpp"

int main()
{
    int exit_loop =  1;
    int option = 0;
    char str[1024];
    cad * new_item = NULL;

    for (;exit_loop;) {

        system(CLEAR);

        printf("1 - Inserir\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Deletar\n");
        printf("5 - Limpar\n");
        printf("0 - Sair\n");

        scanf("%i", &option);

        switch (option) {
            case 1:{ // Inserir
                new_item = (cad *) malloc(sizeof(cad));
                if (new_item != NULL) {

                    srand(100);
                    scanf("%s", new_item->doc);
                    scanf("%s", new_item->name);
                    scanf("%s", new_item->nickname);
                    scanf("%i", &new_item->age);
                    scanf("%f", &new_item->height);
                    scanf("%s", new_item->phone);
                    scanf("%s", new_item->street);
                    scanf("%s", new_item->neighborhood);
                    scanf("%s", new_item->city);
                    scanf("%s", new_item->cep);
                    strcpy(new_item->timestamp, get_timestamp());
                    new_item->id = rand();

                    add_item((void *)new_item);
                }
                option = 0;
                break;
            }
            case 2:{ // Listar
                print_all();
                option = 0;
                break;
            }
            case 3:{ // Buscar
                scanf("%s", str);
                print_item(get_item((void *)str, 1, compare_field));
                option = 0;
                break;
            }
            case 4:{ // Deletar
                puts(get_timestamp());
                option = 0;
                break;
            }
            case 5:{ // Limpar
                puts(get_timestamp());
                option = 0;
                break;
            }
            case 0:{ // Sair
                puts(get_timestamp());
                exit_loop = option =  0;
                continue;
            }
            default:{
                printf("Erro: Opção inválida !!!");
            }
        }
        new_item = NULL;
        clear_keyboard_buffer();
        getchar();

    }

    return 0;
}
