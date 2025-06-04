#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc phân số
typedef struct
{
    int tu;
    int mau;
} phanso;

// Định nghĩa cấu trúc hỗn số
typedef struct
{
    int nguyen; // phần nguyên
    int tu;     // tử số phần phân số
    int mau;    // mẫu số phần phân số
} honso;

// Function prototypes từ thư viện
void nhap(phanso *ps);
void xuat(phanso *ps);
void cong(phanso *ps1, phanso *ps2);
void tru(phanso *ps1, phanso *ps2);
void nhan(phanso *ps1, phanso *ps2);
void chia(phanso *ps1, phanso *ps2);

// Function prototypes cho hỗn số
void nhapHonSo(honso *hs);
void xuatHonSo(honso *hs);
phanso doiHonSoSangPhanSo(honso *hs);
void congHonSo(honso *hs1, honso *hs2);
void truHonSo(honso *hs1, honso *hs2);
void nhanHonSo(honso *hs1, honso *hs2);
void chiaHonSo(honso *hs1, honso *hs2);

// Hàm nhập hỗn số
void nhapHonSo(honso *hs)
{
    printf("Nhap phan nguyen: ");
    scanf("%d", &hs->nguyen);
    printf("Nhap tu so phan phan so: ");
    scanf("%d", &hs->tu);
    do
    {
        printf("Nhap mau so phan phan so (khac 0): ");
        scanf("%d", &hs->mau);
        if (hs->mau == 0)
        {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (hs->mau == 0);
}

// Hàm xuất hỗn số
void xuatHonSo(honso *hs)
{
    if (hs->nguyen == 0)
    {
        printf("%d/%d", hs->tu, hs->mau);
    }
    else if (hs->tu == 0)
    {
        printf("%d", hs->nguyen);
    }
    else
    {
        printf("%d_%d/%d", hs->nguyen, hs->tu, hs->mau);
    }
}

// Hàm đổi hỗn số sang phân số
phanso doiHonSoSangPhanSo(honso *hs)
{
    phanso ps;
    ps.tu = hs->nguyen * hs->mau + hs->tu;
    ps.mau = hs->mau;
    return ps;
}

// Hàm cộng hai hỗn số
void congHonSo(honso *hs1, honso *hs2)
{
    phanso ps1 = doiHonSoSangPhanSo(hs1);
    phanso ps2 = doiHonSoSangPhanSo(hs2);
    printf("Ket qua cong: ");
    cong(&ps1, &ps2);
}

// Hàm trừ hai hỗn số
void truHonSo(honso *hs1, honso *hs2)
{
    phanso ps1 = doiHonSoSangPhanSo(hs1);
    phanso ps2 = doiHonSoSangPhanSo(hs2);
    printf("Ket qua tru: ");
    tru(&ps1, &ps2);
}

// Hàm nhân hai hỗn số
void nhanHonSo(honso *hs1, honso *hs2)
{
    phanso ps1 = doiHonSoSangPhanSo(hs1);
    phanso ps2 = doiHonSoSangPhanSo(hs2);
    printf("Ket qua nhan: ");
    nhan(&ps1, &ps2);
}

// Hàm chia hai hỗn số
void chiaHonSo(honso *hs1, honso *hs2)
{
    phanso ps1 = doiHonSoSangPhanSo(hs1);
    phanso ps2 = doiHonSoSangPhanSo(hs2);
    printf("Ket qua chia: ");
    chia(&ps1, &ps2);
}

int main()
{
    honso *hs1, *hs2;

    // Cấp phát bộ nhớ
    hs1 = (honso *)malloc(sizeof(honso));
    hs2 = (honso *)malloc(sizeof(honso));

    printf("=== CHUONG TRINH TINH TOAN HON SO ===\n");

    // Nhập hỗn số thứ nhất
    printf("\nNhap hon so thu nhat:\n");
    nhapHonSo(hs1);

    // Nhập hỗn số thứ hai
    printf("\nNhap hon so thu hai:\n");
    nhapHonSo(hs2);

    // Hiển thị hỗn số đã nhập
    printf("\nHon so thu nhat: ");
    xuatHonSo(hs1);
    printf("\nHon so thu hai: ");
    xuatHonSo(hs2);

    // Chuyển đổi và hiển thị dạng phân số
    printf("\n\n=== CHUYEN DOI SANG PHAN SO ===\n");
    phanso ps1 = doiHonSoSangPhanSo(hs1);
    phanso ps2 = doiHonSoSangPhanSo(hs2);
    printf("Hon so thu nhat thanh phan so: ");
    xuat(&ps1);
    printf("Hon so thu hai thanh phan so: ");
    xuat(&ps2);

    // Thực hiện các phép tính
    printf("\n=== CAC PHEP TINH ===\n");
    congHonSo(hs1, hs2);
    truHonSo(hs1, hs2);
    nhanHonSo(hs1, hs2);
    chiaHonSo(hs1, hs2);

    // Giải phóng bộ nhớ
    free(hs1);
    free(hs2);

    return 0;
}
