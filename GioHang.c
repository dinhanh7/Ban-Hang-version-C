#include "GioHang.h"

void GioHang_tao(GioHang* sp) {
    sp->gioHang = NULL;
    sp->soLuongHang = 0;
    sp->tienThanhToan = 0.0;
    sp->phanTramGiamGia = 0.0;
}

void GioHang_them_san_pham(GioHang* sp, Hanghoa sanPham) {
    sp->gioHang = realloc(sp->gioHang, (sp->soLuongHang + 1) * sizeof(Hanghoa));
    sp->gioHang[sp->soLuongHang] = sanPham;
    sp->soLuongHang++;
    GioHang_cap_nhat_tien_thanh_toan(sp);
}

void GioHang_xoa_san_pham(GioHang* sp, int index) {
    if (index < 0 || index >= sp->soLuongHang) return;
    for (int i = index; i < sp->soLuongHang - 1; i++) {
        sp->gioHang[i] = sp->gioHang[i + 1];
    }
    sp->soLuongHang--;
    sp->gioHang = realloc(sp->gioHang, sp->soLuongHang * sizeof(Hanghoa));
    GioHang_cap_nhat_tien_thanh_toan(sp);
}

void GioHang_in_gio_hang(const GioHang* sp) {
    printf("\n<------------------Gio hang cua ban---------------->\n");
    for (int i = 0; i < sp->soLuongHang; i++) {
        printf("\n%d. ", i + 1);
        Hanghoa_xuat(&sp->gioHang[i]);
    }
}

void GioHang_ap_ma_giam_gia(GioHang* sp, double phanTram) {
    sp->phanTramGiamGia = phanTram;
    sp->tienThanhToan *= (1 - phanTram / 100);
}

void GioHang_thanh_toan(const GioHang* sp) {
    GioHang_in_gio_hang(sp);
    printf("\nSo tien phai tra la: %.2lf VND\n", sp->tienThanhToan);
}

void GioHang_cap_nhat_tien_thanh_toan(GioHang* sp) {
    sp->tienThanhToan = 0;
    for (int i = 0; i < sp->soLuongHang; i++) {
        sp->tienThanhToan += sp->gioHang[i].gia_thanh * sp->gioHang[i].so_luong;
    }
}

void GioHang_free(GioHang* sp) {
    free(sp->gioHang);
    sp->gioHang = NULL;
    sp->soLuongHang = 0;
    sp->tienThanhToan = 0.0;
    sp->phanTramGiamGia = 0.0;
}
