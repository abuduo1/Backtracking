#include<stdio.h>
#include<stdlib.h>
#define N 20             //���ڵ���
 
int n;                   //ʵ�ʽڵ��� 
int x[20];               //1�����i���ڵ㱻ռ�ã�0δ��ռ�� 
int visited[20];         //�������Ľڵ�ѡ�����
int b[20][20];           //�ڽӾ���
int count=0,bestcount=0; //�������Ľڵ�����Լ����Ž� 


void input(){
	printf("���������������Ĭ�ϼ�Ϊ1-n��:\n");
	scanf("%d",&n);
	printf("���������Ӿ���i���j������Ϊ1��������Ϊ0����\n");
	for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        scanf("%d",&b[i][j]);
}

void output(){
	printf("\n����Ÿ���Ϊ��%d\n�ڵ������[",bestcount);
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
    if(step>n)  //�ִ�Ҷ�ӽڵ���� 
    {
        bestcount=count;
        for(int i=1;i<=n;i++)
            visited[i]=x[i];
        return;
    }
    else
    {
        int sign=1;  //��־λ��sign=1�������������(i������ѡ��ĵ㼯)
        for(int i=1;i<=n;i++)
        {
            if((x[i]==1)&&(b[step][i]==0))
            {
                sign=0;
                break;
            }
        }
        if(sign==1)//˵����i������Ա��ӽ�ȥ,����������
        {
            x[step]=1;
            count++;
            DFS(step+1);
            count--;//���ݵ�ԭ��
            x[step]=0;
        }
        else    //˵����i���㲻�ܱ��ӽ�ȥ,����������
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

