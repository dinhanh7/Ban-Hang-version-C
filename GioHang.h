#ifndef GIOHANG_H
#define GIOHANG_H

#include "Hanghoa.h"

typedef struct {
    Hanghoa* gioHang;
    int soLuongHang;
    double tienThanhToan;
    double phanTramGiamGia;
} GioHang;


void GioHang_tao(GioHang* sp);
void GioHang_them_san_pham(GioHang* sp, Hanghoa sanPham, int soLuong);
void GioHang_xoa_san_pham(GioHang* sp, int index);
void GioHang_in_gio_hang(const GioHang* sp);
void GioHang_ap_ma_giam_gia(GioHang* sp, double phanTram);
void GioHang_thanh_toan(const GioHang* sp);
void GioHang_cap_nhat_tien_thanh_toan(GioHang* sp);
void GioHang_free(GioHang* sp);

#endif
