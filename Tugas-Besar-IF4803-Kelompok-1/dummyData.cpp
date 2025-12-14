#include "menu.h"

infotypeP x;

void insertDummyDataMenu1(listMenu &L) {
    x.id = "ID001";
    x.name = "Nasi Goreng";
    x.price = 18000;
    x.stock = 10;
    insertFirstMenu(L, createElementMenu(x));
}

void insertDummyDataMenu2(listMenu &L) {
    x.id = "ID002";
    x.name = "Mie Goreng";
    x.price = 15000;
    x.stock = 5;
    insertFirstMenu(L, createElementMenu(x));
}

void insertDummyDataMenu3(listMenu &L) {
    x.id = "ID003";
    x.name = "Kwetiaw Goreng";
    x.price = 12000;
    x.stock = 7;
    insertFirstMenu(L, createElementMenu(x));
}
