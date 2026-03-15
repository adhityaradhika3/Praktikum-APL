#include <iostream>
#include <string>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Pelanggan {
    string nama;
    string layanan;
    int harga;
};

bool login(User user);
void tambahData(Pelanggan data[], int &jumlah);
void lihatData(Pelanggan data[], int jumlah);
void ubahData(Pelanggan data[], int jumlah);
void hapusData(Pelanggan data[], int &jumlah);
void tampilLayanan();

int main() {

    User user;
    Pelanggan data[100];
    int jumlah = 0;
    int pilihan;

    user.nama = "Dika";
    user.nim = "130";

    if (!login(user)) {
        cout << "Program berhenti.\n";
        return 0;
    }

    do {

        cout << "\n===== SISTEM MANAJEMEN BARBERSHOP =====\n";
        cout << "1. Tambah Data Pelanggan\n";
        cout << "2. Lihat Data Pelanggan\n";
        cout << "3. Ubah Data Pelanggan\n";
        cout << "4. Hapus Data Pelanggan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            tambahData(data, jumlah);
            break;

        case 2:
            lihatData(data, jumlah);
            break;

        case 3:
            ubahData(data, jumlah);
            break;

        case 4:
            hapusData(data, jumlah);
            break;

        case 5:
            cout << "Terima kasih telah menggunakan sistem barbershop.\n";
            break;

        default:
            cout << "Menu tidak tersedia!\n";
        }

    } while (pilihan != 5);

    return 0;
}

bool login(User user) {

    string inputNama, inputNim;
    int kesempatan = 3;

    while (kesempatan > 0) {

        cout << "\n===== LOGIN =====\n";
        cout << "Nama : ";
        cin >> inputNama;
        cout << "NIM  : ";
        cin >> inputNim;

        if (inputNama == user.nama && inputNim == user.nim) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            kesempatan--;
            cout << "Login gagal! Sisa kesempatan: " << kesempatan << endl;
        }
    }

    cout << "Anda gagal login 3 kali.\n";
    return false;
}

void tampilLayanan() {

    cout << "\n=== Daftar Layanan Barbershop ===\n";
    cout << "1. Potong Rambut  - 30000\n";
    cout << "2. Cukur Jenggot  - 20000\n";
    cout << "3. Hair Coloring  - 70000\n";
    cout << "4. Creambath      - 50000\n";
}

void tambahData(Pelanggan data[], int &jumlah) {

    if (jumlah >= 100) {
        cout << "Data sudah penuh!\n";
        return;
    }

    cin.ignore();

    cout << "\n=== Tambah Data Pelanggan ===\n";
    cout << "Nama Pelanggan : ";
    getline(cin, data[jumlah].nama);

    tampilLayanan();

    int pilih;
    cout << "Pilih layanan : ";
    cin >> pilih;

    switch (pilih) {

    case 1:
        data[jumlah].layanan = "Potong Rambut";
        data[jumlah].harga = 30000;
        break;

    case 2:
        data[jumlah].layanan = "Cukur Jenggot";
        data[jumlah].harga = 20000;
        break;

    case 3:
        data[jumlah].layanan = "Hair Coloring";
        data[jumlah].harga = 70000;
        break;

    case 4:
        data[jumlah].layanan = "Creambath";
        data[jumlah].harga = 50000;
        break;

    default:
        cout << "Layanan tidak tersedia\n";
        return;
    }

    jumlah++;

    cout << "Data berhasil ditambahkan!\n";
}

void lihatData(Pelanggan data[], int jumlah) {

    cout << "\n=== Data Pelanggan ===\n";

    if (jumlah == 0) {
        cout << "Belum ada data pelanggan.\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {

        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama    : " << data[i].nama << endl;
        cout << "Layanan : " << data[i].layanan << endl;
        cout << "Harga   : " << data[i].harga << endl;
    }
}

void ubahData(Pelanggan data[], int jumlah) {

    if (jumlah == 0) {
        cout << "Data masih kosong.\n";
        return;
    }

    int ubah;

    cout << "Data ke berapa yang ingin diubah? ";
    cin >> ubah;

    if (ubah < 1 || ubah > jumlah) {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    cin.ignore();

    cout << "Nama baru : ";
    getline(cin, data[ubah - 1].nama);

    tampilLayanan();

    int pilih;
    cout << "Pilih layanan baru : ";
    cin >> pilih;

    switch (pilih) {

    case 1:
        data[ubah - 1].layanan = "Potong Rambut";
        data[ubah - 1].harga = 30000;
        break;

    case 2:
        data[ubah - 1].layanan = "Cukur Jenggot";
        data[ubah - 1].harga = 20000;
        break;

    case 3:
        data[ubah - 1].layanan = "Hair Coloring";
        data[ubah - 1].harga = 70000;
        break;

    case 4:
        data[ubah - 1].layanan = "Creambath";
        data[ubah - 1].harga = 50000;
        break;

    default:
        cout << "Layanan tidak tersedia\n";
        return;
    }

    cout << "Data berhasil diubah!\n";
}

void hapusData(Pelanggan data[], int &jumlah) {

    if (jumlah == 0) {
        cout << "Data masih kosong.\n";
        return;
    }

    int hapus;

    cout << "Data ke berapa yang ingin dihapus? ";
    cin >> hapus;

    if (hapus < 1 || hapus > jumlah) {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    for (int i = hapus - 1; i < jumlah - 1; i++) {
        data[i] = data[i + 1];
    }

    jumlah--;

    cout << "Data berhasil dihapus!\n";
}