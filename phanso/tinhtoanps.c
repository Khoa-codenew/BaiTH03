#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int tu;
    int mau;
} phanso;
void cong(phanso *ps1, phanso *ps2)
{
    phanso kq;
    kq.tu = ps1->tu * ps2->mau + ps2->tu * ps1->mau;
    kq.mau = ps1->mau * ps2->mau;
    xuat(kq);
}
void tru(phanso *ps1, phanso *ps2)
{
    phanso kq;
    kq.tu = ps1->tu * ps2->mau - ps2->tu * ps1->mau;
    kq.mau = ps1->mau * ps2->mau;
    xuat(kq);
}
void nhan(phanso *ps1, phanso *ps2)
{
    phanso kq;
    kq.tu = ps1->tu * ps2->tu;
    kq.mau = ps1->mau * ps2->mau;
    xuat(kq);
}
void chia(phanso *ps1, phanso *ps2)
{
    phanso kq;
    kq.tu = ps1->tu * ps2->mau;
    kq.mau = ps1->mau * ps2->tu;
    xuat(kq);
}