#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
int msges();
void menu();
void LlenaVect1(int vect1[], int N);
void LlenaVect2(int vect2[], int N);
int comparar(int vect2[], int num, int N);
void LlenaVect3(int vect1[], int vect2[], int vect3[], int N, int S);
void impvect(int vect1[], int vect2[], int vect3[], int N, int S);
void LlenaMatriz(int matriz[][4],int fila,int colum,int vect3[]);
void imprMatriz(int matriz[][4],int fila,int colum);

//****  main principal  *********
int main()
{
    srand(time(NULL));
    menu();

    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- LLENA VECTOR 1 (Manualmente) \n");
    printf("2.- LLENA VECTOR 2 (Aleatoriamente) \n");
    printf("3.- LLENA VECTOR 3 (Vect1 y vect2) \n");
    printf("4.- IMPRIMIR VECTORES\n");
    printf("5.- LLENA MATRIZ 4X4\n");
    printf("6.- IMPRIMIR MATRIZ\n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int N = 10, S = 20, fila=4, colum=4,op;
    int vect1[N], vect2[N], vect3[S];
    int matriz[4][4];
    do
    {
       
        op = msges();
        printf("-----------------------------------------\n");
        switch (op)
        {
        case 1:
            LlenaVect1(vect1, N);
            break;
        case 2:
            LlenaVect2(vect2, N);
            break;
        case 3:
            LlenaVect3(vect1, vect2, vect3, N, S);
            break;
        case 4:
            impvect(vect1, vect2, vect3, N, S);
            break;
        case 5:
            LlenaMatriz(matriz,fila,colum,vect3);
            break;
        case 6:
            imprMatriz(matriz,fila,colum);
            break;
        }

    } while (op != 0);
}

void LlenaVect1(int a[], int N)
{
    int num;
    printf("LLENA VECTOR MANUALMENTE\n");
    printf("Numeros a partir de 30 hasta 70\n");
    for (int i = 0; i < N; i++)
    {
        printf("INGRESE NUM EN LA POSICION [%d] = ", i);
        scanf("%d", &num);
        if (num>=30)
        {
            if (num<=70)
            {
                a[i]=num;
            }
            else
            {
                i--;
            }
        }
        else
        {
            i--;
        }
        
    }
    system("PAUSE");
}

void LlenaVect2(int b[], int N)
{
    int num, i, j, band;
    printf("VECTOR LLENO ALEATORIAMENTE\n");
    for (i = 0; i < N; i++)
    {
        do
        {
            num = 1 + rand() % 19;
            band = comparar(b, num, N);

        } while (band != -1);
        b[i] = num;
        //printf("Posicion [%d] = %d \n", i, b[i]);
    }
    system("PAUSE");
}

int comparar(int b[], int num, int N)
{
    int j = 0, band;
    band = -1;
    for (int j = 0; j < N; j++)
    {
        if (b[j] == num)
        {
            band = j;
        }
    }
    return band;
}

void LlenaVect3(int vect1[], int vect2[], int c[], int N, int S)
{
    printf("VECTOR No.-3 LLENO\n");
    for (int i = 0; i < N; i++)
    {
        c[i] = vect1[i];
        c[i+N]=vect2[i];
    }

    /*for (int i = 0; i < S; i++)
    {
        printf(" pos[%d] = %d \n",i, c[i]);
    }
    */

    system("PAUSE");
}

void impvect(int vect1[], int vect2[], int vect3[], int N, int S)
{
    system("CLS");
    printf("VECTOR No.-1:\n");
    for (int i = 0; i < N; i++)
    {
        printf("[%d] \t", vect1[i]);
    }
    system("PAUSE");
    printf("VECTOR No.-2:\n");
    for (int i = 0; i < N; i++)
    {
        printf("[%d] \t", vect2[i]);
    }
    system("PAUSE");
    printf("VECTOR No.-3:\n");
    for (int i = 0; i < S; i++)
    {
        printf("[%d] \n", vect3[i]);
    }
    system("PAUSE");
}

void LlenaMatriz(int m[][4],int fila,int colum,int vect3[])
{
    printf("MATRIZ LLENA\n");
    int num;
   
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < colum; j++)
        {
             num = rand() % 21;
            //printf("DAME EL NUMERO de f[%d] y c[%d]\n",i,j);
            m[i][j]=vect3[num];
        }
        
    }
    
    system("PAUSE");
}

void imprMatriz(int matriz[][4],int fila,int colum)
{
    printf("MATRIZ 4x4\n");
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            printf("[%d] \t",matriz[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}