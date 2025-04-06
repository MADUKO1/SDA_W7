#ifndef DLLKOTA_H
#define DLLKOTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMA 50
#define true 1
#define false 0

typedef struct SLLNode {
    char nama[MAX_NAMA];
    struct SLLNode* next;
} SLLNode;

typedef struct DLLNode {
    char namaKota[MAX_NAMA];
    struct DLLNode* prev;
    struct DLLNode* next;
    SLLNode* headNama;
} DLLNode;

extern DLLNode* headDLL;
extern int quit;

void tambahKota(const char* namaKota);
DLLNode* cariKota(const char* namaKota);
void tambahNama(const char* namaKota, const char* namaOrang);
void hapusNamaDiKota(const char* namaKota);
void tampilkanData();
void hapusSemuaData();
void menuTambahKota();
void menuTambahNama();
void menuHapusNama();
void menuTampilkan();
void menuKeluar();
void clearScreen();

#endif
