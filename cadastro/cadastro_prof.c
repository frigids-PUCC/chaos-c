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
	printf("\nCadastrado professor: %s %s, matricula: %llu\n",
			new->primeiroNome, new->ultimoNome, new->ra_mtr);
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
	int i;
	struct timeval tv;
	gettimeofday(&tv, NULL);

	unsigned long long ra = (unsigned long long) (tv.tv_sec) * 1000
			+ (unsigned long long) (tv.tv_usec) / 1000;
	No *novo = (No*) malloc(sizeof(No));
	char *nome = malloc(MAX_NOME_TAM);
	Mats tmp_mat;
	tmp_mat.count_alunos = 0;
	tmp_mat.exist = FALSE;
	strcpy(tmp_mat.n_materia, "false");
	if (!novo) {
		printf("Sem memoria disponivel!\n");
		exit(1);
	} else {
		printf(P_NOME_PROF);
		scanf("%s", novo->primeiroNome);
		printf(U_NOME_PROF);

		scanf("%s", novo->ultimoNome);
		for (i = 0; i < MAX_VET; i++) {
			novo->materias[i] = tmp_mat;
		}
		novo->func = PROFESSOR;
		novo->ra_mtr = ra;
		return novo;
	}

}
