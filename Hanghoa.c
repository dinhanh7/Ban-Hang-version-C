#include "Hanghoa.h"

void Hanghoa_tao(Hanghoa* sp) {
    strcpy(sp->san_pham, "");
    strcpy(sp->ma_san_pham, "");
    sp->gia_thanh = 0.0;
    sp->so_luong = 0;
}

void Hanghoa_tao_san_pham(Hanghoa* sp , const char* sanPham, const char* maSanPham, double giaThanh, int soLuong) {
    strcpy(sp->san_pham, sanPham);
    strcpy(sp->ma_san_pham, maSanPham);
    sp->gia_thanh = giaThanh;
    sp->so_luong = soLuong;
}

void Hanghoa_nhap(Hanghoa* sp) {
    printf("Hay nhap cac thong tin sau cua san pham\n");
    printf("Nhap ten san pham: ");
    getchar();
    fgets(sp->san_pham, sizeof(sp->san_pham), stdin);
    strtok(sp->san_pham, "\n"); // Loai bo ki tu xuong dong
    printf("Nhap ma san pham: ");
    fgets(sp->ma_san_pham, sizeof(sp->ma_san_pham), stdin);
    strtok(sp->ma_san_pham, "\n");
    printf("Nhap gia thanh san pham: ");
    scanf("%lf", &sp->gia_thanh);
    printf("Nhap so luong san pham: ");
    scanf("%d", &sp->so_luong);
}

void Hanghoa_xuat(const Hanghoa* sp) {
    printf("%s    %s     %.2lf VND     x%d\n", sp->san_pham, sp->ma_san_pham, sp->gia_thanh, sp->so_luong);
}

void Hanghoa_set_tensp(Hanghoa* sp, const char* tensp) {
    strcpy(sp->san_pham, tensp);
}

void Hanghoa_set_masp(Hanghoa* sp, const char* ma) {
    strcpy(sp->ma_san_pham, ma);
}

void Hanghoa_set_giasp(Hanghoa* sp, double gia) {
    sp->gia_thanh = gia;
}

void Hanghoa_set_so_luong(Hanghoa* sp, int soLuong) {
    sp->so_luong = soLuong;
}

double Hanghoa_lay_gia_thanh(const Hanghoa* sp) {
    return sp->gia_thanh;
}

const char* Hanghoa_lay_ten_san_pham(const Hanghoa* sp) {
    return sp->san_pham;
}

const char* Hanghoa_lay_ma_don_hang(const Hanghoa* sp) {
    return sp->ma_san_pham;
}

int Hanghoa_lay_so_luong(const Hanghoa* sp) {
    return sp->so_luong;
}

