/*
 * cadastro_prof.c
 *
 *  Created on: 22 de fev de 2017
 *      Author: yago
 */
#include <stdio.h>
#include <stdlib.h>
#include "../common.h"
#include "cadastro.h"
#include <string.h>
#include <sys/time.h>

PUBLIC No *aloca_prof();

/**
 * Recebe o vetor de alunos e manipula-o.
 * */
PUBLIC void cadastro_prof(No *pessoas) {
	No *new = aloca_prof();
	printf("\nCadastrado professor: %s %s, matricula: %llu\n", new->primeiroNome, new->ultimoNome, new->ra_mtr);
	new->prox = NULL;

	if (vazia(pessoas)) {
		pessoas->prox = new;
	} else {
		No *tmp = pessoas->prox;

		while (tmp->prox != NULL) {
			tmp = tmp->prox;
		}
		tmp->prox = new;
	}
}

PUBLIC No *aloca_prof() {
	No *novo = (No*) malloc(sizeof(No));
	struct timeval tv;
	gettimeofday(&tv,NULL);

	unsigned long long matricula =
	    (unsigned long long)(tv.tv_sec) * 1000 +
	    (unsigned long long)(tv.tv_usec) / 1000;

	if (!novo) {
		printf("Sem memoria disponivel!\n");
		exit(1);
	} else {
		printf(P_NOME_PROF);
		scanf("%s", novo->primeiroNome);
		printf(U_NOME_PROF);
		scanf("%s", novo->ultimoNome);
		novo->func = PROFESSOR;
		novo->ra_mtr = matricula;
		return novo;
	}
}
