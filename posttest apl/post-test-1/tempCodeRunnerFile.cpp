#include <iostream>
using namespace std;

int main() {
    string nama, password;
    string userBenar = "Radhika";     
    string passBenar = "123";          
    int kesempatan = 3;
    bool loginBerhasil = false;

    //  LOGIN 
    while (kesempatan > 0) {
        cout << " LOGIN " << endl;
        cout << "Nama     : ";
        cin >> nama;
        cout << "Password : ";
        cin >> password;

        if (nama == userBenar && password == passBenar) {
            loginBerhasil = true;
            break;
        } else {
            kesempatan--;
            cout << "Login salah! Sisa kesempatan: " << kesempatan << endl << endl;
        }
    }

    if (!loginBerhasil) {
        cout << "Anda gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    //  MENU 
    int pilihan;
    double nilai;

    do {
        cout << "\n MENU KONVERSI PANJANG " << endl;
        cout << "1. Meter ke Kilometer dan Centimeter" << endl;
        cout << "2. Kilometer ke Meter dan Centimeter" << endl;
        cout << "3. Centimeter ke Meter dan Kilometer" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan nilai panjang: ";
            cin >> nilai;
        }

        switch (pilihan) {
            case 1:
                cout << nilai << " meter = "
                     << nilai / 1000 << " km dan "
                     << nilai * 100 << " cm" << endl;
                break;

            case 2:
                cout << nilai << " km = "
                     << nilai * 1000 << " m dan "
                     << nilai * 100000 << " cm" << endl;
                break;

            case 3:
                cout << nilai << " cm = "
                     << nilai / 100 << " m dan "
                     << nilai / 100000 << " km" << endl;
                break;

            case 4:
                cout << "Terima kasih. Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}