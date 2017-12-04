#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct
{
    char apyn[30];
    int dni;
    char sexo;
    float sueldo;
}t_info;

typedef struct s_nodo
{
    t_info datos;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_pila;


void crearPila(t_pila* p);
int pilaLlena(const t_pila* p);
int pilaVacia(const t_pila* p);
int ponerEnPila(t_pila* p, const t_info* d);
int sacarDePila(t_pila* p, t_info* d);
int verTope(const t_pila* p, t_info* d);

int cargarPila(t_pila* p);
void imprimirStruct(t_info* d);

#endif // PILA_DINAMICA_H_INCLUDED
