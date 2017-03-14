/*
 * matricula.c
 *
 *  Created on: 10 de mar de 2017
 *      Author: yago
 */
#include "matricula.h"

PRIVATE void matricular_aluno(Mats materias[], No *pessoas);
PRIVATE void matricular_prof(Mats materias[], No *pessoas);
PRIVATE int checa_materia(char n_mat[], Mats materias[]);
PRIVATE void att_materia(char n_mat[], Mats materias[]);

PUBLIC void matricula(Mats materias[], No *pessoas) {
	int opt = 0;
	printf(OPTS);
	while (1 == 1) {
		scanf("%i", &opt);
		if (opt != 1 && opt != 2) {
			printf(OPTS_ERR);
			opt = 0;
		} else
			break;
	}

	switch (opt) {
	case 1:
		matricular_aluno(materias, pessoas);
		break;
	case 2:
		matricular_prof(materias, pessoas);
	default:
		break;
	}
}

PRIVATE void matricular_aluno(Mats materias[], No *pessoas) {
	int ret = -1, opt_in = -1, opt_ra = -1, search_control = 0;
	char p_nome[MAX_NOME_TAM], u_nome[MAX_NOME_TAM], n_mat[MAX_NOME_TAM];
	unsigned long long ra;
	while (1 == 1) {
		printf(A_RA_VS_NOME);
		scanf("%i", &opt_ra);
		switch (opt_ra) {
		case 0:
			printf(P_MATRIC_ALUNO);
			scanf("%s", p_nome);
			printf(U_MATRIC_ALUNO);
			scanf("%s", u_nome);
			if (vazia(pessoas)) {
				printf("Lista vazia");
			} else {
				No *tmp;
				tmp = pessoas->prox;
				while (tmp != NULL) {
					if (strcmp(tmp->primeiroNome, p_nome) == 0
							&& strcmp(tmp->ultimoNome, u_nome) == 0) {
						//printf("%s", tmp->materias[0].n_materia);
						while (1 == 1) {
							printf(W_MAT_VINCULAR);
							scanf("%s", n_mat);
							ret = checa_materia(n_mat, materias);
							// Se a materia existe.

							if (ret == OK) {
								int i;
								for (i = 0; i < MAX_VET; i++) {
									// Tenta encaixar em uma posição valida.
									if (strcmp(tmp->materias[i].n_materia,
											"false") == 0) {
										strcpy(tmp->materias[i].n_materia,
												n_mat);
										att_materia(n_mat, materias);
									}
									break;
								}
							} else {
								// @TODO implementar o else
								printf(MAT_INV);
								continue;
							}
							printf(MAIS_MAT);
							scanf("%i", &opt_in);
							if (opt_in == 1) {
								continue;
							} else if (opt_in == 0) {
								return;
							}
						}
					}
					tmp = tmp->prox;
				}
				printf(ALU_INV);
				return;
			}
			break;
		case 1:
			printf(N_RA);
			scanf("%llu", &ra);
			if (vazia(pessoas)) {
				printf("Lista vazia");
			} else {
				No *tmp;
				tmp = pessoas->prox;
				while (tmp != NULL) {
					if (tmp->ra_mtr == ra) {
						printf("\nAluno %s %s", tmp->primeiroNome, tmp->ultimoNome);
						//printf("%s", tmp->materias[0].n_materia);
						while (1 == 1) {
							printf(W_MAT_VINCULAR);
							scanf("%s", n_mat);
							ret = checa_materia(n_mat, materias);
							// Se a materia existe.

							if (ret == OK) {
								int i;
								for (i = 0; i < MAX_VET; i++) {
									// Tenta encaixar em uma posição valida.
									if (strcmp(tmp->materias[i].n_materia,
											"false") == 0) {
										strcpy(tmp->materias[i].n_materia,
												n_mat);
										att_materia(n_mat, materias);
									}
									break;
								}
							} else {
								// @TODO implementar o else
								printf(MAT_INV);
								//continue;
							}
							printf(MAIS_MAT);
							scanf("%i", &opt_in);
							if (opt_in == 1) {
								continue;
							} else if (opt_in == 0) {
								return;
							}
						}
					}
					tmp = tmp->prox;
				}
				printf(ALU_INV);
				return;
			}
			break;
		default:
			break;

		}
	}

}

