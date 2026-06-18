#pragma once

#include "tarefa.h"

#define MAX_PROJETO 2

struct projeto
{
    int codigo;
    char titulo[20];
    char descricao[100];
    Lista_tarefa *tarefas;
};

typedef struct lista_projeto Lista_projeto;

Lista_projeto *cria_lista_projeto();

void libera_lista_projeto(Lista_projeto *li);
void tamanho_lista_projeto(Lista_projeto *li);
void lista_cheia_projeto(Lista_projeto *li);
void lista_vazia_projeto(Lista_projeto *li);

void insere_lista_final_projeto(Lista_projeto *li, struct projeto p);

void remove_lista_ordenada_projeto(Lista_projeto *li, int codigo);

struct projeto consulta_lista_codigo_projeto(Lista_projeto *li, int codigo);

void adiciona_tarefa_projeto(Lista_projeto *li, struct tarefa t, int codigo);

void imprime_lista_projeto(Lista_projeto *li);

void atualiza_nome_pessoa_lista_projetos(Lista_projeto *li, int cod_pessoa, char novo_nome[30]);
void atualiza_descricao_tarefa_lista_projetos(Lista_projeto *li, int cod_tarefa, char nova_descricao[100]);

void atualiza_titulo_projeto(Lista_projeto *li, int codigo, char novo_titulo[20]);
void atualiza_descricao_projeto(Lista_projeto *li, int codigo, char nova_descricao[100]);
