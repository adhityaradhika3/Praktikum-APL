#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// ================== STRUCT ==================
struct User {
    string nama, nim;
};

struct Pelanggan {
    int id;
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

// SORTING
void sortNamaDesc(Pelanggan *data, int jumlah);
void sortHargaAsc(Pelanggan *data, int jumlah);
void sortLayananAsc(Pelanggan *data, int jumlah);
void sortIdAsc(Pelanggan *data, int jumlah);

// SEARCHING
void searchNama(Pelanggan *data, int jumlah); // Linear Search
void searchID(Pelanggan *data, int jumlah);   // Jump Search
int jumpSearch(Pelanggan *data, int jumlah, int key);

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
        cout << "8. Cari ID (Jump Search)\n";
        cout << "9. Cari Nama (Linear Search)\n";
        cout << "10. Keluar\n";
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
            case 8: searchID(data, jumlah); break;
            case 9: searchNama(data, jumlah); break;
            case 10: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 10);

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
    cout << "1. Potong Rambut (30000)\n";
    cout << "2. Cukur Jenggot (20000)\n";
    cout << "3. Hair Coloring (70000)\n";
    cout << "4. Creambath (50000)\n";
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
        default: *layanan = "Tidak ada"; *harga = 0;
    }
}

// ================== CRUD ==================
void tambahData(Pelanggan *data, int *jumlah) {
    if (*jumlah >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\nID pelanggan: ";
    cin >> data[*jumlah].id;

    cin.ignore();
    cout << "Nama pelanggan: ";
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
             << data[i].id << " | "
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

    cout << "ID baru: ";
    cin >> data[i - 1].id;

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
}

void sortHargaAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].harga > data[j + 1].harga) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void sortLayananAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].layanan > data[j + 1].layanan) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void sortIdAsc(Pelanggan *data, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (data[j].id > data[j + 1].id) {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

// ================== SEARCHING ==================

// Linear Search (Nama)
void searchNama(Pelanggan *data, int jumlah) {
    string cari;
    cin.ignore();
    cout << "Masukkan nama: ";
    getline(cin, cari);

    bool found = false;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].nama == cari) {
            cout << "Ditemukan: "
                 << data[i].id << " | "
                 << data[i].nama << " | "
                 << data[i].layanan << " | Rp"
                 << data[i].harga << endl;
            found = true;
        }
    }

    if (!found) cout << "Data tidak ditemukan!\n";
}

// Jump Search (ID)
int jumpSearch(Pelanggan *data, int jumlah, int key) {
    int step = sqrt(jumlah);
    int prev = 0;

    while (data[min(step, jumlah) - 1].id < key) {
        prev = step;
        step += sqrt(jumlah);
        if (prev >= jumlah)
            return -1;
    }

    for (int i = prev; i < min(step, jumlah); i++) {
        if (data[i].id == key)
            return i;
    }

    return -1;
}

void searchID(Pelanggan *data, int jumlah) {
    int key;
    cout << "Masukkan ID: ";
    cin >> key;

    sortIdAsc(data, jumlah);

    int index = jumpSearch(data, jumlah, key);

    if (index != -1) {
        cout << "Ditemukan: "
             << data[index].id << " | "
             << data[index].nama << " | "
             << data[index].layanan << " | Rp"
             << data[index].harga << endl;
    } else {
        cout << "Data tidak ditemukan!\n";
    }
}