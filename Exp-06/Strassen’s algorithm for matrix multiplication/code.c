#include <stdio.h>
#include <stdlib.h>

void addMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

int **createMatrix(int n)
{
    int **M = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        M[i] = malloc(n * sizeof(int));

    return M;
}

void freeMatrix(int **M, int n)
{
    for (int i = 0; i < n; i++)
        free(M[i]);

    free(M);
}

void strassen(int **A, int **B, int **C, int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int m = n / 2;

    int **A11 = createMatrix(m);
    int **A12 = createMatrix(m);
    int **A21 = createMatrix(m);
    int **A22 = createMatrix(m);

    int **B11 = createMatrix(m);
    int **B12 = createMatrix(m);
    int **B21 = createMatrix(m);
    int **B22 = createMatrix(m);

    int **M1 = createMatrix(m);
    int **M2 = createMatrix(m);
    int **M3 = createMatrix(m);
    int **M4 = createMatrix(m);
    int **M5 = createMatrix(m);
    int **M6 = createMatrix(m);
    int **M7 = createMatrix(m);

    int **T1 = createMatrix(m);
    int **T2 = createMatrix(m);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j];
            A22[i][j] = A[i + m][j + m];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j];
            B22[i][j] = B[i + m][j + m];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, T1, m);
    addMatrix(B11, B22, T2, m);
    strassen(T1, T2, M1, m);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, T1, m);
    strassen(T1, B11, M2, m);

    // M3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, T2, m);
    strassen(A11, T2, M3, m);

    // M4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, T2, m);
    strassen(A22, T2, M4, m);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, T1, m);
    strassen(T1, B22, M5, m);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, T1, m);
    addMatrix(B11, B12, T2, m);
    strassen(T1, T2, M6, m);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, T1, m);
    addMatrix(B21, B22, T2, m);
    strassen(T1, T2, M7, m);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, T1, m);
    subtractMatrix(T1, M5, T2, m);
    addMatrix(T2, M7, C, m);

    // C12 = M3 + M5
    addMatrix(M3, M5, T1, m);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i][j + m] = T1[i][j];

    // C21 = M2 + M4
    addMatrix(M2, M4, T1, m);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i + m][j] = T1[i][j];

    // C22 = M1 - M2 + M3 + M6
    subtractMatrix(M1, M2, T1, m);
    addMatrix(T1, M3, T2, m);
    addMatrix(T2, M6, T1, m);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            C[i + m][j + m] = T1[i][j];

    freeMatrix(A11, m);
    freeMatrix(A12, m);
    freeMatrix(A21, m);
    freeMatrix(A22, m);

    freeMatrix(B11, m);
    freeMatrix(B12, m);
    freeMatrix(B21, m);
    freeMatrix(B22, m);

    freeMatrix(M1, m);
    freeMatrix(M2, m);
    freeMatrix(M3, m);
    freeMatrix(M4, m);
    freeMatrix(M5, m);
    freeMatrix(M6, m);
    freeMatrix(M7, m);

    freeMatrix(T1, m);
    freeMatrix(T2, m);
}

int main()
{
    int n;

    printf("Enter the size of matrices: ");
    scanf("%d", &n);

    int **A = createMatrix(n);
    int **B = createMatrix(n);
    int **C = createMatrix(n);

    printf("Enter elements of first matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("Resultant matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    freeMatrix(A, n);
    freeMatrix(B, n);
    freeMatrix(C, n);

    return 0;
}
