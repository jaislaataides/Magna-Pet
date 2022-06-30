#include <string.h>
#include "tratamentos.h"

//-------- C A D A S T R O ----------
//obter nome
char *Nome(){
    char *nome = malloc(50 * sizeof(char*));
    fflush(stdin);
    printf("\nDigite o nome: ");
    fgets(nome, 50, stdin);
    tratamentoASCII(nome);
    return nome;
}

//obter CPF ou CNPJ do usuário
char *CPF(){
    char *input = malloc(14*sizeof(char*));
    fflush(stdin);
    printf("\nDigite seu CPF ou CNPJ: ");
    fgets(input, 14, stdin);
    tratamentoCPFCNPJ(input);
    return input;
}

//obter email do usuário
char *Email(){
    char *email = malloc(20 * sizeof(char*));
    fflush(stdin);
    printf("\nDigite o email: ");
    fgets(email, 30, stdin);
    tratamentoEmail(email);
    return email;
}

//obter senha do usuário
char *Senha(){
    char *senha = malloc(10 * sizeof(char*));
    fflush(stdin);
    printf("\nDigite sua senha (6 - 10 digitos): ");
    fgets(senha, 10, stdin);
    fflush(stdin);
    return senha;
}

//confirmar digitação de email e senha
void Confirma(char *palavra1, char *palavra3){
    char *palavra2 = malloc(20 * sizeof(char));
    fflush(stdin);
    printf("\nConfirme %s: ",palavra1);
    fgets(palavra2, 30, stdin);
    fflush(stdin);
    tratamentoConfirmacao(palavra1, palavra2, palavra3);
    free(palavra2);
}

//---------- C A D A S T R A R   P E T S ----------

//setar variavel/vetor struct
int Quantidade(){
    int *quant = malloc(sizeof(int));
    char *qtd = malloc(2 * sizeof(char));
    printf("\nQuantos pets deseja cadastrar? \n");
    scanf("%c",qtd);
    
    free(qtd);
    return quant;
}



float codificador(int *vetor, int exp, int pos){
    if(exp==0){
        return vetor[pos];
    }
    return (pow(10, exp)*vetor[pos])+codificador(vetor, exp-1, pos+1);
}

// float decodificador(float)
