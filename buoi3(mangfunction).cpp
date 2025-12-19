#include <iostream>
#include <math.h>
using namespace std;

bool KiemTraNguyenTo(int k);
int TongChuSo(int k);
void NhapMang(int a[], int &n);
void XuatMang(int a[], int n);
int DemSoNguyenTo(int a[], int n);
int main() {
 int arr[100];
 int n;

 NhapMang(arr, n);
 cout << "\nMang vua nhap la: ";
 XuatMang(arr, n);

 int ketQuaDem = DemSoNguyenTo(arr, n);
 cout << "\nTrong mang co " << ketQuaDem << " so nguyen to."
<< endl;
 return 0;
}

void NhapMang(int a[], int &n) {
 do {
 cout << "Nhap so phan tu n (0 < n <= 100): ";
 cin >> n;
 }
 while (n <= 0 || n > 100);
 for (int i = 0; i < n; i++) {
 cout << "A[" << i << "] = ";
 cin >> a[i];
 }
}

void XuatMang(int a[], int n) {
 for (int i = 0; i < n; i++) {
 cout << a[i] << " ";
 }
 cout << endl;
}

int TongChuSo(int k) {
 int tong = 0;
 int temp = k;
 if (temp < 0){
    temp = -temp;
 }

 while (temp > 0) {
 tong += temp % 10;
 temp /= 10;
 }
 return tong;
}

bool KiemTraNguyenTo(int k) {
 if (k < 2) return false;
 for (int i = 2; i <= sqrt(k); i++) {
 if (k % i == 0) return false;
 }
 return true;
}

int DemSoNguyenTo(int a[], int n) {
 int dem = 0;
 for (int i = 0; i < n; i++) {

 if (KiemTraNguyenTo(a[i]) == true) {
 dem++;
 }
 }
 return dem;
}
