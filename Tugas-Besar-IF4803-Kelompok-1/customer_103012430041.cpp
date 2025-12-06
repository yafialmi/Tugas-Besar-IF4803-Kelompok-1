#include "customer.h"

/* 
    I.S : Data M terdefinisi.
    F.S : Mengembalikan true jika M->firstCustomer == nullptr, selain itu false.
*/
bool checkEmptyCustomer(adrMenu M)
{
    return M->firstCustomer == nullptr;
};

/* 
    I.S : M, p, dan quantity terdefinisi. Saldo user & stok menu belum berubah.
    F.S : Jika saldo cukup → saldo dikurangi price*quantity dan stok menu berkurang 1.
          Jika saldo tidak cukup → menampilkan pesan saldo tidak mencukupi.
*/
void transaction(adrMenu &M, adrCustomer p, int quantity)
{
    if (p->info.balance > M->info.price)
    {
        p->info.balance = p->info.balance - (M->info.price * quantity);
        M->info.stock--;
    }else {
        cout << "Saldo Pengguna " << p->info.name << " tidak mencukupi" << endl;
    }
}

/* 
    I.S : Data x terdefinisi.
    F.S : Menghasilkan elemen customer baru dengan info x, next = nullptr, prev = nullptr.
*/
adrCustomer createElementCustomer(infotypeC x)
{
    adrCustomer p;
    p = new elmCustomer();
    p->info = x;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
};

/* 
    I.S : List customer M mungkin kosong atau berisi. p belum berada dalam list.
    F.S : p menjadi elemen pertama list customer. Transaksi untuk p diproses.
*/
void insertFirstCustomer(adrMenu &M, adrCustomer p, int quantity)
{
    if (checkEmptyCustomer(M))
    {
        M->firstCustomer = p;
        transaction(M, p, quantity);
    }
    else
    {
        M->firstCustomer->prev = p;
        p->next = M->firstCustomer;
        M->firstCustomer = p;
        transaction(M, p, quantity);
    }
};

/* 
    I.S : List customer M mungkin kosong atau sudah berisi. p belum berada dalam list.
    F.S : p menjadi elemen terakhir list customer. Transaksi diproses.
*/
void insertLastCustomer(adrMenu &M, adrCustomer p, int quantity)
{
    if (checkEmptyCustomer(M))
    {
        M->firstCustomer = p;
        transaction(M, p, quantity);
    }
    else
    {
        adrCustomer temp = M->firstCustomer;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        };
        p->prev = temp;
        temp->next = p;
        transaction(M, p, quantity);
        ;
    }
};

/* 
    I.S : List customer tidak kosong. prec berada di tengah list dan p belum terhubung.
    F.S : p disisipkan setelah prec, relasi next dan prev diperbarui. Transaksi diproses.
*/
void insertAfterCustomer(adrMenu &M, adrCustomer p, adrCustomer prec, int quantity)
{
    /* I.S: List terdefinisi dan prec tidak berada di L.first ataupun L.last */
    p->prev = prec;
    p->next = prec->next;
    prec->next->prev = p;
    prec->next = p;
    transaction(M, p, quantity);
};

/* 
    I.S : List menu M terdefinisi. Customer belum masuk ke menu mana pun.
    F.S : Jika customer VIP → dimasukkan sebagai elemen pertama.
          Jika tidak VIP → dimasukkan sebagai elemen terakhir.
          Transaksi diproses untuk customer tersebut.
*/
void orderMenu(listMenu &M, string idMenu, infotypeC customer, int quantity)
{
    adrMenu temp = M.first;
    adrCustomer x;
    bool found = false;
    while (temp != nullptr && found != true)
    {
        if (temp->info.id == idMenu)
        {
            found = true;
        }
        temp = temp->next;
    }
    x = createElementCustomer(customer);
    if (x->info.vip == true) {
        insertFirstCustomer(temp, x, quantity);
    }else{
        insertLastCustomer(temp, x, quantity);
    }
}
