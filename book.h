#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct infotype_buku {
    string judul;
    int tahunTerbit;
    string kategori;
};

typedef struct ElmChild *adrChild;

struct ElmChild {
    infotype_buku info;
    adrChild next;
};

struct HeaderChild {
    adrChild first;
    adrChild Last;
};

void createListChild(HeaderChild &HC);
adrChild alokasiChild(infotype_buku infoBuku);
void insertLastChild(HeaderChild &HC, adrChild C);
adrChild searchBuku(HeaderChild HC, string judulBuku);
int countBook(HeaderChild HC);
void displayBook(HeaderChild HC);


#endif