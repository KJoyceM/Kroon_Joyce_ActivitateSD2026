// #include<stdio.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #ifndef _WIN32
//     #define strcpy_s(dest, size, src) strcpy(dest, src)
// #endif


// struct Laptop {
// 	int id;
// 	int memorie;
// 	char* producator;
// 	float pret;
// 	char serie;
// };

// struct Laptop initializare(int id, int memorie, const char* producator, float pret, char serie) {
// 	struct Laptop l;
// 	l.id = id;
//     l.memorie= memorie;
//     l.producator=(char*)malloc(sizeof(char)*(strlen(producator)+1));
//     strcpy_s(l.producator, strlen(producator)+1, producator);
//     l.pret=pret;
//     l.serie=serie;
// 	return l;
// }

// void afisare(struct Laptop l) {
// 	printf("%d: Laptopul %s, seria %c, cu memorie %d costa %5.2f\n", 
// 	l.id, l.producator, l.serie, l.memorie, l.pret);
// }

// void afisareVector(struct Laptop* vector, int nrElemente) {
// 	for (int i=0; i<nrElemente;i++){
//         afisare(vector[i]);
//     }
// }

// struct Sablon* copiazaPrimeleNElemente(struct Laptop* vector, int nrElemente, int nrElementeCopiate) {
// 	struct Laptop *vectorNou=NULL;
//     vectorNou= (struct Laptop*)malloc(sizeof(struct Laptop)* nrElementeCopiate);
//     for(int i=0; i<nrElementeCopiate; i++){
//         vectorNou[i]=vector[i];
//         //facem deepcopy si nu shallowcopy pt producator care este char*
//         vectorNou[i].producator=(char*)malloc(strlen(vector[i].producator)+1);
//         strcpy_s(vectorNou[i].producator, strlen(vector[i].producator)+1, vector[i].producator);
//     }
// 	return vectorNou;
// }

// void dezalocare(struct Laptop** vector, int* nrElemente) {
// 	//dezalocam elementele din vector si vectorul
//     for (int i=0; i<(*nrElemente);i++){
//         if((*vector)[i].producator!=NULL){
//             free((*vector)[i].producator);
//         }
//     }
//     free(*vector);
//     *vector=NULL;
//     *nrElemente=0;
// }

// void copiazaLaptopPretMin(struct Laptop* vector, char nrElemente, float pretMin, struct Laptop** vectorNou, int* dimensiune) {
// 	//este creat un nou vector cu elementele care indeplinesc acea conditie
//     //stabilim dimensiunea vectorului
//     *dimensiune=0;
//     for (int i=0; i<nrElemente; i++){
//         if(vector[i].pret>=pretMin){
//             (*dimensiune)++;
//         }
//     }

//     //dezalocam memoria
//     if ((*vectorNou)!=NULL){
//         free(*vectorNou);
//     }

//     //alocam memorie
//     *vectorNou=(struct Laptop*)malloc(sizeof(struct Laptop)*(*dimensiune));

//     //stabilim pozitia si copiem
//     int k=0;
//     for (int i=0; i<nrElemente; i++){
//         if(vector[i].pret>=pretMin){
//             (*vectorNou)[k]=vector[i];
//             (*vectorNou)[k].producator=(char*)malloc(strlen(vector[i].producator)+1);
//             strcpy_s((*vectorNou)[k].producator, strlen(vector[i].producator)+1, vector[i].producator);
//             k++;
//         }
//     }
// }

// struct Laptop getPrimulElementByProducator(struct Laptop* vector, int nrElemente, const char* producator) {
// 	//trebuie cautat elementul care indeplineste o conditie
//     //strcmp=string compare
// 	struct Laptop l;
//     l.producator=NULL;
//     for (int i=0; i<nrElemente; i++){
//         if(strcmp(vector[i].producator, producator)==0){
//             l=vector[i];
//             l.producator=(char*)malloc(strlen(vector[i].producator)+1);
//             strcpy_s(l.producator, (vector[i].producator)+1, vector[i].producator);
//             return l;
//         }
//     }
// 	return l;
// }
	


// int main() {

//     struct Laptop* laptopuri= NULL;
//     int nrLaptopuri=3;
//     laptopuri=(struct Laptop*)malloc(sizeof(struct Laptop)*nrLaptopuri);
//     laptopuri[0]=initializare(1, 512, "Apple", 6500, 'M');
//     laptopuri[1]=initializare(2, 256, "Acer", 2300, 'A');
//     laptopuri[2]=initializare(3, 1000, "Dell", 4500, 'D');
//     afisareVector(laptopuri, nrLaptopuri);

//     struct Laptop* primeleLaptopuri=NULL;
//     int nrPrimeleLaptopuri=2;
//     primeleLaptopuri=copiazaPrimeleNElemente(laptopuri, nrLaptopuri, nrPrimeleLaptopuri);
//     printf("\n\nPrimele Laptopuri:\n");
//     afisareVector(primeleLaptopuri,nrPrimeleLaptopuri);

//     dezalocare(&primeleLaptopuri, &nrPrimeleLaptopuri);
//     printf("\n\nPrimele Laptopuri:\n");
//     afisareVector(primeleLaptopuri,nrPrimeleLaptopuri);

//     struct Laptop* laptopuriScumpe=NULL;
//     int nrLaptopuriScumpe=0;
//     copiazaLaptopPretMin(laptopuri, nrLaptopuri, 4500, &laptopuriScumpe, &nrLaptopuriScumpe);
//     printf("\n\nLaptopuri peste 4500 RON:\n");
//     afisareVector(laptopuriScumpe, nrLaptopuriScumpe);
//     dezalocare(&laptopuriScumpe, &nrLaptopuriScumpe);

//     struct Laptop laptop= getPrimulElementByProducator(laptopuri, nrLaptopuri, "Dell");
//     printf("\n\nPrimul Laptop Dell:\n");
//     afisare(laptop);
//     if(laptop.producator!=NULL){
//         free(laptop.producator);
//         laptop.producator=NULL;
//     }
//     dezalocare(&laptop, &nrLaptopuri);
// 	return 0;

// }