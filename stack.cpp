#include<iostream>//
typedef struct stacknode //节点
{
 	int data;//数据域
 	struct stacknode *next;//指针域
 	

}Snode;
Snode *top=(Snode*)malloc(sizeof(Snode));//给栈顶指针分配空间
Snode Push(int data)//入栈
{  
    Snode *p=(Snode*)malloc(sizeof(Snode));
    p->next=top; //先接在旧的栈顶
    top=p;//栈顶指针更新
	top->data=data;
}
Snode Pop()//出栈
{
    top=top->next;
}
/**/
int main()
{
    
    Push(1); 
    
    Push(2);
     Push(3);
     Push(4);
   
    printf("%d",top->data);
    printf("%d",top->next->data);
    printf("%d",top->next->next->data);
    //1 2  
    //3
    system("pause");
	
}