#include "Hanghoa.h"
#include "GioHang.h"
#include <stdio.h>
/*Neu chinh sua lai code, can xoa file program.exe, sau do:
Mo terminal, chay lenh: gcc -o program main.c Hanghoa.c GioHang.c
de he thong tao lai file programe.exe moi
*/
//De chay chuong trinh, mo terminal va go lenh: ./program

void inDanhSachSanPham(Hanghoa* san_pham, int size);
void themSanPham(Hanghoa** san_pham, int* size);
void xoaSanPham(Hanghoa* san_pham, int* size);
void suaSanPham(Hanghoa* san_pham, int size);
void sapXepTheoGia(Hanghoa* san_pham, int size);
void timKiemTheoMaSanPham(Hanghoa* san_pham, int size);
void giaoDienChinhSua(Hanghoa* san_pham, int* size);
void giaoDienThanhToan(Hanghoa* san_pham, int size, GioHang* quay_thanh_toan);
void timKiemTheoTenSanPham(Hanghoa* san_pham, int size);
void docFileSanPham(const char* filename, Hanghoa** san_pham, int* size);
void themSanPhamVaoGioHangBangMa(GioHang* gioHang, Hanghoa* san_pham, int size);
void themSanPhamVaoGioHangBangTen(GioHang* gioHang, Hanghoa* san_pham, int size);


int main() {
    Hanghoa* san_pham = NULL;
    int size = 0;
    GioHang gioHang;
    GioHang_tao(&gioHang);

    // Đọc file sản phẩm từ đường dẫn cụ thể
    const char* filePath = "C:\\Users\\WINDOWS\\OneDrive - Hanoi University of Science and Technology\\Desktop\\giay.txt";
    docFileSanPham(filePath, &san_pham, &size);

    // Menu chính
    while (1) {
        giaoDienChinhSua(san_pham, &size);
        giaoDienThanhToan(san_pham, size, &gioHang);

        free(san_pham);
        GioHang_free(&gioHang);
        system("cls");
    }
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
    printf("\n---------------------------------------------");
    printf("\n| 1. Them san pham                          |");
    printf("\n| 2. Xoa san pham                           |");
    printf("\n| 3. Sua san pham                           |");
    printf("\n| 4. Sap xep theo gia                       |");
    printf("\n| 5. Tim kiem theo ma san pham              |");
    printf("\n| 6. Tim kiem theo ten san pham             |");
    printf("\n| 7. Hien thi tat ca san pham               |");
    printf("\n| 8. Gio hang                               |");
    printf("\n|                                           |");
    printf("\n| Nhap lua chon cua ban:                    |");
    printf("\n---------------------------------------------\n");
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
            case 6:
                timKiemTheoTenSanPham(san_pham, *size);
                break;
            case 7:
                inDanhSachSanPham(san_pham, *size);
                break;
            case 8:
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
    printf("\n____________________________________________________");
    printf("\n|                                                  |");
    printf("\n| 1. Them san pham vao gio hang bang vi tri        |");
    printf("\n| 2. Them san pham vao gio hang bang ma san pham   |");
    printf("\n| 3. Them san pham vao gio hang bang ten san pham  |");
    printf("\n| 4. Xoa san pham khoi gio hang                    |");
    printf("\n| 5. Ap ma giam gia                                |");
    printf("\n| 6. Hien thi gio hang                             |");
    printf("\n| 7. Thanh toan                                    |");
    printf("\n| 0. Thoat                                         |");
    printf("\n|                                                  |");
    printf("\n| Nhap lua chon cua ban:                           |");
    printf("\n____________________________________________________\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int index, soLuong;
                printf("Nhap vi tri san pham muon them: ");
                scanf("%d", &index);
                printf("Nhap so luong: ");
                scanf("%d", &soLuong);
                if (index < 1 || index > size) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    GioHang_them_san_pham(gioHang, san_pham[index - 1], soLuong);
                    GioHang_in_gio_hang(gioHang);
                }
                break;
            }
            case 2:
                themSanPhamVaoGioHangBangMa(gioHang, san_pham, size);
                break;
            case 3:
                themSanPhamVaoGioHangBangTen(gioHang, san_pham, size);
                break;
            case 4: {
                int index;
                printf("Nhap vi tri san pham muon xoa: ");
                scanf("%d", &index);
                GioHang_xoa_san_pham(gioHang, index - 1);
                GioHang_in_gio_hang(gioHang);
                break;
            }
            case 5: {
                double giamGia;
                printf("Nhap phan tram giam gia: ");
                scanf("%lf", &giamGia);
                GioHang_ap_ma_giam_gia(gioHang, giamGia);
                GioHang_in_gio_hang(gioHang);
                break;
            }
            case 6:
                GioHang_in_gio_hang(gioHang);
                break;
            case 7:
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

