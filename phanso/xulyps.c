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
/*
su khac biet thu vien dong tinh
-kich thuoc file file thuc thi file tinh > file dong
-file tinh chi phu thuoc vao system libraries con file dong phu thuoc vao psdong.so trong lib
- file tinh co the chay doc lap khong can file thu vien con file dong phu thuoc vao psdong.so
- can complie lai file tinh khi thu vien thay doi con file dong chi can cap nhat file so khong can recompile lai main
*/