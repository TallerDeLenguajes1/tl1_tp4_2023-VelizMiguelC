#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAMA 200

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
}typedef tarea;

void inicializararreglo(tarea **tareas,int canttareas);
void cargartareas(tarea **tareas,int canttareas);
void control(tarea **tareaspend,tarea **tareasrealiz,int canttareas);
void mostrartareas(tarea **tareas,int canttareas);
void buscartarea(tarea **tareaspend,tarea **tareasrealiz,int canttareas);
void buscartarea(tarea **tareaspend,tarea **tareasrealiz,int canttareas);

int main (){
    int canttareas;
    tarea **tareaspend;
    tarea **tareasrealiz;
    printf("Ingrese la cantidad de tareas que va a realizar:\n");
    scanf("%d",&canttareas);
    tareaspend=(tarea**)malloc(sizeof(tarea*)*canttareas);
    tareasrealiz=(tarea**)malloc(sizeof(tarea*)*canttareas);
    inicializararreglo(tareaspend,canttareas);
    inicializararreglo(tareasrealiz,canttareas);
    cargartareas(tareaspend,canttareas);
    control(tareaspend,tareasrealiz,canttareas);
    printf("-------------Tareas Pendientes-------------\n");
    mostrartareas(tareaspend,canttareas);
    printf("-------------Tareas Realizadas-------------\n");
    mostrartareas(tareasrealiz,canttareas);
    buscartarea(tareaspend,tareasrealiz,canttareas);
    buscartarea(tareaspend,tareasrealiz,canttareas)
}

void inicializararreglo(tarea **tareas,int canttareas){
    for (int i = 0; i < canttareas; i++)
    {
        tareas[i]=NULL;
    }
    
}
void cargartareas(tarea **tareas,int canttareas){
    for (int i = 0; i < canttareas; i++)
    {
        char *buff=(char*)malloc(sizeof(char)*TAMA);
        tareas[i] = (tarea*)malloc(sizeof(tarea));
        tareas[i]->TareaID=i+1;
        printf("TareaID:%d\n",i+1);
        printf("Ingrese la descripcion de la tarea:\n");
        scanf("%s",buff);
        tareas[i]->Descripcion=(char*)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(tareas[i]->Descripcion,buff);

        free(buff);
        printf("Ingrese la duraion de la tarea:\n");
        scanf("%d",&tareas[i]->Duracion);
    }
    
}
void control(tarea **tareaspend,tarea **tareasrealiz,int canttareas){
    int control;
    printf("------------TareasPendientes------------\n");
    for (int i = 0; i < canttareas; i++)
    {
        printf("TareaID=%d\n",i+1);
        printf("Descripcion de tarea:%s\n",tareaspend[i]->Descripcion);
        printf("Duracion de la tarea:%d\n",tareaspend[i]->Duracion);
        printf("Se realizo la tarea?Si(1),No(0)\n");
        scanf("%d",&control);
        if (control==1)
        {
            tareasrealiz[i]=tareaspend[i];
            tareaspend[i]=NULL;
        }
        
    }
    
}
void mostrartareas(tarea **tareas,int canttareas){
    for (int i = 0; i < canttareas; i++)
    {
        if (tareas[i] != NULL)
        {
            printf("---Tarea numero %d---\n",i+1);
            printf("Descripcion de tarea:%s\n",tareas[i]->Descripcion);
            printf("Duracion de la tarea:%d\n",tareas[i]->Duracion);
        }else{
            printf("La tarea Num %d esta en NULL\n", i+1);
        }
        
        
    }
    
}
void buscartarea(tarea **tareaspend,tarea **tareasrealiz,int canttareas){
    int id;

    printf("Ingrese el ID de la tarea que busca:");
    scanf("%d",&id);
    for (int i = 0; i < canttareas; i++)
    {
        if (tareaspend[i] != NULL && tareaspend[i] == id)
        {
            printf("La tarea que busca esta en tareas pendiente es la numero %d",i+1);
            printf("Descripcion de tarea:%s\n",tareaspend[i]->Descripcion);
            printf("Duracion de la tarea:%d\n",tareaspend[i]->Duracion);
        }
        if (tareasrealiz[i] != NULL && tareasrealiz[i] == id)
        {
            printf("La tarea que busca esta en tareas realizadas es la numero %d",i+1);
            printf("Descripcion de tarea:%s\n",tareasrealiz[i]->Descripcion);
            printf("Duracion de la tarea:%d\n",tareasrealiz[i]->Duracion);
        }
        
    }
    
}
void buscartarea(tarea **tareaspend,tarea **tareasrealiz,int canttareas){
    char *aux;
    printf("Ingrese la descripcion a buscar");
    scanf("%s",aux);
    for (int i = 0; i < canttareas; i++)
    {
        if (tareaspend[i] != NULL && strstr(tareaspend[i]->Descripcion,aux) != NULL)
        {
            printf("La tarea que busca esta en tareas pendiente es la numero %d",i+1);
            printf("Descripcion de tarea:%s\n",tareaspend[i]->Descripcion);
            printf("Duracion de la tarea:%d\n",tareaspend[i]->Duracion);
        }
        if (tareasrealiz[i] != NULL && strstr(tareasrealiz[i]->Descripcion,aux) != NULL)
        {
            printf("La tarea que busca esta en tareas realizadas es la numero %d",i+1);
            printf("Descripcion de tarea:%s\n",tareasrealiz[i]->Descripcion);
            printf("Duracion de la tarea:%d\n",tareasrealiz[i]->Duracion);
        }
        
    }
    
}