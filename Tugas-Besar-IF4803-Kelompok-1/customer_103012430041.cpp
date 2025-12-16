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
void transaction(adrMenu &M, adrCustomer &p, int quantity)
{
    if ((p->info.balance >= M->info.price * quantity && p->info.vip == true) && (M->info.stock >= quantity))
    {
        p->info.balance = p->info.balance - (M->info.price * quantity);
        M->info.stock -= quantity;
        insertFirstCustomer(M, p);
        cout << "[SUKSES] Pesanan berhasil dibuat!" << endl;
    }
    else if ((p->info.balance >= M->info.price * quantity && p->info.vip == false) && (M->info.stock >= quantity))
    {
        p->info.balance = p->info.balance - (M->info.price * quantity);
        M->info.stock -= quantity;
        insertLastCustomer(M, p);
        cout << "[SUKSES] Pesanan berhasil dibuat!" << endl;
    }
    else
    {
        cout << "[INFO] Saldo Pengguna " << p->info.name << " tidak mencukupi, jumlah saldo anda: " << p->info.balance << endl;
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
void insertFirstCustomer(adrMenu &M, adrCustomer p)
{
    if (checkEmptyCustomer(M))
    {
        M->firstCustomer = p;
    }
    else
    {
        p->next = M->firstCustomer;
        M->firstCustomer->prev = p;
        M->firstCustomer = p;
    }
};

/*
    I.S : List customer M mungkin kosong atau sudah berisi. p belum berada dalam list.
    F.S : p menjadi elemen terakhir list customer. Transaksi diproses.
*/
void insertLastCustomer(adrMenu &M, adrCustomer p)
{
    if (checkEmptyCustomer(M))
    {
        M->firstCustomer = p;
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
};

/*
    I.S : List menu M terdefinisi dan mungkin berisi beberapa menu dengan customer.
    F.S : Menampilkan semua customer yang memiliki status VIP dari seluruh list menu.
*/
void showVipCustomer(listMenu &M)
{
    adrMenu temp = M.first;
    while (temp != nullptr)
    {
        adrCustomer q = temp->firstCustomer;
        while (q != nullptr)
        {
            if (q->info.vip == true)
            {
                cout << "Customer VIP: " << q->info.name << " (ID: " << q->info.id << ", Balance: " << q->info.balance << ")" << endl;
            }
            q = q->next;
        }
        temp = temp->next;
    }
}

/*
    I.S : List menu M terdefinisi dan namaMenu terdefinisi.
    F.S : Mengembalikan pointer ke elemen menu yang memiliki nama sesuai namaMenu.
          Jika tidak ditemukan, mengembalikan nullptr.
*/
adrMenu searchMenu(listMenu &M, string namaMenu)
{

    adrMenu temp = M.first;
    while (temp != nullptr)
    {
        if (temp->info.name == namaMenu)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
};

/*
    I.S : List menu M terdefinisi dan idCustomer terdefinisi.
    F.S : Menampilkan daftar pesanan dari customer dengan ID sesuai idCustomer,
          menunjukkan nama menu dan total pemesanan untuk setiap menu.
*/
void showListPesanan(listMenu &M, string idCustomer)
{
    adrMenu temp = M.first;
    cout << "===== Daftar Pesanan =====" << endl;

    while (temp != nullptr)
    {
        int total = countPesanan(temp, idCustomer);

        if (total > 0)
        {
            cout << temp->info.id << " | "
                 << temp->info.name
                 << " | Total: " << total << endl;
        }

        temp = temp->next;
    }

    cout << "-----------------------------" << endl;
}

/*
    I.S : menu terdefinisi dan idCustomer terdefinisi.
    F.S : Mengembalikan jumlah total pesanan (jumlah elemen customer dengan ID tertentu)
          dalam list customer menu.
*/
int countPesanan(adrMenu menu, string idCustomer)
{
    int totalMenu = 0;
    adrCustomer tempC = menu->firstCustomer;

    while (tempC != nullptr)
    {
        if (tempC->info.id == idCustomer)
        {
            totalMenu++;
        }
        tempC = tempC->next;
    }
    return totalMenu;
}

/*
    I.S : customer terdefinisi dengan balance awal tertentu.
    F.S : Meminta input deposit saldo dari user, menambahkan nilai tersebut ke customer.balance,
          dan menampilkan saldo akhir customer.
*/
void addBalance(infotypeC &customer)
{
    int newBalance;
    cout << "[INFO] Masukkan deposit saldo: ";
    cin >> newBalance;
    customer.balance = customer.balance + newBalance;
    cout << "[INFO] Saldo anda berhasil ditambahkan! saldo anda sekarang: " << customer.balance << endl;
}

/*
    I.S : List menu M terdefinisi. Customer belum masuk ke menu mana pun.
    F.S : Jika customer VIP → dimasukkan sebagai elemen pertama.
          Jika tidak VIP → dimasukkan sebagai elemen terakhir.
          Transaksi diproses untuk customer tersebut.
*/
void orderMenu(listMenu &M, string namaMenu, infotypeC &customer, int quantity)
{
    int i;
    adrMenu temp = searchMenu(M, namaMenu);
    adrCustomer x;

    if (customer.balance > temp->info.price * quantity)
    {
        customer.balance = customer.balance - temp->info.price * quantity;
    }
    for (i = 0; i < quantity; i++)
    {
        x = createElementCustomer(customer);
        transaction(temp, x, i);
    }
    deleteWhenStockZero(M);
}
