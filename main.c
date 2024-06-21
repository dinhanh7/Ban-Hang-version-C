#include "Hanghoa.h"
#include "GioHang.h"
#include <stdio.h>

void inDanhSachSanPham(Hanghoa* san_pham, int size);
void themSanPham(Hanghoa** san_pham, int* size);
void xoaSanPham(Hanghoa* san_pham, int* size);
void suaSanPham(Hanghoa* san_pham, int size);
void sapXepTheoGia(Hanghoa* san_pham, int size);
void timKiemTheoMaSanPham(Hanghoa* san_pham, int size);
void giaoDienChinhSua(Hanghoa* san_pham, int* size);
void giaoDienThanhToan(Hanghoa* san_pham, int size, GioHang* quay_thanh_toan);

int main() {
    Hanghoa* san_pham = NULL;
    int size = 0;
    GioHang gioHang;
    GioHang_init(&gioHang);

    // Menu chinh
    giaoDienChinhSua(san_pham, &size);
    giaoDienThanhToan(san_pham, size, &gioHang);


    free(san_pham);
    GioHang_free(&gioHang);

    return 0;
}

void inDanhSachSanPham(Hanghoa* san_pham, int size) {
    if (size == 0) {
        printf("Khong co san pham nao trong danh sach.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("\n%d. ", i + 1);
        Hanghoa_xuat(&san_pham[i]);
    }
}

void themSanPham(Hanghoa** san_pham, int* size) {
    Hanghoa new_product;
    Hanghoa_nhap(&new_product);
    (*size)++;
    *san_pham = realloc(*san_pham, (*size) * sizeof(Hanghoa));
    (*san_pham)[*size - 1] = new_product;
}

void xoaSanPham(Hanghoa* san_pham, int* size) {
    int index;
    printf("Nhap vi tri san pham muon xoa: ");
    scanf("%d", &index);
    if (index < 1 || index > *size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = index - 1; i < *size - 1; i++) {
        san_pham[i] = san_pham[i + 1];
    }
    (*size)--;
    san_pham = realloc(san_pham, (*size) * sizeof(Hanghoa));
}

void suaSanPham(Hanghoa* san_pham, int size) {
    int index;
    printf("Nhap vi tri san pham muon sua: ");
    scanf("%d", &index);
    if (index < 1 || index > size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    Hanghoa_nhap(&san_pham[index - 1]);
}

void sapXepTheoGia(Hanghoa* san_pham, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (san_pham[i].gia_thanh > san_pham[j].gia_thanh) {
                Hanghoa temp = san_pham[i];
                san_pham[i] = san_pham[j];
                san_pham[j] = temp;
            }
        }
    }
}

void timKiemTheoMaSanPham(Hanghoa* san_pham, int size) {
    timkiem:
    char ma[20];
    int isExist = 0;
    printf("Nhap ma san pham muon tim: ");
    getchar();
    fgets(ma, sizeof(ma), stdin);
    strtok(ma, "\n");

    for (int i = 0; i < size; i++) {
        if (strcmp(san_pham[i].ma_san_pham, ma) == 0) {
            Hanghoa_xuat(&san_pham[i]);
            isExist = 1;
            break;
        }
    }
    if(!isExist){
        printf("Khong tim thay san pham voi ma da nhap\n");
    }
    char lc;
    printf("Ban co muon tiep tuc tim khong (y/n) ?  ");
    scanf("%c",&lc);
    if(lc == 'y'){
        goto timkiem;
    }
}

void giaoDienChinhSua(Hanghoa* san_pham, int* size) {
    int choice;
    do {
        printf("\n1. Them san pham");
        printf("\n2. Xoa san pham");
        printf("\n3. Sua san pham");
        printf("\n4. Sap xep theo gia");
        printf("\n5. Tim kiem theo ma san pham");
        printf("\n0. Thoat");
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                themSanPham(&san_pham, size);
                break;
            case 2:
                xoaSanPham(san_pham, size);
                break;
            case 3:
                suaSanPham(san_pham, *size);
                break;
            case 4:
                sapXepTheoGia(san_pham, *size);
                break;
            case 5:
                timKiemTheoMaSanPham(san_pham, *size);
                break;
            case 0:
                return;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (1);
}

void giaoDienThanhToan(Hanghoa* san_pham, int size, GioHang* gioHang) {
    int choice;
    do {
        printf("\n1. Them san pham vao gio hang");
        printf("\n2. Xoa san pham khoi gio hang");
        printf("\n3. Ap ma giam gia");
        printf("\n4. Thanh toan");
        printf("\n0. Thoat");
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int index;
                printf("Nhap vi tri san pham muon them: ");
                scanf("%d", &index);
                if (index < 1 || index > size) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    GioHang_them_san_pham(gioHang, san_pham[index - 1]);
                }
                break;
            }
            case 2: {
                int index;
                printf("Nhap vi tri san pham muon xoa: ");
                scanf("%d", &index);
                GioHang_xoa_san_pham(gioHang, index - 1);
                break;
            }
            case 3: {
                double giamGia;
                printf("Nhap phan tram giam gia: ");
                scanf("%lf", &giamGia);
                GioHang_ap_ma_giam_gia(gioHang, giamGia);
                break;
            }
            case 4:
                GioHang_thanh_toan(gioHang);
                break;
            case 0:
                return;
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    } while (1);
}

