#ifndef GIOHANG_H
#define GIOHANG_H

#include "Hanghoa.h"

typedef struct {
    Hanghoa* gioHang;
    int soLuongHang;
    double tienThanhToan;
    double phanTramGiamGia;
} GioHang;


void GioHang_init(GioHang* self);
void GioHang_them_san_pham(GioHang* self, Hanghoa sanPham);
void GioHang_xoa_san_pham(GioHang* self, int index);
void GioHang_in_gio_hang(const GioHang* self);
void GioHang_ap_ma_giam_gia(GioHang* self, double phanTram);
void GioHang_thanh_toan(const GioHang* self);
void GioHang_cap_nhat_tien_thanh_toan(GioHang* self);
void GioHang_free(GioHang* self);

#endif
