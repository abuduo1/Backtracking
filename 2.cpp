#include<stdio.h>
#include<math.h>
#define N 20     //������� 

int a[20];          //���n������ 
int visited[20]={0};   //1��ʾ��ռ�ã�0��ʾδ��ռ�� 
int n,count;        //nΪʵ������������countΪ�������������� 


int isPrime(int a){
	if(a<=1) return 0;
	if(a==2||a==3) return 1;
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0)
		  return 0;
	}
	return 1;
}

 
//�ݹ��������������
void DFS(int step){
	//��step���ף����
	if(step==n&&isPrime(a[0]+a[n-1])){
		for (int i=0;i<n;i++)
			printf("%d ",a[i]);
		count++;
		printf("\n");
		return ;
	}
	//�ݹ�ѡ��ÿһ�������
	else for (int i=2;i<= n;i++){
		if(!visited[i]&&isPrime(i+a[step-1])){	//��ǰֵiû��ʹ��,����ǰһ��ѡ��ֵ֮��Ϊ����
			a[step]=i;      //ѡiΪ��ǰ��ֵ
			visited[i]=1;   //�ı�״̬
			DFS(step+1);    //������һ��
			visited[i]=0;    //״̬��ԭ
		}
	}
}
 
int main(){
	printf("����������n:\n");
	scanf("%d",&n);
	for(int i=0;i<20;i++) //����Ҫ���е����� 
		a[i]=i+1;
	printf("\n�������������£�\n");
	DFS(1);    //���ݷ����������,�������������
	printf("�����������ĸ���Ϊ%d\n",count);
    return 0;
}

