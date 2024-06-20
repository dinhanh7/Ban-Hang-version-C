#include "GioHang.h"

void GioHang_init(GioHang* self) {
    self->gioHang = NULL;
    self->soLuongHang = 0;
    self->tienThanhToan = 0.0;
    self->phanTramGiamGia = 0.0;
}

void GioHang_them_san_pham(GioHang* self, Hanghoa sanPham) {
    self->gioHang = realloc(self->gioHang, (self->soLuongHang + 1) * sizeof(Hanghoa));
    self->gioHang[self->soLuongHang] = sanPham;
    self->soLuongHang++;
    GioHang_cap_nhat_tien_thanh_toan(self);
}

void GioHang_xoa_san_pham(GioHang* self, int index) {
    if (index < 0 || index >= self->soLuongHang) return;
    for (int i = index; i < self->soLuongHang - 1; i++) {
        self->gioHang[i] = self->gioHang[i + 1];
    }
    self->soLuongHang--;
    self->gioHang = realloc(self->gioHang, self->soLuongHang * sizeof(Hanghoa));
    GioHang_cap_nhat_tien_thanh_toan(self);
}

void GioHang_in_gio_hang(const GioHang* self) {
    printf("\n<------------------Gio hang cua ban---------------->\n");
    for (int i = 0; i < self->soLuongHang; i++) {
        printf("\n%d. ", i + 1);
        Hanghoa_xuat(&self->gioHang[i]);
    }
}

void GioHang_ap_ma_giam_gia(GioHang* self, double phanTram) {
    self->phanTramGiamGia = phanTram;
    self->tienThanhToan *= (1 - phanTram / 100);
}

void GioHang_thanh_toan(const GioHang* self) {
    GioHang_in_gio_hang(self);
    printf("\nSo tien phai tra la: %.2lf VND\n", self->tienThanhToan);
}

void GioHang_cap_nhat_tien_thanh_toan(GioHang* self) {
    self->tienThanhToan = 0;
    for (int i = 0; i < self->soLuongHang; i++) {
        self->tienThanhToan += self->gioHang[i].gia_thanh * self->gioHang[i].so_luong;
    }
}

void GioHang_free(GioHang* self) {
    free(self->gioHang);
    self->gioHang = NULL;
    self->soLuongHang = 0;
    self->tienThanhToan = 0.0;
    self->phanTramGiamGia = 0.0;
}
