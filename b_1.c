#include<stdio.h>
#include<stdlib.h>
typedef int  Status;
typedef Status ** Node;//node指针的指针
#define  MaxNum  10000;//设置10000为无穷
#define  FALSE 0;
#define  TRUE 1;
Node Build (Status num )
{
   int i,j,k;
   Node a;
   a=(Node) malloc( num * sizeof (Status *));
   printf("\n请输入各路由边线的cost的权值 ，如果不存在真接连接请输入10000\n");
   for(i=0;i<num;i++)
   {
	   a[i]=(Status *) malloc( num * sizeof (Status));
	   for(j=0;j<num;j++)
	   {
		   a[i][j]=MaxNum;
	   }
   }
   for(i=0;i<num;i++)
   {
	   for(j=0;j<num;j++)
	   {
		   if(i!=j)
		   {
			   printf("请输入第%d个结点到第个%d结点到的权值",i+1,j+1);
			   scanf("%d",&k);
		   /*if( i>=num || j>=num )
		   {
			   printf("无效的输入!请重新输入!!");
			   exit(1);
		   }*/
			   a[i][j]=k;
		   }
		   else
			   a[i][j]=10000;
	   }
   }
   return a;
}
