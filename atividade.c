#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nota1, nota2, nota3, nota4, dia, mes, ano;
    char nomeAluno[50];
} aluno;

int menu() {
    int opcoes;
    printf("\n***MENU DE CADASTRO***\n");
    printf("\n 1 - Criar Aluno\n 2 - Listar Aluno\n 3 - Editar\n 0 - SAIR\n");
    scanf("%d", &opcoes);
    return opcoes;
}

void listarAlunos(aluno alunos[], int numAlunos) {
    int i;
    if(numAlunos == 0) {
        printf("Lista vazia!\n");
        fflush(stdin);
        getchar();        
    } else {
        for(i = 0; i < numAlunos; i++) {
            printf("*****************ALUNO [%i]******************\n", i);
            printf("Seu nome: %s Sua data de nascimento: %d/%d/%d\n Suas notas: [%d] - [%d] - [%d] - [%d]\n", alunos[i].nomeAluno, alunos[i].dia, alunos[i].mes, alunos[i].ano, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, alunos[i].nota4);
            printf("*********************************************\n");
            printf("\n");
        }
    }
}

aluno criarAluno() {
    aluno a;

    printf("Digite o seu nome: ");
    fflush(stdin);
    fgets(a.nomeAluno, 50, stdin);
    
    printf("Qual eh a sua data de nascimento: ");
    scanf("%d",&a.dia);
    scanf("%d",&a.mes);
    scanf("%d",&a.ano);

    printf("Digite as notas do seu ano escolar: ");
    scanf("%d",&a.nota1);
    scanf("%d",&a.nota2);
    scanf("%d",&a.nota3);
    scanf("%d",&a.nota4);

    return a;
}

void editarAluno(aluno alunos[], int numAlunos) {
    int index, opcao;
    if(numAlunos > 0) {
        do {
            printf("\nEscolha o aluno a ser editado: ");
            scanf("%d", &index);
            if(index < 0 || index > numAlunos) {
                printf("\nNumero Invalido! Digite um numero de ALUNO CADASTRADO!\n");
                fflush(stdin);
                getchar();
            }
        } while(index < 0 || index > numAlunos);
        
        printf("1 - Editar Nome\n 2 - Editar Data\n 3 - Editar Notas\n");
        scanf("%d" , &opcao);

        switch (opcao)
        {
        case 1:
                printf("Digite o seu nome: ");
                fflush(stdin);
                fgets(alunos[index].nomeAluno, 50, stdin);
            break;
        case 2: 
                printf("Qual eh a sua data de nascimento: ");
                scanf("%d",&alunos[index].dia);
                scanf("%d",&alunos[index].mes);
                scanf("%d",&alunos[index].ano);
            break;  
        case 3:
                printf("Digite as notas do seu ano escolar: ");
                scanf("%d",&alunos[index].nota1);
                scanf("%d",&alunos[index].nota2);
                scanf("%d",&alunos[index].nota3);
                scanf("%d",&alunos[index].nota4);
            break;
        }
    }

}


int main(){
    
    int opcoes, numAlunos = 0;
    aluno listaAlunos[10];
    aluno alunoCriado;

    do {

        opcoes = menu();

        switch (opcoes)
        {
        case 1:
                alunoCriado = criarAluno();
                printf("Seu nome: %s Sua data de nascimento: %d/%d/%d\n Suas notas: [%d] - [%d] - [%d] - [%d]", alunoCriado.nomeAluno, alunoCriado.dia, alunoCriado.mes, alunoCriado.ano, alunoCriado.nota1, alunoCriado.nota2, alunoCriado.nota3, alunoCriado.nota4);
                listaAlunos[numAlunos] = alunoCriado;
                numAlunos += 1;
                fflush(stdin);
                getchar();
            break;
        case 2:
                listarAlunos(listaAlunos, numAlunos);
                fflush(stdin);
                getchar();
            break;
        case 3: 
                listarAlunos(listaAlunos, numAlunos);
                editarAluno(listaAlunos, numAlunos);
            break;
        }
    } while (opcoes != 0); 
}
