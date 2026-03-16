#include <stdio.h>
#include <string.h>

// 1. Struktur data yang berbeda penamaannya
struct AkunUser {
    char no_hp[15];
    long balance;
};

// 2. Fungsi pencarian yang mengembalikan urutan (index), bukan pointer
int cariIndexAkun(struct AkunUser arr[], int ukuran, const char* target_hp) {
    for(int i = 0; i < ukuran; i++) {
        // Jika nomor HP cocok, kembalikan posisi indeksnya
        if(strcmp(arr[i].no_hp, target_hp) == 0) {
            return i;
        }
    }
    return -1; // -1 artinya data tidak ditemukan
}