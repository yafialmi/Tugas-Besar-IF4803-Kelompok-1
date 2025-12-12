#include <iostream>
#include "customer.h"
#include "menu.h"

using namespace std;

listMenu darren_almi;

int pelanggan();
int admin();

int main()
{
    string choice;
    cout << "===== Pilih Mode =====" << endl;
    cout << "1. Pelanggan (Studi Kasus)" << endl;
    cout << "2. Admin" << endl;
    cin >> choice;
    if (choice == "1"){
        cout << "\033[2J\033[1;1H";
        pelanggan();
    }else if (choice == "2"){
        cout << "\033[2J\033[1;1H";
        admin();
    }else{
        cout << "\033[2J\033[1;1H";
        main();
    }
    return 0;
}

int pelanggan()
{
    string choice;
    cout << "===== Mode Pelanggan =====" << endl;
    cout << "1. Lihat Menu" << endl;
    cout << "0. Kembali ke menu awal" << endl;
    cin >> choice;
    if (choice == "1"){
        viewMenu(darren_almi);
        pelanggan();
    }else if (choice == "0"){
        cout << "\033[2J\033[1;1H";
        main();
    }else{
        pelanggan();
    }
}

int admin()
{
    string choice;
    cout << "===== Mode Admin =====" << endl;
    cout << "1. Tambah Menu" << endl;
    cout << "2. Tambah Stock Menu" << endl;
    cout << "3. Lihat customer dari sebuah menu" << endl;
    cout << "4. Lihat customer VIP" << endl;
    cout << "0. Kembali ke menu awal" << endl;
    cin >> choice;
    if (choice == "1"){
        infotypeP info;
        cout << "ID: ";
        cin >> info.id;
        cout << "Name: ";
        cin >> info.name;
        cout << "Price: ";
        cin >> info.price;
        cout << "Stock: ";
        cin >> info.stock;s
        tambahMenu(darren_almi, allocate(info));
        admin();
    }else if (choice == "0"){
        cout << "\033[2J\033[1;1H";
        main();
    }
}
