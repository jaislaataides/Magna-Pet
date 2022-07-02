#include <stdio.h>
#include <string.h>

//-------  INFORMAÇÕES DE CADASTRO ---------

typedef struct{
    char data[10];
    float diario[12][31];
}diario;

//struct das informações dos pets
typedef struct{
    char nomepet[50], especie[20], raca[20], **medicacao, **diagnostico;
    int idade, comprimento, id;
    char sexo;
    //sistema matricial de meses gerados a partir da quantidade de pets
    diario dados;
}pet;

//variável ou vetor do tipo struct pet
pet animal[2];

//struct das informações do tutor
struct tutor{
    char nome[50], email[50], senha[20], pessoa[15], numero[11];
    int quantidade;
    pet animal;
}dono;


//struct  das informações do veterinario
typedef struct{
    char nome[50], especialidade[50], pessoa[15];
    int experiencia;
}veterinarios;

//variável ou vetor do tipo struct veterinarios
veterinarios *vet;

typedef struct{
    char nome[50], codigo[20];
    int estoque;
    float preco;
}vendas;

vendas *produto;

//struct das informações da clínica
struct{
    char nome[50], email[50], senha[20], CNPJ[15], numero[11];
    int quantidade;
    veterinarios vet;
    vendas produto;
}clinica;


//------  VARIÁVEIS DE CONTROLE  --------
//vetores de informações diárias
const char *humor[6]={{" "},{"calmo"},{"cabisbaixo"},{"animado"},{"irritado"},{"choramingando"}};
const char *alimentacao[6]={{" "},{"nao comeu"},{"comeu normalmente"},{"comeu algo diferente"},{"ração nova"},{"comida de humano"}};
const char *medicacaododia[4]={{" "},{"não"},{"de rotina"},{"outra medicação"}};
const char *urina[5]={{" "},{"cor típica e líquida"},{"cor alaranjada"},{"cor avermelhada"},{"cor amarronzada"}};
const char *fezes[10]={{" "},{"normal"},{"preta"},{"branca"},{"cinza"},{"verde"},{"com verme"},{"com giárdia"},{"com muco amarelo"},{"com sangue"}};

//variáveis de dados diários
//TODO: escolher nomes melhores para char *medicacaoderotina, *medicacaododia; ou substituir;
char data[10];
int EscolhaPet;

