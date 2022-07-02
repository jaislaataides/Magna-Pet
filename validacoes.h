#include <string.h>
//----------------------------------------- V A L I D A Ç Õ E S -----------------------------------------------------

int validadordecnpj(char *input);
int validadordecpf(char *input);

//------- Validação de email
int validadordeemail(char *email){
    int v=0, v2=0, v3=0, arroba=0, i;

    for (i=0; email[i]!='\0'; i++){

        if(email[i]=='@' && email[i-1]==' '){
            v++;
        }else if(email[i]=='@'){
            v2=i;
            arroba++;
        }

        if(email[i]=='.' && email[i+1]!='\0' && email[i+1]!='\n'){
            v3=i;
        }
    }

    if(v==0 && arroba==1 && v2>0 && (v2+1)<v3){
        return 0;
    }else{
        return 1;
    }
}

//-------- validação de CPF
int validadordecpf(char *input){
    int cpf[11], aux[9], verificador[2], digitosiguais=0;
    int soma;

    //atribuição de valor numérico 
    for (i=0; i<11; i++){
        cpf[i] = input[i] - '0';
    }

    //calculo do produto e soma
    for (i=0, j=10; j>1, i<9; j--, i++){
        aux[i] = j*cpf[i];
        soma += aux[i];
    }

    //calcula o primeiro digito validador
    if (soma%11<2 && soma%11>0){
        verificador[0] = 0;
    }else{
        verificador[0] = 11 - (soma%11);
    }

    soma = 0;

    //calculo do produto e soma (segundo digito)
    for (i=0, j=11; j>1, i<10; j--, i++){
        aux[i] = j*cpf[i];
        soma += aux[i];
    }


    //calculo do segundo digito validador
    if (soma%11<2 && soma%11>0){
        verificador[1] = 0;
    }else{
        verificador[1] = 11 - (soma%11);
    }

    if(input=="0000000000" || input=="1111111111" || input=="2222222222" || input=="3333333333" || input=="4444444444" || input=="5555555555" || input=="6666666666" ||input=="7777777777" || input=="8888888888" || input=="99999999999"){
        digitosiguais++;
    }

    //saída: resultado da validação
    if ((verificador[0] != cpf[9] && verificador[1] != cpf[10]) || digitosiguais!=0){
        return 1;
    }else{
        return 0;
    }
}

//------- validação de CNPJ
int validadordecnpj(char *input){
    int cnpj[14], aux[12], aux2[]={5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}, verificador[2], digitosiguais=0;
    int soma=0;

    //não admite cnpjs fakes com todos os digitos iguais
    // if(input=="000000000000" || input=="111111111111" || input=="222222112222" || input=="333333333333" || input=="444444444444" || input=="555555555555" || input=="666666666666" ||input=="777777777777" || input=="888888888888" || input=="999999999999"){
    //     digitosiguais++;
    // }

    //calculo do produto e soma
    for(i=0; i<14; i++){
        cnpj[i] = input[i] - '0';
        if(i<12){
            aux[i]=aux2[i]*cnpj[i];
            soma+=aux[i];
        }
    }

    //calcula o primeiro dígito validador
    if (soma%11<2 && soma%11>0){
        verificador[0] = 0;
    }else{
        verificador[0] = 11 - (soma%11);
    }

    soma = 0;

    //calculo do produto e soma
    for(i=-1; i<=12; i++){
        if (i==-1){
            aux[i+1]=6*cnpj[i+1];
        }else{
            aux[i+1]=aux2[i]*cnpj[i+1];
        }
        soma+=aux[i+1];
    }

    //calcula o segundo dígito validador
    if (soma%11<2 && soma%11>0){
        verificador[1] = 0;
    }else{
        verificador[1] = 11 - (soma%11);
    }

    //saída: resultado da validação
    if ((verificador[0] != cnpj[12] && verificador[1] != cnpj[13]) || digitosiguais!=0){
        return 1;
    }else{
        return 0;
    }
}

//Confirmar repetição
int Confirmar(char *palavra1, char *palavra2){
    if (strcmp(palavra1, palavra2)==0){
        return 0;
    }else{
        return 1;
    }
}

//validação ASCII
int validadordeAscii(char *palavra){
    for (i=0; palavra[i]!='\0'; i++){
        if((palavra[i]<'A'||(palavra[i]>'Z' && palavra[i]<'a')||palavra[i]>'z')&& palavra[i]!=' ' && palavra[i]!='\n'){
            return 1;
        }
    }
    return 0;
}

