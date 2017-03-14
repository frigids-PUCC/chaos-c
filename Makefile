CC=gcc
CFLAG = -lm

all: main

projeto: projeto.c
	$(CC) -c projeto.c -o projeto.o $(CFLAG)

cadastro_aluno: cadastro/cadastro_aluno.c
	$(CC) -c cadastro/cadastro_aluno.c -o cadastro_aluno.o $(CFLAG)

cadastro_prof: cadastro/cadastro_prof.c
	$(CC) -c cadastro/cadastro_prof.c -o cadastro_prof.o $(CFLAG)

cadastro_materias: cadastro/cadastro_materias.c
	$(CC) -c cadastro/cadastro_materias.c -o cadastro_materias.o $(CFLAG)
	
matricula: matricula/matricula.c
	$(CC) -c matricula/matricula.c -o matricula.o $(CFLAG)
	
impressoes: impressoes/impressor.c
	$(CC) -c impressoes/impressor.c -o impressor.o $(CFLAG)
	

main: projeto cadastro_aluno cadastro_prof cadastro_materias matricula impressoes
	$(CC) projeto.o cadastro_aluno.o cadastro_prof.o cadastro_materias.o matricula.o impressor.o -o projeto $(CFLAG)

clean:
	rm *.o
