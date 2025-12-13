#include "book.h"
#include "author.h"
#include "relation.h"
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

    adrRelation q = P->firstRelation;

    while (q != NULL && q->BookRelation->info.judul != judulBuku) {
        q = q->next;
    }

    if (q == NULL) {
        cout << "Buku dengan judul " << judulBuku << " tidak ditemukan pada penulis " << P->info << "." << endl;
        return;
    }

    if (q == P->firstRelation) {
        P->firstRelation = q->next;
        if (P->firstRelation != NULL) {
            P->firstRelation->prev = NULL;
        }
    } else {
        q->prev->next = q->next;
        if (q->next != NULL) {
            q->next->prev = q->prev;
        }
    }

    delete q;
    cout << "Relasi buku " << judulBuku << " berhasil dihapus dari penulis " << P->info << "." << endl;
}