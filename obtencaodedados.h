#include <string.h>
#include "tratamentos.h"

    char choice;
    int aux;


//-------------------------------------- C A D A S T R O --------------------------------------------------------------

//obter nome do usuário ou pet
char *Nome(){
    char *nome = malloc(50 * sizeof(char*));
    criaForm();
    printf("Digite o nome: ");
    fgets(nome, 50, stdin);
    tratamentoASCII(nome);
    return nome;
}

//obter CPF ou CNPJ do usuário
char *CPF(){
    char *input = malloc(14*sizeof(char*));
    criaForm();
    printf("Digite seu CPF ou CNPJ: ");
    fgets(input, 15, stdin);
    tratamentoCPFCNPJ(input);
    return input;
}

//obter email do usuário
char *Email(){
    char *email = malloc(20 * sizeof(char*));
    criaForm();
    printf("Digite o email: ");
    fgets(email, 30, stdin);
    tratamentoEmail(email);
    return email;
}

//obter senha do usuário
char *Senha(){
    char *senha = malloc(10 * sizeof(char*));
    criaForm();
    printf("Digite sua senha (6 - 10 digitos): ");
    fgets(senha, 10, stdin);
    fflush(stdin);
    return senha;
}

//confirmar digitação de email e senha
void Confirma(char *palavra1, char *palavra3){
    char *palavra2 = malloc(20 * sizeof(char));
    criaForm();
    printf("Confirme %s: ",palavra1);
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
    printf("Quantos pets deseja cadastrar? \n");
    scanf("%d",&quant);
    tratamentoQuantidade(quant, palavra);
    return quant;
}

//obter raca do pet
char *Raca (char *nome){
    char *raca = malloc(20 * sizeof(char));
    criaForm();
    printf("Qual a raca de %s?\n",nome);
    fgets(raca, 20, stdin);
    tratamentoASCII(raca);
    return raca;
}

//obter especie do pet
char *Especie(char *nome){
    char *especie = malloc(20 * sizeof(char));
    criaForm();
    printf("\nQual a especie de %s? ", nome);
    fgets(especie, 20, stdin);
    tratamentoASCII(especie);
    return especie;
}

//obter medicacao do pet (se houver)
void Medicacao(){
    int qtd;
    criaForm();
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
    criaForm();
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
    aux = tratamenoObterDadosDiarios(aux, 1, 5);
    return aux;
}

int obterAlimentacao(){
    criaMenuItem(STRTAM, "          E como foi a alimentação dele(a) hoje?");
    criaMenuItem(STRTAM, "1 - não comeu");
    criaMenuItem(STRTAM, "2 - comeu normalmente");
    criaMenuItem(STRTAM, "3 - comeu algo diferente");
    criaMenuItem(STRTAM, "4 - ração nova");
    criaMenuItem(STRTAM, "5 - comida de humano");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    tratamenoObterDadosDiarios(aux, 1, 5);
    return aux;
}

int obterMedicacao(){
    criaMenuLinhaSuperior(STRTAM, "         Fez uso de algum medicamento hoje?");
    criaMenuItem(STRTAM, "          1 - não");
    criaMenuItem(STRTAM, "          2 - de rotina");
    criaMenuItem(STRTAM, "          3 - outra medicação");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    tratamenoObterDadosDiarios(aux, 1, 3);
    return aux;
}

int obterUrina(){
    criaMenuLinhaSuperior(STRTAM, "         Qual era o aspecto da urina hoje?");
    criaMenuItem(STRTAM, "          1 - cor típica e líquida");
    criaMenuItem(STRTAM, "          2 - cor alaranjada");
    criaMenuItem(STRTAM, "          3 - cor avermelhada");
    criaMenuItem(STRTAM, "          4 - cor amarronzada");
    criaMenuLinhaRodape(STRTAM);
    scanf("%c", &choice);
    aux = choice - '0';
    //TODO:tratamento de erro
    return aux;
}

int obterFezes(){
    criaMenuLinhaSuperior(STRTAM, "         Quanto as fezes, como foi hoje?");
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
    //TODO:tratamento de erro
    return aux;
}

int obterIrregularidades(){
    criaMenuLinhaSuperior(STRTAM, "         Aconteceu algo de diferente?");
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
    //TODO:tratamento de erro
    return aux;
}








//codificador: vetor de inteiro para float
//FIXME: melhorar relação primeira posição do vetor
float codificador(int *vetor, int exp, int pos){
    if(exp==0){
        return vetor[pos];
    }
    return (pow(10, exp)*vetor[pos])+codificador(vetor, exp-1, pos+1);
}

//TODO:float decodificador(float)
