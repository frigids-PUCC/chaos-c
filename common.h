#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OK 	0
#define ERROR 1

#define PUBLIC
#define PRIVATE static

#define TRUE	1
#define FALSE 	0

#define ALUNO     1
#define PROFESSOR 0

// Menu inicial
#define WELCOME            "Chaos Faculdade\n"
#define GET_OPTION		   "Entre com a opção:"
#define OPTIONS_CADASTRO   "1) Cadastrar Aluno\n" "2)Cadastrar Professor\n" "3)Cadastrar Materia\n"
#define OPTIONS_IMPS       "\n5) Impressoes"
#define OPTIONS_MANAGE     "4) Realizar Matricula\n"

// warning
#define TOO_MUCH_P "Muitas pessoas cadastradas\n"
// warning
#define TOO_MUCH_M "Muitas materias cadastradas\n"

#define MAX_NOME_TAM 30
#define MAX_VET		 10

struct Materias{
	char n_materia[MAX_NOME_TAM];
	int count_alunos;
	int exist;
};
typedef struct Materias Mats;

struct No{
    int func;
    unsigned long long ra_mtr;
    char primeiroNome[MAX_NOME_TAM];
    char ultimoNome[MAX_NOME_TAM];
    Mats materias[10];
    struct No *prox;
};
typedef struct No No;

#endif

