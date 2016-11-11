#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "funciones.h"
/**
 * Inicializa en 0 todos los campos de la estructura
 */
void limpiarEMovie(EMovie *movie)
{
    strcpy(movie->titulo,"\0");
    strcpy(movie->descripcion,"\0");
    strcpy(movie->linkImagen,"\0");
    strcpy(movie->genero,"\0");
    movie->puntaje=0;
    movie->duracion=0;
}
/**
 *  Agrega una pelicula al archivo binario
 *  @param peliculas la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *peliculas)
{
    char aux[200];
    system("cls");
    printf("Ingrese el nombre de la pelicula: ");
    fflush(stdin);
    gets(aux);
    strcpy(peliculas->titulo, aux);
    strcpy(aux,"\0");
    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    gets(aux);
    strcpy(peliculas->genero, aux);
    strcpy(aux,"\0");
    printf("Ingrese la duracion de la pelicula: ");
    scanf("%i", &peliculas->duracion);
    printf("Ingrese la descripcion de la pelicula: ");
    fflush(stdin);
    gets(aux);
    strcpy(peliculas->descripcion, aux);
    strcpy(aux,"\0");
    printf("Ingrese la puntuacion de la pelicula: ");
    scanf("%i", &peliculas->puntaje);
    printf("Ingrese url de la imagen: ");
    fflush(stdin);
    gets(aux);
    strcpy(peliculas->linkImagen, aux);
    strcpy(aux,"\0");
    FILE *pArch;
    pArch=fopen("peliculas.dat","ab+");
    if(pArch==NULL)
    {
        system("cls");
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
        system("pause");
        exit(0);
    }
    fwrite(peliculas, sizeof(EMovie),1,pArch);
    fclose(pArch);
    system("cls");
    return 1;
}
/**
 *  Borra una pelicula del archivo binario
 *  @param peliculas la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *borrarPelicula)
{
    FILE *pBorrar;
    FILE *pBorrarAux;
    EMovie peliculasAux;
    pBorrarAux=fopen("peliculasAux.dat","wb");
    pBorrar=fopen("peliculas.dat","rb");
    if(pBorrar==NULL || pBorrarAux==NULL)
    {
        system("cls");
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
        system("pause");
        exit(0);
    }
    while(fread(&peliculasAux, sizeof(EMovie),1, pBorrar) != 0)
    {
        if (strcmp(borrarPelicula->titulo, peliculasAux.titulo)!=0)
        {
            fwrite(&peliculasAux, sizeof(EMovie),1, pBorrarAux);
        }
    }
        fclose(pBorrar);
        fclose(pBorrarAux);
        pBorrarAux=fopen("peliculasAux.dat","rb");
        pBorrar=fopen("peliculas.dat","wb");
    while(fread(&peliculasAux, sizeof(EMovie),1, pBorrarAux))
    {
        fwrite(&peliculasAux, sizeof(EMovie),1, pBorrar);
    }
    fclose(pBorrar);
    fclose(pBorrarAux);
    return 1;
}
/**
 * Busca en el archivo binario el nombre de la pelicula ingresada
 *  @param peliculas la estructura a guardar el nombre de la pelicula a buscar
 *  @return retorna 1 o 0 de acuerdo a si pudo encontrar la pelicula o no.
 */
int buscarpelicula(EMovie *buscarPeliculas)
{
    char aux[50];
    FILE *pBuscar;
    pBuscar=fopen("peliculas.dat","rb");
    if(pBuscar==NULL)
    {
        system("cls");
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
        system("pause");
        exit(0);
    }
    while(fread(buscarPeliculas, sizeof(EMovie), 1, pBuscar)!=0);
    {
        if(strcmp(buscarPeliculas->titulo,aux)==0)
        {
            fclose(pBuscar);
            return 1;
        }
    }
        return NULL;
}
/**
 * Muestra en pantalla las estructuras guardadas en el archivo binario
 */
