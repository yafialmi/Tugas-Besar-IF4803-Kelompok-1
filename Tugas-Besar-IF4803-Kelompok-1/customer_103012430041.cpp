#include "customer.h"

bool checkEmptyCustomer(listCustomer L){
    return L.first == nullptr && L.last == nullptr;
};

void createListCustomer(listCustomer &L){
    L.first = nullptr;
    L.last = nullptr;
};

adrCustomer createElementCustomer(infotypeC x){
    adrCustomer p;
    p = new elmCustomer();
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
};
void insertFirstCustomer(listCustomer &L, adrCustomer p){
    if(checkEmptyCustomer(L)){
        L.first = p;
        L.last = p;
    }else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
};
void insertLastCustomer(listCustomer &L, adrCustomer p){
    if(checkEmptyCustomer(L)){
        L.first = p;
        L.last = p;
    }else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
};

void insertAfterCustomer(listCustomer &L, adrCustomer p, adrCustomer prec){
    /* I.S: List terdefinisi dan prec tidak berada di L.first ataupun L.last */
    p->prev = prec;
    p->next = prec->next;
    prec->next->prev = p;
    prec->next = p;
};