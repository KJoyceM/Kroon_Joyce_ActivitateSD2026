// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// struct Telefon{
//     int id;
//     float pret;
//     char* producator;
//     char* numeMagazin;
//     char serie;
// };

// typedef struct Telefon Telefon;

// void afisare(Telefon t){
//     printf("ID: %d Telefonul cu seria %c, al producatorului %s, cu pretul %.2f se afla la magazinul %s\n\n", 
//     t.id, t.serie, t.producator, t.pret, t.numeMagazin);
// }

// void afisareVector(Telefon* t, int nrTelefoane){
//     for(int i=0; i<nrTelefoane; i++){
//         afisare(t[i]);
//     }
// }

// void adaugareVector(Telefon** t, int* nrTelefoane, Telefon telefonNou){
//     Telefon* aux=(Telefon*)malloc(sizeof(Telefon)*((*nrTelefoane)+1));
//     for (int i=0; i<*nrTelefoane; i++){
//         aux[i]=(*t)[i];
//     }
//     aux[(*nrTelefoane)]=telefonNou;
//     free(*t);
//     (*t)=aux;
//     (*nrTelefoane)++;
// }

// Telefon citireFisier(FILE* f){
//     Telefon t;
//     char buffer[100];
//     char separator[4]=",;\n";
//     fgets(buffer, 100, f);
//     t.id=atoi(strtok(buffer,separator));
//     t.pret=atof(strtok(NULL, separator));
//     char* aux;
//     aux=strtok(NULL, separator);
//     t.producator=(char*)malloc(strlen(aux)+1);
//     strcpy(t.producator, aux);
//     aux=strtok(NULL, separator);
//     t.numeMagazin=(char*)malloc(strlen(aux)+1);
//     strcpy(t.numeMagazin, aux);
//     t.serie=strtok(NULL,separator)[0];
//     return t;
// }

// Telefon* citireVectorFisier(const char* numeFisier, int* nrTelefoane){
//     FILE* f=fopen(numeFisier, "r");
//     Telefon* t=NULL;
//     while(!feof(f)){
//         adaugareVector(&t, nrTelefoane, citireFisier(f));
//     }
//     fclose(f);
//     return t;
// }

// void dezalocare(Telefon** t, int* nrTelefoane){
//     for(int i=0; i<*nrTelefoane; i++){
//         if((*t)[i].producator!=NULL){
//             free((*t)[i].producator);
//         }
//         if((*t)[i].numeMagazin!=NULL){
//             free((*t)[i].numeMagazin);
//         }
//     }
//     free(*t);
//     (*t)=NULL;
//     nrTelefoane=0;
// }

// int main(){

//     int nrTelefoane=0;
//     Telefon* t=citireVectorFisier("masini.txt", &nrTelefoane);
//     afisareVector(t, nrTelefoane);
//     dezalocare(&t, &nrTelefoane);

//     return 0;
// }
