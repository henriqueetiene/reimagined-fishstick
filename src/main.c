#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "projeto.h"
#include "tarefa.h"

void menu_pessoas(Lista_pessoa *pessoas, Lista_tarefa *tarefas, Lista_projeto *projetos)
{
    int opcao = 0, codigo, c;
    struct pessoa p;
    char nome[30];

    do
    {
        system("clear");
        printf("-----------------------------------------------------\n");
        printf("\t\t0 - Sair\n");
        printf("\t\t1 - Cadastrar pessoa\n");
        printf("\t\t2 - Imprimir lista de pessoas\n");
        printf("\t\t3 - Atualizar nome de uma pessoa\n");
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
            imprime_lista_pessoas(pessoas);
            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 3:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da pessoa: ");
            scanf("%d", &codigo);
            printf("\n");

            while ((c = getchar()) != '\n' && c != EOF);
            printf("Digite o novo nome da pessoa: ");
            scanf("%29[^\n]", nome);
            printf("\n");

            atualiza_nome_pessoa_lista_pessoas(pessoas, codigo, nome);
            atualiza_nome_pessoa_lista_tarefas(tarefas, codigo, nome);
            atualiza_nome_pessoa_lista_projetos(projetos, codigo, nome);

            printf("Nome atualizado\n");

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

void menu_tarefas(Lista_tarefa *tarefas, Lista_pessoa *pessoas, Lista_projeto *projetos)
{
    int opcao = 0, codigo, cod_pessoa, c;
    struct pessoa p;
    struct tarefa t;
    char descricao[100];

    do
    {
        system("clear");
        printf("-----------------------------------------------------\n");
        printf("\t\t0 - Sair\n");
        printf("\t\t1 - Cadastrar tarefa\n");
        printf("\t\t2 - Imprimir lista de tarefas\n");
        printf("\t\t3 - Adicionar resposável para uma tarefa\n");
        printf("\t\t4 - Atualizada descrição de uma tarefa\n");
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
            imprime_lista_tarefa(tarefas);
            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 3:
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
            scanf("%d", &cod_pessoa);
            
            p = consulta_lista_codigo_pessoas(pessoas, cod_pessoa);

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
        case 4:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código da tarefa: ");
            scanf("%d", &codigo);
            printf("\n");

            while ((c = getchar()) != '\n' && c != EOF);
            printf("Digite a nova descrição da tarefa: ");
            scanf("%99[^\n]", descricao);
            printf("\n");

            atualiza_descricao_tarefa_lista_tarefas(tarefas, codigo, descricao);
            atualiza_descricao_tarefa_lista_projetos(projetos, codigo, descricao);

            printf("Descrição atualizada\n");

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

void menu_projetos(Lista_projeto *projetos, Lista_tarefa *tarefas)
{
    int opcao = 0, codigo, cod_tarefa, c;
    struct projeto p;
    struct tarefa t;
    Lista_tarefa *tarefas_projeto = cria_lista_tarefa();

    do
    {
        system("clear");
        printf("-----------------------------------------------------\n");
        printf("\t\t0 - Sair\n");
        printf("\t\t1 - Cadastrar projeto\n");
        printf("\t\t2 - Imprimir lista de projetos\n");
        printf("\t\t3 - Adicionar tarefa ao projeto\n");
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

            printf("Digite o código do projeto: ");
            scanf("%d", &p.codigo);
            printf("\n");

            while ((c = getchar()) != '\n' && c != EOF);
            printf("Digite o titulo do projeto: ");
            scanf("%19[^\n]", p.titulo);
            printf("\n");

            while ((c = getchar()) != '\n' && c != EOF);
            printf("Digite a descricao do projeto: ");
            scanf("%99[^\n]", p.descricao);
            printf("\n");

            p.tarefas = tarefas_projeto;

            insere_lista_final_projeto(projetos, p);

            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 2:
            system("clear");

            printf("-----------------------------------------------------\n");
            imprime_lista_projeto(projetos);
            printf("-----------------------------------------------------\n");

            while ((c = getchar()) != '\n' && c != EOF);
            getchar();

            break;
        case 3:
            system("clear");

            printf("-----------------------------------------------------\n");

            printf("Digite o código do projeto: ");
            scanf("%d", &codigo);

            p = consulta_lista_codigo_projeto(projetos, codigo);

            if (p.codigo == -1)
            {
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;
            }

            printf("Digite o código da tarefa a ser adicionada: ");
            scanf("%d", &codigo);
            
            t = consulta_lista_codigo_tarefa(tarefas, codigo);

            if (t.codigo == -1)
            {
                while ((c = getchar()) != '\n' && c != EOF);
                getchar();
                break;
            }

            adiciona_tarefa_projeto(projetos, t, codigo);

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
    Lista_projeto *projetos = cria_lista_projeto();

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
            menu_projetos(projetos, tarefas);
            break;
        case 2:
            menu_tarefas(tarefas, pessoas, projetos);
            break;
        case 3:
            menu_pessoas(pessoas, tarefas, projetos);
            break;
        default:
            printf("opção inválida\n");
            getchar();
            break;
        }
    } while (opcao != 0);
    
    return 0;
}
