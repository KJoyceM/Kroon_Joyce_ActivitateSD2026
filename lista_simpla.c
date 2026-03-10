// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// //trebuie sa folositi fisierul masini.txt
// //sau va creati un alt fisier cu alte date

// struct StructuraMasina {
// 	int id;
// 	int nrUsi;
// 	float pret;
// 	char* model;
// 	char* numeSofer;
// 	unsigned char serie;
// };
// typedef struct StructuraMasina Masina;

// //creare structura pentru un nod dintr-o lista simplu inlantuita
// struct Nod{
//     Masina info;
//     struct Nod* next;
// };

// typedef struct Nod Nod;

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

// void afisareListaMasini(Nod* cap) {
//     while (cap !=NULL){
//         afisareMasina(cap->info);
//         cap=cap->next;
//     }
	
// }

// void adaugaMasinaInLista(Nod* *cap, Masina masinaNoua) {
// 	//adauga la final in lista primita o noua masina pe care o primim ca parametru
//     Nod* nou=(Nod*)malloc(sizeof(Nod));
//     nou->info=masinaNoua; //shalow copy
//     nou->next=NULL;
//     //verificam daca avem sau nu o lista existenta
//     if(*cap){
//         Nod* p=*cap;
//         while (p->next){
//             p=p->next;
//         }
//         p->next=nou;
//     } else {
//         *cap=nou;
//     }
// }

// void adaugaLaInceputInLista(Nod* *cap, Masina masinaNoua) {
// 	//adauga la inceputul listei o noua masina pe care o primim ca parametru
//     Nod* nou=(Nod*)malloc(sizeof(Nod));
//     nou->info=masinaNoua; //shalow copy
//     nou->next=*cap;
//     *cap=nou;
// }

// Nod* citireListaMasiniDinFisier(const char* numeFisier) {
// 	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
// 	//prin apelul repetat al functiei citireMasinaDinFisier()
// 	//ATENTIE - la final inchidem fisierul/stream-ul
//     Nod* cap=NULL;
//     FILE* f=fopen(numeFisier, "r");
//     if(f){
//         while(!feof(f)){
//             adaugaMasinaInLista(&cap, citireMasinaFisier(f));
//         }
//     }
//     fclose(f);
//     return cap;
// }

// void dezalocareListaMasini(Nod* *cap) {
//     while(*cap){
//         Nod* p= *cap;
//         (*cap)= p->next; //putem scrie si (*cap)= (*cap)->next;
//         if(p->info.model){
//             free(p->info.model);
//         }
//         if(p->info.numeSofer){
//             free(p->info.numeSofer);
//         }
//         free(p);
//     }
	
// }

// float calculeazaPretMediu(Nod* cap) {
// 	float suma=0;
//     int contor=0;
//     while(cap){
//         suma+= cap-> info.pret;
//         contor++;
//         cap=cap->next;
//     }
//     if(contor>0){
//         return suma/contor;
//     }
// 	return 0;
// }

// void stergeMasiniDinSeria(Nod* *cap, char serieCautata) {
// 	while((*cap) && (*cap)->info.serie== serieCautata){
//         Nod* aux= *cap;
//         (*cap)=aux->next;
//         if(aux->info.numeSofer){
//             free(aux->info.numeSofer);
//         }
//         if(aux->info.model){
//             free(aux->info.model);
//         }
//         free(aux);
//     }
//     if((*cap)){
//         Nod* p=*cap;
//         while(p){
//         while(p->next && p->next->info.serie!= serieCautata){
//             p=p->next;
//         }
//         if(p->next){
//             Nod* aux=p->next;
//             p->next=aux->next;
//             if(aux->info.numeSofer){
//             free(aux->info.numeSofer);
//         }
//         if(aux->info.model){
//             free(aux->info.model);
//         }
//         free(aux);
//         }
//         else
//         {
//             p=NULL;
//         }
//     }
//     }
// }

// float calculeazaPretulMasinilorUnuiSofer(Nod* cap, const char* numeSofer) {
// 	//calculeaza pretul tuturor masinilor unui sofer.
//     float suma=0;
//     while(cap){
//         if(strcmp(cap->info.numeSofer, numeSofer)==0){
//             suma+= cap-> info.pret;
//         }
//         cap=cap->next;
//     }
// 	return suma;
// }

// int main() {

//     Nod* cap= citireListaMasiniDinFisier("masini.txt");
//     afisareListaMasini(cap);
//     printf("Pretul mediu este: %.2f\n\n", calculeazaPretMediu(cap));
//     printf("Pretul masinilor lui Ionescu este: %.2f\n", calculeazaPretulMasinilorUnuiSofer(cap, "Ionescu"));
//     printf("Pretul masinilor lui Gigel este: %.2f\n", calculeazaPretulMasinilorUnuiSofer(cap, "Gigel"));

//     printf("Stergere seria A:\n");
//     stergeMasiniDinSeria(&cap, 'A');
//     afisareListaMasini(cap);
//     printf("Stergere seria B:\n");
//     stergeMasiniDinSeria(&cap, 'B');
//     afisareListaMasini(cap);
//     dezalocareListaMasini(&cap);
// 	return 0;
// }