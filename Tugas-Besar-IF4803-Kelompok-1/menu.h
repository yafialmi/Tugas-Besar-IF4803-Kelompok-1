#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "customer.h"
using namespace std;

typedef struct elmCustomer *adrCustomer;
typedef struct elmMenu *adrMenu;
typedef struct menu infotypeP;

struct menu
{
    string id;
    string name;
    int stock;
    int price;
};

struct elmMenu
{
    infotypeP info;
    adrMenu next;
    adrCustomer firstCustomer;
};

struct listMenu
{
    adrMenu first;
};

bool checkEmptyMenu(listMenu L);
void createListMenu(listMenu &L);
adrMenu createElementMenu(infotypeP x);
void insertFirstMenu(listMenu &L, adrMenu M);
void insertLastMenu(listMenu &L, adrMenu M);
void insertAfterMenu(listMenu &L, adrMenu M, adrMenu Mrec);
void deleteFirstMenu(listMenu &L, adrMenu &p);
void deleteLastMenu(listMenu &L, adrMenu &p);
void deleteAfterMenu(listMenu &L, adrMenu &p, adrMenu &Mrec);
void viewMenu(listMenu L);
adrMenu allocate(infotypeP x);
void increaseStock(listMenu &L, string x, int p);
adrMenu searchMenu(listMenu M, string namaMenu);
adrMenu findElementMenu(listMenu &L, string idMenu);
void tambahMenu(listMenu &L, adrMenu M);
void insertDummyDataMenu1(listMenu &L);
void insertDummyDataMenu2(listMenu &L);
void insertDummyDataMenu3(listMenu &L);
void deleteMenuIfStockZero(listMenu &L);
adrMenu checkStockMenu(listMenu &L);
adrMenu searchLast(listMenu &L);

#endif // MENU_H_INCLUDED
