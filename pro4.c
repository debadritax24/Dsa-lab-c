//
#include<stdio.h>

int main ()
{
    int sales[5][3],i,j,totalsales=0;
    printf("enter the data\n");
    printf ("\n *************\n");
    for (i=0;i<5;i++)
    {
        printf("enter the sales of 3 items by salesman%d ",i+1);
        for (j=0;j<3;j++)
        scanf("%d",&sales[i][j]);
    }
    for (i=0;i<5;i++)
    {
        totalsales=0;
        for (j=0;j<3;j++)
        totalsales+=sales[i][j];
        printf("\ntotal sales by salesman %d=%d",i+1,totalsales);
    }
    for (i=0;i<3;i++)
    {
        totalsales=0;
        for (j=0;j<5;j++)
        {
            totalsales+=sales[i][j];
            printf ("\n total sales for item %d=%d",i+1,totalsales);
        }
        return 0;
    }
}