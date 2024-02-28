#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int dado;
    struct No* proximoNo;
    struct No* NoAnterior;
} No;

// Função para criar um novo nó
No* CriarNo(int dado) {
    No* NovoNo = (No*)malloc(sizeof(No));
    NovoNo->dado = dado;
    NovoNo->proximoNo = NULL;
    NovoNo->NoAnterior = NULL;
    return NovoNo;
}


//LISTAS DUPLAMENTE ENCADEADAS
typedef struct {
    No* head;
    No* tail;
} ListaDuplamenteEncadeada;

// Função para inserir no início da lista duplamente encadeada
void InserirNoInicio(ListaDuplamenteEncadeada* list, int dado) {
    No* NovoNo = CriarNo(dado);

    if (list->head == NULL) {
        list->head = list->tail = NovoNo;
    } else {
        NovoNo->proximoNo = list->head;
        list->head->NoAnterior = NovoNo;
        list->head = NovoNo;
    }
}

// Função para inserir no fim da lista duplamente encadeada
void InserirNoFinal(ListaDuplamenteEncadeada* list, int dado) {
    No* NovoNo = CriarNo(dado);

    if (list->head == NULL) {
        list->head = list->tail = NovoNo;
    } else {
        NovoNo->NoAnterior = list->tail;
        list->tail->proximoNo = NovoNo;
        list->tail = NovoNo;
    }
}

// Função para inserir em uma posição específica da lista duplamente encadeada
void InserirEmPosicaoEspecifica(ListaDuplamenteEncadeada* list, int dado, int posicao) {
    No* NovoNo = CriarNo(dado);

    if (posicao <= 0) {
        InserirNoInicio(list, dado);
    } else {
        No* NoAtual = list->head;
        int PosicaoAtual = 0;

        while (NoAtual != NULL && PosicaoAtual < posicao - 1) {
            NoAtual = NoAtual->proximoNo;
            PosicaoAtual++;
        }

        if (NoAtual != NULL) {
            NovoNo->proximoNo = NoAtual->proximoNo;
            NovoNo->NoAnterior = NoAtual;
            if (NoAtual->proximoNo != NULL) {
                NoAtual->proximoNo->NoAnterior = NovoNo;
            }
            NoAtual->proximoNo = NovoNo;
        }
    }
}

// Função para remover do início da lista duplamente encadeada
void RemoverDoInicio(ListaDuplamenteEncadeada* list) {
    if (list->head != NULL) {
        No* temp = list->head;
        list->head = list->head->proximoNo;
        if (list->head != NULL) {
            list->head->NoAnterior = NULL;
        }
        free(temp);
    }
}

// Função para remover do fim da lista duplamente encadeada
void RemoverDoFim(ListaDuplamenteEncadeada* list) {
    if (list->tail != NULL) {
        No* temp = list->tail;
        list->tail = list->tail->NoAnterior;
        if (list->tail != NULL) {
            list->tail->proximoNo = NULL;
        }
        free(temp);
    }
}

// Função para remover de uma posição específica da lista duplamente encadeada
void RemoverPosicaoEspecifica(ListaDuplamenteEncadeada* list, int posicao) {
    if (posicao <= 0) {
        RemoverDoInicio(list);
    } else {
        No* NoAtual = list->head;
        int PosicaoAtual = 0;

        while (NoAtual != NULL && PosicaoAtual < posicao) {
            NoAtual = NoAtual->proximoNo;
            PosicaoAtual++;
        }

        if (NoAtual != NULL) {
            if (NoAtual->NoAnterior != NULL) {
                NoAtual->NoAnterior->proximoNo = NoAtual->proximoNo;
            }
            if (NoAtual->proximoNo != NULL) {
                NoAtual->proximoNo->NoAnterior = NoAtual->NoAnterior;
            }
            free(NoAtual);
        }
    }
}

// Função para pesquisar um nó na lista duplamente encadeada
No* PesquisarNo(ListaDuplamenteEncadeada* list, int dado) {
    No* NoAtual = list->head;
    while (NoAtual != NULL) {
        if (NoAtual->dado == dado) {
            return NoAtual;
        }
        NoAtual = NoAtual->proximoNo;
    }
    return NULL;
}

// Função para exibir todos os nós da lista duplamente encadeada
void ExibirTodosNos(ListaDuplamenteEncadeada* list) {
    No* NoAtual = list->head;
    while (NoAtual != NULL) {
        printf("%d ", NoAtual->dado);
        NoAtual = NoAtual->proximoNo;
    }
    printf("\n");
}


// LISTA CIRCULAR
typedef struct {
    No* head;
} ListaCircular;

// Função para inserir no início da lista circular
void InserirNoInicioCircularlist(ListaCircular* list, int dado) {
    No* NovoNo = CriarNo(dado);

    if (list->head == NULL) {
        NovoNo->proximoNo = NovoNo;
        NovoNo->NoAnterior = NovoNo;
        list->head = NovoNo;
    } else {
        NovoNo->proximoNo = list->head;
        NovoNo->NoAnterior = list->head->NoAnterior;
        list->head->NoAnterior->proximoNo = NovoNo;
        list->head->NoAnterior = NovoNo;
        list->head = NovoNo;
    }
}

// Função para inserir no fim da lista circular
void InserirNoFinalCircularalist(ListaCircular* list, int dado) {
    No* NovoNo = CriarNo(dado);

    if (list->head == NULL) {
        NovoNo->proximoNo = NovoNo;
        NovoNo->NoAnterior = NovoNo;
        list->head = NovoNo;
    } else {
        NovoNo->proximoNo = list->head;
        NovoNo->NoAnterior = list->head->NoAnterior;
        list->head->NoAnterior->proximoNo = NovoNo;
        list->head->NoAnterior = NovoNo;
    }
}

// Função para inserir em uma posição específica da lista circular
void InserirEmPosicaoEspecificaCircularlist(ListaCircular* list, int dado, int posicao) {
    No* NovoNo = CriarNo(dado);

    if (posicao <= 0) {
        InserirNoInicioCircularlist(list, dado);
    } else {
        No* NoAtual = list->head;
        int PosicaoAtual = 0;

        while (NoAtual != NULL && PosicaoAtual < posicao - 1) {
            NoAtual = NoAtual->proximoNo;
            PosicaoAtual++;
        }

        if (NoAtual != NULL) {
            NovoNo->proximoNo = NoAtual->proximoNo;
            NovoNo->NoAnterior = NoAtual;
            NoAtual->proximoNo->NoAnterior = NovoNo;
            NoAtual->proximoNo = NovoNo;
        }
    }
}

// Função para remover do início da lista circular
void RemoverDoInicioCircularlist(ListaCircular* list) {
    if (list->head != NULL) {
        No* temp = list->head;
        if (list->head->proximoNo == list->head) {
            list->head = NULL;
        } else {
            list->head->NoAnterior->proximoNo = list->head->proximoNo;
            list->head->proximoNo->NoAnterior = list->head->NoAnterior;
            list->head = list->head->proximoNo;
        }
        free(temp);
    }
}