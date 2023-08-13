#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include "constantes.h"

typedef struct poltrona {
    int fileira;
    int letra;
} Poltrona;

typedef struct sala {
    int assentos[QUANTIDADE_FILEIRAS][QUANTIDADE_POLTRONAS];
    int carteiras_estudantis[MAX_INGRESSOS];
    int codigos_itasil[MAX_INGRESSOS];
    int ingressos_disp_salas;
    int num_sala;
    char nome_filme[MAX_NOME_FILME];
} Sala;

typedef struct cinema {
    Sala salas[QUANTIDADE_SALAS];
} Cinema;

#endif
