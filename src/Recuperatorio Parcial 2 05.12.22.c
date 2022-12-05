/*
 ============================================================================
 Name        : 22.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char marca[20];
	int tipo;
	float peso;

}eVehiculo;

eVehiculo* newVehiculo();
eVehiculo* newVehiculoParam(int id, char marca[], int tipo, float peso);

int vehiculoSetId(eVehiculo* p, int id);
int vehiculoSetMarca(eVehiculo* p, char marca[]);
int vehiculoSetTipo(eVehiculo* p, int tipo);
int vehiculoSetPeso(eVehiculo* p, float peso);


int main(void)
{
	setbuf(stdout, NULL);

	int id = 21000;
	char marca[20] = "Mercedez";
	int tipo = 1200;
	float peso = 700.65;

	FILE* f = NULL;

	eVehiculo* v = newVehiculoParam(id, marca, tipo, peso);

	f = fopen("Mi archivo.txt", "w");

	vehiculoSetId(v, id);
	vehiculoSetMarca(v, marca);
	vehiculoSetPeso(v, peso);
	vehiculoSetTipo(v, tipo);

	fclose(f);

	return EXIT_SUCCESS;
}

eVehiculo* newVehiculo()
{
    eVehiculo* pNuevoVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));

    if(pNuevoVehiculo != NULL)
    {
    	pNuevoVehiculo->id = 0;
        *(pNuevoVehiculo->marca) = '\0';
        pNuevoVehiculo->tipo = 0;
        pNuevoVehiculo->peso = 0;
    }
    return pNuevoVehiculo;
}

eVehiculo* newVehiculoParam(int id, char marca[], int tipo, float peso)
{
    eVehiculo* pNuevoVehiculo = newVehiculo();

    if(!(vehiculoSetId(pNuevoVehiculo, id)
            && vehiculoSetMarca(pNuevoVehiculo, marca)
            && vehiculoSetPeso(pNuevoVehiculo, peso)
            && vehiculoSetTipo(pNuevoVehiculo, tipo)))
    {
        free(pNuevoVehiculo);
        pNuevoVehiculo = NULL;
    }
    return pNuevoVehiculo;
}

int vehiculoSetId(eVehiculo* p, int id)
{
    int todoOk = 0;

    if(p != NULL && id >= 20000 && id <= 30000)
    {
        p->id = id;
        todoOk = 1;
    }

    return todoOk;
}

int vehiculoSetMarca(eVehiculo* p, char marca[])
{
    int todoOk = 0;

    if(p != NULL && marca != NULL && strlen(marca) < 20)
    {
        strcpy(p->marca, marca);
        strlwr(p->marca);
        todoOk = 1;
    }

    return todoOk;
}

int vehiculoSetTipo(eVehiculo* p, int tipo)
{
    int todoOk = 0;

    if(p != NULL && tipo >= 1000 && tipo <= 3000)
    {
        p->tipo = tipo;
        todoOk = 1;
    }

    return todoOk;
}

int vehiculoSetPeso(eVehiculo* p, float peso)
{
    int todoOk = 0;

    if(p != NULL && peso > 0)
    {
        p->peso = peso;
        todoOk = 1;
    }

    return todoOk;
}
