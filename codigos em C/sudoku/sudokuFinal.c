#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>
#define matrixMax 9
#define xInicial 10
#define yInicial 5

//matrizes
clock_t _tempo;
int matrix[matrixMax][matrixMax] = { {5, 3, 4, 6, 7, 8, 9, 1, 2},
       {6, 7, 2, 1, 9, 5, 3, 4, 8},
       {1, 9, 8, 3, 4, 2, 5, 6, 7},
       {8, 5, 9, 7, 6, 1, 4, 2, 3},
       {4, 2, 6, 8, 5, 3, 7, 9, 1},
       {7, 1, 3, 9, 2, 4, 8, 5, 6},
       {9, 6, 1, 5, 3, 7, 2, 8, 4},
       {2, 8, 7, 4, 1, 9, 6, 3, 5},
       {3, 4, 5, 2, 8, 6, 1, 7, 9}
       };
int matrixAux[matrixMax][matrixMax];

//funcoes
//movimentacao na tela
void gotoxy(int x,int y);
//moldura
void criaSudoku(int x, int y);
void imprimeCantos(int linha,int coluna);
void imprimeVazio(int linha, int coluna);
void imprimeMolduraExterna(int linha, int coluna);
void imprimeMolduraInterna(int linha, int coluna);
int EhMolduraExterna(int posicao);
int EhCanto(int posicao);
int EhCantoInicial(int posicao);
int EhImpar(int posicao);
void titulo();
int navegaMenu();
void Bordas();
void inicia_cronometro();
void para_cronometro();
//jogo
void jogar();
void preencheMolduraComMatriz(int x,int y,int matrix[9][9]);
int validaExistenteLinha(int pontoInicial, int numeroInserido);
int validaExistenteColuna(int pontoInicial, int numeroInserido);
void criaMatriz();
int matrixValidated(int x, int y, int digitado);
int finishGame();
int asciiConverter(int number);


int main(){

 system("COLOR F0"); //usado para modificar a cor da tela para branco.


int opc;
 char lerTexto[5];
 int enter = 13;
        int posicao;

while(posicao != 0){

    Bordas(100, 25);
    titulo();

    gotoxy(50,12);
    printf("Iniciar Jogo");
    gotoxy(50,14);
    printf("Regras do Jogo");
    gotoxy(50,16);
    printf("Historia do Sudoku");
    gotoxy(50,18);
    printf("Sair");

    gotoxy(48,12);
    printf("o");

    gotoxy(48,12);

    posicao = 1;
    while(1){
        opc = getch();
        posicao = navegaMenu(opc,posicao);
        if(opc == enter){
            break;
        }

    }

        switch(posicao){
        case 1:
                system("cls");
                inicia_cronometro();

                jogar();
                para_cronometro();
                system("cls");
                break;
        case 2:
            system("cls");
               printf("Regras");
               FILE *regrasFile;
               regrasFile = fopen("regras.txt","r"); // alterar local do texto para poder compilar.
                                                                                  // Salvar Texto na mesma pasta que o arquivo.
               if(regrasFile == NULL){
                    printf("Não foi possivel abrir o Arquivo\n");
                    system("cls");
                    break;
               }
               printf("\n\n");

                while(fgets(lerTexto, 5, regrasFile)!= NULL){
                    if(strcmp(lerTexto, "xxxx") == 0){
                        printf("\nPressione enter para continuar...");
                        getch();
                        system("cls");
                    }else{
                        printf("%s", lerTexto);
                    }
                }
                fclose(regrasFile);
                printf("\n\n");

                system("pause");
                system("cls");
                break;

        case 3:
                system("cls");
                printf("história");
               FILE *file;
               file = fopen("historia.txt","r"); // alterar local do texto para poder compilar.
                                                                                  // Salvar Texto na mesma pasta que o arquivo.
               if(file == NULL){
                    printf("Não foi possivel abrir o Arquivo\n");
                    system("cls");
                    break;
               }
               printf("\n\n");

                while(fgets(lerTexto, 5, file)!= NULL){
                    if(strcmp(lerTexto, "xxxx") == 0){
                        printf("\nPressione enter para continuar...");
                        getch();
                        system("cls");
                    }else{
                        printf("%s", lerTexto);
                    }
                }
                fclose(file);
                printf("\n\n");

                system("pause");
                system("cls");
                break;
        }

}

return 0;
}

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

 void imprimeCantos(int linha,int coluna){
    int cantoSuperiorEsquerdo = 201,
        cantoInferiorEsquerdo = 200,
        cantoSuperiorDireito = 187,
        cantoInferiorDireito = 188;

    if(linha == 1 && coluna == 1) printf("%c",cantoSuperiorEsquerdo);
    if(linha == 1 && coluna == 19) printf("%c",cantoSuperiorDireito);
    if(linha == 19 && coluna == 1) printf("%c",cantoInferiorEsquerdo);
    if(linha == 19 && coluna == 19) printf("%c",cantoInferiorDireito);
}

