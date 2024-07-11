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

void Hanghoa_tao(Hanghoa* sp);
void Hanghoa_tao_san_pham(Hanghoa* sp, const char* sanPham, const char* maSanPham, double giaThanh, int soLuong);
void Hanghoa_nhap(Hanghoa* sp);
void Hanghoa_xuat(const Hanghoa* sp);
void Hanghoa_set_tensp(Hanghoa* sp, const char* tensp);
void Hanghoa_set_masp(Hanghoa* sp, const char* ma);
void Hanghoa_set_giasp(Hanghoa* sp, double gia);
void Hanghoa_set_so_luong(Hanghoa* sp, int soLuong);
double Hanghoa_lay_gia_thanh(const Hanghoa* sp);
const char* Hanghoa_lay_ten_san_pham(const Hanghoa* sp);
const char* Hanghoa_lay_ma_don_hang(const Hanghoa* sp);
int Hanghoa_lay_so_luong(const Hanghoa* sp);

#endif
