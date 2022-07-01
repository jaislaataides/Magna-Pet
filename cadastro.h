#include <string.h>
#include "tratamentos.h"

//-------- C A D A S T R O ----------
//obter nome do usuário ou pet
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
    fgets(input, 15, stdin);
    printf("%s",input);
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

//setar vetor struct
int Quantidade(char *palavra){
    int *quant = malloc(sizeof(int));
    fflush(stdin);
    printf("\nQuantos pets deseja cadastrar? \n");
    scanf("%d",&quant);
    tratamentoQuantidade(quant, palavra);
    return quant;
}

//obter raca do pet
char *Raca (char *nome){
    char *raca = malloc(20 * sizeof(char));
    fflush(stdin);
    printf("\nQual a raca de %s?\n",nome);
    fgets(raca, 20, stdin);
    tratamentoASCII(raca);
    return raca;
}

//obter especie do pet
char Especie(char *nome){
    char *especie = malloc(20 * sizeof(char));
    fflush(stdin);
    printf("\nQual a especie de %s? ", nome);
    fgets(especie, 20, stdin);
    tratamentoASCII(especie);
    return especie;
}

//obter medicacao do pet (se houver)
void Medicacao(){
    int qtd;
    fflush(stdin);
    printf("\n%s faz uso de alguma medicacao? Digite 0 caso nao ou a quantidade de medicamentos: ",dono.animal.nomepet);
    scanf("%d",&qtd);
    animal[i].medicacao = malloc(qtd * sizeof(char*));
    for (i=0; i<qtd; i++){
        animal[i].medicacao[i] = malloc(40 * sizeof(char));
        fflush(stdin);
        printf("\nDigite o nome do %d medicamento: ",i+1);
        fgets(animal[i].medicacao[i], 40, stdin);
    }  
} 

//obter diagnostico
void Diagnostico(){
    int qtd;
    fflush(stdin);
    printf("\n%s tem alguma doenca cronica, disfuncao ou outro diagnostico?\nDigite 0 caso nao ou a quantidade de diagnosticos: ");
    scanf("%d",&qtd);
    dono.animal.diagnostico = malloc(qtd * sizeof(char*));
    for(i=0; i<qtd; i++){
        animal[i].diagnostico[i] = malloc(40 * sizeof(char));;
        fflush(stdin);
        printf("\nDigite o nome do problema: ");
        fgets(animal[i].diagnostico[i], 40, stdin);
    }
}

//--------------------------------------- D A D O S  D I A R I O S -----------------------------------------------------------------------------
//codificador: vetor de inteiro para float
//FIXME: melhorar relação primeira posição do vetor
float codificador(int *vetor, int exp, int pos){
    if(exp==0){
        return vetor[pos];
    }
    return (pow(10, exp)*vetor[pos])+codificador(vetor, exp-1, pos+1);
}

//TODO:float decodificador(float)
