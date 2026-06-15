#include <stdlib.h>
#include <stdio.h>
#include "tarefa.h"
#include "pessoa.h"

struct lista_tarefa
{
    int qtd;
    struct tarefa dados[MAX_TAREFA];
};

Lista_tarefa *cria_lista_tarefa()
{
    Lista_tarefa *li_taLista_tarefa;
    li_taLista_tarefa = malloc(sizeof(struct lista_tarefa));

    if(li_taLista_tarefa != NULL)
    {
        li_taLista_tarefa->qtd = 0;
    }

    return li_taLista_tarefa;  
}

void libera_lista_tarefa(Lista_tarefa *li_tarefa)
{
    free(li_tarefa);
}

void tamanho_lista_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
    }
    else
    {
        printf("Quantidade de tarefas cadastradas: %d\n", li_tarefa->qtd);
    }

    getchar();
}

void lista_cheia_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
    }
    else
    {
        if (li_tarefa->qtd == MAX_TAREFA)
        {
            printf("Lista de tarefas está cheia\n");
        }
        else
        {
            printf("Lista de tarefas não está cheia\n");
        }
    }

    getchar();
}

void lista_vazia_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
    }
    else
    {
        if (li_tarefa->qtd == 0)
        {
            printf("Lista de tarefas está vazia\n");
        }
        else
        {
            printf("Lista de tarefas não está vazia\n");
        }
    }

    getchar();
}

void insere_lista_final_tarefa(Lista_tarefa *li_tarefa, struct tarefa t)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        getchar();
        return;
    }

    if(li_tarefa->qtd == MAX_TAREFA)
    {
        printf("Lista de tarefas está cheia para inserção\n");
        getchar();
        return;
    }

    li_tarefa->dados[li_tarefa->qtd] = t;
    li_tarefa->qtd++;

    printf("Tarefa inserida com sucesso\n");

    getchar();
}

void remove_lista_ordenada_tarefa(Lista_tarefa *li_tarefa, int codigo)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        getchar();
        return;
    }

    if(li_tarefa->qtd == 0)
    {
        printf("Lista de tarefas está vazia\n");
        getchar();
        return;
    }

    int i = 0;
    while(i < li_tarefa->qtd  && li_tarefa->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li_tarefa->qtd)
    {
        printf("Tarefa não encontrada para remoção\n");
        getchar();
        return;
    }

    for(int k = i; k < li_tarefa->qtd-1; k++ )
    {
        li_tarefa->dados[k] = li_tarefa->dados[k + 1];
    }

    li_tarefa->qtd--;

    printf("Tarefa removida com sucesso\n");

    getchar();
}

void consulta_lista_codigo_tarefa(Lista_tarefa *li_tarefa, int codigo)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        getchar();
        return;
    }

    int i = 0;
    while(i < li_tarefa->qtd && li_tarefa->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li_tarefa->qtd)
    {
        printf("Tarefa não encontrada\n");
        getchar();
        return;
    }

    printf("Código: %d\n", li_tarefa->dados[i].codigo);
    printf("Descrição: %s\n", li_tarefa->dados[i].descricao);

    printf("---------- Pessoa relacionada para a tarefa ----------\n");
    printf("Código: %d\n", li_tarefa->dados[i].pessoa.codigo);
    printf("Nome: %s\n", li_tarefa->dados[i].pessoa.nome);

    getchar();
}

void imprime_lista_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        getchar();
        return;
    }

    for(int i = 0; i < li_tarefa->qtd; i++)
    {
        printf("------------------------------------------------------\n");
        printf("Código: %d\n", li_tarefa->dados[i].codigo);
        printf("Descrição: %s\n", li_tarefa->dados[i].descricao);

        printf("---------- Pessoa relacionada para a tarefa ----------\n");
        printf("Código: %d\n", li_tarefa->dados[i].pessoa.codigo);
        printf("Nome: %s\n", li_tarefa->dados[i].pessoa.nome);
    }

    getchar();
}
