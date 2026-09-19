#include <iostream>

int main() {
    int N, K;
    
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai hitungan awal (K): ";
    std::cin >> K;

    // Array untuk menyimpan status astronot (true = masih ada, false = dieliminasi)
    bool astronot[1000];
    for (int i = 0; i < N; i++) {
        astronot[i] = true;
    }

    int sisa_astronot = N;
    int indeks_sekarang = 0; // Memulai dari astronot pertama (posisi 0 / nomor 1)

    std::cout << "\nUrutan eliminasi astronot:\n";

    while (sisa_astronot > 1) {
        int langkah = 0;

        // Mencari astronot ke-K yang masih bertahan dalam lingkaran
        while (langkah < K) {
            if (astronot[indeks_sekarang]) {
                langkah++;
            }
            if (langkah < K) {
                indeks_sekarang = (indeks_sekarang + 1) % N;
            }
        }

        // Eliminasi astronot di posisi indeks_sekarang
        astronot[indeks_sekarang] = false;
        int nomor_dieliminasi = indeks_sekarang + 1; // Nomor astronot (1 hingga N)
        sisa_astronot--;

        std::cout << "Astronot nomor " << nomor_dieliminasi << " dieliminasi. ";

        // Pembaruan aturan nilai K
        if (nomor_dieliminasi % 2 == 0) {
            K += 2; // Jika genap, K bertambah 2
        } else {
            K -= 1; // Jika ganjil, K berkurang 1
        }

        // Aturan K tidak boleh kurang dari 2
        if (K < 2) {
            K = 2;
        }

        std::cout << "(Nilai K baru: " << K << ")\n";

        // Berpindah ke astronot berikutnya yang masih aktif untuk iterasi selanjutnya
        if (sisa_astronot > 1) {
            do {
                indeks_sekarang = (indeks_sekarang + 1) % N;
            } while (!astronot[indeks_sekarang]);
        }
    }

    // Mencari astronot terakhir yang bertahan
    for (int i = 0; i < N; i++) {
        if (astronot[i]) {
            std::cout << "\nAstronot terakhir yang bertahan adalah nomor: " << (i + 1) << std::endl;
            break;
        }
    }

    return 0;
}