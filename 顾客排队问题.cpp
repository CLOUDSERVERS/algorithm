/*	����n���˿͵ȴ�һ����񣬹˿�i��Ҫ�����ʱ��Ϊti 
Ӧ��ΰ��Ź˿͵ķ���������ʹƽ���ȴ�ʱ��ﵽ��С��
ƽ���ȴ�ʱ����n���˿͵ĵȴ�ʱ��֮�ͳ���n. ����㷨��
��֤���㷨����ȷ�ԡ�*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,i ;

double fun(vector<int> x)
{ 
	int n=x.size(); 
	sort(x.begin(),x.end());
	for (i=1;i<n;i++)
		x[i]+=x[i-1]; 
	double t=0;
	for (i=0;i<n;i++) 
		t+=x[i] ;
	t/=n;
	return t;
}

int main()
{  
	int a[1000];    
	cin>>n ; 
	vector<int> x; 
	for(i=0;i<n;i++ )  
	{  
		cin>>a[i];   
		x.push_back(a[i]);
	}
	printf("%.2f\n",fun(x)); 
	return 0;
}