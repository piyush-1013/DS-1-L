#include<stdio.h>
void getmat(int r, int c, int a[10][10])
{
	int i,j;
	printf("Enter elements of matrix: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void comp(int r,int c,int a[10][10],int b[100][3])
{
    int i,j,k,t;
    b[0][0]=r;
	b[0][1]=c;
	k=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
	}
	b[0][2]=k-1;
	t=b[0][2];
	printf("compact matrix is: ");
	printf(" Row   column   value   \n");
	for(i=0;i<=b[0][2];i++)
	{
			printf("\n %d \t %d \t %d",b[i][0],b[i][1],b[i][2]);
	}
	
}
void stp(int b[100][3],int t[100][3],int r,int c)
{
    int q,i,j;
    t[0][0]=b[0][1];
    t[0][1]=b[0][0];
    t[0][2]=b[0][2];
    if(b[0][2]>=0)
    {
        q=1;
        for(j=0;j<c;j++)
        {
            for(int p=1;p<=b[0][2];p++)
            {
                if(b[p][1]==j)
                {
                    t[q][0]=b[p][1];
                    t[q][1]=b[p][0];
                    t[q][2]=b[p][2];
                    q=q+1;
                }
            }
        }
    }
    printf("\nTranspose of matrix is: \n");
    for(i=0;i<=t[0][2];i++)
	{
			printf("\n %d \t %d \t %d",t[i][0],t[i][1],t[i][2]);
	}
}
void ftp()
{
    
}
int  main()
{
	int r,c , a[10][10],b[100][3],k,i,j,t[100][3];
	printf("Enter number of rows of matrix: ");
	scanf("%d",&r);
	printf("Enter number of columns of matrix: ");
	scanf("%d",&c);
	getmat(r,c,a);
	comp(r,c,a,b);
	stp(b,t,r,c);
	return 0;
}
