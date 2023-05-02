#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Tarea{
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;
struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
}typedef Nodo;
Nodo* crearlistavacia();
Nodo* crearnodo(int i);
void insertarnodo(Nodo** L, Nodo* nodo);
Nodo* mostrarlista(Nodo* L);
Nodo* cambiarnodo(Nodo** L,int id);
void cambiarlista(Nodo** L,Nodo** L2);
Nodo* buscartareaporid(Nodo *L, int id);
Nodo* buscartareaporchar(Nodo *L,char chaer[]);

typedef Nodo* lista;

int main (){
    Nodo* Tareapend ,*Tarearealiz,*TareasEnProceso;
    Nodo *tarbusporid,*tarbuspochar;
    int aux,i=0,buscar;
    char chaer[100];
    Tareapend=crearlistavacia();
    Tarearealiz=crearlistavacia();
    printf("Desea crear una tarea nueva SI(1) NO(0)\n");
    scanf("%d",&aux);
    fflush(stdin);
    while (aux != 0)
    {
        insertarnodo(&Tareapend,crearnodo(i));
        printf("Desea crear una tarea nueva SI(1) NO(0)\n");
        scanf("%d",&aux);
        fflush(stdin);
        i++;
    }
    cambiarlista(&Tareapend,&Tarearealiz);

    printf("Tareas Pendientes:\n");
    mostrarlista(Tareapend);
    
    printf("Tareas Realizado:\n");
    mostrarlista(Tarearealiz);
    printf("Ingrese la tarea que va a buscar por id:");
    scanf("%d",&buscar);
    fflush(stdin);
    tarbusporid=buscartareaporid(Tareapend,buscar);
    if (tarbusporid == NULL)
    {
        tarbusporid=buscartareaporid(Tarearealiz,buscar);
    }
    if (tarbusporid == NULL)
    {
        printf("La tarea que busca no exite");
    }else{
        printf("--La tarea encontrada es--\n");
        mostrarlista(tarbusporid);
    }
    
    printf("Ingrese la tarea a buscar por char:");
    gets(chaer);
    tarbuspochar=buscartareaporchar(Tareapend,chaer);
    if (tarbuspochar == NULL)
    {
        tarbuspochar=buscartareaporchar(Tarearealiz,chaer);
    }
    if (tarbuspochar == NULL)
    {
        printf("La tarea que busca no exite");
    }else{
        printf("--La tarea encontrada es--\n");
        mostrarlista(tarbuspochar);   
    }
    
    
}

Nodo* crearlistavacia(){
    return NULL;
}
Nodo* crearnodo(int i){
    Nodo* tarea= malloc(sizeof(Nodo));

    char* buff=(char*)malloc(sizeof(char)*100);
    srand(time(NULL));

    tarea->T.TareaID=1+i;
    tarea->T.Duracion=10+rand() % 91;
    printf("Ingrese la descripcion de la tarea\n");
    scanf("%s",buff);
    tarea->T.Descripcion=(char*)malloc(sizeof(char)*(strlen(buff)+1));
    strcpy(tarea->T.Descripcion,buff);
    free(buff);
    tarea->Siguiente=NULL;
    return tarea;
}
void insertarnodo(Nodo** L, Nodo* nodo){
    nodo->Siguiente=(*L);
    (*L)= nodo;
    
}
void cambiarlista(Nodo** L,Nodo** L2){
    int aux;
    Nodo *punt= NULL,*lista=(*L);
    while ((*L) != NULL)
    {
        printf("------La tarea es la numero %d------\n",(*L)->T.TareaID);
        printf("La descripcion es: %s\n",(*L)->T.Descripcion);
        printf("La duracion es:%d\n",(*L)->T.Duracion);
        printf("Se realizo la tarea? SI(1) NO(0)");
        scanf("%d",&aux);
        if (aux != 0)
        {
            insertarnodo(L2,cambiarnodo(L,(*L)->T.TareaID));
        }else{
            insertarnodo(&punt,cambiarnodo((L),(*L)->T.TareaID));
        }
    }
    (*L)=punt;
    
}
Nodo* cambiarnodo(Nodo** L,int id){
    Nodo* guardar=(*L);
    if ((*L)==NULL)
    {
        return NULL;
    }else if ((*L)->T.TareaID==id)
    {
        (*L)=(*L)->Siguiente;
        return guardar;
    }else{
        while ((*L) != NULL && (*L)->T.TareaID != id)
        {

            guardar=(*L);
            (*L)=(*L)->Siguiente;
        }
        if ((*L)->T.TareaID == id)
        {
            guardar->Siguiente=guardar->Siguiente->Siguiente;
            return (*L); 
        }
        return NULL;
    }
    
    
    (*L)=(*L)->Siguiente;
    return guardar;
}
Nodo* mostrarlista(Nodo* L){
    while (L != NULL)
    {
        printf("------La tarea es la numero %d------\n",L->T.TareaID);
        printf("La descripcion es: %s\n",L->T.Descripcion);
        printf("La duracion es:%d\n",L->T.Duracion);
        L=L->Siguiente;
    }
    
}
Nodo* buscartareaporid(Nodo *L,int id){
    if (L != NULL)
    {
        while (L != NULL && L->T.TareaID != id)
        {
            
            L=L->Siguiente;   
        }
           
    }
    return L;
}
// Nodo* buscartareaporchar(Nodo *L,char chaer[]){
//     if (L != NULL)
//     {
//         while (L != NULL && strstr(L->T.Descripcion,chaer) != NULL)
//         {
//             L=L->Siguiente;
//         }
//     }
//     return L;
// }
Nodo* buscartareaporchar(Nodo *L, char chaer[]) {
    if (L != NULL) {
        while (L != NULL && strstr(L->T.Descripcion, chaer) != NULL) {
            L = L->Siguiente;
        }
    }
    return L;
}
