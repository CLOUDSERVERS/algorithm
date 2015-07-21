/*
��4������ȫ������4!=24�����С�

4�����ֹ���Ҫ3���������ͬһ������������ظ����֣�����4x4x4=64�������

����4�����ֶ��ԣ���������5�м����ŵķ�ʽ��

(A(B(CD)))��(A((BC)D))��((AB)(CD))��((A(BC))D)��(((AB)C)D)��

���Ա����ı��ʽ�����24*64*5=7680�֡���ʹ�����沨�����ʽ���������䡣

/*24����Ϸ�㷨����ٷ��� 
f(Array)
{
   if(Array.Length<2)
   {
     if(�õ������ս����24) ������ʽ
     else ����޷���Ҫ��ı��ʽ
   }
   foreach(��������ȡ���������������)
   {
      foreach(�����(+ - * /))
      {
         1�����������ڴ�������µĽ��
         2����������е���������ԭ������ɾ������������1�Ľ����������
         3����������ݹ����f������ҵ�һ�����ʽ�ͷ���
         4��������1�ļ������Ƴ�������������е����������·Ż������ж�Ӧ��λ��
      } 
   }
}     
*/
*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const double Threshold=1E-6;
const int CardsNumber=4;
const int ResultValue=24;
double number[CardsNumber];
string result[CardsNumber];

bool PointsGame(int n)
{
    if(n==1)
    {
        //�������ıȽ�ʹ�ò�ֵ����ֵ�ıȽ�
        if(fabs(number[0]-ResultValue)<Threshold)
        {
            cout<<result[0]<<endl;
            return true;
        }
        else return false;
    }
    for(int i=0; i<n; ++i)
        for(int j=i+1; j<n; ++j)
        {
            double a,b;
            string expa,expb;

            a=number[i];
            b=number[j];
            number[j]=number[n-1];

            expa=result[i];
            expb=result[j];
            result[j]=result[n-1];

            result[i]='('+expa+'+'+expb+')';
            number[i]=a+b;
            if(PointsGame(n-1)) return true;

            result[i]='('+expa+'-'+expb+')';
            number[i]=a-b;
            if(PointsGame(n-1)) return true;

            result[i]='('+expb+'-'+expa+')';
            number[i]=b-a;
            if(PointsGame(n-1)) return true;

            result[i]='('+expa+'*'+expb+')';
            number[i]=a*b;
            if(PointsGame(n-1)) return true;

            if(b!=0)
            {
                result[i]='('+expa+'/'+expb+')';
                number[i]=a/b;
                if(PointsGame(n-1)) return true;
            }
            if(a!=0)
            {
                result[i]='('+expb+'/'+expa+')';
                number[i]=b/a;
                if(PointsGame(n-1)) return true;
            }

            number[i]=a;
            number[j]=b;
            result[i]=expa;
            result[j]=expb;
        }
        return false;
}

int main()
{
    int x;
    for(int i=0; i<4; ++i)
    {
       char buffer[20];
       cout<<"the "<<i+1<<"th number:";
       cin>>x;
       number[i]=x;
       itoa(x,buffer,10);
       result[i]=buffer;
    }
    if(PointsGame(CardsNumber))
      cout<<"Success."<<endl;
    else cout<<"Fail."<<endl;

    return 0;
}