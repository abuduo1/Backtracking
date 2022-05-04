#include<stdio.h>
#include<math.h>
#define N 20     //最大整数 

int a[20];          //存放n个整数 
int visited[20]={0};   //1表示被占用，0表示未被占用 
int n,count;        //n为实际整数个数，count为符合条件的排列 


int isPrime(int a){
	if(a<=1) return 0;
	if(a==2||a==3) return 1;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0)
		  return 0;
	}
	return 1;
}

 
//递归输出所有素数环
void DFS(int step){
	//若step到底，输出
	if(step==n&&isPrime(a[0]+a[n-1])){
		for (int i=0;i<n;i++)
			printf("%d ",a[i]);
		count++;
		printf("\n");
		return ;
	}
	//递归选定每一层的整数
	else for (int i=2;i<= n;i++){
		if(!visited[i]&&isPrime(i+a[step-1])){	//当前值i没被使用,且与前一个选定值之和为素数
			a[step]=i;      //选i为当前项值
			visited[i]=1;   //改变状态
			DFS(step+1);    //进入下一层
			visited[i]=0;    //状态还原
		}
	}
}
 
int main(){
	printf("请输入整数n:\n");
	scanf("%d",&n);
	for(int i=0;i<20;i++) //输入要排列的整数 
		a[i]=i+1;
	printf("\n素数环排列如下：\n");
	DFS(1);    //回溯法遍历解答树,输出所有素数环
	printf("符合素数环的个数为%d\n",count);
    return 0;
}

