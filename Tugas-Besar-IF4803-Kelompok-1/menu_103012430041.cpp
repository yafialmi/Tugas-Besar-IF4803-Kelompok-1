#include "menu.h"

bool checkEmptyMenu(listMenu L){
    return L.first == nullptr;
};

void createListMenu(listMenu &L){
    L.first = nullptr;
};

adrMenu createElementMenu(infotypeP x){
    adrMenu p;
    p = new elmMenu();
    p->firstCustomer = nullptr;
    p->info = x;
    p->next = nullptr;

    return p;
};

void insertFirstMenu(listMenu &L, adrMenu &p){
    if(checkEmptyMenu(L)){
        L.first = p;
    }else{
        p->next = L.first;
        L.first = p;
    }
};
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
void insertAfterMenu(listMenu &L, adrMenu &p, adrMenu &prec){
    /* I.S: List tidak kosong, prec tidak berada di L.first ataupun L.last */
    p->next = prec->next;
    prec->next = p;
};
