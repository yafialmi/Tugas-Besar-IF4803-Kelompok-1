#include "menu.h"
#include <iostream>
#include "customer.h"

/*
    I.S : ListMenu terdefinisi.
    F.S : Mengembalikan address dari elemen terakhir dalam list.
*/
adrMenu searchLast(listMenu &L) {
    adrMenu temp = L.first;
    while (temp->next !=  nullptr) {
        temp = temp->next;
    }
    return temp;
}

/*
    I.S : ListMenu terdefinisi, p kosong.
    F.S : Memasukkan elemen pertama ke p, menghapus elemen pertama dari list.
*/
void deleteFirstMenu(listMenu &L, adrMenu &p){
    p = L.first;
    L.first = p->next;
}

/*
    I.S : ListMenu terdefinisi, p kosong.
    F.S : Memasukkan elemen terakhir ke p, menghapus elemen terakhir dari list.
*/
void deleteLastMenu(listMenu &L, adrMenu &p){
    adrMenu q;
    q = L.first;
    while (q->next->next != nullptr){ 
        q = q->next;
    }
    p = q->next;
    q->next = nullptr;
}

/*
    I.S : ListMenu terdefinisi, p kosong, Mrec terdefinisi.
    F.S : Memasukkan elemen setelah Mrec ke p, menghapus elemen setelah Mrec dari list.
*/
void deleteAfterMenu(listMenu &L, adrMenu &p, adrMenu &Mrec){
    if (Mrec == L.first) {
        deleteFirstMenu(L, p);
    }else if (Mrec->next != nullptr){
        p = Mrec->next;
        Mrec->next = Mrec->next->next;
    }
}

/*
    I.S : ListMenu terdefinisi, infotype terdefinisi.
    F.S : Mengembalikan elemen yang memiliki infotype yang sama, jika tidak ada akan dikembalikan null.
*/
adrMenu findElementMenu(listMenu &L, string idMenu){
    adrMenu q = L.first;
    while (q->info.id != idMenu && q->next != nullptr){
        q = q->next;
    }
    if (q->info.id == idMenu){
        return q;
    }else{
        return nullptr;
    }
}

/*
    I.S : ListMenu terdefinisi.
    F.S : Menampilkan setiap menu yang ada.
*/
void viewMenu(listMenu &L){
    adrMenu q = L.first;
    cout << "Menu: (ID, Name, Price, Stock)";
    cout << q->info.id << " " << q->info.name << " " << q->info.price << " " << q->info.stock << endl;
    while (q->next != nullptr){
        q = q->next;
        cout << q->info.id << " " << q->info.name << " " << q->info.price << " " << q->info.stock << endl;
    }
}

/*
    I.S : infotype terdefinisi.
    F.S : Mengalokasikan infotype tersebut ke sebuah address.
*/
adrMenu allocate(infotypeP x){
    adrMenu P = new elmMenu;
    P->info = x;
    return P;
}

/*
    I.S : ListMenu dan x terdefinisi.
    F.S : Menambahkan stock dari menu yang memiliki ID sama dengan x
*/
void increaseStock(listMenu &L, string x){
    adrMenu q;
    q = findElementMenu(L, x);
    if (q->info.id == x){
        q->info.stock = q->info.stock + 1;
    }
}

