#include <stdio.h>
#include "DLLKota.h"

int main() {

    
    void (*menu[])() = {
        menuTambahKota,
        menuTambahNama,
        menuHapusNama,
        menuTampilkan,
        menuKeluar
    };

    char pilihan;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Nama ke Kota\n");
        printf("3. Hapus Semua Nama dari Kota\n");
        printf("4. Tampilkan Semua Data\n");
        printf("5. Keluar\n");
        printf("Pilih (1-5): ");

        pilihan = getchar();
        getchar(); // buang newline

        if (pilihan >= '1' && pilihan <= '5') {
            menu[pilihan - '1']();
        } else {
            printf("Pilihan tidak valid.\n");
        }

    } while (!quit);

    return 0;
}
