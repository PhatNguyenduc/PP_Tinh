#include <iostream>
#include <cmath>

using namespace std;

void cholesky(double A[][100], double L[][100], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += (L[i][k] * L[j][k]);
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }
}

void forward_substitution(double L[][100], double B[], double Y[], int n)
{
    for (int i = 0; i < n; i++) {
        double sum = 0;

        for (int j = 0; j < i; j++) {
            sum += (L[i][j] * Y[j]);
        }

        Y[i] = (B[i] - sum) / L[i][i];
    }
}

void backward_substitution(double L[][100], double Y[], double X[], int n)
{
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;

        for (int j = i + 1; j < n; j++) {
            sum += (L[j][i] * X[j]);
        }

        X[i] = (Y[i] - sum) / L[i][i];
    }
}

int main()
{
    int n;
    double A[100][100], L[100][100], B[100], Y[100], X[100];

    cout << "Nhap kich thuoc cua ma tran: ";
    cin >> n;

    cout << "Nhap cac phan tu cua ma tran A va vector B: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> B[i];
    }

    

    cholesky(A, L, n);
    forward_substitution(L, B, Y, n);
    backward_substitution(L, Y, X, n);

    cout << "Nghiem cua he phuong trinh la: " << endl;
    for (int i = 0; i < n; i++) {
        cout <<"x["<<i<<"] = " << X[i] << endl;
    }
    cout << endl;

    return 0;
}

