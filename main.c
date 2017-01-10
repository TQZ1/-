#include<stdio.h>
#include<stdlib.h>
typedef int  Status;
typedef Status ** Node;//node指针的指针
#define  MaxNum  10000;//设置10000为无穷
#define  FALSE 0;
#define  TRUE 1;
void main()
{
	int i,v0,choice;
	int w;
	Node a;
	Status *D,*pre;
	while(1)
	{
      start1:
		printf("\n          请选择：\n");
		printf("                    1.自己制作路由拓补图\n\n");
		printf("                    2.退出!\n\n");
		printf("请输入你的选择：");
		scanf("%d",&choice);
		if(choice==2)
			break;
		else if(choice>3||choice<0||choice%1!=0)
		{
			printf("ERROR!请重新选择\n");
			goto start1;
		}
		switch(choice)
		{
		case 1:
        start:
			printf("请输入网络拓补中路由器总数:");
			scanf("%d",&i);
			if(i<=0|| i%1 !=0)
			{
				printf("你输入的路由器的个数有误，请重新输入\n");
				goto start;
			}
			//printf("input the arcs:");
			//scanf("%d",&j);
			D=(Status *)malloc(sizeof(Status)*i);//用于存放最短路径长度
			pre=(Status *)malloc(sizeof(Status)*i);//用于存放最短路径经过的结点
			a=Build(i);
			//printf("please input the start node: ");
			//scanf("%d",&v0);
			/*if(v0>i)
			{
				printf("input errors!not excite this node!");
				exit(1);
			}*/
			break;

		}
			for(v0=1;v0<=i;v0++)
			{
				ShortestPath_DIJ( a ,i ,v0-1 ,D , pre );
				Show( D, pre, i, v0-1 );
			}
		printf("\n\n你是否还想再尝试一次?是请输入1,不想请输入0结束！\n请选择：");
		scanf("%d",&w);

		if(w!=1)
			break;
	}//while
}