void imprimeVazio(int linha, int coluna){
    if(!EhMolduraExterna(coluna) && !EhMolduraExterna(linha) && !EhImpar(coluna) && !EhImpar(linha)) printf("   ");
}

void imprimeMolduraExterna(int linha, int coluna){
    int lateralEsquerdo = 204,
        lateralDireito = 185,
        superior = 203,
        inferior = 202,
        horizontal = 205,
        vertical = 186,
        cruz = 206;

    if(EhMolduraExterna(coluna) && EhMolduraExterna(linha) && EhCantoInicial(linha) && !EhCanto(coluna)) printf("%c",superior);
    if(EhMolduraExterna(linha) && !EhMolduraExterna(coluna) && !EhImpar(coluna)) printf("%c%c%c",horizontal,horizontal,horizontal);
    if(EhMolduraExterna(linha) && !EhMolduraExterna(coluna) && EhImpar(coluna)) printf("%c",horizontal);
    if(EhMolduraExterna(coluna) && !EhMolduraExterna(linha)) printf("%c",vertical);
    if(EhMolduraExterna(linha) && EhMolduraExterna(coluna) && EhCantoInicial(coluna) && !EhCanto(linha)) printf("%c",lateralEsquerdo);
    if(EhMolduraExterna(linha) && EhMolduraExterna(coluna) && !EhCantoInicial(coluna) && EhCanto(coluna) && !EhCanto(linha)) printf("%c",lateralDireito);
    if(EhMolduraExterna(linha) && EhMolduraExterna(coluna) && !EhCanto(coluna) && !EhCanto(linha)) printf("%c",cruz);
    if(EhMolduraExterna(linha) && EhMolduraExterna(coluna) && EhCanto(linha) && !EhCantoInicial(linha) && !EhCanto(coluna)) printf("%c",inferior);
}

void imprimeMolduraInterna(int linha, int coluna){
     int horizontalInterno = 196,
         verticalInterno = 179,
         cruzInterna = 197;

     if(!EhMolduraExterna(coluna) && !EhMolduraExterna(linha) && EhImpar(coluna) && !EhImpar(linha)) printf("%c",verticalInterno);
     if(!EhMolduraExterna(coluna) && !EhMolduraExterna(linha) && !EhImpar(coluna) && EhImpar(linha)) printf("%c%c%c",horizontalInterno,horizontalInterno,horizontalInterno);
     if(!EhMolduraExterna(coluna) && !EhMolduraExterna(linha) && EhImpar(coluna) && EhImpar(linha)) printf("%c",cruzInterna);

}

int EhMolduraExterna(int posicao){
    if(posicao == 1 || posicao == 7 || posicao == 13 || posicao == 19) return 1;
    return 0;
}

int EhCanto(int posicao){
    if(posicao == 1 || posicao == 19) return 1;
    return 0;
}

int EhCantoInicial(int posicao){
    if(posicao == 1) return 1;
    return 0;
}

