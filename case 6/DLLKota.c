
#include "DLLKota.h"

DLLNode* headDLL = NULL;

int quit = 0;

DLLNode* cariKota(const char* namaKota) {
    DLLNode* current = headDLL;
    while (current != NULL) {
        if (strcmp(current->namaKota, namaKota) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void tambahKota(const char* namaKota) {
    if (cariKota(namaKota)) {
        printf("Kota %s sudah ada.\n", namaKota);
        return;
    }

    DLLNode* baru = (DLLNode*)malloc(sizeof(DLLNode));
    strcpy(baru->namaKota, namaKota);
    baru->prev = baru->next = NULL;
    baru->headNama = NULL;

    if (!headDLL) {
        headDLL = baru;
    } else {
        DLLNode* tail = headDLL;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next = baru;
        baru->prev = tail;
    }

    printf("Kota %s berhasil ditambahkan.\n", namaKota);
    clearScreen();
}

void tambahNama(const char* namaKota, const char* namaOrang) {
    DLLNode* kota = cariKota(namaKota);
    if (!kota) {
        printf("Kota tidak ditemukan!\n");
        clearScreen();
        return;
    }

    SLLNode* baru = (SLLNode*)malloc(sizeof(SLLNode));
    strcpy(baru->nama, namaOrang);
    baru->next = NULL;

    if (!kota->headNama) {
        kota->headNama = baru;
    } else {
        SLLNode* temp = kota->headNama;
        while (temp->next)
            temp = temp->next;
        temp->next = baru;
    }

    printf("%s berhasil ditambahkan ke kota %s.\n", namaOrang, namaKota);
    clearScreen();
}

void hapusNamaDiKota(const char* namaKota) {
    DLLNode* kota = cariKota(namaKota);
    if (!kota) {
        printf("Kota tidak ditemukan!\n");
        clearScreen();
        return;
    }

    SLLNode* current = kota->headNama;
    while (current) {
        SLLNode* temp = current;
        current = current->next;
        free(temp);
    }
    kota->headNama = NULL;
    printf("Semua nama di kota %s dihapus.\n", namaKota);
    clearScreen();
}

void tampilkanData() {
    DLLNode* kota = headDLL;
    if (!kota) {
        printf("Belum ada data kota.\n");
        clearScreen();
        return;
    }

    while (kota) {
        printf("Kota: %s\n", kota->namaKota);
        SLLNode* nama = kota->headNama;
        if (!nama) {
            printf("  (tidak ada nama)\n");
        }
        while (nama) {
            printf("  - %s\n", nama->nama);
            nama = nama->next;
        }
        kota = kota->next;
    }
    
    clearScreen();
}

void hapusSemuaData() {
    DLLNode* kota = headDLL;
    while (kota) {
        hapusNamaDiKota(kota->namaKota);
        DLLNode* temp = kota;
        kota = kota->next;
        free(temp);
    }
    headDLL = NULL;
}

void menuTambahKota() {
    char nama[MAX_NAMA];
    printf("Masukkan nama kota: ");
    fgets(nama, MAX_NAMA, stdin);
    nama[strcspn(nama, "\n")] = 0;
    tambahKota(nama);
}

void menuTambahNama() {
    char kota[MAX_NAMA], nama[MAX_NAMA];
    printf("Masukkan nama kota: ");
    fgets(kota, MAX_NAMA, stdin);
    kota[strcspn(kota, "\n")] = 0;

    printf("Masukkan nama orang: ");
    fgets(nama, MAX_NAMA, stdin);
    nama[strcspn(nama, "\n")] = 0;

    tambahNama(kota, nama);
}

void menuHapusNama() {
    char kota[MAX_NAMA];
    printf("Masukkan nama kota: ");
    fgets(kota, MAX_NAMA, stdin);
    kota[strcspn(kota, "\n")] = 0;

    hapusNamaDiKota(kota);
}

void menuTampilkan() {
    tampilkanData();
}

void menuKeluar() {
    printf("Keluar dari program.\n");
    hapusSemuaData();
    quit = 1;
}

void clearScreen(){
    getchar();
    system("cls");
}