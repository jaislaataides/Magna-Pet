#include <stdio.h>
#include <string.h>

//-------  INFORMAÇÕES DE CADASTRO ---------

typedef struct{
    char data[10];
    float diario[12][31];
}diario;

struct vacinas{
    char nome[40], data[10];
    int dose;
};

struct vacinas *vacina;

//struct das informações dos pets
typedef struct{
    char nomepet[50], especie[20], raca[20], **medicacao, **diagnostico;
    int idade, comprimento, id; 
    float peso;
    //sistema matricial de meses gerados a partir da quantidade de pets
    diario dados;
    struct vacinas vacina;
}pet;

//variável ou vetor do tipo struct pet
pet *animal;

//struct das informações do tutor
struct tutor{
    char nome[50], email[50], senha[20], pessoa[15], numero[11];
    int quantidade, id;
    pet animal;
}dono;


//struct  das informações do veterinario
typedef struct{
    char nome[50], especialidade[50], pessoa[15];
    int experiencia, id;
}veterinarios;

//variável ou vetor do tipo struct veterinarios
veterinarios *vet;

typedef struct{
    char nome[50], codigo[20];
    int estoque;
    float preco;
}vendas;

vendas *produto;

struct agenda{
    char data[10];
    int consultas[12][31];
};

//struct das informações da clínica
struct clinica{
    char nome[50], email[50], senha[20], CNPJ[15], numero[11];
    int quantidade, id;
    veterinarios vet;
    vendas produto;
    struct agenda agenda;
}clinica;


//------  VARIÁVEIS DE CONTROLE  --------
//vetores de informações diárias
const char *humor[6]={{" "},{"calmo"},{"cabisbaixo"},{"animado"},{"irritado"},{"choramingando"}};
const char *alimentacao[6]={{" "},{"nao comeu"},{"comeu normalmente"},{"comeu algo diferente"},{"ração nova"},{"comida de humano"}};
const char *medicacaododia[4]={{" "},{"não"},{"de rotina"},{"outra medicação"}};
const char *urina[5]={{" "},{"cor típica e líquida"},{"cor alaranjada"},{"cor avermelhada"},{"cor amarronzada"}};
const char *fezes[10]={{" "},{"normal"},{"preta"},{"branca"},{"cinza"},{"verde"},{"com verme"},{"com giárdia"},{"com muco amarelo"},{"com sangue"}};
const char *irregularidades[9] = {{" "},{"vomito"},{"diarreia"},{"ingestao incorreta de agua"},{"intestino preso"},{"gases"},{"febre"},{"olhos amarelados"},{"nao"}};

//notificação
int setanotificacao=0;

//variáveis de dados diários
char data[10], tipodeusuario;
int parametro;

//vetores auxiliares

