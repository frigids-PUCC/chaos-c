/*
 * cadastro_materias.c
 *
 *  Created on: 1 de mar de 2017
 *      Author: yago
 */

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

PUBLIC No *aloca_prof();

/**
 * Recebe o vetor de alunos e manipula-o.
 * */
PUBLIC void cadastro_mat(Mats materias[]) {
	int i;
	for (i = 0; i < MAX_VET; i++) {
		if (materias[i].exist == FALSE) {
			printf(NOME_MAT);
			scanf("%s", materias[i].n_materia);
			materias[i].exist = 1;
			materias[i].count_alunos = 0;
			return;
		} else if (materias[i].exist != FALSE && i == MAX_VET){
			printf(TOO_MUCH_M);
			return;
		}
	}
}
