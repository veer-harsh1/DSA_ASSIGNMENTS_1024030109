#include <iostream>
using namespace std;
void transpose(int row[], int col[], int val[], int nm) {
    for (int i = 0; i < nm; i++) {
        int temp = row[i];
        row[i] = col[i];
        col[i] = temp;
    }
}
int add(int row1[], int col1[], int val1[], int nm1,
        int row2[], int col2[], int val2[], int nm2,
        int rowR[], int colR[], int valR[]) {
    
    int i = 0, j = 0, k = 0;
    while (i < nm1 && j < nm2) {
        if (row1[i] == row2[j] && col1[i] == col2[j]) {
            rowR[k] = row1[i];
            colR[k] = col1[i];
            valR[k] = val1[i] + val2[j];
            i++; j++; k++;
        } 
        else if (row1[i] < row2[j] || (row1[i] == row2[j] && col1[i] < col2[j])) {
            rowR[k] = row1[i];
            colR[k] = col1[i];
            valR[k] = val1[i];
            i++; k++;
        } 
        else {
            rowR[k] = row2[j];
            colR[k] = col2[j];
            valR[k] = val2[j];
            j++; k++;
        }
    }
    while (i < nm1) {
        rowR[k] = row1[i];
        colR[k] = col1[i];
        valR[k] = val1[i];
        i++; k++;
    }
    while (j < nm2) {
        rowR[k] = row2[j];
        colR[k] = col2[j];
        valR[k] = val2[j];
        j++; k++;
    }
    return k;
}
int multiply(int row1[], int col1[], int val1[], int nm1,
             int row2[], int col2[], int val2[], int nm2,
             int rowR[], int colR[], int valR[]) {
    
    int k = 0;
    for (int i = 0; i < nm1; i++) {
        for (int j = 0; j < nm2; j++) {
            if (col1[i] == row2[j]) {
               
                bool found = false;
                for (int x = 0; x < k; x++) {
                    if (rowR[x] == row1[i] && colR[x] == col2[j]) {
                        valR[x] += val1[i] * val2[j];
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    rowR[k] = row1[i];
                    colR[k] = col2[j];
                    valR[k] = val1[i] * val2[j];
                    k++;
                }
            }
        }
    }
    return k;
}


void printMatrix(int row[], int col[], int val[], int n, int m, int nm) {
    int z = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (z < nm && row[z] == i && col[z] == j) {
                cout << val[z] << " ";
                z++;
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, m, nm;
    cin >> n >> m >> nm;

    int row[nm], col[nm], val[nm];
    for (int i = 0; i < nm; i++) cin >> row[i];
    for (int i = 0; i < nm; i++) cin >> col[i];
    for (int i = 0; i < nm; i++) cin >> val[i];

    cout << "Original Matrix: ";
    cout<<endl;
    printMatrix(row, col, val, n, m, nm);

  
    transpose(row, col, val, nm);
    cout << "Transpose: ";
    cout<<endl;
    printMatrix(row, col, val, m, n, nm);

   
    int rowR[2*nm], colR[2*nm], valR[2*nm];
    int nmAdd = add(row, col, val, nm, row, col, val, nm, rowR, colR, valR);
    cout << " Addition (Matrix + Matrix): ";
    cout<<endl;
    printMatrix(rowR, colR, valR, n, m, nmAdd);

 
    int rowM[100], colM[100], valM[100];
    int nmMul = multiply(row, col, val, nm, row, col, val, nm, rowM, colM, valM);
    cout << "Multiplication (Matrix * Matrix): ";
    cout<<endl;
    printMatrix(rowM, colM, valM, n, m, nmMul);

    return 0;
}