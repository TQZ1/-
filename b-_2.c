#include<stdio.h>
#include<stdlib.h>
typedef int  Status;
typedef Status ** Node;//node指针的指针
#define  MaxNum  10000;//设置10000为无穷
#define  FALSE 0;
#define  TRUE 1;
void ShortestPath_DIJ( Node a ,Status i ,Status v0 ,Status *D ,Status *pre )//a是传进的矩阵，i是结点数，v0是最短路径的源结点
{
	int v,w,j,l=1;
	Status *final;//设置int 指针
	Status min;
	final=(Status *)malloc( sizeof(Status)*i );//分配空间
	for(v=0;v<i;v++)//初始化
	{
		final[v]=FALSE;
		pre[v]=FALSE;
		D[v]=a[v0][v];
		if(D[v]<10000)//找到头结点
			pre[v]=v0;
	}
	for(v=0;v<i;v++)
	{
		if( a[v0][v]>=10000 )
          l++;
	}
	if(l>i)
	{
		printf("\n从路由%d出发没有最短路径到其他端点!\n",v0+1);
		exit(0);
	}//v0是一个孤立的顶点
	D[v0]=0;
	final[v0]=TRUE;
	for( j=0 ; j<i ; ++j )
	{
		min=MaxNum;
		for( w=0 ; w<i ; w++)
		{
			if( !final[w] )//判断是否已被最短路径路过
			{
				if( D[w]<min )
				{
					v=w;
					min=D[w];
				}//找出最短的路径
			}
		}
         final[v]=TRUE;
		 for( w=0 ; w<i ; w++ )
		 {
			 if( !final[w] && ( (min+a[v][w])<D[w]) )
			 {
				 D[w]=min+a[v][w];
				 pre[w]=v;
			 }
		 }
	}
}
