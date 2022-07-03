#include <string.h>
#include <math.h>
#include "menus.h"
#include "tratamentos.h"

    char choice;
    int aux, qtdMed, qtdDiag;
    char *nome, *raca, *especie;


//-------------------------------------- C A D A S T R O --------------------------------------------------------------

//obter nome do usuário ou pet
char *Nome(){
    free(nome);
    nome = malloc(50 * sizeof(char));
    criaLinhaForm();
    printf("        Digite o nome: ");
    fflush(stdin);
    fgets(nome, 50, stdin);
    tratamentoASCII(nome);
    return nome;
}

//obter CPF ou CNPJ do usuário
char *CPF(){
    char *input = malloc(14*sizeof(char));
    criaLinhaForm();
    printf("        Digite seu CPF ou CNPJ: ");
    fgets(input, 15, stdin);
    tratamentoCPFCNPJ(input);
    return input;
}

//obter email do usuário
char *Email(){
    char *email = malloc(20 * sizeof(char));
    criaLinhaForm();
    printf("        Digite o email: ");
    fgets(email, 30, stdin);
    tratamentoEmail(email);
    return email;
}

//obter senha do usuário
char *Senha(){
    char *senha = malloc(10 * sizeof(char));
    criaLinhaForm();
    printf("        Digite sua senha (6 - 10 digitos): ");
    fgets(senha, 10, stdin);
    fflush(stdin);
    return senha;
}

//confirmar digitação de email e senha
void Confirma(char *palavra1, char *palavra3){
    char *palavra2 = malloc(20 * sizeof(char));
    criaLinhaForm();
    printf("        Confirme %s: ",palavra3);
    fgets(palavra2, 30, stdin);
    fflush(stdin);
    tratamentoConfirmacao(palavra1, palavra2, palavra3);
    free(palavra2);
}

//---------- C A D A S T R A R   P E T S ----------

//setar vetor struct
int Quantidade(char *palavra){
    int *quant = malloc(sizeof(int));
    criaForm();
    printf("        Quantos pets deseja cadastrar? \n");
    scanf("%d",&quant);
    tratamentoQuantidade(quant, palavra);
    return quant;
}

//obter raca do pet
char *Raca (char *nome){
    free(raca);
    raca = malloc(20 * sizeof(char));
    criaLinhaForm();
    printf("        Qual a raca de %s?\n",nome);
    fgets(raca, 20, stdin);
    tratamentoASCII(raca);
    return raca;
}

//obter especie do pet
char *Especie(char *nome){
    free(especie);
    especie = malloc(20 * sizeof(char));
    criaLinhaForm();
    printf("        Qual a especie de %s ? ", nome);
    fgets(especie, 20, stdin);
    tratamentoASCII(especie);
    return especie;
}

//obter medicacao do pet (se houver)
void Medicacao(){
    criaLinhaForm();
    printf("    %s faz uso de alguma medicacao? ");
    criaLinhaForm();
    printf("    Digite 0 caso nao ou a quantidade de medicamentos: ",dono.animal.nomepet);
    scanf("%d",&qtdMed);
    animal[i].medicacao = malloc(qtdMed * sizeof(char*));
    for (i=0; i<qtdMed; i++){
        animal[i].medicacao[i] = malloc(40 * sizeof(char));
        fflush(stdin);
        criaLinhaForm();
        printf("    Digite o nome do %d medicamento: ",i+1);
        fgets(animal[i].medicacao[i], 40, stdin);
    }  
} 

//obter diagnostico
void Diagnostico(){
    criaLinhaForm();
    printf("\n%s tem alguma doenca cronica, disfuncao ou outro diagnostico?\nDigite 0 caso nao ou a quantidade de diagnosticos: ");
    scanf("%d",&qtdDiag);
    dono.animal.diagnostico = malloc(qtdDiag * sizeof(char*));
    for(i=0; i<qtdDiag; i++){
        animal[i].diagnostico[i] = malloc(40 * sizeof(char));;
        fflush(stdin);
        criaLinhaForm();
        printf("    Digite o nome do problema: ");
        fgets(animal[i].diagnostico[i], 40, stdin);
    }
}

