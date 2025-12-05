#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmCustomer *adrCustomer;
typedef struct customer infotypeC;

struct customer{
    int id;
    int balance;
    string name;
};

struct elmCustomer {
    infotypeC info;
    adrCustomer next;
    adrCustomer prev;
};

struct listCustomer {
    adrCustomer first;
    adrCustomer last;
};

bool checkEmptyCustomer(listCustomer L);
void createListCustomer(listCustomer &L);
adrCustomer createElementCustomer(infotypeC x);
void insertFirstCustomer(listCustomer &L, adrCustomer p);
void insertLastCustomer(listCustomer &L, adrCustomer p);
void insertAfterCustomer(listCustomer &L, adrCustomer p, adrCustomer prec);
void deleteFirstCustomer(listCustomer &L, adrCustomer &p);
void deleteLastCustomer(listCustomer &L, adrCustomer &p);
void deleteAfterCustomer(listCustomer &L, adrCustomer &p, adrCustomer prec);
adrCustomer findElementCustomer(listCustomer &L, infotypeC x);
void viewCustomer(listCustomer &L);


#endif // CUSTOMER_H_INCLUDED