PRIVATE int checa_materia(char n_mat[], Mats materias[]) {
	int i;
	for (i = 0; i < MAX_VET; i++) {
		if (strcmp(materias[i].n_materia, n_mat) == 0) {
			return OK;
		}
	}
	return ERROR;
}

PRIVATE void att_materia(char n_mat[], Mats materias[]) {
	int i;
	for (i = 0; i < MAX_VET; i++) {
		if (strcmp(materias[i].n_materia, n_mat) == 0) {
			materias[i].count_alunos++;
		}
	}
}

PRIVATE void matricular_prof(Mats materias[], No *pessoas) {
	int ret = -1, opt_in = -1, opt_ra = -1, search_control = 0;
		char p_nome[MAX_NOME_TAM], u_nome[MAX_NOME_TAM], n_mat[MAX_NOME_TAM];
		unsigned long long mtr;
		while (1 == 1) {
			printf(A_RA_VS_NOME);
			scanf("%i", &opt_ra);
			switch (opt_ra) {
			case 0:
				printf(P_MATRIC_ALUNO);
				scanf("%s", p_nome);
				printf(U_MATRIC_ALUNO);
				scanf("%s", u_nome);
				if (vazia(pessoas)) {
					printf("Lista vazia");
				} else {
					No *tmp;
					tmp = pessoas->prox;
					while (tmp != NULL) {
						if (strcmp(tmp->primeiroNome, p_nome) == 0
								&& strcmp(tmp->ultimoNome, u_nome) == 0) {
							//printf("%s", tmp->materias[0].n_materia);
							while (1 == 1) {
								printf(W_MAT_VINCULAR);
								scanf("%s", n_mat);
								ret = checa_materia(n_mat, materias);
								// Se a materia existe.

								if (ret == OK) {
									int i;
									for (i = 0; i < MAX_VET; i++) {
										// Tenta encaixar em uma posição valida.
										if (strcmp(tmp->materias[i].n_materia,
												"false") == 0) {
											strcpy(tmp->materias[i].n_materia,
													n_mat);
											att_materia(n_mat, materias);
										}
										break;
									}
								} else {
									// @TODO implementar o else
									printf(MAT_INV);
									continue;
								}
								printf(MAIS_MAT);
								scanf("%i", &opt_in);
								if (opt_in == 1) {
									continue;
								} else if (opt_in == 0) {
									return;
								}
							}
						}
						tmp = tmp->prox;
					}
					printf(ALU_INV);
					return;
				}
				break;
			case 1:
				printf(N_MTR);
				scanf("%llu", &mtr);
				if (vazia(pessoas)) {
					printf("Lista vazia");
				} else {
					No *tmp;
					tmp = pessoas->prox;
					while (tmp != NULL) {
						if (tmp->ra_mtr == mtr) {
							printf("\nProfessor %s %s", tmp->primeiroNome, tmp->ultimoNome);
							//printf("%s", tmp->materias[0].n_materia);
							while (1 == 1) {
								printf(W_MAT_VINCULAR);
								scanf("%s", n_mat);
								ret = checa_materia(n_mat, materias);
								// Se a materia existe.

								if (ret == OK) {
									int i;
									for (i = 0; i < MAX_VET; i++) {
										// Tenta encaixar em uma posição valida.
										if (strcmp(tmp->materias[i].n_materia,
												"false") == 0) {
											strcpy(tmp->materias[i].n_materia,
													n_mat);
											att_materia(n_mat, materias);
										}
										break;
									}
								} else {
									// @TODO implementar o else
									printf(MAT_INV);
									//continue;
								}
								printf(MAIS_MAT);
								scanf("%i", &opt_in);
								if (opt_in == 1) {
									continue;
								} else if (opt_in == 0) {
									return;
								}
							}
						}
						tmp = tmp->prox;
					}
					printf(ALU_INV);
					return;
				}
				break;
			default:
				break;

			}
		}

}
