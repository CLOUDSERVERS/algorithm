#include <iostream>
using namespace std;

//��������Ļ��ֺ���
int partition(int a[],int l,int r)
{
    int i,j,x,temp;
    i = l;
    j = r+1;
    x = a[l];
    //��>=x��Ԫ�ػ����������
    //��<=x��Ԫ�ػ����ұ�����
    while (1)
    {
        while(a[++i] > x);
        while(a[--j] < x);
        if(i >= j) break;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    a[l] = a[j];
    a[j] = x;
    return j;
}

//������ֺ���
int random_partition(int a[],int l,int r)
{
    int i = l+rand()%(r-l+1);//���������
    int temp = a[i];
    a[i] = a[l];
    a[l] = temp;
    return partition(a,l,r);//���û��ֺ���
}

//����Ѱ�ҵ�k�����
int random_select(int a[],int l,int r,int k)
{
    int i,j;
    if (l == r) //�ݹ����
    {
        return a[l];
    }
    i = random_partition(a,l,r);//����
    j = i-l+1;
    if(k == j) //�ݹ�������ҵ���K�����
        return a[i];
    if(k < j)
    {
        return random_select(a,l,i-1,k);//�ݹ���ã���ǰ�沿�ֲ��ҵ�K�����
    }
    else
        return random_select(a,i+1,r,k-j);//�ݹ���ã��ں��沿�ֲ��ҵ�K�����
}

int main()
{
    int a[]={1,2,3,4,6,6,7,8,10,10};

    cout<<random_select(a,0,9,1)<<endl;
    cout<<random_select(a,0,9,5)<<endl;
    return 0;
}