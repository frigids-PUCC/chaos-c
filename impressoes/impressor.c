/*
 * impressor.c
 *
 *  Created on: 12 de mar de 2017
 *      Author: yago
 */
#include "impressor.h"

PRIVATE void imprime_materias(Mats materias[]);

PUBLIC void impressoes(Mats materias[], No *pessoas) {
	int opt = -1, cnt;
	unsigned long long ra_mtr;
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
						return;
					}
					tmp = tmp->prox;
				}
			}
			printf(A_INV);
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
						printf("%s %s, ra: %llu\n", tmp->primeiroNome,
								tmp->ultimoNome, tmp->ra_mtr);
						return;
					}
					tmp = tmp->prox;
				}
			}
			printf(P_INV);
			return;
		case 3:
			printf("Disciplinas:\n");
			for (cnt = 0; cnt < MAX_VET; cnt++) {
				if (materias[cnt].exist == TRUE) {
					printf("%s\n", materias[cnt].n_materia);
					return;
				}
			}
			printf(M_INV);
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
						//printf("%s", tmp->materias[0].n_materia);
						imprime_materias(tmp->materias);
					}
				}
				tmp = tmp->prox;
			}
			printf(ALU_INV);
			return;
		case 5:
			break;
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
						//printf("%s", tmp->materias[0].n_materia);
						imprime_materias(tmp->materias);
					}
				}
				tmp = tmp->prox;
			}
			printf(ALU_INV);
			return;
		case 7:
			break;
		default:
			break;

		}
	}
}

PRIVATE void imprime_materias(Mats materias[]) {
	int cnt;
	printf("Disciplinas:\n");
	for (cnt = 0; cnt < MAX_VET; cnt++) {
		if (materias[cnt].exist == TRUE) {
			printf("%s\n", materias[cnt].n_materia);
		}
	}
}
