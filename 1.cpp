#include <stdio.h>
#include <stdlib.h>
#define N 50  //物品最大数量

int w[N];     //物品重量
int v[N];     //物品价值
int x[N];     //物品是是否在背包，1表示放入，0代表不放入
int n,c;      //n物品数量，c背包容量

int CurWeight = 0; //当前放入背包的物品总重量
int CurValue = 0;  //当前放入背包的物品总价值
int BestValue = 0; //最优值；最大价值，初始化为0
int BestX[N];      //最优解；1代表物品i放入背包，0代表不放入
 
void input();
void backtrack(int t);
void output();
 
int main(int argc, char* argv[])
{
	input();
	backtrack(1);
	output();
	return 0;
}

void input()
{
	printf("请输入背包的容量：\n");
	scanf("%d",&c);
	printf("请输入物品的个数：\n");
	scanf("%d",&n);
	printf("请输入所有物品的重量及价值:\n");
	for(int i = 1; i <= n; i++)
	{
	    printf("\t物品[%d]:",i);
	    scanf("%d%d",&w[i],&v[i]);
	}
}

void output()
{
	printf("\n价值最优值是:%d\n",BestValue);
	printf("选中物品对应为：(");
	for(int i=1;i<=n;i++)
		  printf("%d ",BestX[i]);
	printf(")\n");
	//输出物品内容 
	printf("选择物品重量和价值为：[");
	for(int i=1;i<=n;i++){
		if(BestX[i])
		  printf("(%d,%d) ",w[i],v[i]);
	}
	printf("]");
}

void backtrack(int t)
{
	//叶子节点，输出结果
	if(t>n)
	{
	 //找到了更优的解,保存更优的值和解
		if(CurValue>BestValue)  
		{
			BestValue = CurValue;
			for(int i=1; i<=n; ++i)
			  BestX[i] = x[i];
		}
	}
	else{
		//遍历当前节点的子节点：0 不放入背包，1放入背包
		for(int i=0; i<=1; ++i)
		{
			x[t]=i;
			if(i==0) //不放入背包
				backtrack(t+1);
			else //放入背包
			{
				//约束条件：放的下
				if((CurWeight+w[t])<=c)
				{
				CurWeight += w[t];
				CurValue += v[t];
				backtrack(t+1);
				CurWeight -= w[t];
				CurValue -= v[t];
			 	}
			}
		}
    }
}
