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
    while (B != nullptr) {
        count++;
        B = B->next;
    }
    return count;
}

void topThree(HeaderParent HP){
    if (HP.First == NULL) {
            cout << "Tidak ada penulis." << endl;
            return;
        }

        adrParent top1 = NULL, top2 = NULL, top3 = NULL;
        adrParent P = HP.First;
    
    cout << countBook(P) << endl;

        while (P != NULL) {
            int count = countBook(P);

            if (top1 == NULL || count > countBook(top1)) {
                top3 = top2;
                top2 = top1;
                top1 = P;
            }
            else if (top2 == NULL || count > countBook(top2)) {
                top3 = top2;
                top2 = P;
            }
            else if (top3 == NULL || count > countBook(top3)) {
                top3 = P;
            }

            P = P->next;
        }

        cout << "\n=== TOP 3 PENULIS ===\n";

        if (top1) cout << "1. " << top1->info << " (" << countBook(top1) << " buku)\n";
        if (top2) cout << "2. " << top2->info << " (" << countBook(top2) << " buku)\n";
        if (top3) cout << "3. " << top3->info << " (" << countBook(top3) << " buku)\n";
}

void bottomthree(HeaderParent HP){
    if (HP.First == NULL) {
            cout << "Tidak ada penulis." << endl;
            return;
        }

        adrParent top1 = NULL, top2 = NULL, top3 = NULL;
        adrParent P = HP.First;
    
        cout << countBook(P) << endl;

        while (P != NULL) {
            int count = countBook(P);

            if (top1 == NULL || count < countBook(top1)) {
                top3 = top2;
                top2 = top1;
                top1 = P;
            }
            else if (top2 == NULL || count < countBook(top2)) {
                top3 = top2;
                top2 = P;
            }
            else if (top3 == NULL || count < countBook(top3)) {
                top3 = P;
            }

            P = P->next;
        }

        cout << "\n=== TOP 3 PENULIS ===\n";

        if (top1) cout << "1. " << top1->info << " (" << countBook(top1) << " buku)\n";
        if (top2) cout << "2. " << top2->info << " (" << countBook(top2) << " buku)\n";
        if (top3) cout << "3. " << top3->info << " (" << countBook(top3) << " buku)\n";
}

void displayWriter(HeaderParent HP){
    if(HP.First == nullptr){
        cout<<"kosong"<<endl;
    }

    adrParent P = HP.First;
    int i = 1;

    while (P != nullptr){
        cout<<i<< " . " << P->info<<endl;
        P = P->next;
        i++;
    }
    cout<<"========================================================="<<endl;
}