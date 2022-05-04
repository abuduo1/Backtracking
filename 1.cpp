#include <stdio.h>
#include <stdlib.h>
#define N 50  //��Ʒ�������

int w[N];     //��Ʒ����
int v[N];     //��Ʒ��ֵ
int x[N];     //��Ʒ���Ƿ��ڱ�����1��ʾ���룬0��������
int n,c;      //n��Ʒ������c��������

int CurWeight = 0; //��ǰ���뱳������Ʒ������
int CurValue = 0;  //��ǰ���뱳������Ʒ�ܼ�ֵ
int BestValue = 0; //����ֵ������ֵ����ʼ��Ϊ0
int BestX[N];      //���Ž⣻1������Ʒi���뱳����0��������
 
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
	printf("�����뱳����������\n");
	scanf("%d",&c);
	printf("��������Ʒ�ĸ�����\n");
	scanf("%d",&n);
	printf("������������Ʒ����������ֵ:\n");
	for(int i = 1; i <= n; i++)
	{
	    printf("\t��Ʒ[%d]:",i);
	    scanf("%d%d",&w[i],&v[i]);
	}
}

void output()
{
	printf("\n��ֵ����ֵ��:%d\n",BestValue);
	printf("ѡ����Ʒ��ӦΪ��(");
	for(int i=1;i<=n;i++)
		  printf("%d ",BestX[i]);
	printf(")\n");
	//�����Ʒ���� 
	printf("ѡ����Ʒ�����ͼ�ֵΪ��[");
	for(int i=1;i<=n;i++){
		if(BestX[i])
		  printf("(%d,%d) ",w[i],v[i]);
	}
	printf("]");
}

void backtrack(int t)
{
	//Ҷ�ӽڵ㣬������
	if(t>n)
	{
	 //�ҵ��˸��ŵĽ�,������ŵ�ֵ�ͽ�
		if(CurValue>BestValue)  
		{
			BestValue = CurValue;
			for(int i=1; i<=n; ++i)
			  BestX[i] = x[i];
		}
	}
	else{
		//������ǰ�ڵ���ӽڵ㣺0 �����뱳����1���뱳��
		for(int i=0; i<=1; ++i)
		{
			x[t]=i;
			if(i==0) //�����뱳��
				backtrack(t+1);
			else //���뱳��
			{
				//Լ���������ŵ���
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
