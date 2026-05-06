#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct StructuraMasina {
	int id;
	int nrUsi;
	float pret;
	char* model;
	char* numeSofer;
	unsigned char serie;
};
typedef struct StructuraMasina Masina;

struct Heap {
	int lungime;
    Masina* vector;
    int nrMasini;
};
typedef struct Heap Heap;

Masina citireMasinaFisier(FILE* file) {
    Masina m;
    char buffer[100]; 
    char separator[4]=",;\n"; 
    fgets(buffer, 100, file); 
    m.id=atoi(strtok(buffer, separator));
    m.nrUsi=atoi(strtok(NULL, separator));
    m.pret=atof(strtok(NULL, separator));
    char* aux;
    aux=strtok(NULL, separator);
    m.model=(char*)malloc(strlen(aux)+1);
    strcpy(m.model, aux);
    aux=strtok(NULL, separator);
    m.numeSofer=(char*)malloc(strlen(aux)+1);
    strcpy(m.numeSofer, aux);
    m.serie=strtok(NULL, separator)[0]; 
    return m;
}

void afisareMasina(Masina masina) {
	printf("Id: %d\n", masina.id);
	printf("Nr. usi : %d\n", masina.nrUsi);
	printf("Pret: %.2f\n", masina.pret);
	printf("Model: %s\n", masina.model);
	printf("Nume sofer: %s\n", masina.numeSofer);
	printf("Serie: %c\n\n", masina.serie);
}

Heap initializareHeap(int lungime) {
	//initializeaza heap-ul cu 0 elemente 
	//dar cu o lungime primita ca parametru
    Heap heap;
    heap.lungime=lungime;
    heap.nrMasini=0;
    heap.vector=(Masina*)malloc(sizeof(Masina)*lungime);
    return heap;
}

void filtreazaHeap(Heap heap, int pozitieNod) {
    int pozFiuSt=2* pozitieNod+1;
    int pozFiuDr=2* pozitieNod+2;
    int pozMax=pozitieNod;
    if(pozFiuSt<heap.nrMasini && heap.vector[pozMax].id<heap.vector[pozFiuSt].id){
        pozMax=pozFiuSt;
    }
    if(pozFiuDr<heap.nrMasini && heap.vector[pozMax].id<heap.vector[pozFiuDr].id){
        pozMax=pozFiuDr;
    }
    if(pozMax!=pozitieNod){
        Masina aux=heap.vector[pozMax];
        heap.vector[pozMax]=heap.vector[pozitieNod];
        heap.vector[pozitieNod]=aux;
        if(pozMax<=(heap.nrMasini-2)/2){
            filtreazaHeap(heap, pozMax);
        }
    }
}

Heap citireHeapDeMasiniDinFisier(const char* numeFisier) {
	//citim toate masinile din fisier si le stocam intr-un heap 
	// pe care trebuie sa il filtram astfel incat sa respecte 
	// principiul de MAX-HEAP sau MIN-HEAP dupa un anumit criteriu
	// sunt citite toate elementele si abia apoi este filtrat vectorul
    FILE* file=fopen(numeFisier, "r");
    Heap heap=initializareHeap(10);
    while(!feof(file)){
        heap.vector[heap.nrMasini++]=citireMasinaFisier(file);
    }
    fclose(file);
    for( int i=(heap.nrMasini-2)/2; i>=0; i--){
        filtreazaHeap(heap, i);
    }
    return heap;
}

void afisareHeap(Heap heap) {
	//afiseaza elementele vizibile din heap
    for (int i=0; i<heap.nrMasini; i++){
        afisareMasina(heap.vector[i]);
    }
}

void afiseazaHeapAscuns(Heap heap) {
	//afiseaza elementele ascunse din heap
}

Masina extrageMasina(void* heap) {
	//extrage si returneaza masina de pe prima pozitie
	//elementul extras nu il stergem...doar il ascundem
}


void dezalocareHeap(Heap* heap) {
	//sterge toate elementele din Heap
}

int main() {

    Heap heap=citireHeapDeMasiniDinFisier("masini.txt");
    afisareHeap(heap);


	return 0;
}