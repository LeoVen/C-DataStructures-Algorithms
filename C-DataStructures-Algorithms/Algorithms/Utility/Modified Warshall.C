#include <stdio.h>
#include <conio.h>
#define INFINITY 9999
void read (int mat[5][5], int n);
void display(int mat[5][5], int n);
int main()
{
int adj[5][5], Q[5][5], n, i, j, k;
clrscr();
printf("\n Enter the number of nodes in the graph : ");
scanf("%d", &n);
printf("\n Enter the adjacency matrix : ");
read(adj, n);
clrscr();
printf("\n The adjacency matrix is : ");
display(adj, n);
	 for(i=0;i<n;i++)
{
	 	 for(j=0;j<n;j++)
 {
	 	 	 if(adj[i][j] == 0)
 Q[i][j] = INFINITY;
 else
 Q[i][j] = adj[i][j];
 }
}
	 for(k=0; k<n;k++)
{
	 	 for(i=0;i<n;i++)
 {
    for(j=0;j<n;j++)
 {
 if(Q[i][j] <= Q[i][k] + Q[k][j])
 Q[i][j] = Q[i][j];
 else
 Q[i][j] = Q[i][k] + Q[k][j];
 }
 }
 printf("\n\n");
 display(Q, n);
}
getch();
	 return 0;
}
void read(int mat[5][5], int n)
{
int i, j;
	 for(i=0;i<n;i++)
{
	 	 for(j=0;j<n;j++)
 {
 printf("\n mat[%d][%d] = ", i, j);
 scanf("%d", &mat[i][j]);
 }
}
}
void display(int mat[5][5], int n)
{
int i, j;
	 for(i=0;i<n;i++)
{printf("\n");
	 	 for(j=0;j<n;j++)
 printf("%d\t", mat[i][j]);
}
}
