/*
 * impressor.c
 *
 *  Created on: 12 de mar de 2017
 *      Author: yago
 */
#include "impressor.h"

PRIVATE void imprime_materias(Mats materias[]);
PRIVATE void imprime_pessoas(char materia[], No *pessoas, int flag);

PUBLIC void impressoes(Mats materias[], No *pessoas) {
	int opt = -1, cnt;
	unsigned long long ra_mtr;
	char nome_mat[MAX_NOME_TAM];
	printf(OPT_IMP);
	printf(OPT_IMP_2);
	printf(OPT_IMP_3);
	scanf("%i", &opt);
	while (1 == 1) {
		switch (opt) {
		case 1:
			printf("Alunos:\n");
			if (vazia(pessoas)) {
				printf("Lista vazia");
			} else {
				No *tmp;
				tmp = pessoas->prox;
				while (tmp != NULL) {
					if (tmp->func == ALUNO) {
						printf("%s %s, ra: %llu\n", tmp->primeiroNome,
								tmp->ultimoNome, tmp->ra_mtr);
					}
					tmp = tmp->prox;
				}
			}
			return;
		case 2:
			printf("\nProfessores:\n");
			if (vazia(pessoas)) {
				printf("Lista vazia");
			} else {
				No *tmp;
				tmp = pessoas->prox;
				while (tmp != NULL) {
					if (tmp->func == PROFESSOR) {
						printf("%s %s, matricula: %llu\n", tmp->primeiroNome,
								tmp->ultimoNome, tmp->ra_mtr);
					}
					tmp = tmp->prox;
				}
			}
			return;
		case 3:
			printf("\nDisciplinas:\n");
			for (cnt = 0; cnt < MAX_VET; cnt++) {
				if (materias[cnt].exist == TRUE) {
					printf("%s\n", materias[cnt].n_materia);
				}
			}
			return;
		case 4:
			printf(N_RA);
			scanf("%llu", &ra_mtr);
			if (vazia(pessoas)) {
				printf("Lista vazia");
			} else {
				No *tmp;
				tmp = pessoas->prox;
				while (tmp != NULL) {
					if (tmp->ra_mtr == ra_mtr) {

						printf("\nAluno %s %s", tmp->primeiroNome,
								tmp->ultimoNome);
						imprime_materias(tmp->materias);
						return;
					}
					tmp = tmp->prox;
				}
			}
			return;
		case 5:
			printf(N_MAT);
			scanf("%s", nome_mat);
			for (cnt = 0; cnt < MAX_VET; cnt++) {
				if (strcmp(materias[cnt].n_materia, nome_mat) == 0) {
					imprime_pessoas(nome_mat, pessoas, 1);
				}
			}
			return;
		case 6:
			printf(N_MTR);
			scanf("%llu", &ra_mtr);
			if (vazia(pessoas)) {
				printf("Lista vazia");
			} else {
				No *tmp;
				tmp = pessoas->prox;
				while (tmp != NULL) {
					if (tmp->ra_mtr == ra_mtr) {
						printf("\nProfessor %s %s", tmp->primeiroNome,
								tmp->ultimoNome);
						imprime_materias(tmp->materias);
					}

					tmp = tmp->prox;
				}
			}
			return;
		case 7:
			printf(N_MAT);
			scanf("%s", nome_mat);
			for (cnt = 0; cnt < MAX_VET; cnt++) {
				if (strcmp(materias[cnt].n_materia, nome_mat) == 0) {
					imprime_pessoas(nome_mat, pessoas, 0);
				}
			}
			return;
		default:
			break;

		}
	}
}

PRIVATE void imprime_materias(Mats materias[]) {
	int cnt;
	printf("\nDisciplinas:\n");
	for (cnt = 0; cnt < MAX_VET; cnt++) {
		if (strcmp(materias[cnt].n_materia, "false") != 0) {
			printf("%s\n", materias[cnt].n_materia);
		}
	}
}

PRIVATE void imprime_pessoas(char materia[], No *pessoas, int flag) {
	int i;
	if (vazia(pessoas)) {
		printf("Lista vazia");
	} else {
		No *tmp;
		tmp = pessoas->prox;
		while (tmp != NULL) {
			if (tmp->func == flag) {
				for (i = 0; i < MAX_VET; i++) {
					if (strcmp(materia, tmp->materias[i].n_materia) == 0) {
						printf("\n%s %s\n", tmp->primeiroNome, tmp->ultimoNome);
					}
				}
			}
			tmp = tmp->prox;
		}
	}
}
