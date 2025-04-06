#include "ArrayToSLL.h"

Kota daftarKota[MAX_KOTA] = {
    {"Bandung", NULL},
    {"Jakarta", NULL},
    {"Surabaya", NULL},
    {"Yogyakarta", NULL},
    {"Purwakarta", NULL}
};

int quit = 0;


int cariIndexKota(const char* namaKota) {
    for (int i = 0; i < MAX_KOTA; i++) {
        if (strcmp(daftarKota[i].kota, namaKota) == 0)
            return i;
    }
    return -1;
}

void tambahNama(Kota* k, const char* nama) {
    Node* baru = (Node*) malloc(sizeof(Node));
    strcpy(baru->nama, nama);
    baru->next = NULL;

    if (k->head == NULL) {
        k->head = baru;
    } else {
        Node* temp = k->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }
}

void hapusNamaDiKota(Kota* k) {
    Node* current = k->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    k->head = NULL;
}

void tampilkanSemua() {
    for (int i = 0; i < MAX_KOTA; i++) {
        printf("Kota: %s\n", daftarKota[i].kota);
        Node* current = daftarKota[i].head;
        if (!current) {
            printf("  (tidak ada data nama)\n");
        }
        while (current != NULL) {
            printf("  - %s\n", current->nama);
            current = current->next;
        }
    }
}

void menuTambahNama() {
    char namaKota[MAX_NAMA], namaOrang[MAX_NAMA];
    printf("Masukkan nama kota: ");
    fgets(namaKota, MAX_NAMA, stdin);
    namaKota[strcspn(namaKota, "\n")] = 0;

    printf("Masukkan nama orang: ");
    fgets(namaOrang, MAX_NAMA, stdin);
    namaOrang[strcspn(namaOrang, "\n")] = 0;

    int idx = cariIndexKota(namaKota);
    if (idx != -1) {
        tambahNama(&daftarKota[idx], namaOrang);
        printf("Nama berhasil ditambahkan ke kota %s.\n", namaKota);
    } else {
        printf("Kota tidak ditemukan.\n");
    }
    getchar();
    system("cls");
}

void menuHapusNama() {
    char namaKota[MAX_NAMA];
    printf("Masukkan nama kota yang akan dihapus datanya: ");
    fgets(namaKota, MAX_NAMA, stdin);
    namaKota[strcspn(namaKota, "\n")] = 0;

    int idx = cariIndexKota(namaKota);
    if (idx != -1) {
        hapusNamaDiKota(&daftarKota[idx]);
        printf("Semua nama di kota %s telah dihapus.\n", namaKota);
    } else {
        printf("Kota tidak ditemukan.\n");
    }
    getchar();
    system("cls");
}

void menuTampilkan() {
    tampilkanSemua();
    getchar();
    system("cls");
}

void menuKeluar() {
    printf("Keluar dari program.\n");
    quit = true;
    // Bebaskan semua memori
    for (int i = 0; i < MAX_KOTA; i++) {
        hapusNamaDiKota(&daftarKota[i]);
    }
}

