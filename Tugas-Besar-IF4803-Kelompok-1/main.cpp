#include <iostream>
#include "customer.h"
#include "menu.h"

using namespace std;

listMenu darren_almi;
infotypeC infoPelanggan;

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
    if (infoPelanggan.id != ""){
        cout << "ID anda: " << infoPelanggan.id << endl;
        cout << "Nama anda: " << infoPelanggan.name << endl;
        cout << "Saldo anda: " << infoPelanggan.balance << endl;
        if (infoPelanggan.vip == true){
            cout << "Status: VIP Customer" << endl;
        }else{
            cout << "Status: Regular Customer" << endl;
        }
        cout << "-----------------------------" << endl;
    }
    cout << "1. Lihat Menu" << endl;
    cout << "2. Lakukan Pemesanan" << endl;
    cout << "9. Ubah Data Anda" << endl;
    cout << "0. Kembali ke menu awal" << endl;
    cin >> choice;
    if (choice == "1"){
        viewMenu(darren_almi);
        pelanggan();
    }else if(choice == "2"){
        if (infoPelanggan.id == ""){
            string VIP;
            cout << "===== Data Pelanggan =====" << endl;
            cout << "ID Pelanggan: ";
            cin >> infoPelanggan.id;
            cout << "Nama Pelanggan: ";
            cin >> infoPelanggan.name;
            cout << "Saldo: ";
            cin >> infoPelanggan.balance;
            cout << "VIP (y/n): ";
            cin >> VIP;
            if (VIP == "y") {
                infoPelanggan.vip = true;
            }else{
                infoPelanggan.vip = false;
            }
        }
        string menuYangDipesan;
        int quantity;
        cout << "Masukkan nama menu yang ingin anda pesan: ";
        cin >> menuYangDipesan;
        cout << "Jumlah yang ingin dipesan: ";
        cin >> quantity;
        orderMenu(darren_almi,menuYangDipesan,infoPelanggan,quantity);
        pelanggan();
    }else if (choice == "9"){
        string VIP;
        cout << "===== Data Pelanggan =====" << endl;
        cout << "ID Pelanggan: ";
        cin >> infoPelanggan.id;
        cout << "Nama Pelanggan: ";
        cin >> infoPelanggan.name;
        cout << "Saldo: ";
        cin >> infoPelanggan.balance;
        cout << "VIP (y/n): ";
        cin >> VIP;
        infoPelanggan.vip = (VIP == "y");
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
        cin >> info.stock;
        tambahMenu(darren_almi, allocate(info));
        admin();
    }else if (choice == "0"){
        cout << "\033[2J\033[1;1H";
        main();
    }
}
