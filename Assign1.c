#include<stdio.h>
void getmatrix(int r, int c, int m[r][c],const char *name)
{
   printf("Enter elements of %s (%dx%d): \n", name, r, c);
   for (int i = 0; i < r; i++)
   { 
     for (int j = 0; j < c; j++)
       {
         scanf("%d", &m[i][j]);
       }
   }
}

void display(int r, int c, int m[r][c],const char *label)
{
    printf("%s (%dx%d):\n", label, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%5d ", m[i][j]);
    }
}

int add(int r1,int c1,int A[r1][c1],int r2,int c2,int B[r2][c2],int C[r1][c1])
{  
  if (r1 != r2 || c1 != c2) 
  {
    return -1; 
  }
  for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
          {
            C[i][j] = A[i][j] + B[i][j];
          }
    }
    return 0;
}

int subtract(int r1,int c1,int A[r1][c1],int r2,int c2,int B[r2][c2],int C[r1][c1])
{
    if (r1 != r2 || c1 != c2)
    {
      return -1;
    }
    for (int i = 0; i < r1; i++)
      {
        for (int j = 0; j < c1; j++)
          {
            C[i][j] = A[i][j] - B[i][j];
          }
      }
    return 0;
}

int multiply(int r1,int c1,int A[r1][c1],int r2,int c2,int B[r2][c2],int C[r1][c2])
{
    if (c1 != r2)
    {
      return -1;
    }
    for (int i = 0; i < r1; ++i)
      {
        for (int j = 0; j < c2; ++j) 
        {
            C[i][j] = 0;
            for (int k = 0; k < c1; ++k)
              {
                C[i][j] += A[i][k] * B[k][j];
              }
        }
      }
    return 0;
}

int main()
{
  int r1, c1, r2, c2; 
  
  printf("Rows and cols of Matrix A: ");
  scanf("%d %d", &r1, &c1);
  
  printf("Rows and cols of Matrix B: ");
  scanf("%d %d", &r2, &c2);

  int A[r1][c1];
  int B[r2][c2];

  getmatrix(r1, c1, A, "A");
  getmatrix(r2, c2, B, "B");

  if (r1 == r2 && c1 == c2) 
  {
        int C[r1][c1];
        add(r1,c1,A, r2,c2,B, C);
        display(r1, c1, C, "A + B");
  } 
  else 
  {
        printf("Cannot add: different dimensions.\n");
  }

  if (r1 == r2 && c1 == c2) 
  {
        int C[r1][c1];
        subtract(r1,c1,A, r2,c2,B, C);
        display(r1, c1, C, "A - B");
  }
  else 
  {
        printf("Cannot subtract: different dimensions.\n");
  }

  if (c1 == r2) 
  {
        int C[r1][c2];
        multiply(r1,c1,A, r2,c2,B, C);
        display(r1, c2, C, "A × B");
  } 
  else 
  {
        printf("Cannot multiply: inner dimensions differ.\n");
  }
       
  return 0;
}
