/*Definir una estructura que represente una persona, con los campos nombre, edad, dni y un
flag de estado.
Hacer un programa que defina un array de 20 ítems de esta estructura y con un menú como el
siguiente:
1. Agregar una persona
2. Borrar una persona
3. Imprimir lista ordenada por nombre
4. Imprimir gráfico de edades
Se utilizará el campo de estado para indicar si el ítem del array esta ocupado o no.
El gráfico deberá ser un gráfico de barras en donde se agruparán 3 barras:
• Menores de 18
• De 19 a 35
• Mayores de 35.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#define constante 20
int main()
{
    EPersona vec[constante];/*<-----------Array de estructuras*/
    char seguir='s';/*<-----------Indica cuando el programa termina*/
    char seg;/*<------------------Indica si estamos seguros de borrar los datos de la persona*/
    int opcion=0;/*<--------------Sirve para seleccionar las opciones del menu*/
    int edad=0;
    int dni=0;/*<-----------------Utilizado para guardar todo dato util sobre dni*/
    int aux=0;/*<-----------------Entero auxiliar para alguno de los case*/
    int i=0;/*<-------------------Contador*/
    int j=0;/*<-------------------Contador*/
    int posicion;/*<--------------Indica la posicion de una estructura en el array de estructuras*/
    char auxChar[constante];/*<----------Auxiliar tipo char*/
    char validarEntrada[constante];
    int arrayEdades[3];/*<---Cadena de caracteres para la validacion de la entrada de datos*/

    for(i=0;i<constante;i++)/*<-----------Estructura de repeticion para inicializar algunas de las variables de
                                  las estructuras del array de estructuras en cero*/
    {
        vec[i].estado=0;
        vec[i].dni=0;
        arrayEdades[i]=0;
    }
    while(seguir=='s')
    {
        for (i=0; i<constante;i++)/*<----Inicializamos el vector de caracteres para validar vacio*/
        {
            validarEntrada[i]='\0';
        }
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\n\nIngrese la opcion deseada: ");
        scanf("%s",validarEntrada);

        opcion=validar(validarEntrada);/*<-----------Validamos la entrada de datos. Si contiene caracteres,
                                                     ira directamente al default case*/
        if(opcion==-1)
        {
            opcion=0;
        }
        switch(opcion)
        {
            case 1:
                i=0;
                system("cls");
                posicion=obtenerEspacioLibre(vec);/*<-----Se comprueba si hay espacios libre para la carga de datos*/
                if(posicion<=-1)
                {
                    printf("No hay espacios libres para la carga de datos\n\n");
                    system("pause");
                    break;
                }
                printf("Ingrese DNI: ");
                fflush(stdin);
                scanf("%s", validarEntrada);/*<-------A partir de aca se comprueba que el formato de dni tenga
                                                      8 digitos y no tenga caracteres*/
                dni=validarDni(validarEntrada);
                while(dni==-1)
                {
                    system("cls");
                    printf("Ingrese el formato de DNI valido: ");
                    scanf("%s", validarEntrada);
                    dni=validarDni(validarEntrada);
                }
                dni=buscarRepeticion(vec, dni);/*<----Aca se comprueba que no sea un DNI repetido*/
                if(dni==-1)
                {
                    system("cls");
                    printf("Persona ya ingresada al sistema\n\n");
                    system("pause");
                    break;
                }
                vec[posicion].dni=dni;
                printf("\nIngrese nombre: ");
                fflush(stdin);
                gets(vec[posicion].nombre);
                printf("\nIngrese edad: ");
                fflush(stdin);
                scanf("%s", validarEntrada);
                edad=validarEdad(validarEntrada);/*<-------Desde aca se comprueba que el formato de la edad este
                                                      entre [1-130] y no tenga caracteres*/
                while(edad==-1)
                {
                    system("cls");
                    printf("Ingrese el formato de edad valido [1-130]: ");
                    scanf("%s", validarEntrada);
                    edad=validarEdad(validarEntrada);
                }
                vec[posicion].edad=edad;
                vec[posicion].estado=1;
                break;
            case 2:
                i=0;
                system("cls");
                printf("Ingrese DNI de la persona a dar de baja: ");
                scanf("%s", validarEntrada);
                dni=validar(validarEntrada);
                while(dni==-1)
                {
                    system("cls");
                    printf("Ingrese el formato de DNI valido: ");
                    scanf("%s", validarEntrada);
                    dni=validarDni(validarEntrada);
                }
                posicion=buscarPorDni(vec,dni);
                if(posicion<=-1 || vec[posicion].estado==0)
                {
                    system("cls");
                    printf("DNI inexistente\n\n");
                    system("pause");
                    break;
                }
                aux=0;
                do
                {
                    system("cls");
                    printf("Nombre: %s\nDNI: %d\nEdad: %d\n\nContinuar? (s/n): ", vec[posicion].nombre, vec[posicion].dni, vec[posicion].edad);
                    fflush(stdin);
                    seg=tolower(getche());
                    if(seg=='n')
                    {
                        system("cls");
                        printf("Operacion cancelada\n\n");
                        system("pause");
                        aux=1;
                        break;
                    }
                    if(seg=='s')
                    {
                        vec[posicion].estado=0;
                        system("cls");
                        printf("Datos borrados con exito!\n\n");
                        system("pause");
                        aux=1;
                    }
                }while(aux!=1);
                break;
            case 3:
                for(i=0; i<constante-1; i++)
                {
                    if(vec[i].estado==1)
                    {
                        for(j=i+1; j<constante; j++)
                        {
                            if(vec[j].estado==1)
                            {
                                if(stricmp(vec[i].nombre, vec[j].nombre)>0)
                                {
                                    strcpy(auxChar,vec[i].nombre);
                                    aux=vec[i].dni;
                                    vec[i].dni=vec[j].dni;
                                    vec[j].dni=aux;
                                    aux=vec[i].edad;
                                    vec[i].edad=vec[j].edad;
                                    vec[j].edad=aux;
                                    strcpy(vec[i].nombre,vec[j].nombre);
                                    strcpy(vec[j].nombre,auxChar);
                                }
                            }
                        }
                    }
                }
                system("cls");
                printf("Lista ordenada por nombre\n\n");
                for(i=0; i<constante; i++)
                {
                    if(vec[i].estado==1)
                    {
                    printf("Nombre: %s\nDNI: %d\nEdad: %d\n\n", vec[i].nombre, vec[i].dni, vec[i].edad);
                    }
                }
                system("pause");
                break;
            case 4:
                system("cls");
                aux=0;
                edad=0;
                arrayEdades[0]=conteoEdades(vec, 1);
                arrayEdades[1]=conteoEdades(vec, 2);
                arrayEdades[2]=conteoEdades(vec, 3);
                if(arrayEdades[0] >= arrayEdades[1] && arrayEdades[0] >= arrayEdades[2])
                {
                    edad=arrayEdades[0];
                }
                else
                {
                    if(arrayEdades[1] >= arrayEdades[0] && arrayEdades[1] >= arrayEdades[2])
                    {
                        edad=arrayEdades[1];
                    }
                    else
                    {
                        edad=arrayEdades[2];
                    }
                }

                for(i=edad; i>0; i--)
                {
                    printf("%02d|",i);
                    if(i<= arrayEdades[0])
                    {
                        printf("*");
                    }
                    if(i<= arrayEdades[1])
                    {
                        aux=1;
                        printf("\t*");
                    }
                    if(i<= arrayEdades[2])
                    {
                        if(aux==0)
                        {
                            printf("\t\t*");
                        }
                        if(aux==1)
                        {
                            printf("\t*");
                        }
                    }
                printf("\n");
            }
            printf("--+-----------------");
            printf("\n  |<18\t19-35\t>35");
            printf("\n   %d\t%d\t%d\n\n\n", arrayEdades[0], arrayEdades[1], arrayEdades[2]);
            system("pause");
                break;
            case 5:
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
