#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Nhap so bien n: ";
    cin >> n;

    double A[n][n], b[n], x[n], eps, err = 1.0;
    int k = 0, maxit;

    // Nhap ma tran A và vector b
    cout << "Nhap cac phan tu cua ma tran A va vector b: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
        x[i] = 0.0; // Khoi tao giá tri x ban d?u
    }

    // Nhap sai so epsilon và gioi han so vòng lap
    cout << "Nhap sai so epsilon: ";
    cin >> eps;
    cout << "Nhap so vong lap toi da: ";
    cin >> maxit;

    //  phuong pháp Gauss-Seidel
    while (err > eps && k < maxit) {
        err = 0.0;
        for (int i = 0; i < n; i++) {
            double s = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    s += A[i][j] * x[j];
                }
            }
            double tmp = x[i];
            x[i] = (b[i] - s) / A[i][i];
            err += fabs(tmp - x[i]);
        }
        k++;
    }

    // In ra ket qua
    if (k == maxit) {
        cout << "Khong hoi tu sau " << maxit << " vong lap." << endl;
    }
    else {
        cout << "Nghiem x la: " << endl;
        for (int i = 0; i < n; i++) {
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }
        cout << "Sau " << k << " vong lap." << endl;
    }

    return 0;
}

