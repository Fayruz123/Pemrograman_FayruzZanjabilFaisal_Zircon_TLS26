#include <iostream>

// Fungsi manual untuk menghitung panjang string
int hitungPanjang(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fungsi manual untuk mengonversi huruf kecil ke huruf besar
char keHurufBesar(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Fungsi manual untuk mendapatkan nilai posisi alfabet (A=1, B=2, ..., Z=26)
int dapatkanNilaiHuruf(char c) {
    c = keHurufBesar(c);
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    }
    return 0;
}

// Fungsi manual untuk menggeser karakter sesuai nilai pergeseran (1-26) dengan wrap-around
char geserKarakter(char c, int nilaiGeser) {
    c = keHurufBesar(c);
    if (c < 'A' || c > 'Z') {
        return c; // Jika bukan huruf alfabet, kembalikan apa adanya
    }
    
    int posisiAwal = c - 'A'; // Rentang 0 - 25
    int posisiBaru = (posisiAwal + nilaiGeser) % 26;
    return (char)('A' + posisiBaru);
}

// Fungsi utama proses enkripsi pesan
void prosesSandi(const char pesanAsli[], char pesanSandi[]) {
    int len = hitungPanjang(pesanAsli);
    if (len == 0) return;

    // Huruf pertama tidak mengalami perubahan posisi (hanya disesuaikan kapitalisasinya)
    pesanSandi[0] = keHurufBesar(pesanAsli[0]);

    // Setiap huruf berikutnya digeser sebanyak nilai huruf sebelum pergeseran
    for (int i = 1; i < len; i++) {
        int nilaiSebelumnya = dapatkanNilaiHuruf(pesanAsli[i - 1]);
        pesanSandi[i] = geserKarakter(pesanAsli[i], nilaiSebelumnya);
    }
    pesanSandi[len] = '\0'; // Menutup C-string
}

int main() {
    char pesanAsli[1000];
    char pesanSandi[1000];

    std::cout << "Masukkan Pesan Asli : ";
    std::cin >> pesanAsli;

    prosesSandi(pesanAsli, pesanSandi);

    std::cout << "Hasil Pesan Sandi  : " << pesanSandi << std::endl;

    return 0;
}