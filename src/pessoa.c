#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "pessoa.h"

struct lista_pessoa
{
    int qtd;
    struct pessoa dados[MAX_PESSOA];
};

void obtem_data_atual(char *data)
{
    time_t raw_time;
    struct tm *local_time;

    time(&raw_time);

    local_time = localtime(&raw_time);

    strftime(data, 80, "%Y-%m-%d %H:%M:%S", local_time);
}

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
    char data[80];
    obtem_data_atual(data);

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

    if (p.codigo <= 0)
    {
        printf("Código deve ser um valor positivo maior que 0\n");
        return;
    }

    strcpy(p.h[0].ocorrencia, "Cadastro");
    strcpy(p.h[0].data, data);
    p.qtd_historico = 1;

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

struct pessoa consulta_lista_codigo_pessoas(Lista_pessoa *li, int cod)
{
    if(li == NULL)
    {
        printf("Não há lista de pessoas\n");
        return (struct pessoa){-1};
    }

    int i = 0;
    while(i < li->qtd && li->dados[i].codigo != cod)
    {
        i++;
    }

    if(i == li->qtd)
    {
        printf("Pessoa não encontrada\n");
        return (struct pessoa){-1};
    }

    return li->dados[i];
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
        printf("Código: %d\n",li->dados[i].codigo);
        printf("Nome: %s\n",li->dados[i].nome);

        printf("\n-----Histórico-----\n");
        for (int k = 0; k < li->dados[i].qtd_historico; k++)
        {
            printf("%s\n", li->dados[i].h[k].ocorrencia);
            printf("%s\n", li->dados[i].h[k].data);

            if (li->dados[i].qtd_historico > 1 && k < li->dados[i].qtd_historico - 1)
            {
                printf("\n");
            }
            
        }
        printf("---------------------\n");

        if (li->qtd > 1 && i < li->qtd - 1)
        {
            printf("==================================\n");
            printf("\n");
        }
    }
}

void atualiza_nome_pessoa_lista_pessoas(Lista_pessoa *li, int cod, char novo_nome[30])
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

    char nome_antigo[30];
    for (int k = 0; k < 30; k++)
    {
        nome_antigo[k] = li->dados[i].nome[k];
    }
    
    for (int k = 0; k < 30; k++)
    {
        li->dados[i].nome[k] = novo_nome[k];
    }

    strcpy(li->dados[i].h[li->dados[i].qtd_historico].ocorrencia, "Atualizou o nome");
    obtem_data_atual(li->dados[i].h[li->dados[i].qtd_historico].data);
    li->dados[i].qtd_historico++;
}
