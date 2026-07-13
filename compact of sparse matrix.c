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
int  main()
{
	int r,c , a[10][10],b[10][3],k,i,j;
	printf("Enter number of rows of matrix: ");
	scanf("%d",&r);
	printf("Enter number of columns of matrix: ");
	scanf("%d",&c);
	getmat(r,c,a);
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
	printf("Size of compact matrix is %d x %d \n",r,c);
	printf(" Row   column   value   \n");
	for(i=1;i<=b[0][2];i++)
	{
			printf("\n %d\t%d\t%d",b[i][0],b[i][1],b[i][2]);
	}
}
