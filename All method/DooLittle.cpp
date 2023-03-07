#include <iostream> 
#include <vector>

using namespace std;

void doolittle(vector< vector<double> > A, vector<double> b, vector<double>& x) { int n = A.size();
vector< vector<double> > L(n, vector<double>(n)); vector<vector<double> > U(n, vector<double>(n));

//phân tích A=LU
for (int k = 0; k < n; k++) {
U[k][k] = 1;
for (int j = k; j < n; j++) { double sum = 0;
for (int s = 0; s < k; s++) {
sum += L[j][s] * U[s][k];
}
L[j][k] = A[j][k] - sum;
}
for (int i = k + 1; i < n; i++) { double sum = 0;
for (int s = 0; s < k; s++) {
sum += L[k][s] * U[s][i];
}
U[k][i] = (A[k][i] - sum) / L[k][k];
}
}

//giai Ly=b
vector<double> y(n);
for (int i = 0; i < n; i++) { double sum = 0;
for (int j = 0; j < i; j++) {
sum += L[i][j] * y[j];
}
y[i] = (b[i] - sum) / L[i][i];
}

//giai Ux = y
for (int i = n - 1; i >= 0; i--) { double sum = 0;
for (int j = i + 1; j < n; j++) {
sum += U[i][j] * x[j];
}
x[i] = (y[i] - sum) / U[i][i];
}
}

int main() {
int n;
cout << "Nhap so bien n: ";
cin >> n;

vector<vector<double> > A(n, vector<double>(n));
 
vector<double> b(n); vector<double> x(n);

cout << "Nhap ma tran A va vector b:\n"; for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
cin >> A[i][j];
}
cin >> b[i];
}

doolittle(A, b, x);

cout << "Nghiem cua he phuong trinh la:\n"; for (int i = 0; i < n; i++) {
cout << "x[" << i << "] = " << x[i] << endl;
}

return 0;
}

