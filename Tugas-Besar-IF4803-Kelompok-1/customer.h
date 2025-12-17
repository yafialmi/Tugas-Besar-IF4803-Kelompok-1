#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
#include "menu.h"
#include <string>

using namespace std;

typedef struct elmCustomer *adrCustomer;
typedef struct elmMenu *adrMenu;
typedef struct customer infotypeC;

struct listMenu;

struct customer
{
    int balance;
    int quantity;
    bool vip = false;
    string id;
    string name;
};

struct elmCustomer
{
    infotypeC info;
    adrCustomer next;
    adrCustomer prev;
};

bool checkEmptyCustomer(adrMenu M);
void createListCustomer(adrMenu &M);
adrCustomer createElementCustomer(infotypeC x);
void insertFirstCustomer(adrMenu &M, adrCustomer p);
void insertLastCustomer(adrMenu &M, adrCustomer p);
void insertAfterCustomer(adrMenu &M, adrCustomer p, adrCustomer prec);
void deleteFirstCustomer(adrMenu &M, adrCustomer &p);
void deleteLastCustomer(adrMenu &M, adrCustomer &p);
void deleteAfterCustomer(adrMenu &M, adrCustomer &p, adrCustomer prec);
adrCustomer findElementCustomer(adrMenu M, string id);
void viewCustomer(adrMenu &M);
void showListPesanan(listMenu M, string idCustomer);
void addBalance(infotypeC &customer);
int countPesanan(adrMenu menu, string idCustomer);
void orderMenu(listMenu &M, string namaMenu, infotypeC &customer);

#endif // CUSTOMER_H_INCLUDED
