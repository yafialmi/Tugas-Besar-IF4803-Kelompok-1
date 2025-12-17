#include "menu.h"
#include <iostream>
#include <iomanip>
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
void viewMenu(listMenu L){
    adrMenu q = L.first;
    if (q == nullptr) {
        cout << "Menu kosong." << endl;
    }else{
        cout << "-------------------- Menu --------------------" << endl;
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Stock" << endl;
        cout << setw(10) << q->info.id << setw(20) << q->info.name << setw(10) << q->info.price << setw(10) << q->info.stock << endl;
        while (q->next != nullptr){
            q = q->next;
            cout << setw(10) << q->info.id << setw(20) << q->info.name << setw(10) << q->info.price << setw(10) << q->info.stock << endl;
        }
        cout << "----------------------------------------------" << endl;
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
/*
    I.S : List menu L terdefinisi, elemen dengan ID x ditemukan dalam list, dan x terdefinisi.
    F.S : Menambah nilai stock menu dengan ID x sebanyak 1.
*/
void increaseStock(listMenu &L, string x, int p){
    adrMenu q;
    q = findElementMenu(L, x);
    if (q != nullptr){
        q->info.stock = q->info.stock + p;
        cout << "Stock berhasil ditambahkan" << endl;
    }else{
        cout << "Menu tidak ditemukan" << endl;
    }
}

/*
    I.S : ListMenu dan M terdefinisi.
    F.S : Memasukkan M kedalam ListMenu, disorting sesuai dengan abjadnya.
*/
/*
    I.S : List menu L terdefinisi (mungkin kosong atau berisi), M terdefinisi dan siap disisipkan.
    F.S : M disisipkan ke dalam list L dengan urutan berdasarkan nama menu secara alfabetis.
*/
void tambahMenu(listMenu &L, adrMenu M){
    if (L.first == nullptr){
        L.first = M;
    }else if(M->info.name < L.first->info.name){
        M->next = L.first;
        L.first = M;
    }else{
        adrMenu Q = L.first;
        while (Q->next != nullptr && Q->next->info.name < M->info.name) {
        Q = Q->next;
        }
        M->next = Q->next;
        Q->next = M;
    }
}
