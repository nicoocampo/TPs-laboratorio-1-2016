/*
-Todas las funciones matematicas del menu se deberan realizar en una biblioteca aparte,
que contenga las funciones para realizar las 4 operaciones.
-En el menu deberan aparecer los valores actuales cargados en los operandos A y B
(donde dice "x" e "y" en el ejemplo, se debe mostrar el numero cargado.
-Deberan contemplarse los casos de error (division por cero, etc).
-Documentar todas las funciones.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
int main()
{
    float a=0;
    float b=0;
    double c=0;
    float vali=0;
    char seguir='s';
    int opcion=0;
    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%f)\n", a);
        printf("2- Ingresar 2do operando (B=%f)\n", b);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n \n");
        printf("\nIngrese la opcion a elegir: ");
        opcion=validar();
        system("cls");
        switch(opcion)
        {
            case 1:
                printf("Ingrese el valor de A: ");
                a=validar();
                break;
            case 2:
                printf("Ingrese el valor de B: ");
                b=validar();
                break;
            case 3:
                c=suma(a,b);
                printf("La suma entre %f y %f es: %f \n \n", a, b, c);
                system("pause");
                break;
            case 4:
                c=resta(a,b);
                printf("La diferencia entre %f y %f es: %f \n \n", a, b, c);
                system("pause");
                break;
            case 5:
                vali=validivi(b);
                if(vali==1)
                {
                    c=division(a,b);
                    printf("El cociente entre %f y %f es: %f \n \n", a, b, c);
                    system("pause");
                    break;
                }
                    printf("ERROR: El divisor tiene que ser distinto de 0\n\n");
                    system("pause");
                    break;
            case 6:
                c=multiplicacion(a,b);
                printf("El producto entre %f y %f es: %f\n\n", a, b, c);
                system("pause");
                break;
            case 7:
                vali=valifacto(a);
                if(vali==1)
                {
                    c=factorial(a);
                    printf("El factorial de %f es: %f\n\n", a, c);
                    system("pause");
                    break;
                }
                printf("ERROR: Se requiere de un numero entero positivo\n\n");
                system("pause");
                break;
            case 8:
                c=suma(a,b);
                printf("La suma entre %f y %f es: %f \n \n", a, b, c);
                system("pause");
                system("cls");
                c=resta(a,b);
                printf("La diferencia entre %f y %f es: %f \n \n", a, b, c);
                system("pause");
                system("cls");
                vali=validivi(b);
                if(vali==1)
                {
                    c=division(a,b);
                    printf("El cociente entre %f y %f es: %f \n \n", a, b, c);
                    system("pause");
                    system("cls");
                }
                if(vali==0)
                {
                    printf("ERROR: El divisor tiene que ser distinto de 0\n\n");
                    system("pause");
                    system("cls");
                }
                c=multiplicacion(a,b);
                printf("El producto entre %f y %f es: %f\n\n", a, b, c);
                system("pause");
                system("cls");
                vali=valifacto(a);
                if(vali==1)
                {
                    c=factorial(a);
                    printf("El factorial de %f es: %f\n\n", a, c);
                    system("pause");
                }
                if(vali==0)
                {
                printf("ERROR: Se requiere de un numero entero positivo para calcular factorial\n\n");
                system("pause");
                }
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("\n La opcion elegida es incorrecta\n \n");
                system ("pause");
                break;
        }
    }
    return 0;
}
