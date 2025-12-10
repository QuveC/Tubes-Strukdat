#ifndef AUTHOR_H_INCLUDED
#define AUTHOR_H_INCLUDED

#include "RELATION.H"
#include <string>
#include <iostream>
using namespace std;

typedef string infotype_penulis;
typedef struct ElmParent *adrParent;

struct ElmParent {
    infotype_penulis info;
    adrParent next;
    adrParent prev;
    adrRelation firstRelation;
};

struct HeaderParent {
    adrParent First;
    adrParent Last;
};

void createListParent(HeaderParent &HP);
adrParent alokasiParent(infotype_penulis infoPenulis);
void insertLastParent(HeaderParent &HP, adrParent P);
adrParent searchPenulis(HeaderParent HP, infotype_penulis namaPenulis);
void deletePenulis(HeaderParent &HP, infotype_penulis namaPenulis);
void tampilkanBukuPenulis(HeaderParent HP, infotype_penulis namaPenulis);
void tampilkanSemua(HeaderParent HP, HeaderChild HC);

#endif // AUTHOR_H_INCLUDED