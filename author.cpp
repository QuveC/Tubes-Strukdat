#include "author.h"
#include "relation.h"

void createListParent(HeaderParent &HP) {
    /* I.S. List HP sembarang. */
    /* F.S. List HP terinisialisasi dengan First dan Last bernilai nullptr. */
    HP.First = nullptr;
    HP.Last = nullptr;
}

adrParent alokasiParent(infotype_penulis infoPenulis) {
    /* I.S. infoPenulis terdefinisi. */
    /* F.S. Mengembalikan alamat elemen baru dengan info berisi infoPenulis, 
            next, prev, dan firstRelation bernilai nullptr. */
    adrParent P = new ElmParent;
    P->info = infoPenulis;
    P->next = nullptr; 
    P->prev = nullptr;
    P->firstRelation = nullptr;
    return P;
}

adrParent searchPenulis(HeaderParent HP, infotype_penulis namaPenulis) {
    /* I.S. List HP terdefinisi dan namaPenulis yang dicari terdefinisi. */
    /* F.S. Mengembalikan alamat (P) jika nama ditemukan, atau nullptr jika tidak ditemukan. */
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
    /* I.S. List HP terdefinisi (bisa kosong) dan adrParent P sudah dialokasi. */
    /* F.S. Elemen P ditambahkan sebagai elemen terakhir pada list HP (Double Linked List). */
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
    /* I.S. List HP terdefinisi dan namaPenulis terdefinisi. */
    /* F.S. Menampilkan daftar buku yang terelasi dengan penulis tersebut ke layar. */
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
    /* I.S. List HP dan HC terdefinisi. */
    /* F.S. Menampilkan seluruh penulis beserta daftar buku yang mereka miliki. */
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

bool searchAuthor(HeaderParent HP, infotype_penulis namaPenulis){
    /* I.S. List HP terdefinisi. */
    /* F.S. Mengembalikan true jika penulis ditemukan, false jika tidak. */
    return searchPenulis(HP, namaPenulis) != nullptr;
}

void deletePenulis(HeaderParent &HP, HeaderChild &HC, infotype_penulis namaPenulis) {
    /* I.S. List HP dan HC terdefinisi. namaPenulis yang akan dihapus terdefinisi. */
    /* F.S. Penulis dihapus dari List HP. Seluruh buku (Child) yang berelasi dengan penulis tersebut
    juga dihapus dari List HC (Cascade Delete). Relasi diputus. */
    
    adrParent P = searchPenulis(HP, namaPenulis); 
    
    if (P != nullptr) {
        adrRelation R = P->firstRelation;
        while (R != nullptr) {
            adrChild bukuHapus = R->BookRelation;
            
            if (bukuHapus == HC.first) {
                HC.first = bukuHapus->next;
            } else {
                adrChild prevC = HC.first;
                while (prevC != nullptr && prevC->next != bukuHapus) {
                    prevC = prevC->next;
                }
                if (prevC != nullptr) {
                    prevC->next = bukuHapus->next;
                }
            }
            
            bukuHapus->next = nullptr; 
            R = R->next;
        }

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
        cout << "Penulis " << namaPenulis << " dan seluruh bukunya berhasil dihapus." << endl;
    } else {
        cout << "Penulis tidak ditemukan." << endl;
    }
}

int countBook(adrParent P) {
    /* I.S. adrParent P terdefinisi. */
    /* F.S. Mengembalikan jumlah relasi buku (integer) yang dimiliki oleh penulis P. */
    adrRelation B = P->firstRelation;
    int count = 0;
    while (B != nullptr) {
        count++;
        B = B->next;
    }
    return count;
}

void topThree(HeaderParent HP) {
    /* I.S. List HP terdefinisi. */
    /* F.S. Menampilkan 3 penulis dengan jumlah buku terbanyak. */
    if (HP.First == nullptr) {
        cout << "Tidak ada penulis." << endl;
        return;
    }

    adrParent top1 = nullptr, top2 = nullptr, top3 = nullptr;
    adrParent P = HP.First;

    while (P != nullptr) {
        int count = countBook(P);

        if (top1 == nullptr || count > countBook(top1)) {
            top3 = top2;
            top2 = top1;
            top1 = P;
        } else if (top2 == nullptr || count > countBook(top2)) {
            top3 = top2;
            top2 = P;
        } else if (top3 == nullptr || count > countBook(top3)) {
            top3 = P;
        }
        P = P->next;
    }

    cout << "\n=== TOP 3 PENULIS (Terbanyak) ===\n";
    if (top1) cout << "1. " << top1->info << " (" << countBook(top1) << " buku)\n";
    if (top2) cout << "2. " << top2->info << " (" << countBook(top2) << " buku)\n";
    if (top3) cout << "3. " << top3->info << " (" << countBook(top3) << " buku)\n";
}

void bottomthree(HeaderParent HP) {
    /* I.S. List HP terdefinisi. */
    /* F.S. Menampilkan 3 penulis dengan jumlah buku paling sedikit. */
    if (HP.First == nullptr) {
        cout << "Tidak ada penulis." << endl;
        return;
    }

    adrParent bot1 = nullptr, bot2 = nullptr, bot3 = nullptr;
    adrParent P = HP.First;

    while (P != nullptr) {
        int count = countBook(P);

        if (bot1 == nullptr || count < countBook(bot1)) {
            bot3 = bot2;
            bot2 = bot1;
            bot1 = P;
        } else if (bot2 == nullptr || count < countBook(bot2)) {
            bot3 = bot2;
            bot2 = P;
        } else if (bot3 == nullptr || count < countBook(bot3)) {
            bot3 = P;
        }
        P = P->next;
    }

    cout << "\n=== BOTTOM 3 PENULIS (Tersedikit) ===\n";
    if (bot1) cout << "1. " << bot1->info << " (" << countBook(bot1) << " buku)\n";
    if (bot2) cout << "2. " << bot2->info << " (" << countBook(bot2) << " buku)\n";
    if (bot3) cout << "3. " << bot3->info << " (" << countBook(bot3) << " buku)\n";
}

void displayWriter(HeaderParent HP) {
    /* I.S. List HP terdefinisi. */
    /* F.S. Menampilkan daftar seluruh nama penulis dan total buku yang mereka tulis. */
    if(HP.First == nullptr){
        cout << "List Penulis Kosong" << endl;
        return;
    }

    adrParent P = HP.First;
    int i = 1;

    while (P != nullptr){
        cout << i << ". " << P->info << " ( Jumlah Buku : " << countBook(P) << " )" << endl;
        P = P->next;
        i++;
    }
    cout << "=========================================================" << endl;
}