#include "validacoes.h"

//tratamento email
void tratamentoEmail(char *email){
    while(validadordeemail(email)==1){
        fflush(stdin);
        criaLinhaForm();
        printf("O email digitado nao e valido.");
        criaLinhaForm();
        printf("Por favor, insira novamente: ");
        fgets(email, 50, stdin);
        printf("\n\n");
    }
}

//tratamento cpf ou cnpj
void tratamentoCPFCNPJ(char *input){
    back:
    if(strlen(input)==12){
        while(validadordecpf(input)==1){
            criaLinhaForm();
            printf("O CPF digitado nao e valido, por favor, digite novamente: ");
            fgets(input, 12, stdin);
        }
    }else if(strlen(input)==14){
        while(validadordecnpj(input)==1){
            criaLinhaForm();
            printf("O CNPJ digitado nao e valido, por gentileza, digite novamente: ");
            fgets(input, 14, stdin);
        }
    }else{
            criaLinhaForm();
            printf("A quantidade de digitos que voce inseriu ultrapassa o limite do CPF e CNPJ ou e insuficiente!");
            criaLinhaForm();
            printf("Por favor, digite novamente: ");
            fgets(input,14,stdin);
            printf("\n\n");
            goto back;
    }
}

//tratamento: senha
void tratamentoSenha(char *senha){
    while(strlen(senha)<6 || strlen(senha)>10){
        criaLinhaForm();
        printf("A senha inserida e muito curta ou longa demais.");
        criaLinhaForm();
        printf("Tente outra, por favor: ");
        fgets(senha,10,stdin);
    }
}

//tratamento: confirmar
void tratamentoConfirmacao(char *palavra1, char *palavra2, char *palavra3){
    while(Confirmar(palavra1,palavra2)!=0){
        criaLinhaForm();
        printf("A confirmacao de %s nao foi bem sucedida.\nPor favor, confirme %s novamente: ",palavra3, palavra3);
        fgets(palavra2, 50, stdin);
    }
}

//tratamento ascii
void tratamentoASCII(char *palavra){
    while(validadordeAscii(palavra)==1){
        fflush(stdin);
        criaLinhaForm();
        printf("Voce esta inserindo caracteres invalidos neste campo.");
        criaLinhaForm();
        printf("Por favor, digite novamente utilizando apenas simbolos do alfabeto:");
        fgets(palavra, 50, stdin);
    }
}

//estabelece uma quantidade mínima e máxima
void tratamentoQuantidade(int *quant, char *palavra){
    while (quant<1 || quant>30){
        criaLinhaForm();
        printf("O numero digitado nao pode ser admitido como quantidade de %s.",palavra);
        printf("Por favor, digite novamente: ");
        scanf("%d",&quant);
    }
}

//com base em variáveis, gera tratamento de erro por intervalo
int tratamentoObterDadosDiarios(int aux, int op1, int op2){
    char escolha;
    printf("\n\n");

    while (aux < op1 || aux > op2){
        criaMenuLinhaSuperior(STRTAM);
        criaMenuItem(STRTAM, "      Voce digitou uma opcao invalida!");
        criaMenuItem(STRTAM, "          Por favor, digite de novo: ");
        criaMenuLinhaRodape(STRTAM);
        printf("\n\n           escolha: ");
        fflush(stdin);
        scanf("%c", &escolha);
        aux = escolha - '0';
        printf("\n\n");
    }
    return aux;
}

