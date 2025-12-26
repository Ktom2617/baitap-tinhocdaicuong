#include <iostream>

using namespace std;
   const int maxphong=50;
   const int maxnv=50;
   void Nhapdulieu (int &m, int &n, float luong[maxphong][maxnv]);
   void Xuatluongtheophong (int m, int n, float luong[maxphong][maxnv]);
   void LuongtrenTB(int m, int n, float luong[maxphong][maxnv]);
   void sapxep(int m, int n, float luong[maxphong][maxnv]);
int main()
{

    int m, n;
    float luong[maxphong][maxnv];

    Nhapdulieu(m, n, luong);

    cout << "\n[BANG LUONG GOC]"<<endl;
    Xuatluongtheophong(m, n, luong);

    LuongtrenTB(m, n, luong);

    sapxep(m, n, luong); // Gọi hàm sắp xếp

    cout << "\n[BANG LUONG SAU KHI SAP XEP TANG DAN]"<<endl;
   Xuatluongtheophong(m, n, luong); // Gọi lại hàm xuất để xem kết quả mới
   return 0;
}




void Nhapdulieu(int &m, int &n, float luong[maxphong][maxnv]) {
    cout << "Nhap so phong ban  ";
    cin >> m;
    cout << "Nhap so nhan vien moi phong  ";
    cin >> n;
    for (int i=0;i<m;i++){
        cout << "Nhap luong cua nhan vien phong ban thu " << i+1 << endl;
        for (int j=0;j<n;j++){
            cout << "Luong nhan vien thu: " << j+1 << endl;
            cin >> luong[i][j];
        }
    }

}

void Xuatluongtheophong(int m, int n, float luong[maxphong][maxnv]) {
    for (int i=0;i<m;i++){
        cout << "Phong" << i+1 <<":";
        for (int j=0;j<n;j++){
            cout << luong[i][j] << "\t";
        }
    cout << endl;
    }
}

void LuongtrenTB(int m, int n, float luong[maxphong][maxnv]) {
    for(int i = 0; i < m; i++) {
        float tongLuong = 0;


        for(int j = 0; j < n; j++) {
            tongLuong += luong[i][j];
        }


        float luongTB = 0;
        if (n > 0) luongTB = tongLuong / n;

        int dem = 0;
        for(int j = 0; j < n; j++) {
            if(luong[i][j] > luongTB) {
                dem++;
            }
        }

        cout << "Phong " << i+1 << " (TB: " << luongTB << ") co " << dem  << " nhan vien luong cao hon muc TB.\n";
    }
}
void sapxep(int m, int n, float luong[maxphong][maxnv]) {

    // Vòng lặp i: KHÓA CHẶT từng phòng.
    // Khi i=0, ta chỉ làm việc với hàng 0. Xong xuôi mới sang hàng 1.
    for(int i = 0; i < m; i++) {

        // --- THUẬT TOÁN SẮP XẾP (Bên trong phòng i) ---

        // j là vị trí cái ghế ta đang muốn tìm người thấp nhất để xếp vào
        // Chạy từ đầu hàng đến áp chót
        for(int j = 0; j < n - 1; j++) {

            int luongmin = j; // Giả sử người ngồi đầu (j) là thấp nhất

            // Vòng lặp k: Là "người trinh sát" chạy đi tìm xem phía sau có ai thấp hơn không
            for(int k = j + 1; k < n; k++) {

                // So sánh lương của người thứ k với lương thấp nhất hiện tại
                // Chú ý: luong[i][k] (Vẫn là phòng i, chỉ khác cột k)
                if(luong[i][k] < luong[i][luongmin]) {
                    luongmin = k; // Tìm thấy người k thấp hơn, ghi nhớ vị trí k
                }
            }

            // Sau khi trinh sát k chạy hết hàng, nếu tìm được người thấp hơn thật
            if(luongmin != j) {
                // HOÁN ĐỔI (Đổi chỗ)
                // Đổi chỗ người ở vị trí j và người ở vị trí luongmin
                float temp = luong[i][j];
                luong[i][j] = luong[i][luongmin];
                luong[i][luongmin] = temp;
            }
        }
    }
    cout << "\n>> Da sap xep xong!\n";
}
