// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>


// struct StructuraMasina {
// 	int id;
// 	int nrUsi;
// 	float pret;
// 	char* model;
// 	char* numeSofer;
// 	unsigned char serie;
// };

// //alias definit
// typedef struct StructuraMasina Masina;

// void afisareMasina(Masina masina) {
// 	printf("ID:%d\n", masina.id);
//     printf("Numar usi:%d\n", masina.nrUsi);
//     printf("Pret:%.2f\n", masina.pret);
//     printf("Model:%s\n", masina.model);
//     printf("Nume Sofer:%s\n", masina.numeSofer);
//     printf("Serie:%c\n\n", masina.serie);
// }

// void afisareVectorMasini(Masina* masini, int nrMasini) {
// 	for (int i=0; i<nrMasini; i++){
//         afisareMasina(masini[i]);
//     }
// }

// void adaugaMasinaInVector(Masina** masini, int * nrMasini, Masina masinaNoua) {
// 	Masina* aux=(Masina*)malloc(sizeof(Masina)*((*nrMasini)+1));
//     for (int i=0; i<*nrMasini; i++){
//         aux[i]=(*masini)[i];
//     }
//     aux[(*nrMasini)]=masinaNoua; //shallow copy
//     free(*masini);
//     (*masini)=aux;
//     (*nrMasini)++;
// }

// Masina citireMasinaFisier(FILE* file) {
// 	//functia citeste o masina dintr-un stream deja deschis- folosing functia de mai jos
// 	//masina citita este returnata;
//     Masina m;
//     char buffer[100]; //tot randul
//     char separator[4]=",;\n"; //cum sunt impartite in fisier
//     fgets(buffer, 100, file);
//     //folosim functia strtok care returneaza un char
//     //atoi-> ascii to integer, 
//     m.id=atoi(strtok(buffer, separator));
//     m.nrUsi=atoi(strtok(NULL, separator));
//     m.pret=atof(strtok(NULL, separator));
//     //trebuie sa alocam spatiu pt char*
//     char* aux;
//     aux=strtok(NULL, separator);
//     m.model=(char*)malloc(strlen(aux)+1);
//     strcpy(m.model, aux);
//     aux=strtok(NULL, separator);
//     m.numeSofer=(char*)malloc(strlen(aux)+1);
//     strcpy(m.numeSofer, aux);
//     m.serie=strtok(NULL, separator)[0]; //luam doar prima pozitie fiind char
//     return m;
// }

// Masina* citireVectorMasiniFisier(const char* numeFisier, int* nrMasiniCitite) {
// 	//functia primeste numele fisierului, il deschide si citeste toate masinile din fisier
// 	//prin apelul repetat al functiei citireMasinaFisier()
// 	//numarul de masini este determinat prin numarul de citiri din fisier
// 	//ATENTIE - la final inchidem fisierul/stream-ul

//     FILE* file= fopen(numeFisier, "r");
//     Masina* masini=NULL;
//     (*nrMasiniCitite)=0;
//     while (!feof(file)){
//         adaugaMasinaInVector(&masini, nrMasiniCitite, citireMasinaFisier(file));
//     }
//     fclose(file);
//     return masini;
// }

// void dezalocareVectorMasini(Masina** vector, int* nrMasini) {
// 	//este dezalocat intreg vectorul de masini
//     for (int i=0; i<*nrMasini; i++){
//         if((*vector)[i].model!=NULL){
//             free((*vector)[i].model);
//         }
//         if((*vector)[i].numeSofer!=NULL){
//             free((*vector)[i].numeSofer);
//         }
//     }
//     free(*vector);
//     (*vector)=NULL;
//     (*nrMasini)=0;
// }

// int main() {

//     int nrMasini=0;
//     Masina* masini= citireVectorMasiniFisier("masini.txt",&nrMasini);
//     afisareVectorMasini(masini, nrMasini);
//     dezalocareVectorMasini(&masini, &nrMasini);
// 	return 0;
// }