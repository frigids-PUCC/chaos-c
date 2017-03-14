/*
 * cadastro.h
 *
 *  Created on: 17 de fev de 2017
 *      Author: yago
 */

#ifndef CADASTRO_CADASTRO_H_
#define CADASTRO_CADASTRO_H_

#include "../common.h"

#define P_NOME_ALUNO "Primeiro nome do aluno:\n"
#define U_NOME_ALUNO "Ultimo nome do aluno:\n"
#define P_NOME_PROF "Primeiro nome do professor:\n"
#define U_NOME_PROF "Ultimo nome do professor:\n"
#define NOME_MAT   "Por favor, defina o nome da materia:\n"

PUBLIC void cadastro_aluno(No *pessoas);
PUBLIC void cadastro_prof(No *pessoas);
PUBLIC void cadastro_mat(Mats materias[]);
PUBLIC int vazia(No *pessoas);

#endif /* CADASTRO_CADASTRO_H_ */
