/*
 * matricula.h
 *
 *  Created on: 10 de mar de 2017
 *      Author: yago
 */

#ifndef MATRICULA_MATRICULA_H_
#define MATRICULA_MATRICULA_H_

#include "../common.h"
#include <string.h>
#include "../cadastro/cadastro.h"

#define OPTS "\nDigite 1 p/ vincular aluno, 2 para vincular professor, ou 3 para cancelar uma matricula: "
#define OPTS_ERR "\nOpção inválida\n"

#define RMV_RA "\nNumero do RA do aluno:"
#define RMV_MAT "\nNome da materia:"

#define MAT_INV "\nMateria invalida"
#define ALU_INV "\nAluno não encontrado no sistema"
#define PRO_INV "\nProfessor não encontrado no sistema"

#define A_RA_VS_NOME "\nCadastrar por nome (0) ou ra (1)"
#define P_RA_VS_NOME "\nCadastrar por nome (0) ou matricula (1)"

#define N_RA "\nNumero do RA:"
#define N_MTR "\nNumero da matricula:"
#define P_MATRIC_ALUNO "\nPrimeiro nome do aluno a ser vinculado: "
#define U_MATRIC_ALUNO "\nUltimo nome do aluno a ser vinculado: "
#define P_MATRIC_PROF "\nPrimeiro nome do professor a ser vinculado: "
#define U_MATRIC_PROF "\nUltimo nome do aluno a ser vinculado: "
#define W_MAT_VINCULAR "\nNome da materia que queira vincular:"
#define MAIS_MAT "\nVincular mais?(1 = sim/ 0 = nao):"
#define CADASTRADO "\nCadastrado aluno: %s %s, ra: %i\n"


PUBLIC void matricula(Mats materias[], No *pessoas);

#endif /* MATRICULA_MATRICULA_H_ */

