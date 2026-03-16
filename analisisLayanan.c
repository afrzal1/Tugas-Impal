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

int main() {
    // Inisialisasi Database
    struct AkunUser db_telkomsel[2] = {
        {"08111222333", 100000}, // Akun kamu
        {"08999888777", 5000}    // Akun temanmu
    };
    int jumlah_akun = 2;

    printf("========== TELKOMSEL *858# ==========\n");
    printf("Info Saldo Awal:\n");
    printf("- Pengirim : Rp%ld\n", db_telkomsel[0].balance);
    printf("- Penerima : Rp%ld\n", db_telkomsel[1].balance);
    printf("=====================================\n\n");

    // Mengeksekusi transfer senilai Rp 15.000
    printf("Mengeksekusi transfer Rp15000...\n");
    prosesPindahSaldo(db_telkomsel, jumlah_akun, "08111222333", "08999888777", 15000);

    printf("\n========== UPDATE SALDO ==========\n");
    printf("- Pengirim : Rp%ld\n", db_telkomsel[0].balance);
    printf("- Penerima : Rp%ld\n", db_telkomsel[1].balance);
    printf("==================================\n");

    return 0;
}