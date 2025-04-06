#ifndef ARRAYTOSLL_H
#define ARRAYTOSLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KOTA 5
#define MAX_NAMA 50
#define true 1
#define false 0

// Struct untuk node linked list nama
typedef struct Node {
    char nama[MAX_NAMA];
    struct Node* next;
} Node;

// Struct untuk kota
typedef struct {
    char kota[MAX_NAMA];
    Node* head;
} Kota;

extern Kota daftarKota[MAX_KOTA];
extern int quit;



int cariIndexKota(const char* namaKota);
void tambahNama(Kota* k, const char* nama);
void hapusNamaDiKota(Kota* k);
void tampilkanSemua();
void menuTambahNama();
void menuHapusNama();
void menuTampilkan();
void menuKeluar();


#endif