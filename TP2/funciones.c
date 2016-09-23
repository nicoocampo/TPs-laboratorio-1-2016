#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "funciones.h"
#define constante 20
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[])
{
    int retorno=-1;
    int i;
    for(i=0;i<constante;i++)
    {
        if(lista[i].estado==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni)
{
    int retorno=-1;
    int i;
    for(i=0;i<constante;i++)
    {
        if(lista[i].dni==dni)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
    /** \brief Detecta el ingreso de caracteres.
     *
     * \param validarEntrada Cadena de caracteres donde se ingresa los valores a validar.
     * \return El numero validado en entero. Si se detectan caracteres devuelve -1.
     */
   int validar(char validarEntrada[30])
{
    int i=0;
    int num;
    for (i=0;i<constante;i++)
    {
        num=isalpha(validarEntrada[i]);
        if(num!=0)
        {
            return -1;
        }
    }
    int total=atof(validarEntrada);
    return total;
}
    /** \brief Detecta si el numero ingresado tiene 8 digitos y libre de caracteres.
     *
     * \param validarEntrada Cadena de caracteres donde se ingresa los valores a validar.
     * \return El numero validado en entero. Si se detectan caracteres devuelve -1.
     * \note Se utiliza la funcion "validar" para detectar caracteres en la cadena y pasarlo a entero.
     */
int validarDni(char validarEntrada[30])
{
    int num=0;
    num=strlen(validarEntrada);
    if(num!=8)
    {
        return -1;
    }
    num=validar(validarEntrada);
    if(num==-1)
    {
        return -1;
    }
    return num;
}
    /** \brief Recorre el array de estructuras buscando si se repite el DNI
     *
     * \param lista el array se pasa como parametro.
     * \param dato DNI a buscar repeticion.
     * \return Se regresa el DNI sin modificar si no hay repeticion. -1 si el DNI se repite.
     */
int buscarRepeticion(EPersona lista[], int dato)
{
    int i=0;
    for(i=0;i<constante;i++)
    {
        if(lista[i].dni==dato && lista[i].estado==1)
        {
            return -1;
        }
    }
    return dato;
}
    /** \brief Detecta si el numero ingresado esta entre [1-130] y libre de caracteres.
     *
     * \param edad Cadena de caracteres donde se ingresa los valores a validar.
     * \return El numero validado en entero. Si se detectan caracteres y no entra en el rango establecido devuelve -1.
     * \note Se utiliza la funcion "validar" para detectar caracteres en la cadena y pasarlo a entero.
     */
int validarEdad(char edad[30])
{
    int num=validar(edad);
    if(num==-1)
    {
        return -1;
    }
    if(num<0 || num>130)
    {
        return -1;
    }
    return num;
}
    /** \brief Cuenta los rango de edades
     *
     * \param lista el array se pasa como parametro.
     * \param opciones parametro que se utiliza para seleccionar que rango de edades contar.
     * \return La cantidad de edades para el rango seleccionado.
     */
int conteoEdades(EPersona lista[], int opciones)
{
    int edad=0;
    int i=0;
    switch(opciones)
    {
    case 1:
        for(i=0;i<constante;i++)
        {
            if(lista[i].estado==1)
            {
                if(lista[i].edad<=18)
                {
                    edad++;
                }
            }
        }
        break;
    case 2:
        for(i=0;i<constante;i++)
        {
            if(lista[i].estado==1)
            {
                if(lista[i].edad>18 && lista[i].edad<=35)
                {
                    edad++;
                }
            }
        }
        break;
    case 3:
        for(i=0;i<constante;i++)
        {
            if(lista[i].estado==1)
            {
                if(lista[i].edad>35)
                {
                    edad++;
                }
            }
        }
        break;
    }
    return edad;
}
