#include <stdlib.h>
#include <stdio.h>
#include "tarefa.h"
#include "pessoa.h"

struct lista_tarefa
{
    int qtd;
    struct tarefa dados[MAX_TAREFA];
};

Lista_tarefa *cria_lista_tarefa()
{
    Lista_tarefa *li_taLista_tarefa;
    li_taLista_tarefa = malloc(sizeof(struct lista_tarefa));

    if(li_taLista_tarefa != NULL)
    {
        li_taLista_tarefa->qtd = 0;
    }

    return li_taLista_tarefa;  
}

void libera_lista_tarefa(Lista_tarefa *li_tarefa)
{
    free(li_tarefa);
}

void tamanho_lista_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
    }
    else
    {
        printf("Quantidade de tarefas cadastradas: %d\n", li_tarefa->qtd);
    }
}

void lista_cheia_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
    }
    else
    {
        if (li_tarefa->qtd == MAX_TAREFA)
        {
            printf("Lista de tarefas está cheia\n");
        }
        else
        {
            printf("Lista de tarefas não está cheia\n");
        }
    }
}

void lista_vazia_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
    }
    else
    {
        if (li_tarefa->qtd == 0)
        {
            printf("Lista de tarefas está vazia\n");
        }
        else
        {
            printf("Lista de tarefas não está vazia\n");
        }
    }
}

void insere_lista_final_tarefa(Lista_tarefa *li_tarefa, struct tarefa t)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        return;
    }

    if(li_tarefa->qtd == MAX_TAREFA)
    {
        printf("Lista de tarefas está cheia para inserção\n");
        return;
    }

    if (t.codigo <= 0)
    {
        printf("Código deve ser um valor positivo maior que 0\n");
        return;
    }    

    li_tarefa->dados[li_tarefa->qtd] = t;
    li_tarefa->qtd++;

    printf("Tarefa cadastrada com sucesso\n");
}

void remove_lista_ordenada_tarefa(Lista_tarefa *li_tarefa, int codigo)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        return;
    }

    if(li_tarefa->qtd == 0)
    {
        printf("Lista de tarefas está vazia\n");
        return;
    }

    int i = 0;
    while(i < li_tarefa->qtd  && li_tarefa->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li_tarefa->qtd)
    {
        printf("Tarefa não encontrada para remoção\n");
        return;
    }

    for(int k = i; k < li_tarefa->qtd-1; k++ )
    {
        li_tarefa->dados[k] = li_tarefa->dados[k + 1];
    }

    li_tarefa->qtd--;

    printf("Tarefa removida com sucesso\n");
}

struct tarefa consulta_lista_codigo_tarefa(Lista_tarefa *li_tarefa, int codigo)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        return (struct tarefa){-1};
    }

    int i = 0;
    while(i < li_tarefa->qtd && li_tarefa->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li_tarefa->qtd)
    {
        printf("Tarefa não encontrada\n");
        return (struct tarefa){-1};
    }

    return li_tarefa->dados[i];
}

void adiciona_pessoa_tarefa(Lista_tarefa *li_tarefa, struct pessoa p, int codigo)
{
    int i = 0;
    while(i < li_tarefa->qtd && li_tarefa->dados[i].codigo != codigo)
    {
        i++;
    }

    li_tarefa->dados[i].pessoa = p;
}

void remove_pessoa_tarefa(Lista_tarefa *li_tarefa, int codigo)
{
    int i = 0;
    while(i < li_tarefa->qtd && li_tarefa->dados[i].codigo != codigo)
    {
        i++;
    }

    if(i == li_tarefa->qtd)
    {
        printf("Tarefa não encontrada\n");
        return;
    }

    if (li_tarefa->dados[i].pessoa.codigo == -1)
    {
        printf("Não há pessoa vinculada para essa tarefa\n");
        return;
    }

    li_tarefa->dados[i].pessoa.codigo = -1;
    
    printf("Pessoa removida da tarefa\n");
}

void remove_pessoa_deletada_tarefa(Lista_tarefa *li_tarefa, int cod_pessoa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        return;
    }

    int i = 0;
    while(i < li_tarefa->qtd && li_tarefa->dados[i].pessoa.codigo != cod_pessoa)
    {
        i++;
    }

    if(i == li_tarefa->qtd)
    {
        printf("Pessoa não está vinculada a nenhuma tarefa\n");
        return;
    }

    li_tarefa->dados[i].pessoa.codigo = -1;

    printf("Pessoa removida da tarefa\n");
}

void imprime_lista_tarefa(Lista_tarefa *li_tarefa)
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        return;
    }

    if (li_tarefa->qtd == 0)
    {
        printf("Lista de tarefas está vazia\n");
        return;
    }
    

    for(int i = 0; i < li_tarefa->qtd; i++)
    {
        printf("Código: %d\n", li_tarefa->dados[i].codigo);
        printf("Descrição: %s\n", li_tarefa->dados[i].descricao);

        if (li_tarefa->dados[i].pessoa.codigo > 0)
        {
            printf("Pessoa responsável pela tarefa: %s\n", li_tarefa->dados[i].pessoa.nome);
        }

        if (li_tarefa->qtd > 1 && i < li_tarefa->qtd - 1)
        {
            printf("\n");
        }
    }
}

void atualiza_nome_pessoa_lista_tarefas(Lista_tarefa *li_tarefa, int cod_pessoa, char novo_nome[30])
{
    if(li_tarefa == NULL)
    {
        printf("Não há lista de tarefas\n");
        return;
    }

    int i = 0;
    while(i < li_tarefa->qtd && li_tarefa->dados[i].pessoa.codigo != cod_pessoa)
    {
        i++;
    }

    if(i == li_tarefa->qtd)
    {
        return;
    }

    for (int k = 0; k < 30; k++)
    {
        li_tarefa->dados[i].pessoa.nome[k] = novo_nome[k];
    }
}