int EhImpar(int posicao){
    if(posicao%2 == 1) return 1;
    return 0;
}

 void criaSudoku(int x, int y){
    gotoxy(x,y);
    for(int linha = 1; linha <= 19; linha++)
    {
        for(int coluna = 1; coluna <= 19; coluna++)
        {
            imprimeCantos(linha,coluna);

            imprimeVazio(linha,coluna);

            imprimeMolduraExterna(linha,coluna);

            imprimeMolduraInterna(linha,coluna);
        }
        gotoxy(x,++y);
    }
    criaMatriz();
    preencheMolduraComMatriz(xInicial, yInicial, matrixAux);
}
void jogar(){

    criaSudoku(xInicial, yInicial);

    int x = xInicial, y = yInicial;

    int limiteMinimoDoX = x+2;
    int limiteMaximoDoX = (4*8)+limiteMinimoDoX;
    int limiteMinimoDoY = y+1;
    int limiteMaximoDoY = (2*8)+limiteMinimoDoY;
    int xSelecionado = xInicial, ySelecionado = yInicial;

    int enter = 13,
        setaParaCima = 80,
        setaParaBaixo = 72,
        setaParaEsquerda = 75,
        setaParaDireita = 77;

    x+= 2;
    y+= 1;

        gotoxy(limiteMinimoDoX,limiteMinimoDoY);

    while(1){
		int teclaPressionada = getch();

		if(teclaPressionada >= 49 || teclaPressionada <= 57){


                if(matrixValidated(((y-yInicial)/2),((x-xInicial)/4),asciiConverter(teclaPressionada)) > 0){
                    //if(finishGame() == enter){
                     //   printf("%d", teclaPressionada);
                     //   teclaPressiona4da = 13;
                   // }else {
                        printf("%d", asciiConverter(teclaPressionada));
                   // }

            }

		}

		if (teclaPressionada == enter){
            gotoxy(0, 25);
			break;
        }
        else if (teclaPressionada == setaParaBaixo)
           {
              if(y > limiteMinimoDoY) y-= 2;
           }
		else if (teclaPressionada == setaParaCima)
            {
                if(y < limiteMaximoDoY) y+= 2;

            }
		else if (teclaPressionada == setaParaEsquerda)
            {
                if(x > limiteMinimoDoX) x-= 4;
            }

		else if (teclaPressionada==setaParaDireita)
            {
                if(x < limiteMaximoDoX) x+= 4;
            }

        gotoxy(x,y);
    }

}

void preencheMolduraComMatriz(int x,int y,int matriz[9][9]){
    for(int linha = 0; linha < matrixMax; linha++)
    {
        for(int coluna = 0; coluna < matrixMax; coluna++)
        {
            if(matriz[coluna][linha] != 0)
            {
                gotoxy((x+1)+(linha*4),(y+1)+(coluna*2));
                printf("%2d",matriz[coluna][linha]);
            }
        }
    }
}


int validaExistenteLinha(int pontoInicial, int numeroInserido){
    int achou = 0;
    for(int i = 0; i < matrixMax; i++){
        if(matrixAux[pontoInicial][i] ==  numeroInserido){
            achou++;
        }
    }
    if(achou == 0){
        return 0;
    }else{
        return 1;
    }
}

int validaExistenteColuna(int pontoInicial, int numeroInserido){
    int achou = 0;
    for(int i = 0; i < matrixMax; i++){
        if(matrixAux[i][pontoInicial] ==  numeroInserido){
            achou++;
        }
    }
    if(achou == 0){
        return 0;
    }else{
        return 1;
    }
}

void criaMatriz(){

    srand(time(NULL));

    for(int i = 0; i < matrixMax; i++){
            for(int j = 0; j < matrixMax; j++){
                if(rand() % 500 % 2){
                    matrixAux[i][j] = 0;
                }else{
                    matrixAux[i][j] = matrix[i][j];
                }
            }
    }
}

int matrixValidated(int x, int y, int digitado){

    int find = 0;

    if(matrix[x][y] == digitado && matrixAux[x][y] != digitado){
        matrixAux[x][y] = digitado;
        find++;
    }

    return find;
}

