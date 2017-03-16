#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "common.h"
#include "cadastro/cadastro.h"
#include "matricula/matricula.h"
#include "impressoes/impressor.h"
#include <string.h>

PRIVATE void control_opt();
PRIVATE void inicia_lista(No *pessoas);
PRIVATE void inicia_materias(Mats materias[]);

PUBLIC int main(int argc, char *argv[]) {

	control_opt();

	return OK;
}

PRIVATE void control_opt() {
	// Declaração estruturas e lista de alunos.
	No *pessoas = (No*) malloc(sizeof(No));
	Mats materias[MAX_VET];
	inicia_materias(materias);
	if (!pessoas) {
		exit(1);
	}

	int cnt_pessoas = 0;
	int opt;
	printf(WELCOME);
	printf(OPTIONS_CADASTRO);
	printf(OPTIONS_MANAGE);
	printf(GET_OPTION);
	scanf("%i", &opt);
	int i;
	char *nome;
	inicia_lista(pessoas);
	while (1) {

		int i = 0;
		if (cnt_pessoas >= MAX_VET) {
			printf(TOO_MUCH_P);
			continue;
		}
		// Switch do controle do menu.
		switch (opt) {
		case 1:
			cadastro_aluno(pessoas);
			break;
		case 2:
			cadastro_prof(pessoas);
			break;
		case 3:
			cadastro_mat(materias);
			break;
		case 4:
			matricula(materias, pessoas);
			break;
		case 5:
			impressoes(materias, pessoas);
			break;
		default:
			break;
		}
		printf(WELCOME);
		printf(OPTIONS_CADASTRO);
		printf(OPTIONS_MANAGE);
		printf(GET_OPTION);
		scanf("%i", &opt);
	}
	free(pessoas);
}

PRIVATE void inicia_materias(Mats materias[]) {
	int i;
	for (i = 0; i < MAX_VET; i++) {
		materias[i].exist = FALSE;
	}
}

PRIVATE void inicia_lista(No *pessoas) {
	pessoas->prox = NULL;
}

