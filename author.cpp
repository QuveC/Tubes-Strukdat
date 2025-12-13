#include "book.h"
#include "author.h"
#include "relation.h"
void createListParent(HeaderParent &HP) {
    HP.First = NULL;
    HP.Last = NULL;
}

adrParent alokasiParent(infotype_penulis infoPenulis) {
    adrParent P = new ElmParent;
    P->info = infoPenulis;
    P->next = NULL; 
    P->prev = NULL;
    P->firstRelation = NULL;
    return P;
}

adrParent searchPenulis(HeaderParent HP, infotype_penulis namaPenulis) {
    adrParent P = HP.First;
    while (P != NULL) {
        if (P->info == namaPenulis) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void insertLastParent(HeaderParent &HP, adrParent P) {
    if (HP.First == NULL) {
        HP.First = P;
        HP.Last = P;
    } else {
        HP.Last->next = P;
        P->prev = HP.Last;
        HP.Last = P;
    }
}

void tampilkanBukuPenulis(HeaderParent HP, infotype_penulis namaPenulis) {
    adrParent P = searchPenulis(HP, namaPenulis);

    if (P == NULL) {
        cout << "Penulis dengan nama " << namaPenulis << " tidak ditemukan." << endl;
        return;
    }

    cout << "---------------------------------------" << endl;
    cout << "Buku oleh Penulis: " << P->info << endl;

    adrRelation R = P->firstRelation;
    if (R == NULL) {
        cout << "Penulis ini belum menulis buku." << endl;
        return;
    }   

    int i = 1;
    while (R != NULL) {
        cout << i << ". Judul: " << R->BookRelation->info.judul
             << " | Tahun: " << R->BookRelation->info.tahunTerbit
             << " | Kategori: " << R->BookRelation->info.kategori << endl;
        R = R->next;
        i++;
    }
    cout << "---------------------------------------" << endl;
}

void tampilkanSemua(HeaderParent HP, HeaderChild HC) {
    cout << "=======================================" << endl;
    cout << "          DAFTAR SELURUH PENULIS" << endl;
    cout << "=======================================" << endl;

    adrParent P = HP.First;
    if (P == NULL) {
        cout << "List Penulis kosong." << endl;
        return;
    }

    while (P != NULL) {
        tampilkanBukuPenulis(HP, P->info);
        P = P->next;
    }
    cout << "=======================================" << endl;
}

void deletePenulis(HeaderParent &HP, infotype_penulis namaPenulis) {
    adrParent P = searchPenulis(HP, namaPenulis);
    if (P == NULL) {
        cout << "Penulis " << namaPenulis << " tidak ditemukan." << endl;
        return;
    }

    adrRelation R = P->firstRelation;
    while (R != NULL) {
        adrRelation tempR = R;
        R = R->next;
        delete tempR;
    }
    P->firstRelation = NULL;

    if (P == HP.First && P == HP.Last) {
        HP.First = NULL;
        HP.Last = NULL;
    } else if (P == HP.First) {
        HP.First = P->next;
        HP.First->prev = NULL;
    } else if (P == HP.Last) {
        HP.Last = P->prev;
        HP.Last->next = NULL;
    } else {
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }

    delete P;
    cout << "Penulis " << namaPenulis << " beserta seluruh relasi bukunya berhasil dihapus." << endl;
}



int countBook(adrParent HC){
    adrRelation B = HC->firstRelation;
    int count = 0;
    while (!B) {
        count++;
        B = B->next;
    }
    return count;
}




void topThree(HeaderParent HP){
    adrParent top1, top2, top3, P;
    top1 = HP.First;
    top2 = HP.First;
    top3 = HP.First;
    P = top1->next;

    while(!P){
        if (countBook(top1) < countBook(P)) {
        top3 = top2;
        top2 = top1;
        top1 = P;
        }
        P = P->next;
    }
    cout << top1->info;
}