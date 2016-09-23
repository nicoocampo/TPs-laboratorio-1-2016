#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;
int obtenerEspacioLibre(EPersona lista[]);
int buscarPorDni(EPersona lista[], int dni);
int validar();
int validarDni();
int buscarRepeticion(EPersona dni[], int dato);
int validarEdad(char edad[30]);
int conteoEdades(EPersona lista[], int opcion);
#endif // FUNCIONES_H_INCLUDED

