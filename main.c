#include <stdio.h>
#include <string.h>

//-------  INFORMAÇÕES DE CADASTRO ---------

//struct das informações dos pets
typedef struct{
    char nomepet[50], especie[20], raca[20], medicacao[50], diagnostico[50];
    int idade, comprimento;
    //sistema matricial de meses gerados a partir da quantidade de pets
    float diario[12][31];
}pet;

//variável ou vetor do tipo struct pet
pet *animal;

//struct das informações do tutor
struct tutor{
    char nome[50], email[50], senha[20], pessoa[14], numero[11];
    int quantidade;
    pet animal;
}dono;


//struct vet
typedef struct{
    char nome[50], especialidade[50], pessoa[14];
    int experiencia;
}veterinarios;

//variável ou vetor do tipo struct veterinarios
veterinarios *vet;

//struct das informações da clínica
struct{
    char nome[50], email[50], senha[20], CNPJ[14], numero[11];
    int quantidade;
    veterinarios *vet;
}clinica;


//------  VARIÁVEIS DE CONTROLE  --------
//vetores de informações diárias
const char *humor[5]={{"calmo"},{"cabisbaixo"},{"animado"},{"irritado"},{"choramingando"}};
const char *alimentacao[5]={{"nao comeu"},{"comeu normalmente"},{"comeu algo diferente"},{"ração nova"},{"comida de humano"}};
const char *medicacao[3]={{"não"},{"de rotina"},{"outra medicação"}};
const char *urina[4]={{"cor típica e líquida"},{"cor alaranjada"},{"cor avermelhada"},{"cor amarronzada"}};
const char *fezes[10]={{"normal"},{"preta"},{"branca"},{"cinza"},{"verde"},{"com verme"},{"com giárdia"},{"com muco amarelo"},{"com sangue"}};

//variáveis de dados diários
int data[3];
char *medicacaoderotina, *medicacaododia;
int EscolhaPet;

//vetores auxiliares
int VetorAuxiliarCodigo;
int diasPorMes[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};



#include "cadastro.h"



void main(){
    /*int qtd=1,user=0;
    dono.animal=malloc(qtd * sizeof(pet));
    for(int i=0; i<qtd; i++){
        strcpy(dono.animal[i].nomepet,"zezinho");
        printf("%s\n\n",dono.animal[i].nomepet);
    }
    */
    char choice, tipodeusuario;
    
    dono.quantidade = Quantidade();
    printf("%d",dono.quantidade);

    // menuInicial:
    // printf(" ________________________________________________________\n");
    // printf("|                 M E N U     I N I C I A L              |\n");
    // printf("|                                                        |\n");
    // printf("|                   1 - fazer cadastro                   |\n");
    // printf("|                   2 - fazer login                      |\n");
    // printf("|                   0 - sair                             |\n");
    // printf("|________________________________________________________|\n\n\n");

    // printf("Escolha: ");
    // scanf("%c",&choice);
    // fflush(stdin);
    // switch(choice){
    //     case '1':
    //     //codar função limpar + notificação
    //     system("cls");
    //         usertype:
    //         printf("\n\tQual tipo de usuario e' voce?");
    //         printf("\n\t\t1- tutor\n\tdescricao: pai ou mae de pet que quer ter um monitoramento dos seus bichinhos acurado.");
    //         printf("\n\n\t\t2- clinica veterinaria\n\tdescricao: representante do consulturio que deseja conhecer a \n\trotina dos animais fora do ambiente medico e ter uma comunicacao melhor com seus tutores\n\n");
    //         printf("\n\n\t\t0- sair");
    //         scanf("%c",&choice);
    //         system("cls");
    //             switch(choice){
    //                 case '1':

    //                     strcpy(dono.nome, Nome());
    //                     strcpy(dono.pessoa,CPF());
    //                     strcpy(dono.email, Email());
    //                     Confirma(dono.email, "seu email");
    //                     fflush(stdin);
    //                     strcpy(dono.senha, Senha());
    //                     printf("%s",dono.senha);
    //                     Confirma(dono.senha, "sua senha");
    //                     printf("\nCadastro realizado com sucesso!");
    //                     // goto menuPrincipalTutor;
    //                     break;

    //                 case '2':
    //                     strcpy(clinica.nome, Nome());
    //                     strcpy(clinica.email, Email());
    //                     Confirma(clinica.email, "seu email");
    //                     fflush(stdin);
    //                     strcpy(clinica.senha, Senha());
    //                     printf("%s",clinica.senha);
    //                     Confirma(clinica.senha, "sua senha");
    //                     printf("\nCadastro realizado com sucesso!");
    //                     break;

    //                 case '0':
    //                     goto menuInicial;

    //                 // default:
    //                 //     printf("\nO caractere que voce inseriu nao e valido para nenhuma opcao.\nDigite novamente ou pressione 0 para sair\n");
    //                 //     goto usertype;
    //             }
    //     break;
    
    //     case '2':

    //     break;

    //     case '0':
    //         exit(0);

    //     //default:
    // }
    // fflush(stdin);
    // // menuPrincipalTutor:
    // printf("\tMENU PRINCIPAL");
    // printf("\n1- cadastrar pets\n2-informações do(s) pet(s)\n3-vacinas\n4-diario pet\n5-clinica\n0- sair\n\n");
    // scanf("%c",&choice);
    // switch (choice){
    //     case '1':
    //         dono.quantidade = Quantidade(choice);
    //         ptintf("%d",dono.quantidade);
    //     break;
    //     case '2':

    //     break;
    //     case '3':

    //     break;
    //     case '4':

    //     break;
    //     case '5':

    //     break;
    //     case '0':

    //     break;
    //     // default:

    // }


}