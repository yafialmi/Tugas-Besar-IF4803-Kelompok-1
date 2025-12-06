#include "menu.h"
#include <iostream>
#include "customer.h"

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
    for (q->next->next != nullptr){
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
    if (Mrec->next != nullptr){
        p = Mrec->next;
        Mrec->next = Mrec->next->next;
    }
}

/*
    I.S : ListMenu terdefinisi, infotype terdefinisi.
    F.S : Mengembalikan elemen yang memiliki infotype yang sama, jika tidak ada akan dikembalikan null.
*/
adrMenu findElementMenu(listMenu &L, infotypeP x){
    adrMenu q = L.first;
    for (q->info != x && q->next != nullptr){
        q = q->next;
    }
    if (q->info == x){
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
    cout << "Menu: (ID, Name, Price, Stock)"
    cout << q->info.id << " " << q->info.name << " " << q->info.price << " " << q->info.stock << endl;
    for (q->next != nullptr){
        q = q->next
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
    F.S : Mengurangi stock dari menu yang memiliki ID sama dengan x
*/
void reduceStock(listMenu &L, string x){
    adrMenu q = L.first;
    for (q->info.id != x && q->next != nullptr){
        q = q->next;
    }
    if (q->info.id == x){
        q->info.stock = q->info.stock - 1;
    }
}

