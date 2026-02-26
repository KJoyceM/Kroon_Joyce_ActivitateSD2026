// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// //asta e doar pt mac
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

// //declaram const char* ca sa nu fie modificat
// struct Laptop initializare(int id, int memorie, const char* producator, float pret, char serie) {
// 	struct Laptop l;
// 	l.id = id;
//     l.memorie= memorie;
//     //pentru pointer trb sa alocam spatiu, char (un caracter) * strlen aloca cat avem nevoie +1 
//     l.producator=(char*)malloc(sizeof(char)*(strlen(producator)+1));
//     //copiem pointerul (unde copiem, cat alocam, de unde copiem)
//     strcpy_s(l.producator, strlen(producator)+1, producator);
//     l.pret=pret;
//     l.serie=serie;
// 	return l;
// }

// void afisare(struct Laptop l) {
// 	printf("%d: Laptopul %s, seria %c, cu memorie %d costa %5.2f\n", 
// 	l.id, l.producator, l.serie, l.memorie, l.pret);
// }

// void modifica_pret(struct Laptop* l, float noulPret) {
// 	if(noulPret >0 ){
// 		l->pret= noulPret;
// 	}
// }

// void dezalocare(struct Laptop *l) {
// 	if(l->producator!=NULL){
// 		free(l->producator);
// 		l->producator=NULL;
// 	}
	
// }

// int main() {
// 	struct Laptop l;
//     l=initializare(1, 512, "Apple", 6500, 'M');
// 	afisare(l);
// 	modifica_pret(&l, 6300);
// 	afisare(l);
// 	dezalocare(&l);
// 	afisare(l);
// 	return 0;
// }