void mostrarPeliculas()
{
    FILE *mostrar;
    EMovie *movie = malloc(sizeof(EMovie));
    system("cls");
    mostrar=fopen("peliculas.dat","rb+");
    if(mostrar==NULL)
    {
        exit(0);
    }
        while(fread(movie,sizeof(EMovie),1,mostrar)!=0)
    {
        printf("TITULO: %s\nDESCRIPCION: %s\nGENERO: %s\nIMAGEN: %s\nDURACION: %d\nPUNTUACION: %d\n\n", movie->titulo, movie->descripcion, movie->genero, movie->linkImagen, movie->duracion, movie->puntaje);
    }
}
/**
 *  Borra una pelicula del archivo binario
 */
void modificarPelicula(EMovie *modificarPelicula)
{
    char aux[200];
    FILE *pModificar;
    FILE *pModificarAux;//se declara los punteros para cada archivo binario
    EMovie peliculasAux;
    pModificarAux=fopen("peliculasAux.dat","wb");
    pModificar=fopen("peliculas.dat","rb");
    if(pModificar==NULL || pModificarAux==NULL)
    {
        system("cls");
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
        system("pause");
        exit(0);
    }
    while(fread(&peliculasAux, sizeof(EMovie),1, pModificar) != 0)/*CON ESTE WHILE COPIAMOS LAS PELICULAS QUE NO TENGAN EL TITULO QUE BUSCAMOS AL BINARIO AUXILIAR*/
    {
        if (strcmp(modificarPelicula->titulo, peliculasAux.titulo)==0)
        {
            system("cls");
            printf("Ingrese el nuevo nombre de la pelicula: ");
            fflush(stdin);
            gets(aux);
            strcpy(peliculasAux.titulo, aux);
            strcpy(aux,"\0");
            printf("Ingrese el genero de la pelicula: ");
            fflush(stdin);
            gets(aux);
            strcpy(peliculasAux.genero, aux);
            strcpy(aux,"\0");
            printf("Ingrese la duracion de la pelicula: ");
            scanf("%i", &peliculasAux.duracion);
            printf("Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(aux);
            strcpy(peliculasAux.descripcion, aux);
            strcpy(aux,"\0");
            printf("Ingrese la puntuacion de la pelicula: ");
            scanf("%i", &peliculasAux.puntaje);
            printf("Ingrese url de la imagen: ");
            fflush(stdin);
            gets(aux);
            strcpy(peliculasAux.linkImagen, aux);
            strcpy(aux,"\0");
        }
        fwrite(&peliculasAux, sizeof(EMovie),1, pModificarAux);
    }
        fclose(pModificar);
        fclose(pModificarAux);
        pModificarAux=fopen("peliculasAux.dat","rb");
        pModificar=fopen("peliculas.dat","wb");
    while(fread(&peliculasAux, sizeof(EMovie),1, pModificarAux))
    {
        fwrite(&peliculasAux, sizeof(EMovie),1, pModificar);
    }
    fclose(pModificar);
    fclose(pModificarAux);
}
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 */
void generarPagina(void)
{
    EMovie html;
    FILE *pHtml;
    FILE *pPeli;
    pHtml = fopen("index.html", "w+");
    pPeli = fopen("peliculas.dat", "rb");
    if(pHtml == NULL || pPeli==NULL)
    {
        system("cls");
        printf("PROBLEMAS AL LEER EL ARCHIVO BINARIO\n\nPOR FAVOR, REVISAR SI SE ENCUENTRA EN LA CARPETA DEL EJECUTABLE Y VUELVA A INTENTAR\n\n");
        system("pause");
        exit(0);
    }
    while((fread(&html,sizeof(EMovie),1,pPeli))!=0)
    {
        fprintf(pHtml, "<article class='col-md-4 article-intro'>\n<a href=\'#\'>\n<img class=\'img-responsive img-rounded\' src=\'%s\n\'alt=\'\'>\n", html.linkImagen);
        fprintf(pHtml, "</a><h3><a href=\'#\'>%s</a>\n</h3>\n<ul>\n<li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d</li>\n</ul>\n<p>%s</p>\n</article>", html.titulo, html.genero, html.puntaje, html.duracion, html.descripcion);
    }
    fclose(pHtml);
    fclose(pPeli);
    system("cls");
    printf("HTML REALIZADO CON EXITO\n\n");
    system("pause");
}
