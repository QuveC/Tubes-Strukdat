#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "book.h" 

using namespace std;


typedef struct ElmParent *adrParent;

typedef struct ElmRelation *adrRelation;

struct ElmRelation {
    adrChild BookRelation;
    adrRelation next;
    adrRelation prev;
};

adrRelation alokasiRelation(adrChild C);
void tambahRelasi(adrParent P, adrChild C);
void deleteRelasi(adrParent P, string judulBuku);

#endif