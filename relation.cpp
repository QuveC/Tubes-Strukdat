#include "relation.h"
#include "author.h" 

adrRelation alokasiRelation(adrChild C) {
    adrRelation R = new ElmRelation;
    R->BookRelation = C;
    R->next = NULL;
    R->prev = NULL;
    return R;
}

void tambahRelasi(adrParent P, adrChild C) {
    adrRelation R = alokasiRelation(C);

    if (P->firstRelation == NULL) {
        P->firstRelation = R;
    } else {
        adrRelation LastR = P->firstRelation;
        while (LastR->next != NULL) {
            LastR = LastR->next;
        }

        LastR->next = R;
        R->prev = LastR;
    }
    cout << "Relasi antara penulis " << P->info << " dan buku " << C->info.judul << " berhasil ditambahkan." << endl;
}

void deleteRelasi(adrParent P, string judulBuku) {
    if (P == NULL || P->firstRelation == NULL) {
        cout << "Penulis atau List Relasi kosong." << endl;
        return;
    }

    adrRelation Curr = P->firstRelation;

    while (Curr != NULL && Curr->BookRelation->info.judul != judulBuku) {
        Curr = Curr->next;
    }

    if (Curr == NULL) {
        cout << "Buku dengan judul " << judulBuku << " tidak ditemukan pada penulis " << P->info << "." << endl;
        return;
    }

    if (Curr == P->firstRelation) {
        P->firstRelation = Curr->next;
        if (P->firstRelation != NULL) {
            P->firstRelation->prev = NULL;
        }
    } else {
        Curr->prev->next = Curr->next;
        if (Curr->next != NULL) {
            Curr->next->prev = Curr->prev;
        }
    }

    delete Curr;
    cout << "Relasi buku " << judulBuku << " berhasil dihapus dari penulis " << P->info << "." << endl;
}