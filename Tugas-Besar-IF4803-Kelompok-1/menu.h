#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "customer.h"
using namespace std;

typedef struct elmMenu *adrMenu;
struct infotype_menu{
    int id;
    int quantity;
    int price;
    string name;
};

struct elmMenu {
    infotype_menu info;
    adrMenu next;
    adrCustomer firstChild;
};

struct ListMenu {
    adrMenu first;
};


#endif // MENU_H_INCLUDED
