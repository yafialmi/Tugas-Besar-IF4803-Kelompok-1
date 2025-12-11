#include "customer.h"

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
    adrCustomer q = M->firstCustomer;
    cout << "Customer dari menu " << M->info.name << " : (ID, Name, Balance, VIP)" << endl;
    cout << q->info.id << " " << q->info.name << " " << q->info.balance << " " << q->info.vip << endl;
    while (q->next != nullptr){
        q = q->next;
        cout << q->info.id << " " << q->info.name << " " << q->info.balance << " " << q->info.vip << endl;
    }
}