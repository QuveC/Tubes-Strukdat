#include "book.h"

void createListChild(HeaderChild &HC) {
/* I.S. List HC sembarang. */
/* F.S. List HC terbentuk dengan HC.first = NULL. */
    HC.first = nullptr;
}

adrChild alokasiChild(infotype_buku infoBuku) {
/* I.S. Variabel infoBuku berisi data buku yang valid. */
/* F.S. Mengembalikan alamat node baru (adrChild) yang berisi data infoBuku. */
    adrChild C = new ElmChild;
    C->info = infoBuku;
    C->next = nullptr;
    return C;
}

adrChild searchBuku(HeaderChild HC, string judulBuku) {
/* I.S. List HC terdefinisi dan string judulBuku sudah ditentukan. */
/* F.S. Mengembalikan alamat elemen (C) jika judul ditemukan, atau NULL jika tidak ditemukan. */
    adrChild C = HC.first;
    while (C != nullptr) {
        if (C->info.judul == judulBuku) {
            return C;
        }
        C = C->next;
    }
    return nullptr;
}

void insertLastChild(HeaderChild &HC, adrChild C) {
 /* I.S. List HC terdefinisi (bisa kosong) dan adrChild C sudah dialokasi. */
/* F.S. Elemen C ditambahkan sebagai elemen terakhir pada list HC. */
    if (HC.first == nullptr) {
        HC.first = C;
    } else {
        adrChild Q = HC.first; 
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        
        Q->next = C;
    }
}

void displayBook(HeaderChild HC){
/* I.S. List HC terdefinisi (mungkin kosong). */
/* F.S. Seluruh informasi buku dalam list tercetak ke layar secara berurutan. */
    cout << "\n=== DAFTAR SEMUA BUKU ===" << endl;
    if(HC.first == nullptr){
        cout << "(Kosong)" << endl;
        return;
    }

    adrChild C = HC.first;
    int i = 1;

    while (C != nullptr){
        cout << i << ". " << C->info.judul 
             << " (" << C->info.tahunTerbit << ") - " 
             << C->info.kategori << endl;
        C = C->next;
        i++;
    }
    cout << "=========================================================" << endl;
}

int countBook(HeaderChild HC) {
/* I.S. List HC terdefinisi (mungkin kosong). */
/* F.S. Mengembalikan nilai integer berupa total jumlah node/elemen di dalam list. */
    int count = 0;
    adrChild C = HC.first;
    while(C != nullptr) {
        count++;
        C = C->next;
    }
    return count;
}