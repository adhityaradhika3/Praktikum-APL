#include <iostream>
#include <string>
using namespace std;

struct User {
    string nama, nim;
};

struct Pelanggan {
    string nama, layanan;
    int harga;
};

// ===== FUNCTION =====
bool login(User *user);
void tampilLayanan();
void pilihLayanan(string *layanan, int *harga);
void tambahData(Pelanggan *data, int *jumlah);
void lihatData(Pelanggan *data, int jumlah);
void ubahData(Pelanggan *data, int jumlah);
void hapusData(Pelanggan *data, int *jumlah);

// ===== MAIN =====
int main() {
    User user = {"Dika", "130"};
    Pelanggan data[100];
    int jumlah = 0, pilih;

    if (!login(&user)) return 0; // <-- address-of (&)

    do {
        cout << "\n=== BARBERSHOP ===\n";
        cout << "1. Tambah\n2. Lihat\n3. Ubah\n4. Hapus\n5. Keluar\n";
        cout << "Pilih: "; cin >> pilih;

        switch (pilih) {
            case 1: tambahData(data, &jumlah); break;
            case 2: lihatData(data, jumlah); break;
            case 3: ubahData(data, jumlah); break;
            case 4: hapusData(data, &jumlah); break;
        }

    } while (pilih != 5);

    return 0;
}

// ===== LOGIN =====
bool login(User *user) {
    string nama, nim;
    int kesempatan = 3;

    while (kesempatan--) {
        cout << "\nLogin\nNama: "; cin >> nama;
        cout << "NIM : "; cin >> nim;

        // dereference (*)
        if (nama == user->nama && nim == user->nim) {
            cout << "Berhasil login!\n";
            return true;
        }
        cout << "Salah! Sisa: " << kesempatan << endl;
    }
    return false;
}

// ===== LAYANAN =====
void tampilLayanan() {
    cout << "\n1. Potong Rambut (30000)\n";
    cout << "2. Cukur Jenggot (20000)\n";
    cout << "3. Hair Coloring (70000)\n";
    cout << "4. Creambath (50000)\n";
}

void pilihLayanan(string *layanan, int *harga) {
    int pilih;
    tampilLayanan();
    cout << "Pilih: "; cin >> pilih;

    switch (pilih) {
        case 1: *layanan = "Potong Rambut"; *harga = 30000; break;
        case 2: *layanan = "Cukur Jenggot"; *harga = 20000; break;
        case 3: *layanan = "Hair Coloring"; *harga = 70000; break;
        case 4: *layanan = "Creambath"; *harga = 50000; break;
        default: cout << "Pilihan salah!\n";
    }
}

// ===== CRUD =====
void tambahData(Pelanggan *data, int *jumlah) {
    cin.ignore();
    cout << "\nNama: ";
    getline(cin, data[*jumlah].nama);

    // kirim alamat variabel
    pilihLayanan(&data[*jumlah].layanan, &data[*jumlah].harga);

    (*jumlah)++; // dereference
    cout << "Data ditambah!\n";
}

void lihatData(Pelanggan *data, int jumlah) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\n" << i+1 << ". "
             << data[i].nama << " | "
             << data[i].layanan << " | "
             << data[i].harga << endl;
    }
}

void ubahData(Pelanggan *data, int jumlah) {
    int i;
    cout << "Ubah data ke: "; cin >> i;

    if (i < 1 || i > jumlah) return;

    cin.ignore();
    cout << "Nama baru: ";
    getline(cin, data[i-1].nama);

    pilihLayanan(&data[i-1].layanan, &data[i-1].harga);

    cout << "Data diubah!\n";
}

void hapusData(Pelanggan *data, int *jumlah) {
    int i;
    cout << "Hapus data ke: "; cin >> i;

    if (i < 1 || i > *jumlah) return;

    for (int j = i-1; j < *jumlah-1; j++) {
        data[j] = data[j+1];
    }

    (*jumlah)--; // dereference
    cout << "Data dihapus!\n";
}