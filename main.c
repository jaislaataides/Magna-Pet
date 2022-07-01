#include <stdio.h>
#include <string.h>

//-------  INFORMAÇÕES DE CADASTRO ---------
//struct das informações dos pets
typedef struct{
    char nomepet[50], especie[20], raca[20], **medicacao, **diagnostico;
    int idade, comprimento;
    //sistema matricial de meses gerados a partir da quantidade de pets
    float diario[12][31];
}pet;

//variável ou vetor do tipo struct pet
pet *animal;

//struct das informações do tutor
struct tutor{
    char nome[50], email[50], senha[20], pessoa[15], numero[11];
    int quantidade;
    pet animal;
}dono;


//struct vet
typedef struct{
    char nome[50], especialidade[50], pessoa[15];
    int experiencia;
}veterinarios;

//variável ou vetor do tipo struct veterinarios
veterinarios *vet;

//struct das informações da clínica
struct{
    char nome[50], email[50], senha[20], CNPJ[15], numero[11];
    int quantidade;
    veterinarios *vet;
}clinica;


//------  VARIÁVEIS DE CONTROLE  --------
//vetores de informações diárias
const char *humor[6]={{" "},{"calmo"},{"cabisbaixo"},{"animado"},{"irritado"},{"choramingando"}};
const char *alimentacao[6]={{" "},{"nao comeu"},{"comeu normalmente"},{"comeu algo diferente"},{"ração nova"},{"comida de humano"}};
const char *medicacaododia[4]={{" "},{"não"},{"de rotina"},{"outra medicação"}};
const char *urina[5]={{" "},{"cor típica e líquida"},{"cor alaranjada"},{"cor avermelhada"},{"cor amarronzada"}};
const char *fezes[10]={{" "},{"normal"},{"preta"},{"branca"},{"cinza"},{"verde"},{"com verme"},{"com giárdia"},{"com muco amarelo"},{"com sangue"}};

//variáveis de dados diários
int data[3];
//TODO: escolher nomes melhores para char *medicacaoderotina, *medicacaododia; ou substituir;
int EscolhaPet;

//vetores auxiliares
int VetorAuxiliarCodigo;
int diasPorMes[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//variaveis de loop
int i,j;

#include "cadastro.h"
#include "arquivo.h"



void main(){
    // //EXEMPLO DE APLICAÇÃO DE ALOCAÇÃO DINÂMICA
    // /*int qtd=1,user=0;
    // dono.animal=malloc(qtd * sizeof(pet));
    // for(int i=0; i<qtd; i++){
    //     strcpy(dono.animal[i].nomepet,"zezinho");
    //     printf("%s\n\n",dono.animal[i].nomepet);
    // }
    // */
    char choice, tipodeusuario;

    menuInicial:
    printf(" ________________________________________________________\n");
    printf("|                 M E N U     I N I C I A L              |\n");
    printf("|                                                        |\n");
    printf("|                   1 - fazer cadastro                   |\n");
    printf("|                   2 - fazer login                      |\n");
    printf("|                   0 - sair                             |\n");
    printf("|________________________________________________________|\n\n\n");

    printf("Escolha: ");
    scanf("%c",&choice);
    fflush(stdin);
    switch(choice){
        case '1':
        //TODO: codar função limpar + notificação
        system("cls");
            usertype:
            //TODO: Felipe - decisão: tipo de usuário 
            printf("\n\tQual tipo de usuario e' voce?");
            printf("\n\t\t1- tutor\n\tdescricao: pai ou mae de pet que quer ter um monitoramento dos seus bichinhos acurado.");
            printf("\n\n\t\t2- clinica veterinaria\n\tdescricao: representante do consulturio que deseja conhecer a \n\trotina dos animais fora do ambiente medico e ter uma comunicacao melhor com seus tutores\n\n");
            printf("\n\n\t\t0- sair");
            scanf("%c",&tipodeusuario);
            system("cls");
                switch(tipodeusuario){
                    case '1':

                        strcpy(dono.nome, Nome());
                        strcpy(dono.pessoa,CPF());
                        strcpy(dono.email, Email());
                        Confirma(dono.email, "seu email");
                        fflush(stdin);
                        strcpy(dono.senha, Senha());
                        printf("%s",dono.senha);
                        Confirma(dono.senha, "sua senha");
                        printf("\nCadastro realizado com sucesso!");
                        //TODO: goto menuPrincipalTutor;
                        break;

                    case '2':
                        strcpy(clinica.nome, Nome());
                        strcpy(clinica.email, Email());
                        Confirma(clinica.email, "seu email");
                        fflush(stdin);
                        strcpy(clinica.senha, Senha());
                        printf("%s",clinica.senha);
                        Confirma(clinica.senha, "sua senha");
                        printf("\nCadastro realizado com sucesso!");
                        //TODO: goto menuPrincipalClinica;
                        break;

                    case '0':
                        goto menuInicial;

                    //FIXME: erro default
                    // default:
                    //     printf("\nO caractere que voce inseriu nao e valido para nenhuma opcao.\nDigite novamente ou pressione 0 para sair\n");
                    //     goto usertype;
                    //break;
                }
        break;
    
        case '2':
            //TODO: criar função de busca

        break;

        case '0':
            exit(0);

        //default:
        //break;
    }

    fflush(stdin);
    if (tipodeusuario=='1'){

        //FIXME: FELIPE menuPrincipalTutor:
        menuPrincipalTutor:
        printf("\tMENU PRINCIPAL");

        //sair ou fazer logout???????

        printf("\n1- cadastrar pets\n2-informações do(s) pet(s)\n3-vacinas\n4-diario pet\n5-clinica\n0- sair\n\n");
        scanf("%c",&choice);
        switch (choice){
            case '1':
                dono.quantidade = Quantidade(choice);
                    for(i=0; i<dono.quantidade; i++){
                        strcpy(animal[i].nomepet, Nome());
                        strcpy(animal[i].especie, Especie(animal[i].nomepet));
                        strcpy(animal[i].raca, Raca(animal[i].nomepet));
                        Medicacao();
                        Diagnostico();
                    }
                    //limpa
                    //colocar em arquivo
                    printf("\n\nCadastro realizado com sucesso!");

            break;
            case '2':
                //TODO: FELIPE MENU CARTILHA
                printf("MENU CARTILHA\n1-visualizar informacoes\n2-editar informacoes\n3- voltar\n0- sair");
                scanf("%c",&choice);
                switch(choice){
                    case '1':

                    break;

                    case '2':
                        
                    break;

                    case '3':

                    break;

                    case '0':

                    break;
                    
                    // default:
                    
                    // break;
                }

            break;
            case '3':
                //TODO: FELIPE ÁREA DE VACINAS
                printf("MENU VACINAS\n1- 'sincronizar' cartao de vacina\n2- ver cartao de vacinas\n3- receber lembrete vacinal\n4- voltar\n0-sair");
                scanf("%c",choice);
                switch(choice){
                    case '1':

                    break;
                    
                    case '2':
                    
                    break;
                    
                    case '3':
                    
                    break;

                    case '4':

                    break;

                    case '0':

                    break;

                    // default: 
                    // break:
                }

            break;
            case '4':
                //TODO: FELIPE MENU DIARIO
                printf("MENU DIARIO\n\tcadastre as informacoes do(s) seu(s) bichinhos diariamente!\nVoce deseja:\n");
                printf("\n1- inserir informações\n-");

            break;
            case '5':
                //TODO: FELIPE MENU CLINICA

            break;
            case '0':
                exit(0);

            break;
            // default:
        }
    }
}


