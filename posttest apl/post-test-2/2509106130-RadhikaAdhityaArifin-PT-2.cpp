#include <iostream>
#include <limits>
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

int main() {

    User user;
    Pelanggan data[100];
    int jumlah = 0;

    string inputNama, inputNim;
    int kesempatan = 3;
    bool login = false;

    user.nama = "Dika";
    user.nim = "130";

    
    while (kesempatan > 0) {

        cout << "\n===== LOGIN =====\n";
        cout << "Nama : ";
        cin >> inputNama;
        cout << "NIM  : ";
        cin >> inputNim;

        if (inputNama == user.nama && inputNim == user.nim) {
            cout << "\nLogin berhasil!\n";
            login = true;
            break;
        } else {
            kesempatan--;
            cout << "Login gagal! Sisa kesempatan: " << kesempatan << endl;
        }
    }

    if (!login) {
        cout << "\nAnda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    int pilihan;

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
            if (jumlah >= 100) {
                cout << "Data sudah penuh!\n";
                break;
            }

            cout << "\n=== Tambah Data Pelanggan ===\n";
            cout << "Nama Pelanggan : ";
            cin.ignore();
            getline(cin, data[jumlah].nama);

            cout << "Jenis Layanan : ";
            getline(cin, data[jumlah].layanan);

            cout << "Harga : ";
            cin >> data[jumlah].harga;

            jumlah++;
            cout << "Data berhasil ditambahkan!\n";
            break;

        case 2:
            cout << "\n=== Data Pelanggan ===\n";

            if (jumlah == 0) {
                cout << "Belum ada data pelanggan.\n";
            } else {

                for (int i = 0; i < jumlah; i++) {
                    cout << "\nData ke-" << i + 1 << endl;
                    cout << "Nama    : " << data[i].nama << endl;
                    cout << "Layanan : " << data[i].layanan << endl;
                    cout << "Harga   : " << data[i].harga << endl;
                }
            }
            break;

        case 3:

            if (jumlah == 0) {
                cout << "Data masih kosong.\n";
                break;
            }

            int ubah;
            cout << "Data ke berapa yang ingin diubah? ";
            cin >> ubah;

            if (ubah < 1 || ubah > jumlah) {
                cout << "Data tidak ditemukan.\n";
            } else {

                cin.ignore();

                cout << "Nama baru : ";
                getline(cin, data[ubah - 1].nama);

                cout << "Layanan baru : ";
                getline(cin, data[ubah - 1].layanan);

                cout << "Harga baru : ";
                cin >> data[ubah - 1].harga;

                cout << "Data berhasil diubah!\n";
            }

            break;

        case 4:

            if (jumlah == 0) {
                cout << "Data masih kosong.\n";
                break;
            }

            int hapus;
            cout << "Data ke berapa yang ingin dihapus? ";
            cin >> hapus;

            if (hapus < 1 || hapus > jumlah) {
                cout << "Data tidak ditemukan.\n";
            } else {

                for (int i = hapus - 1; i < jumlah - 1; i++) {
                    data[i] = data[i + 1];
                }

                jumlah--;
                cout << "Data berhasil dihapus!\n";
            }

            break;

        case 5:
            cout << "\nTerima kasih telah menggunakan sistem barbershop.\n";
            break;

        default:
            cout << "Menu tidak tersedia!\n";
        }

    } while (pilihan != 5);

    return 0;
}