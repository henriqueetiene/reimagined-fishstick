#pragma once

#define MAX_PESSOA 2

struct pessoa
{
    int codigo;
    char nome[30];
};

typedef struct lista_pessoa Lista_pessoa;

Lista_pessoa *cria_lista_pessoas();

void libera_lista_pessoas(Lista_pessoa *li);
void tamanho_lista_pessoas(Lista_pessoa *li);
void lista_cheia_pessoas(Lista_pessoa *li);
void lista_vazia_pessoas(Lista_pessoa *li);

void insere_lista_final_pessoas(Lista_pessoa *li, struct pessoa p);

void remove_lista_ordenada_pessoas(Lista_pessoa *li, int codigo);

struct pessoa consulta_lista_codigo_pessoas(Lista_pessoa *li, int cod);
void consulta_lista_nome_pessoas(Lista_pessoa *li, char *nome);

void imprime_lista_pessoas(Lista_pessoa *li);