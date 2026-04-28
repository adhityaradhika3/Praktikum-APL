#ifndef BARBERSHOP_H
#define BARBERSHOP_H

#include <iostream>
#include <string>

using namespace std;
struct User {
    string nama, nim;
};

struct Pelanggan {
    int id;
    string nama, layanan;
    int harga;
};

#endif