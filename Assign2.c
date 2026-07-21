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
	printf("compact matrix is: \n");
	printf(" Row   column   value   \n");
	for(i=0;i<=b[0][2];i++)
	{
			printf("\n %d \t %d \t %d",b[i][0],b[i][1],b[i][2]);
	}
	
}
void smtp(int b[100][3],int stp[100][3],int r,int c)
{
    int q,i,j,t;
    t=b[0][2];
    stp[0][0]=b[0][1];
    stp[0][1]=b[0][0];
    stp[0][2]=b[0][2];
    if(b[0][2]>=0)
    {
        q=1;
        for(j=0;j<c;j++)
        {
            for(int p=1;p<=b[0][2];p++)
            {
                if(b[p][1]==j)
                {
                    stp[q][0]=b[p][1];
                    stp[q][1]=b[p][0];
                    stp[q][2]=b[p][2];
                    q=q+1;
                }
            }
        }
    }
    printf("\nTranspose of matrix by simple transpose method: \n");
    for(i=0;i<=b[0][2];i++)
	{
			printf("\n %d \t %d \t %d",stp[i][0],stp[i][1],stp[i][2]);
	}
}
void fstp(int b[100][3],int s[100],int t[100],int ftp[100][3],int c)
{
    int i,j;
    ftp[0][0]=b[0][1];
    ftp[0][1]=b[0][0];
    ftp[0][2]=b[0][2];
    if(b[0][2]>=0)
    {
        for(i=0;i<c;i++)
        {
            s[i]=0;
        }   
        for(i=1;i<=b[0][2];i++)
        {
            s[b[i][1]]=s[b[i][1]]+1;
        }
        t[0]=1;
        for(i=1;i<c;i++)
        {
            t[i]=t[i-1]+s[i-1];
        }
        for(i=1;i<=b[0][2];i++)
        {
            j=b[i][1];
            ftp[t[j]][0]=b[i][1];
            ftp[t[j]][1]=b[i][0];
            ftp[t[j]][2]=b[i][2];
            t[j]=t[j]+1;
        }
    }
    printf("\nTranspose of matrix by fast transpose method: \n");
    for(i=0;i<=b[0][2];i++)
	{
			printf("\n %d \t %d \t %d",ftp[i][0],ftp[i][1],ftp[i][2]);
	}
}
int  main()
{
	int r,c,a[10][10],b[100][3],k,i,j,stp[100][3],ft[100][3],s[100],t[100],ftp[100][3];
	printf("Enter number of rows of matrix: ");
	scanf("%d",&r);
	printf("Enter number of columns of matrix: ");
	scanf("%d",&c);
	getmat(r,c,a);
	comp(r,c,a,b);
	smtp(b,stp,r,c);
	fstp(b,s,t,ftp,c);
	return 0;
}
