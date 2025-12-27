#include "author.h"
#include "relation.h"

void createListParent(HeaderParent &HP) {
    HP.First = nullptr;
    HP.Last = nullptr;
}

adrParent alokasiParent(infotype_penulis infoPenulis) {
    adrParent P = new ElmParent;
    P->info = infoPenulis;
    P->next = nullptr; 
    P->prev = nullptr;
    P->firstRelation = nullptr;
    return P;
}

adrParent searchPenulis(HeaderParent HP, infotype_penulis namaPenulis) {
    adrParent P = HP.First;
    while (P != nullptr) {
        if (P->info == namaPenulis) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertLastParent(HeaderParent &HP, adrParent P) {
    if (HP.First == nullptr) {
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

    if (P == nullptr) {
        cout << "Penulis " << namaPenulis << " tidak ditemukan." << endl;
        return;
    }

    cout << "---------------------------------------" << endl;
    cout << "Penulis: " << P->info << endl;

    adrRelation R = P->firstRelation;
    if (R == nullptr) {
        cout << "   (Belum ada buku)" << endl;
    } 
    
    int i = 1;
    while (R != nullptr) {
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
    if (P == nullptr) {
        cout << "List Penulis kosong." << endl;
        return;
    }
    while (P != nullptr) {
        tampilkanBukuPenulis(HP, P->info);
        P = P->next;
    }
}

bool searchAuthor(HeaderParent HC){

}
void deletePenulis(HeaderParent &HP, infotype_penulis namaPenulis) {
    adrParent P = searchPenulis(HP, namaPenulis); 
    
    if (P != nullptr) {
        P->firstRelation = nullptr; 
        
        if (P == HP.First) {
            if (HP.First == HP.Last) { 
                HP.First = nullptr;
                HP.Last = nullptr;
            } else {
                HP.First = P->next;
                HP.First->prev = nullptr;
                P->next = nullptr;
            }

        } else if (P == HP.Last) {
            HP.Last = P->prev;
            HP.Last->next = nullptr;
            P->prev = nullptr; 

        } else {
            adrParent pro = P->prev; 
            adrParent nextNode = P->next; 
            pro->next = nextNode;
            nextNode->prev = pro;
            
            P->next = nullptr;
            P->prev = nullptr;
        }

        cout << "Penulis " << namaPenulis << " berhasil dihapus dari list." << endl;

    } else {
        cout << "Penulis tidak ditemukan." << endl;
    }
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
    if (HP.First == nullptr) {
            cout << "Tidak ada penulis." << endl;
            return;
        }

        adrParent top1 = nullptr, top2 = nullptr, top3 = nullptr;
        adrParent P = HP.First;
    
    cout << countBook(P) << endl;

        while (P != nullptr) {
            int count = countBook(P);

            if (top1 == nullptr || count > countBook(top1)) {
                top3 = top2;
                top2 = top1;
                top1 = P;
            }
            else if (top2 == nullptr || count > countBook(top2)) {
                top3 = top2;
                top2 = P;
            }
            else if (top3 == nullptr || count > countBook(top3)) {
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
    if (HP.First == nullptr) {
            cout << "Tidak ada penulis." << endl;
            return;
        }

        adrParent top1 = nullptr, top2 = nullptr, top3 = nullptr;
        adrParent P = HP.First;
    
        cout << countBook(P) << endl;

        while (P != nullptr) {
            int count = countBook(P);

            if (top1 == nullptr || count < countBook(top1)) {
                top3 = top2;
                top2 = top1;
                top1 = P;
            }
            else if (top2 == nullptr || count < countBook(top2)) {
                top3 = top2;
                top2 = P;
            }
            else if (top3 == nullptr || count < countBook(top3)) {
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
        cout<<i<< " . " << P->info<<" ( Jumlah Buku : " << countBook(P)<<" )"<<endl;
        P = P->next;
        i++;
    }
    cout<<"========================================================="<<endl;
}