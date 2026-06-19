#pragma once

#include "pessoa.h"

#define MAX_TAREFA 2

struct tarefa
{
    int codigo;
    char descricao[100];
    struct pessoa pessoa;
    struct historico h[20];
    int qtd_historico;
};

typedef struct lista_tarefa Lista_tarefa;

Lista_tarefa *cria_lista_tarefa();

void libera_lista_tarefa(Lista_tarefa *li);
void tamanho_lista_tarefa(Lista_tarefa *li);
void lista_cheia_tarefa(Lista_tarefa *li);
void lista_vazia_tarefa(Lista_tarefa *li);

void insere_lista_final_tarefa(Lista_tarefa *li, struct tarefa t);

void remove_lista_ordenada_tarefa(Lista_tarefa *li, int codigo);

struct tarefa consulta_lista_codigo_tarefa(Lista_tarefa *li, int codigo);

void adiciona_pessoa_tarefa(Lista_tarefa *li_tarefa, struct pessoa p, int codigo);
void remove_pessoa_tarefa(Lista_tarefa *li_tarefa, int codigo);
void remove_pessoa_deletada_tarefa(Lista_tarefa *li_tarefa, int cod_pessoa);

void imprime_lista_tarefa(Lista_tarefa *li);
void imprime_historico_tarefa(Lista_tarefa *li, int codigo);

void atualiza_nome_pessoa_lista_tarefas(Lista_tarefa *li_tarefa, int cod_pessoa, char novo_nome[30]);
void atualiza_descricao_tarefa_lista_tarefas(Lista_tarefa *li_tarefa, int cod_tarefa, char nova_descricao[100]);
