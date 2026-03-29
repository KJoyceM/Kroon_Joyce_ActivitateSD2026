// #define _CRT_SECURE_NO_WARNING
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// struct Telefon{
//     int id;
//     float pret;
//     char* producator;
//     char* numeMagazin;
//     char serie;
// };

// typedef struct Telefon Telefon;

// struct Nod{
//     Telefon info;
//     struct Nod* next;
//     struct Nod* prev;
// };

// typedef struct Nod Nod;

// struct ListaDubla{
//     Nod* first;
//     Nod* last;
//     int nrNoduri;
// };

// typedef struct ListaDubla ListaDubla;

// void afisareTelefon(Telefon t){
//     printf("\nID: %d\n", t.id);
//     printf("Pret: %.2f\n", t.pret);
//     printf("Producator:%s\n", t.producator);
//     printf("Nume Magazin:%s\n", t.numeMagazin);
//     printf("Serie:%c\n", t.serie);
// }

// void afisareListaInceput(ListaDubla lista){
//     Nod* p=lista.first;
//     while(p){
//         afisareTelefon(p->info);
//         p=p->next;
//     }
// }

// void afisareListaFinal(ListaDubla lista){
//     Nod* p=lista.last;
//     while(p){
//         afisareTelefon(p->info);
//         p=p->prev;
//     }
// }

// void adaugaTelefonLista(ListaDubla* lista, Telefon telefonNou){
//     Nod* nou=(Nod*)malloc(sizeof(Nod));
//     nou->info=telefonNou;
//     nou->next=NULL;
//     nou->prev=lista->last;
//     if(lista->last!=NULL){
//         lista->last->next=nou;
//     } else {
//         lista->first=nou;
//     }
//     lista->last=nou;
//     lista->nrNoduri++;
// }

// void adaugaTelefonListaInceput(ListaDubla* lista, Telefon telefonNou){
//     Nod* nou=(Nod*)malloc(sizeof(Nod));
//     nou->info=telefonNou;
//     nou->next=lista->first;
//     nou->prev=NULL;
//     if(lista->first!=NULL){
//         lista->first->prev=nou;
//     } else {
//         lista->last=nou;
//     }
//     lista->first=nou;
//     lista->nrNoduri++;
// }

// Telefon citireFisier(FILE* f){
//     Telefon t;
//     char buffer[100];
//     char separator[4]=",;\n";
//     fgets(buffer, 100, f);
//     t.id=atoi(strtok(buffer, separator));
//     t.pret=atof(strtok(NULL, separator));
//     char* aux;
//     aux=strtok(NULL, separator);
//     t.producator=(char*)malloc(sizeof(aux)+1);
//     strcpy(t.producator, aux);
//     aux=strtok(NULL, separator);
//     t.numeMagazin=(char*)malloc(sizeof(aux)+1);
//     strcpy(t.numeMagazin, aux);
//     t.serie=strtok(NULL, separator)[0];
//     return t;
// }

// ListaDubla citireListaFisier(const char* numeFisier){
//     FILE* f=fopen(numeFisier, "r");
//     ListaDubla lista;
//     lista.first=NULL;
//     lista.last=NULL;
//     lista.nrNoduri=0;
//     if(f){
//         while(!feof(f)){
//             adaugaTelefonLista(&lista, citireFisier(f));
//         }
//     }
//     fclose(f);
//     return lista;
// }

// void dezalocare(ListaDubla* lista){
//     Nod* p=lista->first;
//     while(p){
//         Nod* aux=p;
//         p=p->next;
//         if(aux->info.producator!=NULL){
//             free(aux->info.producator);
//         }
//         if(aux->info.numeMagazin!=NULL){
//             free(aux->info.numeMagazin);
//         }
//         free(aux);
//     }
//     lista->first=NULL;
//     lista->last=NULL;
//     lista->nrNoduri=0;
// }

// int main(){
//     ListaDubla lista=citireListaFisier("masini.txt");
//     afisareListaInceput(lista);
//     afisareListaFinal(lista);
//     dezalocare(&lista);
//     return 0;
// }
