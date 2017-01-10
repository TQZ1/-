#include<stdio.h>
#include<stdlib.h>
typedef int  Status;
typedef Status ** Node;//node指针的指针
#define  MaxNum  10000;//设置10000为无穷
#define  FALSE 0;
#define  TRUE 1;
void Show(Status *D , Status *pre ,int i ,int v0)//D是最短路径长度，PRE是最短路径经过的结点，I是结点数，V0是源结点
{
	int j,k,m,n;
	int *temp;
	temp=(int *)malloc(sizeof(int)*i);
	for(j=0;j<i;j++)
	{
		if(j!=v0)
		{
		printf("\n路由[%d]到路由[%d]的最短路径长度为:%3d   " ,v0+1,j+1,D[j]);
		n=j;
		if(D[j]!=10000)//判断是不是有可达路径
			for(k=0;k<i;k++)
			{
				temp[k]=pre[n];
				if(temp[k]!=v0)//判断是不是源点自身
					n=temp[k];
				else
					//(temp[k]==v0)//是源点跳出
					break;
			}
			if( k==0&&D[j]!=10000&&D[j]!=0 )//当是源点时
			{
				printf("路由[%d]->路由[%d]",v0+1,j+1);
			}
			if( k!=0 &&D[j]!=10000&&D[j]!=0)//不是源点时
			{
				for(m=k;m>=0;m--)
				{
					printf("路由[%d]->",temp[m]+1);
				}
				printf("路由[%d]",j+1);
			}
			if(D[j]==10000)//没有路径
			{
				printf("从路由[%d]出发没有最短路径到路由[%d]!",v0+1,j+1);
			}
			if(D[j]==0)
			{
				printf("路由[%d]",v0);
			}
		}
	}
}
