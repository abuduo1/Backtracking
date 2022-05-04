#include<stdio.h>
#include<stdlib.h>
#define N 20             //最大节点数
 
int n;                   //实际节点数 
int x[20];               //1代表第i个节点被占用，0未被占用 
int visited[20];         //最大团里的节点选择情况
int b[20][20];           //邻接矩阵
int count=0,bestcount=0; //最大团里的节点个数以及最优解 


void input(){
	printf("请输入点数个数（默认记为1-n）:\n");
	scanf("%d",&n);
	printf("请输入连接矩阵（i点和j点相连为1，不相连为0）：\n");
	for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        scanf("%d",&b[i][j]);
}

void output(){
	printf("\n最大团个数为：%d\n节点包括：[",bestcount);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==1)
        {
            printf("%d ",i);
        }
    }
    printf("]\n");
}

void DFS(int step)
{
    if(step>n)  //抵达叶子节点输出 
    {
        bestcount=count;
        for(int i=1;i<=n;i++)
            visited[i]=x[i];
        return;
    }
    else
    {
        int sign=1;  //标志位，sign=1代表遍历左子树(i加入已选择的点集)
        for(int i=1;i<=n;i++)
        {
            if((x[i]==1)&&(b[step][i]==0))
            {
                sign=0;
                break;
            }
        }
        if(sign==1)//说明第i个点可以被加进去,遍历左子树
        {
            x[step]=1;
            count++;
            DFS(step+1);
            count--;//回溯到原点
            x[step]=0;
        }
        else    //说明第i个点不能被加进去,遍历右子树
        {
            x[step]=0;
            if(count+n-step>bestcount)
                DFS(step+1);
        }
    }
 
}

int main()
{
    input();
    DFS(1);
    output(); 
    return 0;
}

