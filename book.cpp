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

void displayBook(HeaderChild HC){
    if(HC.first == nullptr){
        cout<<"kosong"<<endl;
    }

    adrChild C = HC.first;
    int i = 1;

    while (C != nullptr){
        cout<<i<< " . " << C->info.judul<<endl;
        cout<<i<< " . " << C->info.kategori<<endl;
        cout<<i<< " . " << C->info.tahunTerbit<<endl;
        C = C->next;
        i++;
    }
    cout<<"========================================================="<<endl;

}