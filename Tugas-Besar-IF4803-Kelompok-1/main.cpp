#include <iostream>
#include "customer.h"
#include "menu.h"

using namespace std;

infotypeC infoPelanggan;

int pelanggan(listMenu &darren_almi);
int admin(listMenu &darren_almi);

int main()
{
    listMenu darren_almi;
    string choice;
    createListMenu(darren_almi);
    insertDummyDataMenu1(darren_almi);
    insertDummyDataMenu2(darren_almi);
    insertDummyDataMenu3(darren_almi);
    cout << "===== Pilih Mode =====" << endl;
    cout << "1. Pelanggan (Studi Kasus)" << endl;
    cout << "2. Admin" << endl;
    cin >> choice;
    if (choice == "1")
    {
        cout << "\033[2J\033[1;1H";
        pelanggan(darren_almi);
    }
    else if (choice == "2")
    {
        cout << "\033[2J\033[1;1H";
        admin(darren_almi);
    }
    else
    {
        cout << "\033[2J\033[1;1H";
        main();
    }
    return 0;
}

int pelanggan(listMenu &darren_almi)
{
    int choice;
    int quantity;
    string VIP;
    string menuYangDipesan;
    cout << "===== Mode Pelanggan =====" << endl;
    if (infoPelanggan.id != "")
    {
        cout << "ID anda: " << infoPelanggan.id << endl;
        cout << "Nama anda: " << infoPelanggan.name << endl;
        cout << "Saldo anda: " << infoPelanggan.balance << endl;
        if (infoPelanggan.vip == true)
        {
            cout << "Status: VIP Customer" << endl;
        }
        else
        {
            cout << "Status: Regular Customer" << endl;
        }
        cout << "-----------------------------" << endl;
    }
    cout << "1. Lihat Menu" << endl;
    cout << "2. Lakukan Pemesanan" << endl;
    cout << "3. Tambah Saldo" << endl;
    cout << "4. Lihat Pesanan" << endl;
    cout << "9. Ubah Data Anda" << endl;
    cout << "0. Kembali ke menu awal" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        viewMenu(darren_almi);
        pelanggan(darren_almi);
        break;
    case 2:
        if (infoPelanggan.id == "")
        {
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
            cout << "Masukkan nama menu yang ingin anda pesan: ";
            cin >> menuYangDipesan;
            cout << "Jumlah yang ingin dipesan: ";
            cin >> quantity;
            orderMenu(darren_almi, menuYangDipesan, infoPelanggan, quantity);
            pelanggan(darren_almi);
        }
        else
        {
            cout << "Masukkan nama menu yang ingin anda pesan: " << endl;
            cin >> menuYangDipesan;
            cout << "Jumlah yang ingin dipesan: ";
            cin >> quantity;
            orderMenu(darren_almi, menuYangDipesan, infoPelanggan, quantity);
            pelanggan(darren_almi);
        }
        break;
    case 3:
        if (infoPelanggan.id == "")
        {
            cout << "ID Tidak terdaftar! Mohon daftar terlebih dahulu" << endl;
            pelanggan(darren_almi);
        }
        else
        {
            addBalance(infoPelanggan);
            pelanggan(darren_almi);
        }
        break;
    case 4:
        if (infoPelanggan.id == "")
        {
            cout << "ID Tidak terdaftar! Mohon daftar terlebih dahulu" << endl;
            pelanggan(darren_almi);
        }
        else
        {
            showListPesanan(darren_almi, infoPelanggan.id);
            pelanggan(darren_almi);
        }
        break;
    case 9:
    {
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
        pelanggan(darren_almi);
    }
    break;
    case 0:
        cout << "\033[2J\033[1;1H";
        main();
        break;
    default:
        pelanggan(darren_almi);
    }
    return 0;
};

int admin(listMenu &darren_almi)
{
    string choice;
    cout << "===== Mode Admin =====" << endl;
    cout << "1. Tambah Menu" << endl;
    cout << "2. Tambah Stock Menu" << endl;
    cout << "3. Lihat customer dari sebuah menu" << endl;
    cout << "4. Lihat customer VIP" << endl;
    cout << "0. Kembali ke menu awal" << endl;
    cin >> choice;
    if (choice == "1")
    {
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
        admin(darren_almi);
    }
    else if (choice == "0")
    {
        cout << "\033[2J\033[1;1H";
        main();
    }
    return 0;
}
