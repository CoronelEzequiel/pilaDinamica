#include "pila_dinamica.h"

int main()
{
    t_pila pila2;
    t_info auxDeLectura;

    crearPila(&pila2);
    cargarPila(&pila2);

    if(!pilaVacia(&pila2))
        printf("\nMostramos la pila, DESAPILAMOS.");
    while(!pilaVacia(&pila2))
    {
        sacarDePila(&pila2, &auxDeLectura);
        imprimirStruct(&auxDeLectura);
    }
    puts("\n");
    system("pause");

    return 0;
}
