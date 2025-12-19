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
        cout << "Penulis " << namaPenulis << " tidak ditemukan." << endl;
        return;
    }

    cout << "---------------------------------------" << endl;
    cout << "Penulis: " << P->info << endl;

    adrRelation R = P->firstRelation;
    if (R == NULL) {
        cout << "   (Belum ada buku)" << endl;
    } 
    
    int i = 1;
    while (R != NULL) {
        cout << "   " << i << ". " << R->BookRelation->info.judul
             << " (" << R->BookRelation->info.tahunTerbit << ")" << endl;
        R = R->next;
        i++;
    }
    cout << "---------------------------------------" << endl;
}

void tampilkanSemua(HeaderParent HP, HeaderChild HC) {
    cout << "\n=== DAFTAR SELURUH DATA ===" << endl;
    adrParent P = HP.First;
    if (P == NULL) {
        cout << "List Penulis kosong." << endl;
        return;
    }
    while (P != NULL) {
        tampilkanBukuPenulis(HP, P->info);
        P = P->next;
    }
}

void deletePenulis(HeaderParent &HP, infotype_penulis namaPenulis) {
    adrParent P = searchPenulis(HP, namaPenulis);
    if (P == NULL) {
        cout << "Penulis tidak ditemukan." << endl;
        return;
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

    P->next = NULL;
    P->prev = NULL;

    cout << "Penulis berhasil dihapus (dilepas dari list)." << endl;
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