//vetores auxiliares
int VetorAuxiliarCodigo[7];
int diasPorMes[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//variaveis de loop
int i,j;

#include "obtencaodedados.h"
#include "exibicao.h"
#include "arquivo.h"

int calculoDia(char *a){
    int dia;
    dia = a[0] - '0';
    dia = (int)dia/10;
    dia+= a[1] - '0';
    return dia;
}

int calculoMes(char *a){
    int mes;
    if(strlen(a)>2){
        mes = a[3] - '0';
        mes = (int)mes/10;
        mes+= a[4] - '0';
    }else{
        mes = a[0] - '0';
        mes = (int)mes/10;
        mes+= a[1] - '0';
    }

    return mes;
}

int main(){
    // //EXEMPLO DE APLICAÇÃO DE ALOCAÇÃO DINÂMICA
    // /*int qtd=1,user=0;
    // dono.animal=malloc(qtd * sizeof(pet));
    // for(int i=0; i<qtd; i++){
    //     strcpy(dono.animal[i].nomepet,"zezinho");
    //     printf("%s\n\n",dono.animal[i].nomepet);
    // }
    // */

    strcpy(data, getData());

    int dia = calculoDia(data), mes = calculoMes(data);

    char choice, tipodeusuario, dd, mm;

    animal[0].id = gerarID();

    menuInicial:
    MenuInicio();
    printf("\n\n        escolha: ");
    fflush(stdin);
    scanf("%c",&choice);

    fflush(stdin);
    switch(choice){
        case '1':
        //TODO: codar função limpar + notificação
        system("cls");
            usertype:
            criaMenuLinhaSuperior(STRTAM, "     ");
            criaMenuItem(STRTAM, "  ");
            criaMenuItem(STRTAM, "                Qual tipo de usuario e voce? ");
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, "                         1- tutor");  
            criaMenuItem(STRTAM, "        descricao: pai ou mae de pet que quer ter  ");  
            criaMenuItem(STRTAM, "       um monitoramento dos seus bichinhos acurado");
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, "                   2- clinica veterinaria");  
            criaMenuItem(STRTAM, "         descricao: profissional da clinica que deseja ");
            criaMenuItem(STRTAM, "         conhecer a rotina dos animais fora do ambiente");
            criaMenuItem(STRTAM, "      medico e ter uma comunicacao m1elhor com seus tutores");
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, "                 3 - voltar ao ultimo menu");
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM, "                          0 - sair");
            criaMenuItem(STRTAM, " ");
            criaMenuLinhaRodape(STRTAM);
            printf("\n\n        escolha: ");
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
                        cadastroRealizado();
                        //TODO: fprintf
                        break;

                    case '2':
                        strcpy(clinica.nome, Nome());
                        strcpy(clinica.email, Email());
                        Confirma(clinica.email, "seu email");
                        fflush(stdin);
                        strcpy(clinica.senha, Senha());
                        printf("%s",clinica.senha);
                        Confirma(clinica.senha, "sua senha");
                        cadastroRealizado();
                        //TODO: fprintf
                        break;

                    case '3':
                        goto menuInicial;

                    case '0':
                        sair();

                    default:
                        opcaoInvalida();
                        goto usertype;
                    break;
                }
        break;
    
        case '2':
            //TODO: criar função de busca em binario

        break;

        case '0':
            sair();

        default:
            opcaoInvalida();
            goto menuInicial;
        break;
    }

    fflush(stdin);
    if (tipodeusuario=='1'){

        menuPrincipalTutor:
        Menu_Tutor();
        scanf("%c",&choice);

        switch (choice){
            //cadastrar pet
            case '1'://-----------------------------------------------------------------------

                animal[0].id = 1;
                dono.quantidade = Quantidade(choice);
                for(i=0; i<dono.quantidade; i++){
                    strcpy(animal[i].nomepet, Nome());
                    strcpy(animal[i].especie, Especie(animal[i].nomepet));
                    strcpy(animal[i].raca, Raca(animal[i].nomepet));
                    Medicacao();
                    Diagnostico();
                    animal[i].id = gerarID();
                }
                //função limpa
                //colocar em arquivo
                cadastroRealizado();
                break;

            case '2'://-----------------------------------------------------------------------

                menuCartilhaTutor:
                Menu_Cartilha_Tutor();
                scanf("%c",&choice);

                    switch(choice){

                        case '1':
                            //TODO: EDITAR INFO
                        break;

                        case '2':
                            //TODO: VISUALIZAR INFO
                        break;

                        case '3':
                            //TODO: GOTO MENU PRINCIPAL
                        break;

                        case '0':
                            sair();

                        default:
                        opcaoInvalida();
                        //TODO: GOTO
                    }
            break;

            case '3'://-----------------------------------------------------------------------
            //TODO: CARTÃO DE VACINAS
            menuVacinas:
            Menu_Vacinas_Tutor();
            scanf("%c",choice);
    
                switch(choice){
    
                    case '1':
                        //TODO: PERMITIR/INSERIR NOTIFICAÇÃO
                    break;
                    
                    case '2':
                        //TODO: VISUALIZAR VACINAS
                    break;
                    
                    case '3':
                        //TODO: INSERIR VACINA 1  VEZ
                    break;

                    case '4':
                        //TODO: GOTO MENU PRINCIPAL
                    break;

                    case '0':
                        sair();

                    default: 
                        opcaoInvalida();
                        //TODO: GOTO
                }

            break;

            case '4'://-----------------------------------------------------------------------
            Menu_Pet_Tutor();
            scanf("%c",choice);
                
                switch(choice){
                    case '1':
                        VetorAuxiliarCodigo[0] = obterHumor();
                        VetorAuxiliarCodigo[1] = obterAlimentacao();
                        VetorAuxiliarCodigo[2] = obterMedicacao();
                        VetorAuxiliarCodigo[3] = obterUrina();
                        VetorAuxiliarCodigo[4] = obterFezes();
                        VetorAuxiliarCodigo[5] = obterIrregularidades();
                        //limpa
                        system("cls");
                        salvarDiario:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, "      Deseja salvar os dados na data de hoje?");
                        criaMenuItem(STRTAM, "                  1 - Sim");
                        criaMenuItem(STRTAM, "                  2 - Nao");
                        criaMenuLinhaRodape(STRTAM);
                        fflush(stdin);
                        printf("\n\n            escolha:");
                        scanf("%c",&choice);
                        if(choice == '1'){
                            animal[i].dados.diario[mes][dia] = codificador(VetorAuxiliarCodigo, 5, 0);
                            // armazenarDiario();
                        }else if(choice == 2){
                            criaForm();
                            printf("    Escreva o dia em que os dados serao salvos: ");
                            fgets(dd, 2, stdin);
                            dia = calculoDia(dd);
                            criaLinhaForm();
                            printf("    Agora escreva o mes: ");
                            fgets(mm, 2, stdin);
                            mes = calculoMes(mm);
                            animal[i].dados.diario[mes][dia] = codificador(VetorAuxiliarCodigo, 5, 0);


                            //TODO: pegar string e armazenar diario
                        }else{
                            opcaoInvalida();
                            goto salvarDiario;
                        }
                        //TODO: FINALIZAR
                    break;
                
                    case '2':
                        //TODO: editar
                    break;

                    case '3':
                        //TODO: desenvolver buscador
                    break;
                    
                    case '4':
                        //TODO: GOTO
                    break;
                    
                    case '0':
                    sair();
                    break;
                    
                    default:
                    opcaoInvalida();
                    //TODO: GOTO
                    break;
                }

            case '5':
            menuTutorClinica:
            Menu_Clinica_Tutor();
            scanf("%c",&choice);
            switch(choice){
                case '1':
                    //TODO: VISUALIZAR ITENS
                break;

                case '2':
                    //TODO: CONTATAR CLINICA
                break;

                case '3':
                    //TODO: AGENDAR CONSULTA
                break;
                
                case '4':
                    //TODO: GOTO MENU PRINCIPAL
                break;

                case '0':
                    sair();
                
                default:
                opcaoInvalida();
                //TODO: GOTO MENU PRINCIPAL
            }

            break;

            case '0':
                sair();

            default:
                opcaoInvalida();
                //TODO: GOTO
            break;
        }    
    }else{
        menuPrincipalClinica:
        Menu_Clinica();
        scanf("%c",choice);

            switch(choice){

                case '1':
                menuProdutosClinica:
                Menu_Produtos_Clinica();
                    scanf("%c",choice);

                    switch(choice){
                        case '1':
                            //TODO: CADASTRO DE PRODUTOS
                        break;

                        case '2':
                            //TODO: EDIÇÃO DE PRODUTOS
                        break;

                        case '3':
                            //TODO: VISUALIZAR PRODUTOS
                        break;

                        case '4':
                            //TODO:GOTO MENU PRINCIPAL
                        break;

                        case '0':
                        sair();
                        break;

                        default:
                            opcaoInvalida();
                            //TODO: GOTO
                        break;
                    }
                break;

                case '2':
                    menuVacinasClinica:
                    Menu_Vacinas_Clinica();
                    scanf("%c",choice);
                    switch(choice){
                        case '1':
                            //TODO: INSERIR VACINAS
                        break;

                        case '2':
                            //TODO: EDITAR VACINAS
                        break;

                        case '3':
                            //TODO: INSERIR AVISOS
                        break;

                        case '4':
                            //TODO: VOLTAR AO MENU PRINCIPAL
                        break;

                        case '0':
                        sair();

                        default:
                        opcaoInvalida();
                        //TODO: GOTO MENU PRINCIPAL
                    }
                break;

                case '3':
                meuDiarioPetClinica:
                Menu_Pet_Clinica();
                scanf("%c",&choice);
                
                switch(choice){
                    case '1':
                        //TODO: ADD BUSCADOR POR DATA
                    break;

                    case '2':
                        //TODO: ADD BUSCADOR POR TIPO
                    break;
                    
                    case '3':
                        //TODO: VOLTAR AO MENU PRINCIPAL
                    break;

                    case '0':
                        sair();

                    default:
                        opcaoInvalida();
                        //TODO: ADD GOTO
                }
                break;

                case '4':
                menuContatoClinica:
                Menu_Contato_Clinica();
                scanf("%c",&choice);
                switch(choice){
                    case '1':
                        //  TODO: MENU INFO
                    break;

                    case '2':
                        //TODO: SISTEMA DE PLANTÃO
                    break;

                    case '3':
                        //TODO: GOTO MENU PRINCIPAL
                    break;

                    case '0':
                    sair();
                    break;

                    default:
                    opcaoInvalida();
                    //TODO: GOTO MENU PRINCIPAL;
                }
                break;

                case '0':
                    sair();

                default:
                    opcaoInvalida();
                    //TODO: GOTO MENU PRINCIPAL
                
            }

    }

return 0;
}
