// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Telefon{

//     int id;
//     float pret;
//     char* producator;
//     char* numeMagain;
//     char serie;
// };

// typedef struct Telefon Telefon;

// struct Nod{
//     Telefon info;
//     struct Nod* next;
// };

// typedef struct Nod Nod;

// void afisare(Telefon t){
//     printf("\nID: %d\n", t.id);
//     printf("Pret: %.2f\n", t.pret);
//     printf("Producator:%s\n", t.producator);
//     printf("Nume Magazin:%s\n", t.numeMagain);
//     printf("Serie:%c\n", t.serie);
// }

// void afisareLista(Nod* cap){
//     while(cap!=NULL){
//         afisare(cap->info);
//         cap=cap->next;
//     }
// }

// void adaugaLista(Nod** cap, Telefon telefonNou){
//     Nod* nou=(Nod*)malloc(sizeof(Nod));
//     nou->info=telefonNou;
//     nou->next=NULL;
//     if(*cap){
//         Nod* p=*cap;
//         while(p->next){
//             p=p->next;
//         }
//         p->next=nou;
//     } else {
//         *cap=nou;
//     }
// }


// Telefon citireFisier(FILE* f){
//     Telefon t;
//     char buffer[100];
//     char separator[4]=",;\n";
//     fgets(buffer, 100, f);
//     t.id=atoi(strtok(buffer,separator));
//     t.pret=atof(strtok(NULL,separator));
//     char* aux;
//     aux=strtok(NULL, separator);
//     t.producator=(char*)malloc(sizeof(aux));
//     strcpy(t.producator, aux);
//     aux=strtok(NULL, separator);
//     t.numeMagain=(char*)malloc(sizeof(aux));
//     strcpy(t.numeMagain, aux);
//     t.serie=strtok(NULL,separator)[0];
//     return t;
// }

// Nod* citireListaFisier(const char* numeFisier){
//     FILE* f=fopen(numeFisier, "r");
//     Nod* cap=NULL;
//     if(f){
//         while(!feof(f)){
//             adaugaLista(&cap, citireFisier(f));
//         }
//     }
//     fclose(f);
//     return(cap);
// }

// void dezalocare(Nod** cap){
//     while(*cap){
//         Nod* p=*cap;
//         (*cap)=p->next;
//         if(p->info.producator!=NULL){
//             free(p->info.producator);
//         }
//         if(p->info.numeMagain!=NULL){
//             free(p->info.numeMagain);
//         }
//         free(p);
//     }
// }


// int main(){

//     Nod* cap=citireListaFisier("masini.txt");
//     afisareLista(cap);
//     dezalocare(&cap);
//     return 0;

// }
