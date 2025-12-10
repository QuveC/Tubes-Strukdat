#include "book.h"

void createListChild(HeaderChild &HC) {
    HC.first = NULL;
    HC.Last = NULL;
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
        HC.Last = C;
    } else {
        HC.Last->next = C;
        HC.Last = C;
    }
    
}


int countBook(HeaderChild HC){
    int i;
    adrChild P;
    P = HC.first;
    while (P != nullptr){
        i++;
        P = P->next;
    }
    return i;


}