//-----------------------------------------------------------------------------------------


//--------------------------------------- D A D O S  D I A R I O S -----------------------------------------------------------------------------

//---------- OBTER DADOS DIÁRIOS ----------
int obterHumor(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "          Nos conte como estava seu amiguinho hoje!");
    criaMenuItem(STRTAM, " ");
    criaMenuItem(STRTAM, "          1 - calmo");
    criaMenuItem(STRTAM, "          2 - cabisbaixo");
    criaMenuItem(STRTAM, "          3 - animado");
    criaMenuItem(STRTAM, "          4 - irritado");
    criaMenuItem(STRTAM, "          5 - choramingando");
    criaMenuLinhaRodape(STRTAM);
    printf("\n          escolha: ");
    scanf("%c", &choice);
    aux = choice - '0';
    aux = tratamentoObterDadosDiarios(aux, 1, 5);
    return aux;
}

int obterAlimentacao(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "          E como foi a alimentação dele(a) hoje?");
    criaMenuItem(STRTAM, "1 - não comeu");
    criaMenuItem(STRTAM, "2 - comeu normalmente");
    criaMenuItem(STRTAM, "3 - comeu algo diferente");
    criaMenuItem(STRTAM, "4 - ração nova");
    criaMenuItem(STRTAM, "5 - comida de humano");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    tratamentoObterDadosDiarios(aux, 1, 5);
    return aux;
}

int obterMedicacao(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "         Fez uso de algum medicamento hoje?");
    criaMenuItem(STRTAM, "          1 - não");
    criaMenuItem(STRTAM, "          2 - de rotina");
    criaMenuItem(STRTAM, "          3 - outra medicação");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    tratamentoObterDadosDiarios(aux, 1, 3);
    return aux;
}

int obterUrina(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "         Qual era o aspecto da urina hoje?");
    criaMenuItem(STRTAM, "          1 - cor típica e líquida");
    criaMenuItem(STRTAM, "          2 - cor alaranjada");
    criaMenuItem(STRTAM, "          3 - cor avermelhada");
    criaMenuItem(STRTAM, "          4 - cor amarronzada");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    tratamentoObterDadosDiarios(aux, 1, 4);
    return aux;
}

int obterFezes(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "         Quanto as fezes, como foi hoje?");
    criaMenuItem(STRTAM, "          1 - normal");
    criaMenuItem(STRTAM, "          2 - preta");
    criaMenuItem(STRTAM, "          3 - branca");
    criaMenuItem(STRTAM, "          4 - cinza");
    criaMenuItem(STRTAM, "          5 - verde");
    criaMenuItem(STRTAM, "          6 - com verme");
    criaMenuItem(STRTAM, "          7 - com giárdia");
    criaMenuItem(STRTAM, "          8 - com muco amarelo");
    criaMenuItem(STRTAM, "          9 - com sangue");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    tratamentoObterDadosDiarios(aux, 1, 9);
    return aux;
}

int obterIrregularidades(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "         Aconteceu algo de diferente?");
    criaMenuItem(STRTAM, "          1 - vômito");
    criaMenuItem(STRTAM, "          2 - diarréia");
    criaMenuItem(STRTAM, "          3 - intestino preso");
    criaMenuItem(STRTAM, "          4 - Ingestão incorreta de água");
    criaMenuItem(STRTAM, "          5 - gases");
    criaMenuItem(STRTAM, "          6 - febre");
    criaMenuItem(STRTAM, "          7 - olhos amarelados");
    criaMenuItem(STRTAM, "          8 - não");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    tratamentoObterDadosDiarios(aux, 1, 8);
    return aux;
}




//codificador: vetor de inteiro para float
float codificador(int *vetor, int exp, int pos){
    if(exp==0){
        return vetor[pos];
    }
    return (pow(10, exp)*vetor[pos])+codificador(vetor, exp-1, pos+1);
}

//decodificador float para vetor de inteiro
void decodificador(float codigo, int *vetor){
    int exp=5,aux;
    for(i=0; i<6; i++){
        aux = (int)codigo/pow(10,exp);
        vetor[i] = aux%10;
        exp--;
    }
}

