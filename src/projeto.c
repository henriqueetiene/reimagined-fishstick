#include <stdlib.h>
#include <stdio.h>
#include <projeto.h>
#include "tarefa.h"

struct lista_projeto
{
    int qtd;
    struct projeto dados[MAX_PROJETO];
};

Lista_projeto *cria_lista_projeto()
{
    Lista_projeto *li_taLista_projeto;
    li_taLista_projeto = malloc(sizeof(struct lista_projeto));

    if(li_taLista_projeto != NULL)
    {
        li_taLista_projeto->qtd = 0;
    }

    return li_taLista_projeto;
}

void libera_lista_projeto(Lista_projeto *li)
{
    free(li->dados->tarefas);
    free(li);
}

void tamanho_lista_projeto(Lista_projeto *li)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
    }
    else
    {
        printf("Quantidade de projetos cadastrados: %d\n", li->qtd);
    }

    getchar();
}

void lista_cheia_projeto(Lista_projeto *li)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
    }
    else
    {
        if (li->qtd == MAX_PROJETO)
        {
            printf("Lista de projetos está cheia\n");
        }
        else
        {
            printf("Lista de projetos não está cheia\n");
        }
    }

    getchar();
}

void lista_vazia_projeto(Lista_projeto *li)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
    }
    else
    {
        if (li->qtd == 0)
        {
            printf("Lista de projetos está vazia\n");
        }
        else
        {
            printf("Lista de projetos não está vazia\n");
        }
    }

    getchar();
}

void insere_lista_final_projeto(Lista_projeto *li, struct projeto p)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
        return;
    }

    if(li->qtd == MAX_PROJETO)
    {
        printf("Lista de projetos está cheia para inserção\n");
        return;
    }

    if (p.codigo <= 0)
    {
        printf("Código deve ser um valor positivo maior que 0\n");
        return;
    } 

    li->dados[li->qtd] = p;
    li->qtd++;

    printf("Projeto cadastrado com sucesso\n");
}

void remove_lista_ordenada_projeto(Lista_projeto *li, int codigo)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
        return;
    }

    if(li->qtd == 0)
    {
        printf("Lista de projetos está vazia\n");
        return;
    }

    int i = 0;
    while(i < li->qtd  && li->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li->qtd)
    {
        printf("Projeto não encontrado para remoção\n");
        return;
    }

    for(int k = i; k < li->qtd-1; k++ )
    {
        li->dados[k] = li->dados[k + 1];
    }

    li->qtd--;

    printf("Projeto removido com sucesso\n");
}

struct projeto consulta_lista_codigo_projeto(Lista_projeto *li, int codigo)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
        return (struct projeto){-1};
    }

    int i = 0;
    while(i < li->qtd && li->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li->qtd)
    {
        printf("projeto não encontrada\n");
        return (struct projeto){-1};
    }
}

void adiciona_tarefa_projeto(Lista_projeto *li, struct tarefa t, int codigo)
{
    int i = 0;
    while(i < li->qtd && li->dados[i].codigo != codigo)
    {
        i++;
    }

    insere_lista_final_tarefa(li->dados[i].tarefas, t);
}

void imprime_lista_projeto(Lista_projeto *li)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
        return;
    }

    if (li->qtd == 0)
    {
        printf("Lista de projetos está vazia\n");
        return;
    }

    for(int i = 0; i < li->qtd; i++)
    {
        printf("Código: %d\n", li->dados[i].codigo);
        printf("Título: %s\n", li->dados[i].descricao);
        printf("Descrição: %s\n", li->dados[i].descricao);

        printf("\n-----Tarefas-----\n");
        imprime_lista_tarefa(li->dados[i].tarefas);
        printf("-----------------\n");
    }
}

void atualiza_nome_pessoa_lista_projetos(Lista_projeto *li, int cod_pessoa, char novo_nome[30])
{
    for (int i = 0; i < MAX_PROJETO; i++)
    {
        for (int k = 0; k < MAX_TAREFA; k++)
        {
            atualiza_nome_pessoa_lista_tarefas(li->dados[i].tarefas, cod_pessoa, novo_nome);
        }
    }
}

void atualiza_descricao_tarefa_lista_projetos(Lista_projeto *li, int cod_tarefa, char nova_descricao[100])
{
    for (int i = 0; i < MAX_PROJETO; i++)
    {
        atualiza_descricao_tarefa_lista_tarefas(li->dados[i].tarefas, cod_tarefa, nova_descricao);
    }
}
