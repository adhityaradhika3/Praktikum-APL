#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdexcept>

#include "barbershop.h" 

using namespace std;

bool login(User *user);
void tampilLayanan();
void pilihLayanan(string *layanan, int *harga);
void tambahData(Pelanggan *data, int *jumlah);
void lihatData(Pelanggan *data, int jumlah);
void ubahData(Pelanggan *data, int jumlah);
void hapusData(Pelanggan *data, int *jumlah);
void sortNamaDesc(Pelanggan *data, int jumlah);
void sortHargaAsc(Pelanggan *data, int jumlah);
void sortLayananAsc(Pelanggan *data, int jumlah);
void sortIdAsc(Pelanggan *data, int jumlah);
void searchNama(Pelanggan *data, int jumlah);
void searchID(Pelanggan *data, int jumlah);
int jumpSearch(Pelanggan *data, int jumlah, int key);

void loadingEffect() {
    cout << "Memproses...\n";
}

int main() {
    User user = {"Dika", "130"};
    Pelanggan data[100];
    int jumlah = 0, pilih;

    if (!login(&user)) return 0;

    do {
        cout << "\n=========================================\n";
        cout << "        💈 BARBERSHOP PREMIUM 💈       \n";
        cout << "=========================================\n";
        cout << "1. Tambah Pelanggan\n";
        cout << "2. Lihat Daftar Pelanggan\n";
        cout << "3. Ubah Data Pelanggan\n";
        cout << "4. Hapus Data Pelanggan\n";
        cout << "5. Sort Nama (Z-A)\n";
        cout << "6. Sort Harga (Murah-Mahal)\n";
        cout << "7. Sort Layanan (A-Z)\n";
        cout << "8. Cari ID (Jump Search)\n";
        cout << "9. Cari Nama (Linear Search)\n";
        cout << "10. Keluar\n";
        cout << "=========================================\n";
        cout << "Pilih menu (1-10): ";

        try {
            if (!(cin >> pilih)) {
                throw invalid_argument("Input harus berupa angka!");
            }
            if (pilih < 1 || pilih > 10) {
                throw out_of_range("Pilihan menu tidak ada!");
            }

            loadingEffect();

            switch (pilih) {
                case 1: tambahData(data, &jumlah); break;
                case 2: lihatData(data, jumlah); break;
                case 3: ubahData(data, jumlah); break;
                case 4: hapusData(data, &jumlah); break;
                case 5: sortNamaDesc(data, jumlah); lihatData(data, jumlah); break;
                case 6: sortHargaAsc(data, jumlah); lihatData(data, jumlah); break;
                case 7: sortLayananAsc(data, jumlah); lihatData(data, jumlah); break;
                case 8: searchID(data, jumlah); break;
                case 9: searchNama(data, jumlah); break;
                case 10: cout << "Terima kasih telah menggunakan sistem Barbershop Premium!\n"; break;
            }
        } 
        catch (const exception& e) {
            cout << "❌ ERROR: " << e.what() << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while (pilih != 10);

    return 0;
}

bool login(User *user) {
    string nama, nim;
    int kesempatan = 3;

    while (kesempatan--) {
        cout << "\n=== LOGIN SISTEM BARBERSHOP ===\n";
        cout << "Nama : "; cin >> nama;
        cout << "NIM  : "; cin >> nim;

        try {
            if (nama != user->nama || nim != user->nim) {
                throw runtime_error("Kredensial tidak valid!");
            }
            cout << "✅ Login berhasil!\n";
            return true;
        } 
        catch (const exception& e) {
            cout << "❌ " << e.what() << " Sisa kesempatan: " << kesempatan << "\n";
        }
    }
    cout << "Akses diblokir. Silakan coba lagi nanti.\n";
    return false;
}

void tampilLayanan() {
    cout << "\n=== DAFTAR LAYANAN ===\n";
    cout << "1. Potong Rambut  (Rp 30.000)\n";
    cout << "2. Cukur Jenggot  (Rp 20.000)\n";
    cout << "3. Hair Coloring  (Rp 70.000)\n";
    cout << "4. Creambath      (Rp 50.000)\n";
}

void pilihLayanan(string *layanan, int *harga) {
    int pilih;
    tampilLayanan();
    cout << "Pilih layanan (1-4): ";
    cin >> pilih;

    switch (pilih) {
        case 1: *layanan = "Potong Rambut"; *harga = 30000; break;
        case 2: *layanan = "Cukur Jenggot"; *harga = 20000; break;
        case 3: *layanan = "Hair Coloring"; *harga = 70000; break;
        case 4: *layanan = "Creambath";     *harga = 50000; break;
        default: *layanan = "Tidak ada";    *harga = 0;
    }
}

void tambahData(Pelanggan *data, int *jumlah) {
    if (*jumlah >= 100) {
        cout << "⚠️ Kapasitas data penuh!\n";
        return;
    }

    try {
        cout << "\nID pelanggan: ";
        if (!(cin >> data[*jumlah].id)) throw invalid_argument("ID harus berupa angka!");
        if (data[*jumlah].id < 0) throw invalid_argument("ID tidak boleh negatif!");

        cin.ignore();
        cout << "Nama pelanggan: ";
        getline(cin, data[*jumlah].nama);

        pilihLayanan(&data[*jumlah].layanan, &data[*jumlah].harga);

        (*jumlah)++;
        cout << "✅ Data berhasil ditambahkan!\n";
    } 
    catch (const exception& e) {
        cout << "❌ ERROR: " << e.what() << "\nData gagal ditambahkan.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void lihatData(Pelanggan *data, int jumlah) {
    if (jumlah == 0) {
        cout << "⚠️ Data masih kosong!\n";
        return;
    }

    cout << "\n" << setfill('=') << setw(65) << "=" << setfill(' ') << "\n";
    cout << left << setw(5) << "NO" << setw(10) << "ID" << setw(20) << "NAMA" << setw(18) << "LAYANAN" << "HARGA\n";
    cout << setfill('-') << setw(65) << "-" << setfill(' ') << "\n";
    
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(5) << i + 1
             << setw(10) << data[i].id
             << setw(20) << data[i].nama
             << setw(18) << data[i].layanan
             << "Rp " << data[i].harga << "\n";
    }
    cout << setfill('=') << setw(65) << "=" << setfill(' ') << "\n";
}

void ubahData(Pelanggan *data, int jumlah) {
    if (jumlah == 0) { cout << "⚠️ Data kosong!\n"; return; }
    
    lihatData(data, jumlah);
    
    try {
        int i;
        cout << "Ubah data ke (No urut): ";
        if (!(cin >> i)) throw invalid_argument("Input harus berupa angka!");
        if (i < 1 || i > jumlah) throw out_of_range("Nomor urut tidak ditemukan!");

        cout << "ID baru: ";
        if (!(cin >> data[i - 1].id)) throw invalid_argument("ID harus angka!");

        cin.ignore();
        cout << "Nama baru: ";
        getline(cin, data[i - 1].nama);

        pilihLayanan(&data[i - 1].layanan, &data[i - 1].harga);
        cout << "✅ Data berhasil diubah!\n";
    }
    catch (const exception& e) {
        cout << "❌ ERROR: " << e.what() << "\n";
        cin.clear(); cin.ignore(10000, '\n');
    }
}

void hapusData(Pelanggan *data, int *jumlah) {
    if (*jumlah == 0) { cout << "⚠️ Data kosong!\n"; return; }
    
    lihatData(data, *jumlah);
    
    try {
        int i;
        cout << "Hapus data ke (No urut): ";
        if (!(cin >> i)) throw invalid_argument("Input harus berupa angka!");
        if (i < 1 || i > *jumlah) throw out_of_range("Nomor urut tidak ditemukan!");

        for (int j = i - 1; j < *jumlah - 1; j++) {
            data[j] = data[j + 1];
        }
        (*jumlah)--;
        cout << "✅ Data berhasil dihapus!\n";
    }
    catch (const exception& e) {
        cout << "❌ ERROR: " << e.what() << "\n";
        cin.clear(); cin.ignore(10000, '\n');
    }
}

void sortNamaDesc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].nama < data[j + 1].nama) swap(data[j], data[j + 1]);
        }
    }
}

void sortHargaAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].harga > data[j + 1].harga) swap(data[j], data[j + 1]);
        }
    }
}

void sortLayananAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].layanan > data[j + 1].layanan) swap(data[j], data[j + 1]);
        }
    }
}

void sortIdAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].id > data[j + 1].id) swap(data[j], data[j + 1]);
        }
    }
}

void searchNama(Pelanggan *data, int jumlah) {
    string cari;
    cin.ignore();
    cout << "Masukkan nama yang dicari: ";
    getline(cin, cari);

    bool found = false;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].nama == cari) {
            cout << "🔍 Ditemukan: ID " << data[i].id << " | " << data[i].nama << " | " << data[i].layanan << " | Rp " << data[i].harga << "\n";
            found = true;
        }
    }
    if (!found) cout << "⚠️ Data tidak ditemukan!\n";
}

int jumpSearch(Pelanggan *data, int jumlah, int key) {
    int step = sqrt(jumlah);
    int prev = 0;

    while (data[min(step, jumlah) - 1].id < key) {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah) return -1;
    }

    for (int i = prev; i < min(step, jumlah); i++) {
        if (data[i].id == key) return i;
    }
    return -1;
}

void searchID(Pelanggan *data, int jumlah) {
    if (jumlah == 0) { cout << "⚠️ Data kosong!\n"; return; }
    
    try {
        int key;
        cout << "Masukkan ID yang dicari: ";
        if (!(cin >> key)) throw invalid_argument("Input ID harus berupa angka!");

        sortIdAsc(data, jumlah); // Jump Search butuh data terurut
        int index = jumpSearch(data, jumlah, key);

        if (index != -1) {
            cout << "🔍 Ditemukan: ID " << data[index].id << " | " << data[index].nama << " | " << data[index].layanan << " | Rp " << data[index].harga << "\n";
        } else {
            cout << "⚠️ Data tidak ditemukan!\n";
        }
    }
    catch (const exception& e) {
        cout << "❌ ERROR: " << e.what() << "\n";
        cin.clear(); cin.ignore(10000, '\n');
    }
}