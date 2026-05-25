#pragma once

#define MAX 100

struct pessoa {
    int codigo;
    char nome[30];
};

typedef struct lista_pessoa Lista_pessoa;

/* Retorna um ponteiro para uma estrutura Lista_pessoa para pessoas */
Lista_pessoa *cria_lista_pessoas();

void libera_lista_pessoas(Lista_pessoa *li);
/* Retorna o comprimento da Lista_pessoa Linear ou -1 se ela for nula */
int tamanho_lista_pessoas(Lista_pessoa *li);
int lista_cheia_pessoas(Lista_pessoa *li);
int lista_vazia_pessoas(Lista_pessoa *li);

/* -------- INSERÇÃO DE ELEMENTOS NA LISTA --------------*/
/* Insere um pessoa no final. Retorna 0 se a lista não existir ou estiver cheia e 1 se deu certo */
int insere_lista_final_pessoas(Lista_pessoa *li, struct pessoa p);

/* -------- REMOÇÃO DE ELEMENTOS DA LISTA --------------*/
// Remove um elemento da lista por código. Retorna 0, se a lista não existe ou está vazia, OU 1 se elemento removido com sucesso
int remove_lista_ordenada_pessoas(Lista_pessoa *li, int codigo);

/* -------- CONSULTA A ELEMENTOS DA LISTA --------------*/
// Consulta um pessoa pelo código e retorna, por referência, o pessoa pesquisado
int consulta_lista_codigo_pessoas(Lista_pessoa *li, int cod, struct pessoa *p);
// Consulta um pessoa pelo nome e retorna, por referência, o pessoa pesquisado
int consulta_lista_nome_pessoas(Lista_pessoa *li, char *nome, struct pessoa *p);


int imprime_lista_pessoas(Lista_pessoa *li);
