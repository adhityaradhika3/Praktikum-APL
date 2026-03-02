#include <iostream>
using namespace std;

int main() {
    string nama, password;
    int kesempatan = 3;

    // LOGIN
    while (kesempatan--) {
        cout << "=== LOGIN ===\n";
        cout << "Nama     : ";
        cin >> nama;
        cout << "Password : ";
        cin >> password;

        if (nama == "Dika" && password == "130") {
            cout << "Login berhasil!\n";
            break;
        } else {
            cout << "Salah! ";
            if (kesempatan > 0)
                cout << "Sisa kesempatan: " << kesempatan << "\n\n";
            else {
                cout << "\nAnda gagal login 3 kali.\n";
                return 0;
            }
        }
    }

    int pilih;
    double nilai;

    // MENU
    do {
        cout << "\n=== MENU KONVERSI ===\n";
        cout << "1. Meter ke Km & Cm\n";
        cout << "2. Km ke Meter & Cm\n";
        cout << "3. Cm ke Meter & Km\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;

        if (pilih == 4) {
            cout << "Program selesai.\n";
            break;
        }

        if (pilih < 1 || pilih > 4) {
            cout << "Menu tidak ada!\n";
            continue;
        }

        cout << "Masukkan nilai: ";
        cin >> nilai;

        if (pilih == 1) {
            cout << nilai << " m = "
                 << nilai / 1000 << " km dan "
                 << nilai * 100 << " cm\n";
        }
        else if (pilih == 2) {
            cout << nilai << " km = "
                 << nilai * 1000 << " m dan "
                 << nilai * 100000 << " cm\n";
        }
        else if (pilih == 3) {
            cout << nilai << " cm = "
                 << nilai / 100 << " m dan "
                 << nilai / 100000 << " km\n";
        }

    } while (true);

    return 0;
}