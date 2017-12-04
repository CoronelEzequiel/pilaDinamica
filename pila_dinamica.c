#include "pila_dinamica.h"

void crearPila(t_pila* p)
{
    *p = NULL;
}

void vaciarPila(t_pila* p)
{
    t_nodo* aux = *p;
    while(aux)
    {
        *p = aux->sig;
        free(aux);
        aux = *p;
    }
}

int pilaLlena(const t_pila* p)
{
    t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}

int pilaVacia(const t_pila* p)
{
    return *p == NULL;
}

int ponerEnPila(t_pila* p, const t_info* d)
{
    t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->datos = *d;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int sacarDePila(t_pila* p, t_info* d)
{
    t_nodo* aux = *p;
    if(!*p)
        return 0;
    *d = aux->datos;
    *p = aux->sig;
    free(aux);
    return 1;
}

int verTope(const t_pila* p, t_info* d)
{
    if(!*p)
        return 0;
    *d = (*p)->datos;
    return 1;
}

int cargarPila(t_pila* p)
{
    t_info auxDeCarga;
    char op;

    printf("\nCarga de datos en la pila. Desea cargar un nuevo dato ?  S / N:  ");
    fflush(stdin);
    scanf("%c", &op);

    while(op == 'S' && !pilaLlena(p))
    {
        printf("\nNombre y apellido: ");
        fflush(stdin);
        scanf("%[^\n]", auxDeCarga.apyn);

        printf("\nDNI: ");
        scanf("%d", &auxDeCarga.dni);

        printf("\nSexo(M / F): ");
        fflush(stdin);
        scanf("%c", &auxDeCarga.sexo);

        printf("\nSueldo: ");
        scanf("%f", &auxDeCarga.sueldo);

        if(!ponerEnPila(p, &auxDeCarga))
        {
            printf("\nNo se pudo cargar el dato. La pila esta llena.");
            return 0;
        }
        printf("\nDesea cargar un nuevo dato ?  S / N:  ");
        fflush(stdin);
        scanf("%c", &op);
    }
    printf("\nFIN DE CARGA DE DATOS EN LA PILA.");
    return 1;
}

void imprimirStruct(t_info* d)
{
    printf("\n%-30s\t%d\t%c\t%.2f",
           d->apyn,
           d->dni,
           d->sexo,
           d->sueldo);
}

