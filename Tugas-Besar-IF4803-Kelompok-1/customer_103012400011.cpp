#include "customer.h"
#include <iostream>
#include <iomanip>

/*
    I.S : List customer M tidak kosong.
    F.S : p menunjuk ke elemen customer pertama, M->firstCustomer menunjuk ke elemen kedua (atau nullptr jika hanya ada satu).
          Relasi next dan prev diperbarui sesuai dengan penghapusan elemen pertama.
*/
void deleteFirstCustomer(adrMenu &M, adrCustomer &p){
    p = M->firstCustomer;
    M->firstCustomer = p->next;
    M->firstCustomer->prev = nullptr;
}

/*
    I.S : List customer M tidak kosong.
    F.S : p menunjuk ke elemen customer terakhir, elemen sebelumnya memiliki next = nullptr.
          Relasi next dan prev diperbarui sesuai dengan penghapusan elemen terakhir.
*/
void deleteLastCustomer(adrMenu &M, adrCustomer &p){
    adrCustomer q = M->firstCustomer;
    while (q->next->next != nullptr){
        q = q->next;
    }
    p = q->next;
    q->next = nullptr;
}


/*
    I.S : List customer M tidak kosong, prec adalah elemen dalam list yang bukan elemen pertama atau terakhir.
    F.S : p menunjuk ke elemen yang berada setelah prec, prec->next menunjuk ke node setelah p.
          Relasi next dan prev diperbarui untuk menghubungkan prec dengan elemen yang sebelumnya ada setelah p.
*/
void deleteAfterCustomer(adrMenu &M, adrCustomer &p, adrCustomer prec){
    p = prec->next;
    prec->next = p->next;
    prec->next->prev = prec;
}

/*
    I.S : List customer M terdefinisi (mungkin kosong atau berisi), data x terdefinisi.
    F.S : Mengembalikan pointer ke elemen customer dengan data yang sesuai dengan x (berdasarkan field yang relevan).
          Jika tidak ditemukan, mengembalikan nullptr.
*/
adrCustomer findElementCustomer(adrMenu &M, string id){
    adrCustomer q = M->firstCustomer;
    while (q->info.id != id && q->next != nullptr){
        q = q->next;
    }
    if (q->info.id == id){
        return q;
    }else{
        return nullptr;
    }
}

/*
    I.S : List customer M terdefinisi (mungkin kosong atau berisi).
    F.S : Menampilkan semua customer dalam list M ke output dengan format yang terstruktur.
          Struktur list tidak berubah setelah pemanggilan fungsi ini.
*/
void viewCustomer(adrMenu &M){
    if (M->firstCustomer == nullptr){
        cout << "Tidak ada pelanggan dari menu ini" << endl;
    }else{
        adrCustomer q = M->firstCustomer;
        cout << "------------ Customer dari " << M->info.name << " ------------" << endl;
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "VIP" << setw(10) << "Order Quantity" << endl;
        cout << setw(10) << q->info.id << setw(20) << q->info.name << setw(10) << q->info.vip << setw(10) << q->info.quantity << endl;
        while (q->next != nullptr){
            q = q->next;
            cout << setw(10) << q->info.id << setw(20) << q->info.name << setw(10) << q->info.vip << setw(10) << q->info.quantity << endl;
        }
        cout << "----------------------------------------------" << endl;
    }
}

/*
    I.S : List customer M terdefinisi (mungkin kosong atau berisi).
    F.S : Menampilkan semua pesanan yang ada.
*/
void viewAllOrders(listMenu M)
{
    adrMenu temp = M.first;
    while (temp != nullptr){
        int n = 0;
        adrCustomer q = temp->firstCustomer;
        while(q != nullptr){
            n = n + q->info.quantity;
            q = q->next;
        }
        if (n > 0){
            cout << temp->info.id << " | " << temp->info.name << " || Jumlah Pesanan: " << n << endl;
        }
        temp = temp->next;
    }
}
