#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#define STRTAM 60



void criaMenuLinhaSuperior()
{
    int i;
    printf("%c", 201);
    for (i = 0; i < STRTAM; i++)
        printf("%c", 205);
    printf("%c\n", 187);
}

void criaMenuLinhaRodape(int tamX)
{
    int i;
    printf("%c", 200);
    for (i = 0; i < STRTAM; i++)
        printf("%c", 205);
    printf("%c\n", 188);
}

void criaMenuItem(int tamX, char str[])
{
    int contaLetras = 0;
    int i;

    for (i = 0; i < tamX; i++)
    {
        if (str[i] == '\0')
            break;
        else
            contaLetras++;
    }

    printf("%c", 186);
    // for (i=0;i<STRTAM;i++)
    printf("%s", str);
    while (contaLetras < tamX)
    {
        printf("%c", 32);
        contaLetras++;
    }
    printf("%c\n", 186);
}

void MenuInicio()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Bem vindo, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "              1 - Cadastrar");
    criaMenuItem(STRTAM, "              2 - Login");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Tutor()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Onde deseja ir tutor?: ");
    criaMenuItem(STRTAM, "       1 - Cadastrar Pets ");
    criaMenuItem(STRTAM, "       2 - Cartilha ");
    criaMenuItem(STRTAM, "       3 - Cartao de Vacinas");
    criaMenuItem(STRTAM, "       4 - Diario Pet ");
    criaMenuItem(STRTAM, "       5 - Clinica");
    criaMenuItem(STRTAM, "           0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Cartilha_Tutor()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Tutor, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Editar Informacoes");
    criaMenuItem(STRTAM, "      2 - Visualizar Informacoes");
    criaMenuItem(STRTAM, "      3 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Clinica_Tutor()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Tutor, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Visualizar Produtos");
    criaMenuItem(STRTAM, "      2 - Contato Clinica");
    criaMenuItem(STRTAM, "      3 - Agendar Consulta");
    criaMenuItem(STRTAM, "      4 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_CadPet_Tutor()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Tutor, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Inserir Lembrete Vacinal");
    criaMenuItem(STRTAM, "      2 - Visualizar Vacinas");
    criaMenuItem(STRTAM, "      3 - Cadastrar Vacinas");
    criaMenuItem(STRTAM, "      4 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Vacinas_Tutor()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Tutor, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Inserir Lembrete Vacinal");
    criaMenuItem(STRTAM, "      2 - Visualizar Vacinas");
    criaMenuItem(STRTAM, "      3 - Cadastrar Vacinas");
    criaMenuItem(STRTAM, "      4 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Pet_Tutor()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Tutor, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Inserir Informacoes");
    criaMenuItem(STRTAM, "      2 - Editar Informacoes");
    criaMenuItem(STRTAM, "      3 - Pesquisar Informacoes");
    criaMenuItem(STRTAM, "      4 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Clinica()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Onde deseja ir profissional?: ");
    criaMenuItem(STRTAM, "      1 - Produtos");
    criaMenuItem(STRTAM, "      2 - Cartao de Vacinas");
    criaMenuItem(STRTAM, "      3 - Diario Pet");
    criaMenuItem(STRTAM, "      4 - Contato");
    criaMenuItem(STRTAM, "      0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Vacinas_Clinica()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Profissional, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Inserir Vacinas");
    criaMenuItem(STRTAM, "      2 - Editar Vacinas");
    criaMenuItem(STRTAM, "      3 - Inserir Avisos");
    criaMenuItem(STRTAM, "      4 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "           0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Contato_Clinica()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Profissional, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Informações de Contato");
    criaMenuItem(STRTAM, "      2 - Editar Plantonista");
    criaMenuItem(STRTAM, "      3 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Pet_Clinica()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Profissional, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Buscar informacoes por data");
    criaMenuItem(STRTAM, "      2 - Buscar informacoes por tipo");
    criaMenuItem(STRTAM, "      3 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

void Menu_Produtos_Clinica()
{
    criaMenuLinhaSuperior();
    criaMenuItem(STRTAM, "      Profissional, o que deseja fazer?: ");
    criaMenuItem(STRTAM, "      1 - Cadastrar Produtos");
    criaMenuItem(STRTAM, "      2 - Editar Produtos");
    criaMenuItem(STRTAM, "      3 - Visualizar Produtos");
    criaMenuItem(STRTAM, "      4 - Voltar ao Menu Principal");
    criaMenuItem(STRTAM, "              0 - Sair");
    criaMenuLinhaRodape(STRTAM);
    fflush(stdin);
}

// ------------ FORMULARIO ----------------

void criaLinhaSuperiorForm()
{
    int i;
    printf("%c", 201);
    for (i = 0; i < STRTAM; i++)
        printf("%c", 205);
}

void criaLinhaForm()
{
    fflush(stdin);
    printf("\n%c", 186);
}

void criaForm(){
    criaLinhaSuperiorForm();
    criaLinhaForm();
}
