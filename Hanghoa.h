#ifndef HANGHOA_H
#define HANGHOA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char san_pham[100];
    char ma_san_pham[20];
    double gia_thanh;
    int so_luong;
} Hanghoa;

void Hanghoa_init(Hanghoa* self);
void Hanghoa_init_with_details(Hanghoa* self, const char* sanPham, const char* maSanPham, double giaThanh, int soLuong);
void Hanghoa_nhap(Hanghoa* self);
void Hanghoa_xuat(const Hanghoa* self);
void Hanghoa_set_tensp(Hanghoa* self, const char* tensp);
void Hanghoa_set_masp(Hanghoa* self, const char* ma);
void Hanghoa_set_giasp(Hanghoa* self, double gia);
void Hanghoa_set_so_luong(Hanghoa* self, int soLuong);
double Hanghoa_lay_gia_thanh(const Hanghoa* self);
const char* Hanghoa_lay_ten_san_pham(const Hanghoa* self);
const char* Hanghoa_lay_ma_don_hang(const Hanghoa* self);
int Hanghoa_lay_so_luong(const Hanghoa* self);

#endif
