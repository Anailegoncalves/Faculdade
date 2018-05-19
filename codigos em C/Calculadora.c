#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include <locale.h> //necess�rio para usar setlocale.

int main()
{


    int opc,foi=0;
    system("COLOR F0"); //usado para modificar a cor da tela para branco.
 	setlocale(LC_ALL, "Portuguese"); //define a linguagem para portugues permitindo o uso de acentos.
    float n1,result, resultAnterior, n2;
     char ope,util;



    while (opc !=0){

        printf("[1] Soma\n");
        printf("[2] Subtra��o\n");
        printf("[3] Divis�o\n");
        printf("[4] Multiplica��o\n");
        printf("[5] Potencia\n");
        printf("[6] Raiz\n");
        printf("[7] Resto da divis�o\n");
        printf("[0] Sair\n");
        printf("Escolha uma op��o\n");
        scanf ("%d", &opc);

        switch(opc)
        {
            case 1:
                system("cls"); // Esta fun��o limpa o console/tela

                printf("[Soma]\n\n");
                printf("Digite um numero seguido de '+' e outro numero.\n\n");
                printf("*********************************************************************\n\n");
                if(foi==0){ // Valida��o se houve ou n�o uma opera��o realizada anteriormente

                    scanf("%f", &n1); //recebe o que foi digitado pelo usuario
                    scanf(" %c", &ope);
                    scanf(" %f", &n2);

                    if(ope=='+'){ // Valida��o se foi digitado o operando correto
                            result = n1+n2;
                        printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                        foi++;// ele adiciona 1 ao foi para proseguir
                    }else{
                        printf("operador inv�lido\n");
                    }
                }else { // Caso j� tenha sido realizada uma opera��o anterior
                    printf("voc� deseja usar o resultado anterior [s/n]: ");
                    scanf(" %c",&util);
                    if(util=='s'){ //Se deseja utilizar o resultado da opera��o anterior
                        printf("%.2f", result);
                        scanf(" %f", &ope);
                        scanf(" %f", &n2);

                        if(ope=='+'){
                            result = result+n2;
                            printf("%.2f %c %.2f = %.2f\n\n", result-n2, ope, n2, result);

                        }else{
                            printf("operador inv�lido\n");
                        }

                    }else{ // Caso n�o deseje utilizar o resultado da opera��o anterior
                        printf("inicie sua conta\n");

                        scanf("%f", &n1);
                        scanf(" %c", &ope);
                        scanf(" %f", &n2);

                        if(ope=='+'){
                                result = n1+n2;
                            printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                        }else{
                            printf("operador inv�lido\n");
                        }
                    }
                }

                system("pause");// Da um "pause" na no console/ tela, pedindo ao usuario digitar algo para prosseguir. Muito
                                // utilizado para permitir o usuario a visualizar o que se foi feito de opera��o

                system("cls");


                break; // Pausa o conjuto de opera��es no case, pois, caso n�o tenha essa fun��o aqui, ser� executado todos os cases
                       // posteriores ao da verifica��o.
            case 2:

                system("cls");

                printf("[Subtra��o]\n\n");
                printf("Digite um numero seguido de '-' e outro numero.\n\n");
                printf("*********************************************************************\n\n");
                if(foi==0){

                    scanf("%f", &n1);
                    scanf(" %c", &ope);
                    scanf(" %f", &n2);

                    if(ope=='-'){
                            result = n1-n2;
                        printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                        foi++;
                    }else{
                        printf("operador inv�lido\n");
                    }

                } else {

                    printf("voc� deseja usar o resultado anterior [s/n]: ");
                    scanf(" %c",&util);
                    if(util=='s'){

                        printf("%.2f",result);
                        scanf(" %c", &ope);
                        scanf(" %f", &n2);

                        if(ope=='-'){
                                resultAnterior= result;
                                result = resultAnterior-n2;
                            printf("%.2f %c %.2f = %.2f\n\n", resultAnterior, ope, n2, result);
                        }else{
                            printf("operador inv�lido\n");
                        }


                    } else {

                            scanf("%f", &n1);
                            scanf(" %c", &ope);
                            scanf(" %f", &n2);

                            if(ope=='-'){
                                    result = n1-n2;
                                printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                            }else{
                                printf("operador inv�lido\n");
                            }

                    }
                }




                system("pause");

                system("cls");
                break;
            case 3:

                system("cls");

                printf("[Divis�o]\n\n");
                printf("Digite um numero seguido de '/' e outro numero.\n\n");
                printf("*********************************************************************\n\n");
                if(foi==0){

                    scanf("%f", &n1);
                    scanf(" %c", &ope);
                    scanf(" %f", &n2);

                    if(ope=='/'){


                        if(n1>=1&& n2 >=1)
                        {
                            result = n1/n2;
                            printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                            foi++;
                        }
                        else {
                            printf(" A divis�o n�o pode ser feita com 0\n\n");
                        }

                    }else{
                        printf("operador inv�lido\n");
                    }


                } else{

                    printf("voc� deseja usar o resultado anterior [s/n]: ");
                    scanf(" %c",&util);
                    if(util=='s'){
                        printf("%.2f", result);
                        scanf(" %c", &ope);
                        scanf(" %f", &n2);

                        if(ope=='/'){
                                resultAnterior= result;
                                result = resultAnterior/n2;
                                printf("%.2f %c %.2f = %.2f\n\n", resultAnterior, ope, n2, result);

                        }else{
                            printf("operador inv�lido\n");
                        }
                     }else{

                          scanf("%f", &n1);
                        scanf(" %c", &ope);
                        scanf(" %f", &n2);

                        if(ope=='/'){


                            if(n1>=1&& n2 >=1)
                            {
                                result = n1/n2;
                                printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);

                            }
                            else {
                                printf(" A divis�o n�o pode ser feita com 0\n\n");
                            }

                        }else{
                            printf("operador inv�lido\n");
                        }


                     }
                }


                system("pause");

                system("cls");
                break;
            case 4:

                system("cls");

                printf("[Multiplica��o]\n\n");
                printf("Digite um numero seguido de '*' e outro numero.\n\n");
                printf("*********************************************************************\n\n");
                if(foi==0){
                    scanf("%f", &n1);
                    scanf(" %c", &ope);
                    scanf(" %f", &n2);

                    if(ope=='*'){
                            result = n1*n2;
                        printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                        foi++;
                    }else{
                        printf("operador inv�lido\n");
                    }


                }else{

                    printf("voc� deseja usar o resultado anterior [s/n]: ");
                    scanf(" %c",&util);
                    if(util=='s'){
                        printf("%.2f", result);
                        scanf(" %c", &ope);
                        scanf(" %f", &n2);
                        if(ope=='*'){
                                resultAnterior= result;
                                result = resultAnterior*n2;
                                printf("%.2f %c %.2f = %.2f\n\n", resultAnterior, ope, n2, result);


                        }else{
                            printf("operador inv�lido\n");
                        }
                    }else{

                        printf("multiplica��o\n");
                        scanf("%f", &n1);
                        scanf(" %c", &ope);
                        scanf(" %f", &n2);

                        if(ope=='*'){
                                result = n1*n2;
                            printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                            foi++;
                        }else{
                            printf("operador inv�lido\n");
                        }


                    }

                }


                system("pause");

                system("cls");
                break;
            case 5:

                system("cls");

                printf("[Pot�ncia]\n\n");
                printf("Digite um numero seguido de '^' e outro numero.\n\n");
                printf("*********************************************************************\n\n");
                if(foi==0){
                    scanf("%f", &n1);
                    scanf(" %c", &ope);
                    scanf(" %f", &n2);

                    if(ope=='^'){
                        result = pow(n1,n2);
                        printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                        foi++;
                    }else{
                        printf("operador inv�lido\n");
                    }

                }else{
                    printf("voc� deseja usar o resultado anterior [s/n]: ");
                    scanf(" %c",&util);
                    if(util=='s'){
                        printf("%.2f", result);
                        scanf(" %c", &ope);
                        scanf(" %f", &n1);
                        if(ope=='^'){
                                resultAnterior= result;
                                result = pow(resultAnterior,n1);
                                printf("%.2f %c %.2f = %.2f\n\n", resultAnterior, ope, n1, result);
                        }
                    }else{
                        printf("pot�ncia\n");
                        scanf("%f", &n1);
                        scanf(" %c", &ope);
                        scanf(" %f", &n2);

                        if(ope=='^'){
                                result = pow(n1,n2);
                            printf("%.2f %c %.2f = %.2f\n\n", n1, ope, n2, result);
                            foi++;
                        }else{
                            printf("operador inv�lido\n");
                        }
                    }

                }




                system("pause");

                system("cls");
                break;
            case 6:

                system("cls");

                printf("[Raiz]\n\n");
                printf("Digite um numero seguido de 'v' e outro numero.\n\n");
                printf("*********************************************************************\n\n");
                if(foi==0){
                    scanf(" %c", &ope);
                    scanf(" %f", &n1);

                    if(ope=='v'){
                        result = sqrt(n1);
                        printf(" %c%.2f = %.2f\n\n", ope,n1, result);
                        foi++;
                    }else{
                        printf("operador inv�lido\n");
                    }


                }else{
                    printf("voc� deseja usar o resultado anterior [s/n]: ");
                    scanf(" %c",&util);
                    if(util=='s'){
                        resultAnterior= result;
                        result = sqrt(resultAnterior);
                        printf("v%.2f = %.2f\n\n", resultAnterior, result);
                    }else{

                        printf("raiz\n");
                        scanf(" %c", &ope);
                        scanf(" %f", &n1);

                        if(ope=='v'){
                            result = sqrt( n1);
                            printf(" %c%.2f = %.2f\n\n", ope,n1, result);
                            foi++;
                        }else{
                            printf("operador inv�lido\n");
                        }


                    }

                }



                system("pause");

                system("cls");
                break;
            case 7:
                system("cls");

                printf("[Resto da divis�o]\n\n");
                printf("Digite um numero seguido de '%%' e outro numero.\n\n");
                printf("*********************************************************************\n\n");
                int num1,num2;
                 if(foi==0){

                    scanf("%d", &num1);
                    scanf(" %c", &ope);
                    scanf(" %d", &num2);

                    if(ope=='%'){
                        result = num1%num2;
                        printf("%d %c %d = %.2f\n\n", num1, ope, num2, result);
                    }else{
                        printf("operador inv�lido\n");
                    }

                }else{
                    printf("voc� deseja usar o resultado anterior [s/n]: ");
                    scanf(" %c",&util);
                    if(util=='s'){
                        printf("%.2f", result);
                        scanf(" %c", &ope);
                        scanf(" %d", &num2);

                        if(ope=='%'){
                            num1 = result;
                            result = num1%num2;
                            printf("%.2f %c %.2f = %.2f\n\n", num1, ope, n2, result);
                        }else{
                            printf("operador inv�lido\n");
                        }

                    }else{
                        scanf("%d", &num1);
                        scanf(" %c", &ope);
                        scanf(" %d", &num2);

                        if(ope=='%'){
                            result = num1%num2;
                            printf("%d %c %d = %.2f\n\n", num1, ope, num1, result);
                        }else{
                            printf("operador inv�lido\n");

                        }

                    }
                }

                system("pause");
                system("cls");
                break;

            case 0:
                printf("at� mais.\n");
                system("cls");
                break;

			default:
				printf("\nOp��o inv�lida\n\n");
        }
    }



    return 0;
}
