#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmCustomer *adrCustomer;
struct infotype_customer{
    /* Tolong lengkapin ADT untuk Customer */
    int id;
    string name;
};

struct elmCustomer {
    infotype_customer info;
    adrCustomer next;
    adrCustomer netClass;
};

#endif // CUSTOMER_H_INCLUDED
