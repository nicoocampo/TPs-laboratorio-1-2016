#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
/** \brief Suma los dos numeros ingresados previamente
 *
 * \param x Primera variable flotante a sumar.
 * \param y Segunda variable flotante a sumar.
 * \param total la sumatoria entre las variables x e y.
 * \return El total de la suma entre x e y en flotante.
 *
 */
float suma(float x, float y)
{
    float total=x+y;
    return total;
}
/** \brief Resta los dos numeros ingresados previamente
 *
 * \param x Primera variable flotante a restar.
 * \param y Segunda variable flotante a restar.
 * \param total La diferencia entre las variables x e y.
 * \return El total de la diferencia entre x e y en flotante.
 *
 */
float resta(float x, float y)
{
    float total=x-y;
    return total;
}
/** \brief Divide los dos numeros ingresados previamente
 *
 * \param x Primera variable flotante utilizada como dividendo.
 * \param y Segunda variable flotante utilizada como divisor.
 * \param total El cociente entre las variables x e y.
 * \return El total del cociente entre x e y en flotante.
 *
 */
float division(float x, float y)
{
    float total=x/y;
    return total;
}
/** \brief Multiplica los dos numeros ingresados previamente
 *
 * \param x Primera variable flotante a multiplicar.
 * \param y Segunda variable flotante a multiplicar.
 * \param total El producto entre las variables x e y.
 * \return El total del producto entre x e y en flotante.
 *
 */
float multiplicacion(float x, float y)
{
    if(x==0 || y==0)
    {
        return 0;
    }
    float total=x*y;
    return total;
}
/** \brief Calcula el factorial del numero previamente ingresado
 *
 * \param x Variable a factorear.
 * \param total El valor total del factorial.
 * \return El factorial de la variable ingresada en flotante.
 * \note Se emplea una funcion recursiva para el calculo del factorial.
 */
float factorial(float x)
{
    float total;
        if(x==0 || x==1)
        {
            return 1;
        }
    total=x*factorial(x-1);
    return total;
    }
    /** \brief Detecta el ingreso de caracteres.
     *
     * \param c Cadena de caracteres donde se ingresa los valores a ser validados.
     * \param i Variable entera empleado tanto como contador, como tambien para recorrer la cadena de caracteres.
     * \param num Variable entera empleada para almacenar los valores arrojados por la funcion isalpha()
     * \param total Variable flotante que almacena los valores ingresados en la cadena de caracteres.
     * \return El numero validado. Si se detectan caracteres devuelve 0.
     */
   float validar()
{
    int i=0;
    char c[20];
    int num;
    scanf("%s", c);
    while(i<=19)
    {
        num=isalpha(c[i]);
        if(num!=0)
        {
            system("cls");
            printf("ERROR: No se pueden ingresar caracteres\n\n");
            system("pause");
            return 0;
        }
        i++;
    }
    float total=atof(c);
    return total;
    system("cls");
}
/** \brief Detecta si se ingreso el divisor con valor 0.
 *
 * \param x Variable flotante a analizar.
 * \return 0 si el divisor es igual a 0. 1 si el divisor es distinto de 0.
 *
 */
float validivi(float x)
{
    if(x==0)
    {
        return 0;
    }
    return 1;
}
/** \brief Detecta si el numero a factorear es negativo o flotante.
 *
 * \param x Variable flotante a analizar.
 * \param y Variable que contiene los valores arrojados por la funcion ceil().
 * \return 0 si la variable ingresada es negativa o contiene decimales. 1 si
 * \return la variable se le puede calcular el factorial.
 *
 */
float valifacto(float x)
{
    float y=ceil(x);
    if(x>0)
    {
        if(x==y)
        {
            return 1;
        }
    }
    return 0;
}
