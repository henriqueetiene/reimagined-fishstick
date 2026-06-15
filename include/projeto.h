#pragma once

#include "tarefa.h"

#define MAX_PROJETO 2

struct projeto
{
    int codigo;
    char titulo[20];
    char descricao[100];
    struct tarefa tarefas[5];
};

typedef struct lista_projeto Lista_projeto;

Lista_projeto *cria_lista_projeto();

void libera_lista_projeto(Lista_projeto *li);
void tamanho_lista_projeto(Lista_projeto *li);
void lista_cheia_projeto(Lista_projeto *li);
void lista_vazia_projeto(Lista_projeto *li);

void insere_lista_final_projeto(Lista_projeto *li, struct projeto t);

void remove_lista_ordenada_projeto(Lista_projeto *li, int codigo);

void consulta_lista_codigo_projeto(Lista_projeto *li, int codigo);

void imprime_lista_projeto(Lista_projeto *li);
