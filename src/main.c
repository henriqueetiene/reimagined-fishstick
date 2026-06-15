#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "projeto.h"
#include "tarefa.h"

void menu_pessoas()
{
    int opcao = 0, codigo, c;
    char nome[30];
    Lista_pessoa *pessoas = cria_lista_pessoas();

    do
    {
        system("clear");
        printf("-----------------------------------------------------\n");
        printf("\t\t0 - Sair\n");
        printf("\t\t1 - Cadastrar pessoa\n");
        printf("\t\t2 - Remover pessoa\n");
        printf("\t\t3 - Consultar pessoa pelo código\n");
        printf("\t\t4 - Consultar pessoa pelo nome\n");
        printf("\t\t5 - Imprimir lista de pessoas\n");
        printf("-----------------------------------------------------\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            system("clear");

            printf("-----------------------------------------------------\n");

            struct pessoa p;

            printf("Digite o código da pessoa: ");
            scanf("%d", &p.codigo);
            printf("\n");

            while ((c = getchar()) != '\n' && c != EOF);
            printf("Digite o nome da pessoa: ");
            scanf("%29[^\n]", p.nome);
            printf("\n");

            insere_lista_final_pessoas(pessoas, p);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 2:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da pessoa a ser removida: ");
            scanf("%d", &codigo);

            remove_lista_ordenada_pessoas(pessoas, codigo);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 3:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da pessoa a ser consultada: ");
            scanf("%d", &codigo);

            printf("\n");
            consulta_lista_codigo_pessoas(pessoas, codigo);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 4:
            system("clear");

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            printf("Digite o nome da pessoa a ser consultada: ");
            scanf("%29[^\n]", nome);

            printf("\n");
            consulta_lista_nome_pessoas(pessoas, nome);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 5:
            system("clear");

            printf("-----------------------------------------------------\n");
            imprime_lista_pessoas(pessoas);
            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        default:
            system("clear");

            printf("-----------------------------------------------------\n");
            printf("opção inválida");
            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        }
    } while (opcao != 0);
    
}

int main(int argc, char const *argv[])
{
    int opcao = 0, c;

    do
    {
        system("clear");
        printf("-----------------------------------------------------\n");
        printf("\t\t0 - Sair\n");
        printf("\t\t1 - Menu de Projetos\n");
        printf("\t\t2 - Menu de Tarefas\n");
        printf("\t\t3 - Menu de Pessoas\n");
        printf("-----------------------------------------------------\n");

        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        while ((c = getchar()) != '\n' && c != EOF);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            printf("projetos\n");
            getchar();
            break;
        case 2:
            printf("tarefas\n");
            getchar();
            break;
        case 3:
            menu_pessoas();
            break;
        default:
            printf("opção inválida\n");
            getchar();
            break;
        }
    } while (opcao != 0);
    
    return 0;
}
