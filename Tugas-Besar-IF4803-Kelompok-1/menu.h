#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
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
};


#endif // MENU_H_INCLUDED
