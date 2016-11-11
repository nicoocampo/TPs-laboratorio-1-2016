#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int main()
{
    EMovie peliculas;
    char seguir='s';
    int opcion=0;
    int aux=0;
    char charaux[50];
    while(seguir=='s')
    {
        limpiarEMovie(&peliculas);
        system("cls");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Mostrar peliculas\n");
        printf("5- Generar pagina web\n");
        printf("6- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                aux=agregarPelicula(&peliculas);
                if(aux==0)
                {
                    system("cls");
                    printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
                    system("pause");
                    exit(0);
                }
                printf("CARGA EXITOSA!\n\n");
                system("pause");
                break;
            case 2:
                mostrarPeliculas();
                printf("INGRESE EL NOMBRE DE LA PELICULA A BORRAR: ");
                fflush(stdin);
                gets(charaux);
                strcpy(peliculas.titulo,charaux);
                strcpy(charaux,"\0");
                if((buscarpelicula(&peliculas))==NULL)
                    {
                        system("cls");
                        printf("NO SE PUDO ENCONTRAR LA PELICULA\n\n");
                        system("pause");
                        break;
                    }
                aux=borrarPelicula(&peliculas);
                if(aux==0)
                {
                    system("cls");
                    printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
                    system("pause");
                    exit(0);
                }
                system("cls");
                printf("BORRADO EXITOSO!\n\n");
                system("pause");
                break;
            case 3:
                system("cls");
                mostrarPeliculas();
                printf("INGRESE EL NOMBRE DE LA PELICULA A BUSCAR: ");
                fflush(stdin);
                gets(charaux);
                strcpy(peliculas.titulo,charaux);
                strcpy(charaux,"\0");
                if((buscarpelicula(&peliculas))==NULL)
                    {
                        system("cls");
                        printf("NO SE PUDO ENCONTRAR LA PELICULA\n\n");
                        system("pause");
                        break;
                    }
                modificarPelicula(&peliculas);
                system("cls");
                printf("MODIFICADO EXITOSAMENTE!\n\n");
                system("pause");
                break;
               break;
            case 4:
                mostrarPeliculas();
                system("pause");
                system("cls");
                break;
            case 5:
                generarPagina();
                break;
            case 6:
                seguir='n';
                break;
            default:
                system("cls");
                printf("OPCION NO VALIDA\n\n");
                system("pause");
                break;
        }
    }
    return 0;
}
