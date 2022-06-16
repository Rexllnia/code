// 1803020131 郑宇凡 电信18-1
#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct sequeue
{
    struct node *rear;  //队尾指针
    struct node *front; //队头指针
};
sequeue init(sequeue seq)
{
    seq.front = seq.rear = (node *)malloc(sizeof(node)); //给队头队位分配空间 空队列队头等于队位
    seq.rear->next = NULL;
    seq.rear->prev = NULL;
    return seq;
}
sequeue pop(sequeue seq)
{

    seq.front = seq.front->next;
    return seq;
}
sequeue rear_pop(sequeue seq)
{

    seq.rear = seq.rear->prev;
    return seq;
}
sequeue push(sequeue seq, int data)
{

    node *temp;
    temp = (node *)malloc(sizeof(node));
    seq.rear->next = temp;
    temp->prev = seq.rear;
    seq.rear = temp;
    seq.rear->data = data;

    return seq;
}
sequeue add(sequeue a, sequeue b)
{
    int Cout = 0, data, flag1 = 0, flag2 = 0;
    sequeue c;
    node *pa, *pb, *pc;
    pa = a.front;
    pb = b.front;
    c = init(c);

    while ((pa != a.rear) || (pb != b.rear)) // pa 或者 pb不是队尾
    {
        if (pa != a.rear)
        {
            pa = pa->next;
        }
        if (pb != b.rear)
        {
            pb = pb->next;
        }
        if (flag1 == 1)
        {
            data = pa->data + Cout;
        }
        else if (flag2 == 1)
        {
            data = pb->data + Cout;
        }
        else
        {
            data = pa->data + pb->data + Cout;
        }

        if (pb == b.rear)
        {
            flag1 = 1;
        }
        if (pa == a.rear)
        {
            flag2 = 1;
        }

        if (data < 10)
        {
            Cout = 0;
        }
        else
        {
            data = data - 10;
            Cout = 1;
        }
        c = push(c, data);
    }
    if (Cout > 0)
    {
        c = push(c, Cout);
    }
    return c;
}
sequeue sub(sequeue a, sequeue b)
{

    int data, Cin = 0, flag1, flag2;
    sequeue c;
    c = init(c);
    node *pa, *pb;

    pa = a.front;
    pb = b.front;

    while ((pa != a.rear) || (pb != b.rear)) // pa 或者 pb不是队尾
    {
        if (pa != a.rear)
        {
            pa = pa->next;
        }
        if (pb != b.rear)
        {
            pb = pb->next;
        }
        if (flag1 == 1)
        {
            data = pa->data - Cin;
        }
        else if (flag2 == 1)
        {
            data = pb->data - Cin;
        }
        else
        {
            data = pa->data - pb->data - Cin;
        }

        if (pb == b.rear)
        {
            flag1 = 1; //本次b到队尾 下一次不算b
        }
        if (pa == a.rear)
        {
            flag2 = 1;
        }
        if (data >= 0)
        {
            Cin = 0;
        }
        else
        {
            data = data + 10;
            Cin = 1;
        }
        c = push(c, data);
    }
    
    while (c.rear!=c.front->next)
    {
        if(c.rear->data==0)
        {
            c=rear_pop(c);
        }
        else 
        {
            break;
        }
    }
    
    return c;
}

sequeue mul(sequeue a, int b)
{ // b 为乘数
    int Cout = 0, tmp = 0, data;
    sequeue c;
    node *pa;
    pa = a.front;
    c = init(c);

    while (pa != a.rear)
    {
        pa = pa->next;
        tmp = pa->data * b + Cout;
        data = tmp % 10;
        Cout = tmp / 10;
        c = push(c, data);
    }
    if (Cout > 0)
    {
        while (Cout > 0)
        {
            c = push(c, Cout % 10);
            Cout /= 10;
        }
    }

    return c;
}
sequeue Sequeue_invert(sequeue s)
{
    node *cur = s.rear;      //用于指向初始队列的队尾元素
    node *p = s.front->next; // p指向对头元素
    int temp;
    while ((p != cur->next) && (p != cur))
    {

        temp = cur->data;
        cur->data = p->data;
        p->data = temp;
        p = p->next;
        cur = cur->prev;
    }

    return s;
}

void Sequeue_display(sequeue s)
{
    node *p;
    p = s.rear;
    while (p != s.front)
    {

        printf("%d", p->data);
        p = p->prev;
    }
}
int sequeue_equal(sequeue a, sequeue b)
{
    sequeue c;
    c=init(c);
    c=sub(a,b);
    if((c.front->next==c.rear)&&(c.rear->data==0))
    {
        return 1;
    }
    return 0;


}
sequeue SequeueMul(sequeue a, sequeue b)
{
    int temp = 1;
    sequeue c;
    node *pb = b.front;
    pb = pb->next;
    c = mul(a, pb->data); // 932*2

    while (pb != b.rear)
    {

        pb = pb->next;
        temp *= 10;
        c = add(c, mul(a, pb->data * temp)); // 20*132+2*132
        // 300*132+20*132+2*132
    }
    return c;
}
/**
  * @brief  判断一个数是否在队列中
  * @param  b: 队列 
  * @param  num: 要判断的数 
  * @retval 存在返回true 不存在返回false
  */
bool Sequeue_find(sequeue b,int num)
{
    node *p=b.front;

    while(p!=b.rear)
    {
        p=p->next;
        if(p->data==num)
        {
            return true;
        }
    }
    return false ;
}
/**
  * @brief  输入一个队列，删除队列中相同的数
  * @param  a: 输入的队列
  * @retval 输出删除相同数的队列
  */
sequeue Sequeue_DeleteSame(sequeue a)
{
    sequeue b;
    b=init(b);
    node *pa=a.front;
    while(pa!=a.rear)
    {
       pa=pa->next;
       if(Sequeue_find(b,pa->data)==false)//没找到说明是新的数
       {
           b=push(b,pa->data); //进一个数
       }
       
    }

    return b;
}
int main()
{
    sequeue input_data, s2, count,num1,sum;
    int data,result;
    count=init(count);
    count=push(count,0);
    sum=init(sum);
    sum=push(sum,1);
    input_data=init(input_data);
    input_data=push(input_data,1);
    input_data=push(input_data,2);
    input_data=push(input_data,1);
    input_data=push(input_data,3);
    input_data=push(input_data,1);
    input_data=push(input_data,4);
    input_data=push(input_data,2);
    Sequeue_display(input_data);
    printf("\n");
    s2=init(s2);
    s2=Sequeue_DeleteSame(input_data);
    Sequeue_display(s2);
    // input_data=Sequeue_invert(input_data);
    // num1=init(num1);
    // num1=push(num1,1);
    // printf("input:");
    // Sequeue_display(input_data);
    // printf("\n");


    // while (1)
    // {
    //     count=add(count,num1);
    //     sum=mul(sum,2);
    //     printf("",result=sequeue_equal(input_data,count));
    //     //result=sequeue_equal(s1,s2);
    //     if(result==1)
    //     {
    //         break;
    //     }
    // }
    // printf("\n");
    // printf("output:");
    // Sequeue_display(sum=sub(sum,num1));

    
 


    system("pause");
    return 0;
}