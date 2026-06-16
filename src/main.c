#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "projeto.h"
#include "tarefa.h"

void menu_pessoas(Lista_pessoa *pessoas, Lista_tarefa *tarefas)
{
    int opcao = 0, codigo, c;
    struct pessoa p;

    do
    {
        system("clear");
        printf("-----------------------------------------------------\n");
        printf("\t\t0 - Sair\n");
        printf("\t\t1 - Cadastrar pessoa\n");
        printf("\t\t2 - Remover pessoa\n");
        printf("\t\t3 - Consultar pessoa pelo código\n");
        printf("\t\t4 - Imprimir lista de pessoas\n");
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
            remove_pessoa_deletada_tarefa(tarefas, codigo);

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
            p = consulta_lista_codigo_pessoas(pessoas, codigo);

            if (p.codigo == -1)
            {
                printf("-----------------------------------------------------\n");

                while ((c = getchar()) != '\n' && c != EOF);
                getchar();

                break;
            }

            printf("Codigo: %d\n", p.codigo);
            printf("Nome: %s\n", p.nome);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 4:
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

void menu_tarefas(Lista_tarefa *tarefas, Lista_pessoa *pessoas)
{
    int opcao = 0, codigo, c;
    struct pessoa p;
    struct tarefa t;

    do
    {
        system("clear");
        printf("-----------------------------------------------------\n");
        printf("\t\t0 - Sair\n");
        printf("\t\t1 - Cadastrar tarefa\n");
        printf("\t\t2 - Remover tarefa\n");
        printf("\t\t3 - Consultar tarefa pelo código\n");
        printf("\t\t4 - Imprimir lista de tarefas\n");
        printf("\t\t5 - Adicionar resposável para uma tarefa\n");
        printf("\t\t6 - Remover resposável para uma tarefa\n");
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

            t.pessoa.codigo = -1;

            printf("Digite o código da tarefa: ");
            scanf("%d", &t.codigo);
            printf("\n");

            while ((c = getchar()) != '\n' && c != EOF);
            printf("Digite a descrição da tarefa: ");
            scanf("%29[^\n]", t.descricao);
            printf("\n");

            insere_lista_final_tarefa(tarefas, t);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 2:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da tarefa a ser removida: ");
            scanf("%d", &codigo);

            remove_lista_ordenada_tarefa(tarefas, codigo);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 3:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da tarefa a ser consultada: ");
            scanf("%d", &codigo);

            printf("\n");
            t = consulta_lista_codigo_tarefa(tarefas, codigo);

            if (t.codigo == -1)
            {
                break;
            }

            printf("Codigo: %d\n", t.codigo);
            printf("Nome: %s\n", t.descricao);

            if (t.pessoa.codigo > 0)
            {
                printf("\tPessoa responsável pela tarefa: %s\n", t.pessoa.nome);
            }

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 4:
            system("clear");

            printf("-----------------------------------------------------\n");
            imprime_lista_tarefa(tarefas);
            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 5:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da tarefa: ");
            scanf("%d", &codigo);

            t = consulta_lista_codigo_tarefa(tarefas, codigo);

            if (t.codigo == -1)
            {
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;
            }

            printf("Digite o código da pessoa a ser adicionada: ");
            scanf("%d", &codigo);
            
            p = consulta_lista_codigo_pessoas(pessoas, codigo);

            if (p.codigo == -1)
            {
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;
            }

            adiciona_pessoa_tarefa(tarefas, p, codigo);
            printf("Pessoa adicionada á tarefa\n");

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 6:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da tarefa: ");
            scanf("%d", &codigo);

            remove_pessoa_tarefa(tarefas, codigo);

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
    Lista_pessoa *pessoas = cria_lista_pessoas();
    Lista_tarefa *tarefas = cria_lista_tarefa();

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
            menu_tarefas(tarefas, pessoas);
            break;
        case 3:
            menu_pessoas(pessoas, tarefas);
            break;
        default:
            printf("opção inválida\n");
            getchar();
            break;
        }
    } while (opcao != 0);
    
    return 0;
}
