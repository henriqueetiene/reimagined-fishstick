#include <stdlib.h>
#include <stdio.h>
#include <projeto.h>

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
        getchar();
        return;
    }

    if(li->qtd == MAX_PROJETO)
    {
        printf("Lista de projetos está cheia para inserção\n");
        getchar();
        return;
    }

    li->dados[li->qtd] = p;
    li->qtd++;

    printf("Projeto cadastrado com sucesso\n");

    getchar();
}

void remove_lista_ordenada_projeto(Lista_projeto *li, int codigo)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
        getchar();
        return;
    }

    if(li->qtd == 0)
    {
        printf("Lista de projetos está vazia\n");
        getchar();
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
        getchar();
        return;
    }

    for(int k = i; k < li->qtd-1; k++ )
    {
        li->dados[k] = li->dados[k + 1];
    }

    li->qtd--;

    printf("Projeto removido com sucesso\n");

    getchar();
}

void consulta_lista_codigo_projeto(Lista_projeto *li, int codigo)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
        getchar();
        return;
    }

    int i = 0;
    while(i < li->qtd && li->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li->qtd)
    {
        printf("projeto não encontrada\n");
        getchar();
        return;
    }

    printf("Código: %d\n", li->dados[i].codigo);
    printf("Descrição: %s\n", li->dados[i].descricao);
    

    getchar();
}

void imprime_lista_projeto(Lista_projeto *li)
{
    if(li == NULL)
    {
        printf("Não há lista de projetos\n");
        getchar();
        return;
    }

    if (li->qtd == 0)
    {
        printf("Lista de projetos está vazia\n");
        getchar();
        return;
    }

    for(int i = 0; i < li->qtd; i++)
    {
        printf("------------------------------------------------------\n");
        printf("Código: %d\n", li->dados[i].codigo);
        printf("Descrição: %s\n", li->dados[i].descricao);
    }

    getchar();
}