int finishGame(){

    int find = 0;
    int returned = 0;


    for(int i = 0; i < matrixMax; i++){
        for(int j = 0; j < matrixMax; j++){
            if(matrix[i][j] != matrixAux[i][j]){
                find++;
            }
        }
    }


    if(find == 0){
        returned = 13;
    }

return returned;
}
int asciiConverter(int number){

    int convertedNumber;

    if(number == 49){
        convertedNumber = 1;
    }else if(number == 50){
        convertedNumber = 2;
    }else if(number == 51){
        convertedNumber = 3;
    }else if(number == 52){
        convertedNumber = 4;
    }else if(number == 53){
        convertedNumber = 5;
    }else if(number == 54){
        convertedNumber = 6;
    }else if(number == 55){
        convertedNumber = 7;
    }else if(number == 56){
        convertedNumber = 8;
    }else if(number == 57){
        convertedNumber = 9;
    }

 return convertedNumber;
 }

 void titulo(){
    gotoxy(32, 5);
    printf(" ####  ##   ##  ####     #####   ##  ##  ##   ##");
    gotoxy(32, 6);
    printf("##     ##   ##  ##  ##  ##   ##  ## ##   ##   ##");
    gotoxy(32, 7);
    printf(" ###   ##   ##  ##   ## ##   ##  ###     ##   ##");
    gotoxy(32, 8);
    printf("   ### ##   ##  ##   ## ##   ##  ####    ##   ##");
    gotoxy(32, 9);
    printf("##  ## #######  ##  ##  ##   ##  ## ##   #######");
    gotoxy(32, 10);
    printf(" ####   #####   #####    ####    ##  ##   #####");


}
void Bordas(int x1, int y1){
int x= 18, y= 3,cont;


cont=y;
for(cont=cont;cont<y1;cont++){
gotoxy(x,cont);printf("%c",176);
gotoxy(x1,cont);printf("%c",176);
}
cont=x;
for(cont=cont;cont<x1;cont++)
{
gotoxy(cont,y);printf("%c",176);
gotoxy(cont,y1);printf("%c",176);
}
gotoxy(x,y);printf("%c",176);
gotoxy(x1,y);printf("%c",176);
gotoxy(x,y1);printf("%c",176);
gotoxy(x1,y1);printf("%c",176);

}
void inicia_cronometro() {

    _tempo = clock();


}


void para_cronometro() {

    printf("%.5f s\n",(float) (clock() - _tempo) / ((float) CLOCKS_PER_SEC));

}

int navegaMenu(int opc,int posicao){
    int setaParaCima = 72,
        setaParaBaixo = 80;

if(opc == setaParaCima){
            if(posicao == 1){
                printf(" ");
                gotoxy(48, 18);
                printf("o");
                posicao = 0;
                gotoxy(48, 18);
            }else if(posicao == 0){
                printf(" ");
                gotoxy(48, 16);
                printf("o");
                posicao = 3;
                gotoxy(48, 16);
            }else if(posicao == 3){
                printf(" ");
                gotoxy(48, 14);
                printf("o");
                posicao = 2;
                gotoxy(48, 14);
            }else{
                printf(" ");
                gotoxy(48, 12);
                printf("o");
                posicao = 1;
                gotoxy(48, 12);
            }
        }
        if(opc == setaParaBaixo){
            if(posicao == 1){
                printf(" ");
                gotoxy(48, 14);
                printf("o");
                posicao = 2;
                gotoxy(48, 14);
            }else if(posicao == 2){
                printf(" ");
                gotoxy(48, 16);
                printf("o");
                posicao = 3;
                gotoxy(48, 16);
            }else if(posicao == 3){
                printf(" ");
                gotoxy(48, 18);
                printf("o");
                posicao = 0;
                gotoxy(48, 18);
            }else{
                printf(" ");
                gotoxy(48, 12);
                printf("o");
                posicao = 1;
                gotoxy(48, 12);
            }

        }

return posicao;
}
