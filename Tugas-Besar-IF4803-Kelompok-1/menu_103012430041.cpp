#include "menu.h"
#include <iostream>
#include "customer.h"

/*
    I.S : List L terdefinisi.
    F.S : Mengembalikan true jika L.first == nullptr (list kosong), false jika list berisi elemen.
*/
bool checkEmptyMenu(listMenu L){
    return L.first == nullptr;
};

/*
    I.S : List L belum diinisialisasi.
    F.S : L.first = nullptr, list siap digunakan dalam kondisi kosong.
*/
void createListMenu(listMenu &L){
    L.first = nullptr;
};

/*
    I.S : Data x (informasi menu) terdefinisi.
    F.S : Membuat elemen menu baru dengan info x, firstCustomer = nullptr, next = nullptr.
          Mengembalikan pointer ke elemen yang baru dibuat.
*/
adrMenu createElementMenu(infotypeP x){
    adrMenu p;
    p = new elmMenu();
    p->firstCustomer = nullptr;
    p->info = x;
    p->next = nullptr;

    return p;
};

/*
    I.S : List L terdefinisi (mungkin kosong atau berisi). p terdefinisi dan siap disisipkan.
    F.S : Jika list kosong, p menjadi elemen pertama (L.first = p).
          Jika list tidak kosong, p menunjuk ke elemen pertama lama, dan L.first menunjuk ke p.
*/
void insertFirstMenu(listMenu &L, adrMenu &p){
    if(checkEmptyMenu(L)){
        L.first = p;
    }else{
        p->next = L.first;
        L.first = p;
    }
};
/*
    I.S : List L terdefinisi (mungkin kosong atau berisi). p terdefinisi dan siap disisipkan.
    F.S : Jika list kosong, p menjadi elemen pertama (L.first = p).
          Jika list tidak kosong, p menjadi elemen terakhir dengan p->next = nullptr.
*/
void insertLastMenu(listMenu &L, adrMenu &p){
    if(checkEmptyMenu(L)){
        L.first = p;
    }else{
        adrMenu temp = L.first;
        while(temp->next != nullptr){
            temp = temp->next;
        };
        temp->next = p;
    }
};
/*
    I.S : List tidak kosong, prec tidak berada di L.first ataupun L.last. p terdefinisi dan siap disisipkan.
    F.S : p disisipkan setelah prec. p->next menunjuk ke node yang sebelumnya ada setelah prec, dan prec->next menunjuk ke p.
*/
void insertAfterMenu(listMenu &L, adrMenu &p, adrMenu &prec){
    /* I.S: List tidak kosong, prec tidak berada di L.first ataupun L.last */
    p->next = prec->next;
    prec->next = p;
};

/*
    I.S : List L terdefinisi dan mungkin berisi beberapa elemen menu.
    F.S : Menghapus semua elemen menu dari list L yang memiliki nilai stock sama dengan 0.
          Elemen yang dihapus adalah yang berada setelah elemen saat ini dalam iterasi.
    Parameter:
        - listMenu &L : Referensi ke list menu yang akan diperiksa dan dihapus elemennya jika stock = 0.
*/
void deleteWhenStockZero(listMenu &L) {
    adrMenu p = L.first;
    adrMenu outputDelete;
    while (p != nullptr) {
        if(p->next != nullptr && p->next->info.stock == 0) {
            deleteAfterMenu(L, outputDelete, p);
        } else {
            p = p->next;
        }
    };
}

