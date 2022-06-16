//1803020131 郑宇凡 电信18-1
#include<iostream>
using namespace std;
int main()
{
    int i,j,temp=0,m=0;
    int num[10]={31,10,2,3,4,7,3,8,9,1};
    for(i=0;i<10;i++)//每次选择最小的放在前面
    {
        m=i;//第一个位置
        for(j=i+1;j<10;j++)//选择数最小的下标
        {
            
            if(num[j]<num[m])
            {
                m=j;
            }

        }
         if(m!=i)//如果有位置移动则交换数值
            {
                 temp=num[i];
                num[i]=num[m];
               num[m]=temp;
            }
    }
    system("pause");
    return 0;
}