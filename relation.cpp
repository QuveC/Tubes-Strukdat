#include "relation.h"
#include "author.h" 
using namespace std;

adrRelation alokasiRelation(adrChild C) {
/* I.S. adrChild C terdefinisi (alamat buku yang akan direlasikan). */
/* F.S. Mengembalikan alamat relasi (adrRelation) baru yang menunjuk ke C, dengan pointer next dan prev bernilai NULL. */
    adrRelation R = new ElmRelation;
    R->BookRelation = C;
    R->next = nullptr;
    R->prev = nullptr;
    return R;
}

void tambahRelasi(adrParent P, adrChild C) {
/* I.S. adrParent P dan adrChild C terdefinisi dan tidak NULL. */
/* F.S. Terbentuk node relasi baru yang menghubungkan P ke C, = node diletakkan di akhir list relasi milik P (Insert Last). */
    adrRelation R = alokasiRelation(C);

    if (P->firstRelation == nullptr) {
        P->firstRelation = R;
    } else {
        adrRelation LastR = P->firstRelation;
        while (LastR->next != nullptr) {
            LastR = LastR->next;
        }
        LastR->next = R;
        R->prev = LastR;
    }
    cout << "Relasi berhasil ditambahkan." << endl;
}

void deleteRelasi(adrParent P, string judulBuku) {
/* I.S. adrParent P terdefinisi, string judulBuku terdefinisi sebagai kunci pencarian. */
/* F.S. Jika ditemukan, node relasi yang menunjuk ke buku dengan judul tersebut dihapus dari list relasi P dan memori diatur kembali. */
    if (P == nullptr || P->firstRelation == nullptr) {
        cout << "List Relasi kosong." << endl;
        return;
    }

    adrRelation q = P->firstRelation;

    while (q != nullptr && q->BookRelation->info.judul != judulBuku) {
        q = q->next;
    }

    if (q == nullptr) {
        cout << "Buku tidak ditemukan pada penulis ini." << endl;
        return;
    }

    if (q == P->firstRelation) {
        P->firstRelation = q->next;
        if (P->firstRelation != nullptr) {
            P->firstRelation->prev = nullptr;
        }
    } else {
        q->prev->next = q->next;
        if (q->next != nullptr) {
            q->next->prev = q->prev;
        }
    }
    q->next = nullptr;
    q->prev = nullptr;
    q->BookRelation = nullptr;    
    cout << "Relasi buku berhasil dilepas." << endl;
}