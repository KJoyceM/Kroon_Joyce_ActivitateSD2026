// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #ifndef _WIN32
//     #define strcpy_s(dest, size, src) strcpy(dest, src)
// #endif

// struct StructuraMasina {
// 	int id;
// 	int nrUsi;
// 	float pret;
// 	char* model;
// 	char* numeSofer;
// 	unsigned char serie;
// };
// typedef struct StructuraMasina Masina;

// struct Nod{
//     Masina masina;
//     struct Nod* next;
//     struct Nod* prev;
// };

// typedef struct Nod Nod;

// //creare structura pentru Lista Dubla 

// struct ListaDubla{
//     Nod* first;
//     Nod* last;
//     int nrNoduri;

// };

// typedef struct ListaDubla ListaDubla;

// Masina citireMasinaFisier(FILE* file) {
//     Masina m;
//     char buffer[100]; 
//     char separator[4]=",;\n"; 
//     fgets(buffer, 100, file);
//     m.id=atoi(strtok(buffer, separator));
//     m.nrUsi=atoi(strtok(NULL, separator));
//     m.pret=atof(strtok(NULL, separator));
//     char* aux;
//     aux=strtok(NULL, separator);
//     m.model=(char*)malloc(strlen(aux)+1);
//     strcpy(m.model, aux);
//     aux=strtok(NULL, separator);
//     m.numeSofer=(char*)malloc(strlen(aux)+1);
//     strcpy(m.numeSofer, aux);
//     m.serie=strtok(NULL, separator)[0]; 
//     return m;
// }

// void afisareMasina(Masina masina) {
// 	printf("Id: %d\n", masina.id);
// 	printf("Nr. usi : %d\n", masina.nrUsi);
// 	printf("Pret: %.2f\n", masina.pret);
// 	printf("Model: %s\n", masina.model);
// 	printf("Nume sofer: %s\n", masina.numeSofer);
// 	printf("Serie: %c\n\n", masina.serie);
// }

// void afisareListaMasinideLaInceput(ListaDubla lista) {
//     Nod* p=lista.first;
//     while(p){
//         afisareMasina(p->masina);
//         p=p->next;
//     }
	
// }

// void afisareListaMasiniDeLaSfarsit(ListaDubla lista) {
// 	Nod* p=lista.last;
//     while(p){
//         afisareMasina(p->masina);
//         p=p->prev;
//     }
// }

// void adaugaMasinaInLista(ListaDubla* lista, Masina masinaNoua) {
// 	//adauga la final in lista
//     Nod* nou=(Nod*)malloc(sizeof(Nod));
//     nou->masina=masinaNoua;
//     nou->next=NULL;
//     nou->prev=lista->last;
//     if(lista->last !=NULL){
//         lista->last->next=nou;
//     } else {
//         lista-> first=nou;
//     }
//     lista->last=nou;
//     lista->nrNoduri++;
// }

// void adaugaLaInceputInLista(ListaDubla* lista, Masina masinaNoua) {
// 	Nod* nou=(Nod*)malloc(sizeof(Nod));
//     nou->masina=masinaNoua;
//     nou->next=lista->first;
//     nou->prev=NULL;
//     if(lista->first !=NULL){
//         lista->first->prev=nou;
//     } else {
//         lista-> last=nou;
//     }
//     lista->first=nou;
//     lista->nrNoduri++;
// }

// ListaDubla citireLDMasiniDinFisier(const char* numeFisier) {
// 	FILE* f=fopen(numeFisier, "r");
//     ListaDubla lista;
//     //trebuie sa initializam
//     lista.first=NULL;
//     lista.last=NULL;
//     lista.nrNoduri=0;
//     while(!feof(f)){
//         adaugaMasinaInLista(&lista, citireMasinaFisier(f));
//     }
//     fclose(f);
//     return lista;
// }

// void dezalocareLDMasini(ListaDubla* lista) {
//     Nod* p=lista->first;
//     while(p){
//         Nod* aux=p;
//         p=p->next;
//         if(aux->masina.model){
//             free(aux->masina.model);
//         }
//         if(aux->masina.numeSofer){
//             free(aux->masina.numeSofer);
//         }
//         free(aux);
//     }
// 	lista->first=NULL;
//     lista->last=NULL;
//     lista->nrNoduri=0;
// }

// float calculeazaPretMediu(ListaDubla lista) {
// 	//calculeaza pretul mediu al masinilor din lista.
//     //nu avem nevoie de contor pt ca avem nrNoduri
//     if(lista.nrNoduri>0){
//         float suma=0;
//         Nod* p=lista.first;
//         while(p){
//             suma+=p->masina.pret;
//             p=p->next;
//         }
//         return suma/lista.nrNoduri;
//     }
// 	return 0;
// }

// void stergeMasinaDupaID(ListaDubla* lista, int id) {
// 	//tratati situatia ca masina se afla si pe prima pozitie, si pe ultima pozitie
//     //tratam situatia in care nu avem lista
//     if(lista->first==NULL){
//         return;
//     }
//     //tratam situatile in care nu avem id-ul
//     Nod* p=lista->first;
//     while (p!=NULL && p->masina.id!=id){
//         p=p->next;
//     }
//     if(p==NULL){
//         return;
//     }
//     //avem ce sa stergem
//     //daca trb sa stergem primul nod
//     if(p->prev==NULL){
//         lista->first=p->next;
//         //daca e singurul nod
//         if(lista->first){
//             lista->first->prev=NULL;
//         }
//     } 
//     else {
//         p->prev->next=p->next;
//     }
//     if(p->next!=NULL){
//         p->next->prev=p->prev;
//     } else {
//         lista->last=p->prev;
//     }
//     if(p->masina.model){
//             free(p->masina.model);
//         }
//         if(p->masina.numeSofer){
//             free(p->masina.numeSofer);
//         }
//         free(p);
//         lista->nrNoduri--;
// }

// char* getNumeSoferMasinaScumpa(ListaDubla lista) {
//     if(lista.first){
//         Nod* max=lista.first;
//         Nod* p=lista.first->next;
//         while(p){
//             if(p->masina.pret> max->masina.pret){
//                 max=p;
//             }
//             p= p->next;
//         }
//         char* nume=(char*)malloc(strlen(max->masina.numeSofer)+1);
//         strcpy_s(nume, strlen(max->masina.numeSofer)+1, max->masina.numeSofer);
//         return nume;
//     } else{
//         return NULL;
//     }
// }

// int main() {

//     ListaDubla lista=citireLDMasiniDinFisier("masini.txt");
//     afisareListaMasinideLaInceput(lista);
//     stergeMasinaDupaID(&lista, 6);
//     stergeMasinaDupaID(&lista, 10);
//     printf("lista de la sfarsit\n\n");
//     afisareListaMasiniDeLaSfarsit(lista);
//     printf("\nPretul mediu: %.2f\n", calculeazaPretMediu(lista));

//     char* numeSofer=getNumeSoferMasinaScumpa(lista);
//     printf("Soferul cu cea mai scumpa masina este: %s\n", numeSofer);

//     if(numeSofer){
//         free(numeSofer);
//     }

//     dezalocareLDMasini(&lista);

// 	return 0;
// }