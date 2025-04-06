#include "ArrayToSLL.h"

int main() {
    void (*tab[4]) () = {menuTambahNama, menuHapusNama, menuTampilkan, menuKeluar};
    int pilihan;
    

    do {
        printf("List Kota :\n1. Bandung\n2. Jakarta\n3. Surabaya\n4. Yogyakarta\n5. Purwakarta");
        printf("\n=== MENU ===\n");
        printf("1. Tambah Nama ke Kota\n");
        printf("2. Hapus Semua Nama dari Kota\n");
        printf("3. Tampilkan Semua Data\n");
        printf("4. Keluar\n");
        printf("Pilih (1-4): ");

        pilihan = getchar();
        getchar(); // buang newline

        if (pilihan >= '1' && pilihan <= '4') {
            tab[pilihan - '1']();
        } else {
            printf("Pilihan tidak valid!\n");
        }
    } while (!quit);

    return 0;
}
