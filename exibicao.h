#include <stdio.h>
#include "menus.h"

//----------------------------------------------------------- E X I B I Ç Ã O ------------------------------------------------------

//---- mensagens ----

//cadastro realizado com sucesso
void cadastroRealizado(){
    printf("\n\n");
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "Cadastro realizado com sucesso!");
    criaMenuLinhaRodape(STRTAM);
    printf("\n\n");
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
    criaMenuItem(STRTAM, "          Voce voltara para o menu : ");
    criaMenuItem(STRTAM, "           para escolher uma opcao : ");
    criaMenuLinhaRodape(STRTAM);
    system("pause");
}