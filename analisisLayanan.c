#include <stdio.h>
#include <string.h>


struct AkunUser {
    char no_hp[15];
    long balance;
};

int cariIndexAkun(struct AkunUser arr[], int ukuran, const char* target_hp) {
    for(int i = 0; i < ukuran; i++) {
        if(strcmp(arr[i].no_hp, target_hp) == 0) {
            return i;
        }
    }
    return -1;
}

void prosesPindahSaldo(struct AkunUser db[], int ukuran_db, char* hp_asal, char* hp_tujuan, long nilai_transfer) {
    long tarif_admin = 2500; 
    
    int idx_asal = cariIndexAkun(db, ukuran_db, hp_asal);
    int idx_tujuan = cariIndexAkun(db, ukuran_db, hp_tujuan);
    
    if(idx_asal == -1 || idx_tujuan == -1) {
        printf("[SISTEM] Transaksi dibatalkan: Nomor tidak terdaftar di jaringan.\n");
        return;
    }
    
    long total_potongan = nilai_transfer + tarif_admin;
    
    if(db[idx_asal].balance >= total_potongan) {
        db[idx_asal].balance -= total_potongan;
        db[idx_tujuan].balance += nilai_transfer;
        
        printf("[SISTEM] Sukses! Anda membagikan pulsa Rp%ld ke %s.\n", nilai_transfer, hp_tujuan);
        printf("[SISTEM] Sisa pulsa Anda sekarang: Rp%ld\n", db[idx_asal].balance);
    } else {
        printf("[SISTEM] Gagal: Pulsa Anda tidak cukup.\n");
        printf("         Butuh Rp%ld, Saldo Anda Rp%ld.\n", total_potongan, db[idx_asal].balance);
    }
}