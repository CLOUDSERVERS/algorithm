/**
nxn�ķ������̣���n����������Ļʺ�Ҫ��ÿ���У��У���б���ϲ����������ʺ�
��������һ���ж����ֲ��ַ�����
*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Queen{
public:
	friend int nQueen(int n);
private:
	bool Place(int k);
	void BackTrack(int t);

	int sum;
	int *p;
	int n;
};

bool Queen::Place(int k)
{
	for(int i=1;i<k;i++)
	{
		if(abs(i-k)==abs(p[i]-p[k])||p[i]==p[k])
			return false;
	}
	return true;
}

void Queen::BackTrack(int t)
{
	if(t>n){
		sum++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		p[t]=i;
		if(Place(t))
		{
			BackTrack(t+1);
		}
	}
}

int nQueen(int n)
{
	Queen q;
	q.sum=0;
	q.n=n;
	int *x=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		x[i]=0;
	}
	q.p=x;
	q.BackTrack(1);
	delete []x;
	return q.sum;

}

void main(){

	int QueenNum,n;
	cin>>n;
	QueenNum=nQueen(n);
	cout<<QueenNum<<endl;
}