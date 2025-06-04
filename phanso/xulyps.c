#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int tu;
    int mau;
} phanso;
// Function prototypes
void nhap(phanso *ps);
void xuat(phanso *ps);
void cong(phanso *ps1, phanso *ps2);
void tru(phanso *ps1, phanso *ps2);
void nhan(phanso *ps1, phanso *ps2);
void chia(phanso *ps1, phanso *ps2);

int main()
{
    phanso *ps1, *ps2;
    ps1 = (phanso *)malloc(sizeof(phanso));
    ps2 = (phanso *)malloc(sizeof(phanso));
    printf("Nhap phan so thu nhat:\n");
    nhap(ps1);
    printf("Nhap phan so thu hai:\n");
    nhap(ps2);

    printf("Cong: ");
    cong(ps1, ps2);
    printf("Tru: ");
    tru(ps1, ps2);
    printf("Nhan: ");
    nhan(ps1, ps2);
    printf("Chia: ");
    chia(ps1, ps2);
    free(ps1);
    free(ps2);
    return 0;
}