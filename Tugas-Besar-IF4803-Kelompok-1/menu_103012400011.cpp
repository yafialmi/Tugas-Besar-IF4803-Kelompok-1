#include "menu.h"

void createListParent(listParent &L);
adrMenu createElementParent(infotypeP x);
void insertFirstParent(listParent &L, adrMenu p);
void insertLastParent(listParent &L, adrMenu p);
void insertAfterParent(listParent &L, adrMenu p, adrMenu prec);
void deleteFirstParent(listParent &L, adrMenu &p);
void deleteLastParent(listParent &L, adrMenu &p);
void deleteAfterParent(listParent &L, adrMenu &p, adrMenu prec);
adrMenu findElementParent(listParent &L, infotypeP x);
void viewParent(listParent &L);
