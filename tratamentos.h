
#include "validacoes.h"

//tratamento email
void tratamentoEmail(char *email){
    while(validadordeemail(email)==1){
        printf("\nO email digitado nao e valido.\nPor favor, insira novamente: ");
        fgets(email, 50, stdin);
    }
}

//tratamento cpf ou cnpj
void tratamentoCPFCNPJ(char *input){
    back:
    if(strlen(input)==11){
        while(validadordecpf(input)==1){
            printf("\nO CPF digitado nao e valido, por favor, digite novamente: ");
            fgets(input, 11, stdin);
        }
    }else if(strlen(input)==14){
        while(validadordecnpj(input)==1){
            printf("\nO CNPJ digitado nao e valido, por gentileza, digite novamente: ");
            fgets(input, 14, stdin);
        }
    }else{
        do{
            printf("\nOs digitos que voce inseriu ultrapassam o limite do CPF e CNPJ ou sao insuficientes!\nPor favor, digite novamente: ");
            fgets(input,14,stdin);
            goto back;
        }while(strlen(input)!=11 && strlen(input)!=14);
    }
}

//tratamento: senha
void tratamentoSenha(char *senha){
    while(strlen(senha)<6 || strlen(senha)>10){
        fflush(stdin);
        system("cls");
        printf("\nA senha inserida e muito curta ou longa demais.\nTente outra, por favor: ");
        fgets(senha,10,stdin);
    }
}

//tratamento: confirmar
void tratamentoConfirmacao(char *palavra1, char *palavra2, char *palavra3){
    printf("%s\n%s\n\n%d",palavra1,palavra2,Confirmar(palavra1, palavra2));
    while(Confirmar(palavra1,palavra2)!=0){
        printf("\nA confirmacao de %s nao foi bem sucedida.\nPor favor, confirme %s novamente: ",palavra3, palavra3);
        fgets(palavra2, 50, stdin);
    }
}

//tratamento ascii
void tratamentoASCII(char *palavra){
    while(validadordeAscii(palavra)==1){
        printf("\nVoce esta inserindo caracteres invalidos neste campo.\nPor favor, digite novamente utilizando apenas simbolos do alfabeto:");
        fgets(palavra, 50, stdin);
    }
}