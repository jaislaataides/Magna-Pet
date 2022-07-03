#include <stdio.h>


//----------------------------------------------------------- E X I B I Ç Ã O ------------------------------------------------------

//---- mensagens ----

//cadastro realizado com sucesso
void cadastroRealizado(){
    printf("\n\n");
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "Cadastro realizado com sucesso!");
    criaMenuLinhaRodape(STRTAM);
    printf("\n\n");
    system("pause");
}

//você escolheu sair
void sair(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "          Infelizmente voce escolheu sair :( ");
    criaMenuLinhaRodape(STRTAM);
    printf("\n\n");
    exit(0);
}

//default
void opcaoInvalida(){
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Voce digitou uma opcao invalida!");
    criaMenuItem(STRTAM, "      Voce voltara para o ultimo menu  ");
    criaMenuItem(STRTAM, "      para escolher uma opcao valida");
    criaMenuLinhaRodape(STRTAM);
    system("pause");
}

//printar cartilha
void printaCartilha(char tipodeusuario1, int escolha, int setanotificacao){
    limpaENotifica(tipodeusuario1, setanotificacao);

    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, " ");
    criaMenuItem(STRTAM, "                  CARTILHA");
    criaMenuItem(STRTAM, " ");
    criaMenuLinhaRodape(STRTAM);
    criaLinhaForm();
    criaLinhaForm();
    printf("    Nome : %s",animal[escolha].nomepet);
    criaLinhaForm();
    printf("     Especie: %s",animal[escolha].especie);
    criaLinhaForm();
    printf("    Raca: %s");
    criaLinhaForm();
    printf("    Idade: %d");
    criaLinhaForm();
    printf("    Tamanho : %d cm");
    criaLinhaForm();
    printf("    Peso: %.2f");
    criaLinhaForm();
    if(animal[escolha].medicacao[0][0]==' '){
        printf("    Medicacao : nenhuma");
    }else{
        printf("    Medicacao :");
        for(i=0; i<qtdMed; i++){
            criaLinhaForm();
            printf("    %s",animal[escolha].medicacao[i]);
        }
    }
    criaLinhaForm();
    printf("    Diagnostico : ");
    if(animal[escolha].diagnostico[0][0]==' '){
        printf(" nenhum");
    }else{
        for(i=0; i<qtdDiag; i++){
            criaLinhaForm();
            printf("    %s",animal[escolha].diagnostico[i]);
        }
    }
    criaMenuLinhaRodape(STRTAM);
}