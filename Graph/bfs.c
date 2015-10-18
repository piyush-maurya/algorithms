#include<stdio.h>
int a[20][20],reach[20],n,s;
void dfs(int v)
{
 int i;
 reach[v]=1;
 for(i=1;i<=n;i++)
  if(a[v][i] && !reach[i])
  {
   printf("\n%d->%d",v,i);
   dfs(i);
  }
}
int main()
{
	int i,j,count=0;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		reach[i]=0;
		for(j=1;j<=n;j++)
			a[i][j]=0;
	}
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		printf("Enter the source of the graph: ");
		scanf("%d",&s);
		printf("The BFS traversal of graph is:");
		dfs(s);
		for(i=1;i<=n;i++)
		{
			if(reach[i])
				count++;
		}
		if(count==n)
			printf("\nGraph is connected\n");
		else
			printf("\nGraph is not connected\n");
		return 0;
}

