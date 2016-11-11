#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[30];
    int duracion;
    char descripcion[220];
    int puntaje;
    char linkImagen[220];
}EMovie;
/**
 * Inicializa en 0 todos los campos de la estructura
 */
void limpiarEMovie(EMovie *movie);
/**
 * Muestra en pantalla las estructuras guardadas en el archivo binario
 */
void mostrarPeliculas(void);
/**
 * Busca en el archivo binario el nombre de la pelicula ingresada
 *  @param peliculas la estructura a guardar el nombre de la pelicula a buscar
 *  @return retorna 1 o 0 de acuerdo a si pudo encontrar la pelicula o no.
 */
int buscarpelicula(EMovie *peliculas);
/**
 *  Agrega una pelicula al archivo binario
 *  @param peliculas la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie *peliculas);
/**
 *  Borra una pelicula del archivo binario
 *  @param peliculas la estructura a ser eliminada del archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *peliculas);
/**
 *  Borra una pelicula del archivo binario
 */
void modificarPelicula(EMovie *modificarPelicula);
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 */
void generarPagina(void);
#endif // FUNCIONES_H_INCLUDED
