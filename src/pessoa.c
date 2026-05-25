#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h> // Para usar a função strcmp
#include "pessoa.h"

// Definição do tipo Lista_pessoa de pessoas 
struct lista_pessoa {
    int qtd;
    struct pessoa dados[MAX];
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

int tamanho_lista_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        return -1;
    }
    else
    {
        return li->qtd;
    } 
}

int lista_cheia_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        return -1;
    }
    else
    {
        return (li->qtd == MAX);
    }
}

int lista_vazia_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        return -1;
    }
    else
    {
        return (li->qtd == 0);
    }
}

int insere_lista_final_pessoas(Lista_pessoa *li, struct pessoa p)
{
    if(li == NULL)
    {
        return 0;
    }

    if(lista_cheia_pessoas(li))
    {
        return 0;
    }

    li->dados[li->qtd] = p;
    li->qtd++;

    return 1;
}

int remove_lista_ordenada_pessoas(Lista_pessoa *li, int codigo)
{
    if(li == NULL)
    {
        return 0;
    }

    if(lista_vazia_pessoas(li))
    {
        return 0;
    }

    int i = 0;
    while(i < li->qtd  && li->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li->qtd)
    {
        return 0;
    }

    for(int k = i; k < li->qtd - 1; k++ )
    {
        li->dados[k] = li->dados[k + 1];
    }

    li->qtd--;

    return 1;
}

int consulta_lista_codigo_pessoas(Lista_pessoa *li, int cod, struct pessoa *p)
{
    if(li == NULL)
    {
        return 0;
    }

    int i = 0;
    while(i < li->qtd && li->dados[i].codigo != cod)
    {
        i++;
    }

    if(i == li->qtd)
    {
        return 0;
    }

    *p = li->dados[i];

    return 1;
}


int consulta_lista_nome_pessoas(Lista_pessoa *li, char *nome, struct pessoa *p)
{
    if(li == NULL)
    {
        return 0;
    }

    int i = 0;
    while(i < li->qtd && strcmp(li->dados[i].nome, nome) != 0)
    {
        i++;
    }

    if(i == li->qtd)
    {
        return 0;
    }

    *p = li->dados[i];

    return 1;
}

int imprime_lista_pessoas(Lista_pessoa *li)
{
    if(li == NULL)
    {
        return 0;
    }

    for(int i = 0; i < li->qtd; i++)
    {
        printf("----------------------------------------------\n"); 
        printf("codigo: %d\n",li->dados[i].codigo);
        printf("Nome: %s \n",li->dados[i].nome);
    }
    getchar();
}
