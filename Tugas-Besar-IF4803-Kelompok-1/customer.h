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

struct listChild {
    adrCustomer first;
    adrCustomer last;
};

void createListChild(listChild &L);
adrCustomer createElementChild(infotypeC x);
void insertFirstChild(listChild &L, adrCustomer p);
void insertLastChild(listChild &L, adrCustomer p);
void insertAfterChild(listChild &L, adrCustomer p, adrCustomer prec);
void deleteFirstChild(listChild &L, adrCustomer &p);
void deleteLastChild(listChild &L, adrCustomer &p);
void deleteAfterChild(listChild &L, adrCustomer &p, adrCustomer prec);
adrCustomer findElementChild(listChild &L, infotypeC x);
void viewChild(listChild &L);


#endif // CUSTOMER_H_INCLUDED
