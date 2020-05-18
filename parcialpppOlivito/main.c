#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4
typedef struct{
int id;
char marca[20];
char procesador[20];
float precio;
int isEmpty;
}eNotebook;

void mostrarNotebook(eNotebook note, int tam);
void mostrarNotebooks(eNotebook vec[], int tam);
void aplicarDescuento(float precio);
int ordenamiento(eNotebook vec[], int tam);
int contarCaracteres(char palabra[], char letra);
int main()
{
    eNotebook lista[TAM]={{100,"Asus","AMD",32500,0},{101,"HP","Intel",45000,0},{102,"HP","AMD",32000,0},{103,"Lenovo","Intel",45000,0}};
    float precio = 50;
    printf("El precio es: %.2f\n", precio);
    aplicarDescuento(precio);


    mostrarNotebooks(lista,TAM);

    printf("Notebooks ordenadas por marca y ante igualdad por precio: \n");
    ordenamiento(lista,TAM);
    mostrarNotebooks(lista,TAM);

    printf("\n\n\n");


    return 0;
}

void aplicarDescuento(float precio)
{
    precio = precio *0.95;

    printf("El precio con descuento es: %.2f\n", precio);


}

void mostrarNotebook(eNotebook note, int tam)
{


   printf("%d   %10s  %10s      %.2f\n",note.id,note.marca,note.procesador,note.precio);


}

void mostrarNotebooks(eNotebook vec[], int tam)
{
    int flag=0;
    printf("****Listado Notebooks****\n\n");
    printf(" Id        Marca     Procesador   Precio\n");
    for(int i = 0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarNotebook(vec[i],tam);
            flag=1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay notebooks que listar\n");
    }
}

int ordenamiento(eNotebook vec[], int tam)
{
    eNotebook aux;
    int comp;
    for(int i=0;i<tam;i++)
    {
        for(int j=i+1;j<tam-1;j++)
        {
            comp=strcmp(vec[i].marca,vec[j].marca);

            if(vec[i].isEmpty==0 && comp>0)
        {
            aux=vec[i];
            vec[i]=vec[j];
            vec[j]=aux;

        }
        else{
                if(comp == 0 && vec[i].precio>vec[j].precio)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
        }

    }


}

return 0;
}

int contarCaracteres(char palabra[], char letra)
{
    int letraRep=0;

    for(int i=0;i<strlen(palabra);i++)
    {
        if(palabra[i]==letra)
        {
            letraRep++;
        }
    }

    return letraRep;
}
