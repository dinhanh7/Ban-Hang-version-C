#include "Hanghoa.h"

void Hanghoa_init(Hanghoa* self) {
    strcpy(self->san_pham, "");
    strcpy(self->ma_san_pham, "");
    self->gia_thanh = 0.0;
    self->so_luong = 0;
}

void Hanghoa_init_with_details(Hanghoa* self, const char* sanPham, const char* maSanPham, double giaThanh, int soLuong) {
    strcpy(self->san_pham, sanPham);
    strcpy(self->ma_san_pham, maSanPham);
    self->gia_thanh = giaThanh;
    self->so_luong = soLuong;
}

void Hanghoa_nhap(Hanghoa* self) {
    printf("Nhap thong tin san pham: ");
    printf("\nNhap ten san pham: ");
    getchar();
    fgets(self->san_pham, sizeof(self->san_pham), stdin);
    strtok(self->san_pham, "\n"); // Lo?i b? ký t? xu?ng dòng
    printf("\nNhap ma san pham: ");
    fgets(self->ma_san_pham, sizeof(self->ma_san_pham), stdin);
    strtok(self->ma_san_pham, "\n");
    printf("\nNhap gia thanh san pham: ");
    scanf("%lf", &self->gia_thanh);
    printf("\nNhap so luong san pham: ");
    scanf("%d", &self->so_luong);
}

void Hanghoa_xuat(const Hanghoa* self) {
    printf("%s    %s     %.2lf VND     x%d\n", self->san_pham, self->ma_san_pham, self->gia_thanh, self->so_luong);
}

void Hanghoa_set_tensp(Hanghoa* self, const char* tensp) {
    strcpy(self->san_pham, tensp);
}

void Hanghoa_set_masp(Hanghoa* self, const char* ma) {
    strcpy(self->ma_san_pham, ma);
}

void Hanghoa_set_giasp(Hanghoa* self, double gia) {
    self->gia_thanh = gia;
}

void Hanghoa_set_so_luong(Hanghoa* self, int soLuong) {
    self->so_luong = soLuong;
}

double Hanghoa_lay_gia_thanh(const Hanghoa* self) {
    return self->gia_thanh;
}

const char* Hanghoa_lay_ten_san_pham(const Hanghoa* self) {
    return self->san_pham;
}

const char* Hanghoa_lay_ma_don_hang(const Hanghoa* self) {
    return self->ma_san_pham;
}

int Hanghoa_lay_so_luong(const Hanghoa* self) {
    return self->so_luong;
}