int VetorAuxiliarCodigo[7];
int diasPorMes[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int regulador=0;

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

////////////////////////////////////////////////    MAIN     ////////////////////////////////////////////////////////////////////
int main(){
    //obter data do sistema
    strcpy(data, getData());
    int dia = calculoDia(data), mes = calculoMes(data);
    char dd, mm;
    //variaveis de escolha
    char escolha, string[30];
    int escolhaInt;

    menuInicial:
    MenuInicio();
    printf("\n\n        escolha: ");
    fflush(stdin);
    scanf("%c",&escolha);

    fflush(stdin);
    switch(escolha){
        case '1':
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

                        criaLinhaSuperiorForm();
                        strcpy(dono.nome, Nome());
                        strcpy(dono.pessoa,CPF());
                        strcpy(dono.email, Email());
                        Confirma(dono.email, "seu email");
                        fflush(stdin);
                        strcpy(dono.senha, Senha());
                        Confirma(dono.senha, "sua senha");
                        criaMenuLinhaRodape(STRTAM);
                        dono.id = gerarID2();
                        salvar(tipodeusuario);
                        historicoLogins();
                        system("cls");

                        setanotificacao2:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "      Voce gostaria de receber lembretes?    ");
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "                   0 - nao");
                        criaMenuItem(STRTAM, "                   1 - sim");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        printf("\n\n            escolha: ");
                        fflush(stdin);
                        scanf("%c", &escolha);

                        while(escolha!='0' || escolha!= '1'){
                            opcaoInvalida();
                            goto setanotificacao2;
                        }

                        break;

                    case '2':
                        criaLinhaSuperiorForm();
                        strcpy(clinica.nome, Nome());
                        strcpy(clinica.email, Email());
                        Confirma(clinica.email, "seu email");
                        fflush(stdin);
                        strcpy(clinica.senha, Senha());
                        printf("%s",clinica.senha);
                        Confirma(clinica.senha, "sua senha");
                        criaMenuLinhaRodape(STRTAM);
                        clinica.id = gerarID2;
                        salvar(tipodeusuario);
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
            login:
            criaMenuLinhaSuperior();
            criaMenuItem(STRTAM, " ");
            criaMenuItem(STRTAM,"           LOGIN");
            criaMenuItem(STRTAM, " ");
            criaMenuLinhaRodape(STRTAM);
            printf("\n\n");
            criaForm();
            criaLinhaForm();
            fflush(stdin);
            printf("     Escreva o email: ");
            fgets(dono.email, 30, stdin);
            criaLinhaForm();
            fflush(stdin);
            printf("     Insira a senha: ");
            fgets(dono.senha, 10, stdin);

            while(validaLogin()==1){
                criaMenuLinhaSuperior();
                criaMenuItem(STRTAM, " ");
                criaMenuItem(STRTAM, "      Os dados que voce inseriu nao constam");
                criaMenuItem(STRTAM, "          nos registros de cadastro.");
                criaMenuItem(STRTAM, "      Voce sera direcionado para a pagina");
                criaMenuItem(STRTAM, "               de login novamente");
                criaMenuItem(STRTAM, " ");
                criaMenuLinhaRodape(STRTAM);
                printf("\n\n");
                system("pause");
                system("cls");
                system("pause");
                goto login;
            }

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
        scanf("%c",&escolha);

        switch (escolha){
            //cadastrar pet
            case '1'://-----------------------------------------------------------------------
                cadastrarPets:
                dono.quantidade = Quantidade("pets");
                animal = malloc(dono.quantidade * sizeof(pet));
                for(i=0; i<dono.quantidade; i++){
                    strcpy(animal[i].nomepet, Nome());
                    strcpy(animal[i].especie, Especie(animal[i].nomepet));
                    strcpy(animal[i].raca, Raca(animal[i].nomepet));
                    Idade(animal[i].nomepet);
                    Tamanho(animal[i].nomepet);
                    Peso(animal[i].nomepet);
                    Medicacao();
                    Diagnostico();
                    animal[i].id = gerarID1();
                }
                //função limpa
                salvarPet(tipodeusuario);
                cadastroRealizado();
                break;

            case '2'://-----------------------------------------------------------------------

                menuCartilhaTutor:
                Menu_Cartilha_Tutor();
                scanf("%c",&escolha);

                    switch(escolha){

                        case '1':
                            criaMenuLinhaSuperior();
                            criaMenuItem(STRTAM, " ");
                            criaMenuItem(STRTAM, "      Essa opcao implica no apagamento");
                            criaMenuItem(STRTAM, "        das informaçoes cadastradas");
                            criaMenuItem(STRTAM, "              anteriormente.");
                            criaMenuItem(STRTAM, " ");
                            criaMenuLinhaRodape(STRTAM);
                            goto cadastrarPets;
                        break;

                        case '2':
                            printaCartilha(escolhaInt, setanotificacao);
                        break;

                        case '3':
                            goto menuPrincipalTutor;
                        break;

                        case '0':
                            sair();

                        default:
                        opcaoInvalida();
                        goto menuPrincipalTutor;
                    }
            break;

            case '3'://-----------------------------------------------------------------------
            menuVacinas:
            Menu_Vacinas_Tutor();
            scanf("%c",escolha);
    
                switch(escolha){
    
                    case '1':
                        setarNotificacoes:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "               NOTIFICACOES ");
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "    Voce gostaria de receber notificacoes ");
                        criaMenuItem(STRTAM, "          sobre as vacinas pendentes?");
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "                  0 - nao");
                        criaMenuItem(STRTAM, "                  1 - sim");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        printf("\n\n            escolha: ");
                        fflush(stdin);
                        scanf("%c", &escolha);

                        while(escolha!='0' || escolha!= '1'){
                            opcaoInvalida();
                            goto setarNotificacoes;
                        }
                        if(escolha=='1'){
                            setanotificacao=1;
                        }

                    break;
                    
                    case '2':
                        //TODO: codar função printy vacinas
                    break;
                    
                    case '3':

                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "         CADASTRAR VACINAS");
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "   Voce so pode realizar essa etapa ");
                        criaMenuItem(STRTAM, "          uma vez por pet");
                        criaMenuLinhaRodape(STRTAM);
                        system("pause");
                        printf("\n\n");
                        if(dono.quantidade==1){
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "     Vimos aqui que voce so tem um pet");
                        criaMenuItem(STRTAM, "   cadastrado. Vamos ao cadastro de vacinas");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        system("pause");
                        printf("\n\n");
                        cadastrarVacina(animal[0].id, tipodeusuario, 0);
                        goto menuPrincipalTutor;
                        }else{
                            prosseguirParaCadastro:
                            criaMenuLinhaSuperior();
                            criaMenuItem(STRTAM, " ");
                            criaMenuItem(STRTAM, "     Para prosseguir para o cadastro voce ");
                            criaMenuItem(STRTAM, "     precisa selecionar um pet dentre os");
                            criaMenuItem(STRTAM, "          que voce tem cadastrados: ");
                            criaMenuItem(STRTAM, " ");
                            criaMenuLinhaRodape(STRTAM);
                            for(i=0; i<dono.quantidade; i++){
                                printf("\n          %d - %s",i,animal[i].nomepet);
                            }
                            printf("\n\n            escolha: ");
                            fflush(stdin);
                            scanf("%c", &escolha);

                            escolhaInt = escolha - '0';

                            while(escolhaInt < 0 || escolhaInt > dono.quantidade){
                                goto prosseguirParaCadastro;
                            }
                            system("pause");
                            printf("\n\n");
                            cadastrarVacina(animal[escolhaInt].id, tipodeusuario, escolhaInt);
                        }

                    break;

                    case '4':
                        goto menuPrincipalTutor;

                    case '0':
                        sair();

                    default: 
                        opcaoInvalida();
                        goto menuPrincipalTutor;
                }

            break;

            case '4'://-----------------------------------------------------------------------
            Menu_Pet_Tutor();
            scanf("%c",escolha);
                
                switch(escolha){
                    case '1':
                        
                        prosseguirParaDiario:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "      Para prosseguir para o diario voce ");
                        criaMenuItem(STRTAM, "     precisa selecionar um pet dentre os");
                        criaMenuItem(STRTAM, "          que voce tem cadastrados: ");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        for(i=0; i<dono.quantidade; i++){
                            printf("\n          %d - %s",i,animal[i].nomepet);
                        }
                        printf("\n\n            escolha: ");
                        fflush(stdin);
                        scanf("%c", &escolha);

                        escolhaInt = escolha - '0';

                        while(escolhaInt < 0 || escolhaInt > dono.quantidade){
                            goto prosseguirParaDiario;
                        }

                        VetorAuxiliarCodigo[0] = obterHumor(tipodeusuario);
                        VetorAuxiliarCodigo[1] = obterAlimentacao(tipodeusuario);
                        VetorAuxiliarCodigo[2] = obterMedicacao(tipodeusuario);
                        VetorAuxiliarCodigo[3] = obterUrina(tipodeusuario);
                        VetorAuxiliarCodigo[4] = obterFezes(tipodeusuario);
                        VetorAuxiliarCodigo[5] = obterIrregularidades(tipodeusuario);

                        //limpaENotifica();
                        system("cls");
                        salvarDiario:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, "      Deseja salvar os dados na data de hoje?");
                        criaMenuItem(STRTAM, "                  1 - Sim");
                        criaMenuItem(STRTAM, "                  2 - Nao");
                        criaMenuLinhaRodape(STRTAM);
                        fflush(stdin);
                        printf("\n\n            escolha:");
                        scanf("%c",&escolha);

                        if(escolha == '1'){
                            animal[escolhaInt].dados.diario[mes][dia] = codificador(VetorAuxiliarCodigo, 5, 0);
                            armazenarDiario(escolhaInt, data, animal[escolhaInt].dados.diario[mes][dia]);
                        }else if(escolha == 2){
                            criaForm();
                            
                            insereDia:
                            fflush(stdin);
                            printf("    Escreva o dia em que os dados serao salvos: ");
                            fgets(dd, 2, stdin);
                            dia = calculoDia(dd);
                            criaLinhaForm();
                            
                            insereMes:
                            fflush(stdin);
                            printf("    Agora escreva o mes: ");
                            fgets(mm, 2, stdin);
                            mes = calculoMes(mm);
                            while(validaMes(mes)==1){
                                goto insereMes;
                            }
                            while(validaDia(dia, mes)==1){
                                goto insereDia;
                            }

                            animal[escolhaInt].dados.diario[mes][dia] = codificador(VetorAuxiliarCodigo, 5, 0);
                            armazenarDiario(escolhaInt, data, animal[escolhaInt].dados.diario[mes][dia]);
                        }else{
                            opcaoInvalida();
                            goto salvarDiario;
                        }
                    break;
                
                    case '2':
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "      Essa opcao implica no apagamento");
                        criaMenuItem(STRTAM, "        das informaçoes cadastradas");
                        criaMenuItem(STRTAM, "              anteriormente.");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        goto prosseguirParaDiario;
                    break;

                    case '3':
                        prosseguirParaBusca:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "      Para prosseguir para a busca voce ");
                        criaMenuItem(STRTAM, "     precisa selecionar um pet dentre os");
                        criaMenuItem(STRTAM, "          que voce tem cadastrados: ");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        for(i=0; i<dono.quantidade; i++){
                            printf("\n          %d - %s",i,animal[i].nomepet);
                        }
                        printf("\n\n            escolha: ");
                        fflush(stdin);
                        scanf("%c", &escolha);

                        escolhaInt = escolha - '0';

                        while(escolhaInt < 0 || escolhaInt > dono.quantidade){
                            goto prosseguirParaBusca;
                        }
                    break;
                    
                    case '4':
                        goto menuPrincipalTutor;
                    break;
                    
                    case '0':
                    sair();
                    break;
                    
                    default:
                    opcaoInvalida();
                    goto menuPrincipalTutor;
                    break;
                }

            case '5':
            menuTutorClinica:
            Menu_Clinica_Tutor();
            scanf("%c",&escolha);
            switch(escolha){
                case '1':
                    //TODO: função printy loja
                break;

                case '2':
                    //TODO: função printy potr motivos tecnicos essa função não foi implementada.: numero 
                break;

                case '3':
                    //TODO: AGENDAR CONSULTA
                break;
                
                case '4':
                    goto menuTutorClinica;
                break;

                case '0':
                    sair();
                
                default:
                opcaoInvalida();
                goto menuTutorClinica;
            }

            break;

            case '0':
                sair();

            default:
                opcaoInvalida();
                goto menuPrincipalTutor;
            break;
        }    
    }else{
        menuPrincipalClinica:
        Menu_Clinica();
        scanf("%c",escolha);

            switch(escolha){

                case '1':
                cadastrarVets:



                break;

                case '2':
                menuProdutosClinica:
                Menu_Produtos_Clinica();
                    scanf("%c",escolha);

                    switch(escolha){
                        case '1':
                            cadastrarProdutos();
                        break;

                        case '2':
                            //TODO: função printy produtos
                        break;

                        case '3':
                            
                        break;

                        case '4':
                            goto menuPrincipalClinica;
                        break;

                        case '0':
                        sair();
                        break;

                        default:
                            opcaoInvalida();
                            goto menuPrincipalClinica;
                        break;
                    }
                break;

                case '3':
                    menuVacinasClinica:
                    Menu_Vacinas_Clinica();
                    scanf("%c",escolha);
                    switch(escolha){
                        case '1':
                        prosseguirParaCadastro2:
                            criaMenuLinhaSuperior();
                            criaMenuItem(STRTAM, " ");
                            criaMenuItem(STRTAM, "     Para prosseguir para o cadastro voce ");
                            criaMenuItem(STRTAM, "     precisa selecionar um tutor dentre os");
                            criaMenuItem(STRTAM, "             que estao cadastrados: ");
                            criaMenuItem(STRTAM, " ");
                            criaMenuLinhaRodape(STRTAM);
                            listaUsuario();
                            printf("\n\n            escolha: ");
                            fflush(stdin);
                            scanf("%c", &escolha);

                            escolhaInt = escolha - '0';

                            while(escolhaInt < 0 || escolhaInt > parametro){
                                goto prosseguirParaCadastro2;
                            }

                            dono.id = encontraIDUsuario(escolhaInt); 

                            prosseguirParaCadastro3:
                            criaMenuLinhaSuperior();
                            criaMenuItem(STRTAM, " ");
                            criaMenuItem(STRTAM, "      Otimo, agora para prosseguir para o");
                            criaMenuItem(STRTAM, "    cadastro voce precisa selecionar um pet:");
                            criaMenuItem(STRTAM, " ");
                            criaMenuLinhaRodape(STRTAM);
                            
                            listaPetsPorTutor(encontraIDUsuario(escolhaInt));

                            printf("\n\n            escolha: ");
                            fflush(stdin);
                            scanf("%c", &escolha);

                            escolhaInt = escolha - '0';

                            while(escolhaInt < 0 || escolhaInt > parametro){
                                goto prosseguirParaCadastro3;
                            }

                            system("pause");
                            printf("\n\n");
                            if(encontraPet(escolhaInt, encontraIDUsuario(escolhaInt))!=0){
                            cadastrarVacina(encontraPet(escolhaInt, encontraIDUsuario(escolhaInt)), tipodeusuario, escolhaInt);
                            }else{
                                criaMenuLinhaSuperior();
                                criaMenuItem(STRTAM, " ");
                                criaMenuItem(STRTAM, "          Nao foi possivel cadastrar vacinas ");
                                criaMenuItem(STRTAM, "         a partir dos dados inseridos. tente ");
                                criaMenuItem(STRTAM, "                novamente mais tarde.");
                                criaMenuItem(STRTAM, " ");
                                criaMenuLinhaRodape(STRTAM);
                            }
                        break;

                        case '2':
                            limpaENotifica(0);
                        break;

                        case '3':
                            goto menuPrincipalClinica;
                        break;

                        case '0':
                        sair();

                        default:
                        opcaoInvalida();
                        goto menuPrincipalClinica;
                    }
                break;

                case '4':
                menuDiarioPetClinica:
                Menu_Pet_Clinica();
                scanf("%c",&escolha);
                
                switch(escolha){
                    case '1':
                        // criaForm();
                            
                        //     insereDia:
                        //     fflush(stdin);
                        //     printf("    Escreva o dia em que os dados serao salvos: ");
                        //     fgets(dd, 2, stdin);
                        //     dia = calculoDia(dd);
                        //     criaLinhaForm();
                            
                        //     insereMes:
                        //     fflush(stdin);
                        //     printf("    Agora escreva o mes: ");
                        //     fgets(mm, 2, stdin);
                        //     mes = calculoMes(mm);
                        //     while(validaMes(mes)==1){
                        //         goto insereMes;
                        //     }
                        //     while(validaDia(dia, mes)==1){
                        //         goto insereDia;
                        //     }

                        //     animal[escolhaInt].dados.diario[mes][dia] = codificador(VetorAuxiliarCodigo, 5, 0);
                        //     armazenarDiario(escolhaInt, data, animal[escolhaInt].dados.diario[mes][dia]);
                    break;

                    case '2':
                        prosseguirParaDiario1:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "     Para prosseguir para o cadastro voce ");
                        criaMenuItem(STRTAM, "     precisa selecionar um tutor dentre os");
                        criaMenuItem(STRTAM, "             que estao cadastrados: ");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        listaUsuario();
                        printf("\n\n            escolha: ");
                        fflush(stdin);
                        scanf("%c", &escolha);

                        escolhaInt = escolha - '0';

                        while(escolhaInt < 0 || escolhaInt > parametro){
                            goto prosseguirParaDiario1;
                        }
                        dono.id = encontraIDUsuario(escolhaInt); 

                        prosseguirParaDiario2:
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "      Para prosseguir para o diario voce ");
                        criaMenuItem(STRTAM, "     precisa selecionar um pet dentre os");
                        criaMenuItem(STRTAM, "          que estao cadastrados: ");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);

                        listaPetsPorTutor(dono.id);
                        
                        printf("\n\n            escolha: ");
                        fflush(stdin);
                        scanf("%c", &escolha);

                        escolhaInt = escolha - '0';

                        while(escolhaInt < 0 || escolhaInt > dono.quantidade){
                            goto prosseguirParaDiario2;
                        }
                        animal[0].id = encontraPet(escolhaInt, dono.id);

                        escolhaTipo: 
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, "      ");
                        criaMenuItem(STRTAM, "    Escolha um dos tipos de informacao abaixo");
                        criaMenuItem(STRTAM, "        para conhecer a data em que o pet");
                        criaMenuItem(STRTAM, "          escolhido apresentou essas");
                        criaMenuItem(STRTAM, "                caracteristicas.");
                        criaMenuItem(STRTAM, " ");
                        criaMenuItem(STRTAM, "              1 - humor");
                        criaMenuItem(STRTAM, "              2 - alimentacao");
                        criaMenuItem(STRTAM, "              3 - medicacao");
                        criaMenuItem(STRTAM, "              4 - urina ");
                        criaMenuItem(STRTAM, "              5 - fezes");
                        criaMenuItem(STRTAM, "              6 - outras irregularidades");
                        criaMenuItem(STRTAM, " ");
                        criaMenuLinhaRodape(STRTAM);
                        fflush(stdin);
                        scanf("%c",&escolha);
                        switch(escolha){
                            case '1':
                                buscadorPorTipo(11, (obterHumor(tipodeusuario)+'0'), animal[escolhaInt].id);
                            break;

                            case '2':
                                buscadorPorTipo(12, (obterAlimentacao(tipodeusuario) + '0'), animal[escolhaInt].id);
                            break;

                            case '3':
                                buscadorPorTipo(13, (obterMedicacao(tipodeusuario) + '0'),animal[escolhaInt].id);
                            break;
                            case '4':
                                buscadorPorTipo(14, (obterUrina(tipodeusuario) + '0'), animal[escolhaInt].id);
                            break;

                            case '5':
                                buscadorPorTipo(15, (obterFezes(tipodeusuario) + '0'), animal[escolhaInt].id);
                            break;

                            case '6':
                                buscadorPorTipo(16, (obterIrregularidades(tipodeusuario) + '0'), animal[escolhaInt].id);
                            break;

                            default:
                            opcaoInvalida();
                            goto escolhaTipo;
                        }
                    break;
                    
                    case '3':
                        goto menuPrincipalClinica;
                    break;

                    case '0':
                        sair();

                    default:
                        opcaoInvalida();
                        goto menuPrincipalClinica;
                }
                break;

                case '5':
                menuContatoClinica:
                Menu_Contato_Clinica();
                scanf("%c",&escolha);
                switch(escolha){
                    case '1':
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, "      CONTATO: ");
                        criaMenuLinhaRodape(STRTAM);
                        printf("            %s",clinica.numero);
                    break;

                    case '2':
                        criaMenuLinhaSuperior();
                        criaMenuItem(STRTAM, "      Escreva o nome do plantonista de hoje abaixo:");
                        criaMenuLinhaRodape(STRTAM);
                        fflush(stdin);
                        fgets(string, 30, stdin);
                        armazenarPlantonista(string);
                    break;

                    case '3':
                        goto menuPrincipalClinica;
                    break;

                    case '0':
                    sair();
                    break;

                    default:
                    opcaoInvalida();
                    goto menuPrincipalClinica;
                }
                break;

                case '0':
                    sair();

                default:
                    opcaoInvalida();
                    goto menuPrincipalClinica;
            }
    }
return 0;
}