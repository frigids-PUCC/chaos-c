/*
 * impressor.h
 *
 *  Created on: 12 de mar de 2017
 *      Author: yago
 */

#ifndef IMPRESSOES_IMPRESSOR_H_
#define IMPRESSOES_IMPRESSOR_H_

#include "../common.h"
#include <string.h>
#include "../cadastro/cadastro.h"
#include "../matricula/matricula.h"

#define OPT_IMP   "\n1)Imprimir todos os alunos" "\n2)Imprimir todos os professores" "\n3)Imprimir todas as materias"
#define OPT_IMP_2 "\n4)Imprimir todas materia de um aluno" "\n5)Imprimir todos alunos em uma materia"
#define OPT_IMP_3 "\n6)Imprimir todas materia de um professor" "\n7)Imprimir todos professores em uma materia"

#define A_INV "\nAluno nao encontrado"
#define P_INV "\nProfessor nao encontrado"
#define M_INV "\nMateria nao encontrada"

#define N_MAT "\nNome da materia:"

PUBLIC void impressoes(Mats materias[], No *pessoas);

#endif /* IMPRESSOES_IMPRESSOR_H_ */
