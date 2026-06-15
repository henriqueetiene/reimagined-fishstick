#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pessoa.h"

struct lista_pessoa
{
    int qtd;
    struct pessoa dados[MAX_PESSOA];
};

Lista_pessoa *cria_lista_pessoas()
{
    Lista_pessoa *li;
    li = malloc(sizeof(struct lista_pessoa));
    if(li != NULL)
    {
        li->qtd = 0;
    }

    return li;  
}

void libera_lista_pessoas(Lista_pessoa *li)
{
    free(li);
}

void tamanho_lista_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
    }
    else
    {
        printf("Quantidade de pessoas cadastradas: %d\n", li->qtd);
    }
}

void lista_cheia_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
    }
    else
    {
        if (li->qtd == MAX_PESSOA)
        {
            printf("Lista de pessoas está cheia\n");
        }
        else
        {
            printf("Lista de pessoas não está cheia\n");
        }
    }
}

void lista_vazia_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
    }
    else
    {
        if (li->qtd == 0)
        {
            printf("Lista de pessoas está vazia\n");
        }
        else
        {
            printf("Lista de pessoas não está vazia\n");
        }
    }
}

void insere_lista_final_pessoas(Lista_pessoa *li, struct pessoa p)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
        return;
    }

    if(li->qtd == MAX_PESSOA)
    {
        printf("Lista de pessoas está cheia para inserção\n");
        return;
    }

    li->dados[li->qtd] = p;
    li->qtd++;

    printf("Pessoa cadastrada com sucesso\n");
}

void remove_lista_ordenada_pessoas(Lista_pessoa *li, int codigo)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
        return;
    }

    if(li->qtd == 0)
    {
        printf("Lista de pessoas está vazia para remoção\n");
        return;
    }

    int i = 0;
    while(i < li->qtd  && li->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li->qtd)
    {
        printf("Pessoa não encontrada para remoção\n");
        return;
    }

    for(int k = i; k < li->qtd - 1; k++)
    {
        li->dados[k] = li->dados[k + 1];
    }

    li->qtd--;

    printf("Pessoa removida com sucesso\n");
}

void consulta_lista_codigo_pessoas(Lista_pessoa *li, int cod)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
        return;
    }

    int i = 0;
    while(i < li->qtd && li->dados[i].codigo != cod)
    {
        i++;
    }

    if(i == li->qtd)
    {
        printf("Pessoa não encontrada\n");
        return;
    }

    printf("Codigo: %d\n", li->dados[i].codigo);
    printf("Nome: %s\n", li->dados[i].nome);
}


void consulta_lista_nome_pessoas(Lista_pessoa *li, char *nome)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
        return;
    }

    int i = 0;
    while(i < li->qtd && strcmp(li->dados[i].nome, nome) != 0)
    {
        i++;
    }

    if(i == li->qtd)
    {
        printf("Pessoa não encontrada\n");
        return;
    }

    printf("Codigo: %d\n", li->dados[i].codigo);
    printf("Nome: %s\n", li->dados[i].nome);
}

void imprime_lista_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
        return;
    }

    if (li->qtd == 0)
    {
        printf("Lista de pessoas está vazia\n");
        return;
    }


    for(int i = 0; i < li->qtd; i++)
    {
        printf("codigo: %d\n",li->dados[i].codigo);
        printf("nome: %s\n",li->dados[i].nome);

        if (li->qtd > 1 && i < li->qtd - 1)
        {
            printf("\n");
        }
    }
}
