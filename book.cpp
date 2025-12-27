#include "book.h"

void createListChild(HeaderChild &HC) {
    HC.first = NULL;
}

adrChild alokasiChild(infotype_buku infoBuku) {
    adrChild C = new ElmChild;
    C->info = infoBuku;
    C->next = NULL;
    return C;
}

adrChild searchBuku(HeaderChild HC, string judulBuku) {
    adrChild C = HC.first;
    while (C != NULL) {
        if (C->info.judul == judulBuku) {
            return C;
        }
        C = C->next;
    }
    return NULL;
}

void insertLastChild(HeaderChild &HC, adrChild C) {
    if (HC.first == NULL) {
        HC.first = C;
    } else {
        adrChild Q = HC.first; 
        while (Q->next != NULL) {
            Q = Q->next;
        }
        
        Q->next = C;
    }
}

void displayBook(HeaderChild HC){
    cout << "\n=== DAFTAR SEMUA BUKU ===" << endl;
    if(HC.first == NULL){
        cout << "(Kosong)" << endl;
        return;
    }

    adrChild C = HC.first;
    int i = 1;

    while (C != NULL){
        cout << i << ". " << C->info.judul 
             << " (" << C->info.tahunTerbit << ") - " 
             << C->info.kategori << endl;
        C = C->next;
        i++;
    }
    cout << "=========================================================" << endl;
}

int countBook(HeaderChild HC) {
    int count = 0;
    adrChild C = HC.first;
    while(C != NULL) {
        count++;
        C = C->next;
    }
    return count;
}