void timKiemTheoTenSanPham(Hanghoa* san_pham, int size) {
    char ten[100];
    int isExist = 0;
    printf("Nhap ten san pham muon tim: ");
    getchar();
    fgets(ten, sizeof(ten), stdin);
    strtok(ten, "\n");

    for (int i = 0; i < size; i++) {
        if (strcmp(san_pham[i].san_pham, ten) == 0) {
            Hanghoa_xuat(&san_pham[i]);
            isExist = 1;
        }
    }
    if(!isExist){
        printf("Khong tim thay san pham voi ten da nhap\n");
    }
}

void docFileSanPham(const char* filename, Hanghoa** san_pham, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file %s\n", filename);
        return;
    }

    Hanghoa temp;
    while (fscanf(file, "%[^,],%[^,],%lf,%d\n", temp.ma_san_pham, temp.san_pham, &temp.gia_thanh, &temp.so_luong) == 4) {
        (*size)++;
        *san_pham = realloc(*san_pham, (*size) * sizeof(Hanghoa));
        (*san_pham)[*size - 1] = temp;
    }

    fclose(file);
}
void themSanPhamVaoGioHangBangMa(GioHang* gioHang, Hanghoa* san_pham, int size) {
    char ma[20];
    int soLuong;
    int isExist = 0;
    printf("Nhap ma san pham muon them vao gio hang: ");
    getchar();
    fgets(ma, sizeof(ma), stdin);
    strtok(ma, "\n");
    printf("Nhap so luong: ");
    scanf("%d", &soLuong);

    for (int i = 0; i < size; i++) {
        if (strcmp(san_pham[i].ma_san_pham, ma) == 0) {
            GioHang_them_san_pham(gioHang, san_pham[i], soLuong);
            printf("Da them %d %s vao gio hang.\n", soLuong, san_pham[i].san_pham);
            isExist = 1;
            GioHang_in_gio_hang(gioHang);
            break;
        }
    }
    if (!isExist) {
        printf("Khong tim thay san pham voi ma da nhap\n");
    }
}


void themSanPhamVaoGioHangBangTen(GioHang* gioHang, Hanghoa* san_pham, int size) {
    char ten[100];
    int soLuong;
    int isExist = 0;
    printf("Nhap ten san pham muon them vao gio hang: ");
    getchar();
    fgets(ten, sizeof(ten), stdin);
    strtok(ten, "\n");
    printf("Nhap so luong: ");
    scanf("%d", &soLuong);

    for (int i = 0; i < size; i++) {
        if (strcmp(san_pham[i].san_pham, ten) == 0) {
            GioHang_them_san_pham(gioHang, san_pham[i], soLuong);
            printf("Da them %d %s vao gio hang.\n", soLuong, san_pham[i].san_pham);
            isExist = 1;
            GioHang_in_gio_hang(gioHang);
            break;
        }
    }
    if (!isExist) {
        printf("Khong tim thay san pham voi ten da nhap\n");
    }
}
