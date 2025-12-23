#include <iostream>
#include <string>
#include "book.h"
#include "author.h"
#include "relation.h"

using namespace std;

int main() {
    HeaderParent HP;
    createListParent(HP);
    
    HeaderChild HC;
    createListChild(HC);

    int pilihan;
    string namaPenulis, judulBuku, kategori;
    int tahun;
    
    adrParent P;
    adrChild C;

    insertLastParent(HP, alokasiParent("J.K._Rowling"));
    insertLastParent(HP, alokasiParent("Tere_Liye"));
    insertLastParent(HP, alokasiParent("Raditya_Dika"));

    infotype_buku b1;
    b1.judul="Harry_Potter_1"; b1.tahunTerbit="1997"; b1.kategori="Fantasy";
    insertLastChild(HC, alokasiChild(b1));

    infotype_buku b2;
    b2.judul="Harry_Potter_2"; b2.tahunTerbit="1998"; b2.kategori="Fantasy";
    insertLastChild(HC, alokasiChild(b2));

    infotype_buku b3;
    b3.judul="Harry_Potter_3"; b3.tahunTerbit="1999"; b3.kategori="Fantasy";
    insertLastChild(HC, alokasiChild(b3));

    infotype_buku b4; 
    b4.judul="Bumi"; b4.tahunTerbit="2014"; b4.kategori="Fiksi";
    insertLastChild(HC, alokasiChild(b4));

    infotype_buku b5; 
    b5.judul="Bulan"; b5.tahunTerbit="2015"; b5.kategori="Fiksi";
    insertLastChild(HC, alokasiChild(b5));

    infotype_buku b6; 
    b6.judul="Kambing_Jantan"; b6.tahunTerbit="2005"; b6.kategori="Komedi";
    insertLastChild(HC, alokasiChild(b6));

    tambahRelasi(searchPenulis(HP, "J.K._Rowling"), searchBuku(HC, "Harry_Potter_1"));
    tambahRelasi(searchPenulis(HP, "J.K._Rowling"), searchBuku(HC, "Harry_Potter_2"));
    tambahRelasi(searchPenulis(HP, "J.K._Rowling"), searchBuku(HC, "Harry_Potter_3"));
    tambahRelasi(searchPenulis(HP, "Tere_Liye"), searchBuku(HC, "Bumi"));
    tambahRelasi(searchPenulis(HP, "Tere_Liye"), searchBuku(HC, "Bulan"));
    tambahRelasi(searchPenulis(HP, "Raditya_Dika"), searchBuku(HC, "Kambing_Jantan"));
  
   
     while (true) {
        cout << "\n+==========================================+" << endl;
        cout << "| NO |       APLIKASI PERPUSTAKAAN         |" << endl;
        cout << "+====+=====================================+" << endl;
        cout << "| 1  | Tambah Penulis                      |" << endl;
        cout << "| 2  | Tambah Buku                         |" << endl;
        cout << "| 3  | Hubungkan (Relasi)                  |" << endl;
        cout << "+----+-------------------------------------+" << endl;
        cout << "| 4  | Tampilkan Semua                     |" << endl;
        cout << "| 5  | Tampilkan Buku                      |" << endl;
        cout << "| 6  | Tampilkan Penulis                   |" << endl;
        cout << "| 7  | Cari Buku Penulis                   |" << endl;
        cout << "| 8  | Tampilkan Top 3 Penulis             |" << endl;
        cout << "| 9  | Tampilkan 3 Penulis terendah       |" << endl;
        cout << "+----+-------------------------------------+" << endl;
        cout << "| 10  | Hapus Penulis                      |" << endl;
        cout << "| 11  | Hapus Relasi Buku                  |" << endl;
        cout << "+----+-------------------------------------+" << endl;
        cout << "| 0  | Keluar                              |" << endl;
        cout << "+==========================================+" << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilihan;

      switch (pilihan) {
            case 1:
                cout << "Nama Penulis: "; cin >> namaPenulis;
                insertLastParent(HP, alokasiParent(namaPenulis));
                break;

            case 2:
                cout << "Judul Buku: "; cin >> judulBuku;
                cout << "Tahun: "; cin >> tahun;
                cout << "Kategori: "; cin >> kategori;
                {
                    infotype_buku dataBuku;
                    dataBuku.judul = judulBuku;
                    dataBuku.tahunTerbit = tahun;
                    dataBuku.kategori = kategori;
                    insertLastChild(HC, alokasiChild(dataBuku));
                }
                break;

            case 3:
                cout << "Nama Penulis: "; 
                cin >> namaPenulis;
                cout << "Judul Buku: "; 
                cin >> judulBuku;
                P = searchPenulis(HP, namaPenulis);
                C = searchBuku(HC, judulBuku);
                if (P != NULL && C != NULL) {
                    tambahRelasi(P, C);
                } else {
                    cout << "Penulis atau Buku tidak ditemukan!" << endl;
                }
                break;

            case 4:
                tampilkanSemua(HP, HC);
                break;

            case 5:
                cout << "Daftar Seluruh Buku:" << endl;
                displayBook(HC); 
                break;

            case 6:
                cout << "Daftar Seluruh Penulis:" << endl;
                displayWriter(HP);
                break;

            case 7:
                cout << "Nama Penulis yang dicari: "; 
                cin >> namaPenulis;
                tampilkanBukuPenulis(HP, namaPenulis);
                break;

            case 8:
                topThree(HP);
                break;

            case 9:
                bottomthree(HP);
                break;

            case 10:
                cout << "Nama Penulis yang akan dihapus: "; 
                cin >> namaPenulis;
                deletePenulis(HP, namaPenulis);
                break;

            case 11:
                cout << "Nama Penulis: "; 
                cin >> namaPenulis;
                cout << "Judul Buku yang akan diputus relasinya: "; 
                cin >> judulBuku;
                P = searchPenulis(HP, namaPenulis);
                if (P != NULL) {
                    deleteRelasi(P, judulBuku);
                } else {
                    cout << "Penulis tidak ditemukan." << endl;
                }
                break;

            case 0:
                cout << "Program selesai. Sampai jumpa!\n";
                return 0;

            default:
                cout << "Pilihan tidak tersedia!" << endl;
        }
    }

    return 0;
}
   
