#include <stdio.h>
typedef struct
{
    int tu;
    int mau;
} phanso;
void nhap(phanso *ps)
{
    printf("Nhap tu so:");
    scanf("%d", &ps->tu);
    do
    {
        printf("Nhap mau so (khac 0):");
        scanf("%d", &ps->mau);
        if (ps->mau == 0)
        {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}
int ucln(int a, int b)
{
    if (b == 0)
        return a;
    return ucln(b, a % b);
}
void xuat(phanso *ps)
{
    int uc = ucln(ps->tu, ps->mau);
    ps->tu /= uc;
    ps->mau /= uc;
    printf("%d/%d\n", ps->tu, ps->mau);
}