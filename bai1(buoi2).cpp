/*Viết chương trình cho phép người dùng nhập vào một số nguyên dương n (0 < n <= 100) và
một mảng gồm n số nguyên. Thực hiện các yêu cầu sau:
1. Nhập & Xuất: Nhập các phần tử của mảng và in mảng ra màn hình trên một dòng,
các số cách nhau bởi dấu cách.
2. Tính toán cơ bản: Tính trung bình cộng các số lẻ có trong mảng.
3. Tìm kiếm: Nhập vào một số nguyên x. Hãy đếm xem x xuất hiện bao nhiêu lần trong
mảng và in ra vị trí (chỉ số) của các lần xuất hiện đó.
4. Sắp xếp: Sắp xếp mảng theo thứ tự giảm dần và in kết quả ra màn hình.*/

#include<iostream>
using namespace std;
int main() {
    int n;
    int A[100];
    cout << "Nhap n so nguyen (0<n<=100)";
    cin >> n;
    if (n>100 or n<0) {
        cout << "Vui long nhap lai";
    }
    else {
        for (int i=0;i<n;i++) {
            cout <<"Vui long nhap gia tri thu: " << i+1 << " = ";
            cin >> A[i];
        }
        cout << "Mang vua nhap: " << endl;
        for (int i=0;i<n;i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        float sole=0;
        int demsole=0;
        for (int i=0;i<n;i++) {
            if (A[i]%n!=2) {
                demsole++;
                sole+=A[i];
            }
        }
        float tbc = sole/demsole;
        cout << "TBC cua cac so le trong mang la: " << tbc <<endl;
     int x;
     int demx;
        cout << "Nhap vi tri x can tim: " << endl;
        cin >> x;
        cout << "Vi tri cua x trong mang la vi tri ";
        for (int i=0;i<n;i++) {
            if (A[i]==x) {
                demx++;
                cout << i+1 << ";";
            }
        }
        cout << endl;
        cout << "So: " << x << " xuat hien " << demx << " lan trong mang";

    }
}
