#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ================== STRUCT ==================
struct User {
    string nama, nim;
};

struct Pelanggan {
    string nama, layanan;
    int harga;
};

// ================== FUNCTION ==================
bool login(User *user);
void tampilLayanan();
void pilihLayanan(string *layanan, int *harga);

void tambahData(Pelanggan *data, int *jumlah);
void lihatData(Pelanggan *data, int jumlah);
void ubahData(Pelanggan *data, int jumlah);
void hapusData(Pelanggan *data, int *jumlah);

// ================== SORTING ==================
void sortNamaDesc(Pelanggan *data, int jumlah);
void sortHargaAsc(Pelanggan *data, int jumlah);
void sortLayananAsc(Pelanggan *data, int jumlah);

// ================== MAIN ==================
int main() {
    User user = {"Dika", "130"};
    Pelanggan data[100];
    int jumlah = 0, pilih;

    if (!login(&user)) return 0;

    do {
        cout << "\n=== BARBERSHOP ===\n";
        cout << "1. Tambah\n";
        cout << "2. Lihat\n";
        cout << "3. Ubah\n";
        cout << "4. Hapus\n";
        cout << "5. Sort Nama (Z-A)\n";
        cout << "6. Sort Harga (Murah-Mahal)\n";
        cout << "7. Sort Layanan (A-Z)\n";
        cout << "8. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahData(data, &jumlah); break;
            case 2: lihatData(data, jumlah); break;
            case 3: ubahData(data, jumlah); break;
            case 4: hapusData(data, &jumlah); break;
            case 5: sortNamaDesc(data, jumlah); lihatData(data, jumlah); break;
            case 6: sortHargaAsc(data, jumlah); lihatData(data, jumlah); break;
            case 7: sortLayananAsc(data, jumlah); lihatData(data, jumlah); break;
            case 8: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 8);

    return 0;
}

// ================== LOGIN ==================
bool login(User *user) {
    string nama, nim;
    int kesempatan = 3;

    while (kesempatan--) {
        cout << "\n=== LOGIN ===\n";
        cout << "Nama : ";
        cin >> nama;
        cout << "NIM  : ";
        cin >> nim;

        if (nama == user->nama && nim == user->nim) {
            cout << "Login berhasil!\n";
            return true;
        }

        cout << "Login gagal! Sisa kesempatan: " << kesempatan << endl;
    }
    return false;
}

// ================== LAYANAN ==================
void tampilLayanan() {
    cout << "\n=== DAFTAR LAYANAN ===\n";
    cout << "1. Potong Rambut (Rp. 30000)\n";
    cout << "2. Cukur Jenggot (Rp. 20000)\n";
    cout << "3. Hair Coloring (Rp. 70000)\n";
    cout << "4. Creambath (Rp. 50000)\n";
}

void pilihLayanan(string *layanan, int *harga) {
    int pilih;
    tampilLayanan();
    cout << "Pilih layanan: ";
    cin >> pilih;

    switch (pilih) {
        case 1: *layanan = "Potong Rambut"; *harga = 30000; break;
        case 2: *layanan = "Cukur Jenggot"; *harga = 20000; break;
        case 3: *layanan = "Hair Coloring"; *harga = 70000; break;
        case 4: *layanan = "Creambath"; *harga = 50000; break;
        default:
            cout << "Pilihan salah!\n";
            *layanan = "Tidak ada";
            *harga = 0;
    }
}

// ================== CRUD ==================
void tambahData(Pelanggan *data, int *jumlah) {
    if (*jumlah >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cin.ignore();
    cout << "\nNama pelanggan: ";
    getline(cin, data[*jumlah].nama);

    pilihLayanan(&data[*jumlah].layanan, &data[*jumlah].harga);

    (*jumlah)++;
    cout << "Data berhasil ditambahkan!\n";
}

void lihatData(Pelanggan *data, int jumlah) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA PELANGGAN ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". "
             << data[i].nama << " | "
             << data[i].layanan << " | Rp"
             << data[i].harga << endl;
    }
}

void ubahData(Pelanggan *data, int jumlah) {
    int i;
    cout << "Ubah data ke: ";
    cin >> i;

    if (i < 1 || i > jumlah) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    cin.ignore();
    cout << "Nama baru: ";
    getline(cin, data[i - 1].nama);

    pilihLayanan(&data[i - 1].layanan, &data[i - 1].harga);

    cout << "Data berhasil diubah!\n";
}

void hapusData(Pelanggan *data, int *jumlah) {
    int i;
    cout << "Hapus data ke: ";
    cin >> i;

    if (i < 1 || i > *jumlah) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    for (int j = i - 1; j < *jumlah - 1; j++) {
        data[j] = data[j + 1];
    }

    (*jumlah)--;
    cout << "Data berhasil dihapus!\n";
}

// ================== SORTING ==================
void sortNamaDesc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].nama < data[j + 1].nama) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Sorting nama (Z-A) berhasil!\n";
}

void sortHargaAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].harga > data[j + 1].harga) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Sorting harga berhasil!\n";
}

void sortLayananAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].layanan > data[j + 1].layanan) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Sorting layanan berhasil!\n";
}