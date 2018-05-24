#include<stdio.h>
#include<math.h>
#include<locale.h>
#define PI 3.14159265

float quadrado(float lado, float *perimetro){
    float area;
    area=lado*lado;
    *perimetro = 4 * lado;
    return area;
}
float retangulo(float base, float altura,float *perimetro){

    float area;
    area = base * altura;
    *perimetro = 2*(base + altura);

    return area;
}
float circulo(float raio, float *perimetro){

    float area;
    area= PI*(raio*raio);
    *perimetro = (2*PI)*raio;


    return area;

}
float triangulo(float base, float altura, float *perimetro, float lado1, float lado2){
    float area;
    area = (base*altura)/2;
    *perimetro = lado1 + lado2 + base;

    return area;

}
float trapezio(float baseMaior, float baseMenor,float lado, float lado2,float altura,float *perimetro){
    float area;
    area = ((baseMaior + baseMenor) * altura)/2;
    *perimetro = baseMaior + baseMenor + lado + lado2;

    return area;
}
int main(){

    int opcao;
    float lado,perimetro, area,base, altura,raio,lado2,baseMenor;

    while(opcao!=0){
        printf("[1] Quadrado\n");
        printf("[2] Retangulo\n");
        printf("[3] Circulo\n");
        printf("[4] Triangulo\n");
        printf("[5] Trapezio\n");
        printf("[0] Sair \n");
        scanf("%d",&opcao);

            switch(opcao){

                case 1:
                        system("cls");

                        printf("quadrado\n");
                        printf("digite lado:\n");
                        scanf("%f",&lado);
                        area = quadrado(lado,&perimetro);
                        printf("Area:%.2f\nPerimetro: %.2f\n\n", area, perimetro);

                        system("pause");
                        system("cls");
                        break;

                case 2:
                        system("cls");
                        printf("retangulo\n");
                        printf("digite base: ");
                        scanf("%f",&base);
                        printf("digite altura: ");
                        scanf("%f",&altura);
                        area= retangulo(base,altura,&perimetro);
                        printf("Area:%.2f\nPerimetro: %.2f\n\n", area, perimetro);

                        system("pause");
                        system("cls");
                        break;

                case 3:
                        system("cls");
                        printf("circulo\n");
                        printf("Digite o Raio: ");
                        scanf("%f",&raio);
                        area=circulo(raio,&perimetro);
                        printf("Area:%.2f\nPerimetro: %.2f\n\n", area, perimetro);

                        system("pause");
                        system("cls");
                        break;
                case 4:
                        system("cls");
                        printf("Triangulo\n");
                        printf("Digite Lado 1: ");
                        scanf("%f",&lado);
                        printf("Digite Lado 2: ");
                        scanf("%f",&lado2);
                        printf("Digite Base: ");
                        scanf("%f",&base);
                        printf("Digite Altura: ");
                        scanf("%f",&altura);
                        area= triangulo(base,altura, &perimetro,lado,lado2);
                        printf("Area:%.2f\nPerimetro: %.2f\n\n", area, perimetro);

                        system("pause");
                        system("cls");
                        break;
                case 5:
                        system("cls");
                        printf("Trapezio\n");
                        printf("Digite Base Maior: ");
                        scanf("%f",&base);
                        printf("Digite Base Menor: ");
                        scanf("%f",&baseMenor);
                        printf("Digite Lado 1: ");
                        scanf("%f",&lado);
                        printf("Digite Lado 2: ");
                        scanf("%f",&lado2);
                        printf("Digite Altura: ");
                        scanf("%f",&altura);
                        area = trapezio(base,baseMenor,lado,lado2,altura,&perimetro);
                        printf("Area:%.2f\nPerimetro: %.2f\n\n", area, perimetro);

                        system("pause");
                        system("cls");
                        break;
                case 0:
                        system("cls");
                        printf("Ate Mais!\n\n");

                        system("pause");
                        system("cls");
                        break;



        }
    }


}
