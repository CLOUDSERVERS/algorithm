/*
�������������� 
��һ��������n��ʾ��һϵ���������ĺͣ��磺
N=n1+n2+��+nk ������n1��n2�ݡ���nk��1�� k��1)
������n��һ�����ֱ�ʾ��Ϊ������n��һ�����֡�
���ڸ���һ��������n��80��n��1������n�Ĳ�ͬ����һ���ж�����

*/

#include <stdio.h>

int huafen(int n, int m)
{
      if(n < 1 || m < 1) 
		  return 0;
      if(n == 1 || m == 1) 
		  return 1;
      if(n < m) 
		  return huafen(n, n);
      if(n == m) 
		  return (huafen(n, m - 1) + 1);
      if(n > m) 
		  return (huafen(n, m - 1) + huafen((n - m), m));
}

int main()
{
	int m;
	printf("������Ҫ���ֵ���:");
	scanf("%d",&m);
    printf("%d�Ļ�����: %d\n", m,huafen(m, m));
    return 0;
}


