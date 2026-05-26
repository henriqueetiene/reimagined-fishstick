#pragma once

#include "pessoa.h"

#define MAX_TAREFA 40

struct tarefa {
    int codigo;
    char descricao[100];
    Lista_pessoa *lista_pessoa;
};

typedef struct lista_tarefa Lista_tarefa;

Lista_tarefa *cria_lista_tarefa();

void libera_lista_tarefa(Lista_tarefa *li);
void tamanho_lista_tarefa(Lista_tarefa *li);
void lista_cheia_tarefa(Lista_tarefa *li);
void lista_vazia_tarefa(Lista_tarefa *li);

void insere_lista_final_tarefa(Lista_tarefa *li, struct tarefa tu);

int remove_lista_ordenada_tarefa(Lista_tarefa *li, int codigo);

int consulta_lista_codigo_tarefa(Lista_tarefa *li, int codigo, struct tarefa *tu);

int imprime_lista_tarefa(Lista_tarefa *li);
