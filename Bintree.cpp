//1803020131 郑宇凡 电信18-1
#include<iostream>
using namespace std;
typedef struct Bnode
{
   int data;
   struct Bnode *Lson, *Rson;
} BinTree;

BinTree *PerCreateTree()
{
	BinTree *T; 
	int item;
	cin >> item;
	if( item == 0 )              //叶节点数据标志：其后根两个0 
	    T = NULL;            //若某一节点为叶子结点，则其左右子树均为NULL，0表示建空树
	else
	{
		T = (BinTree*)malloc(sizeof(BinTree));
		T->data = item;
		
		T->Lson = PerCreateTree();             //递归创建其左子树 
		T->Rson = PerCreateTree();            //递归创建其右子树 
	} 
	
	return T;                              //返回根节点 
}


void PreOrder(BinTree *root)
{
     if(root!=NULL)
     {
        printf("%d ", root->data);
        PreOrder(root->Lson);
        PreOrder(root->Rson);
      }
}
void InOrder(BinTree *root)
{
     if(root!=NULL)
     {
        InOrder(root->Lson);
        printf("%d ", root->data);
        InOrder(root->Rson);
     }
}

int main()
{
   BinTree *s; 
   s=PerCreateTree();//1 2 4 0 0 5 0 0 3 0 0
   InOrder(s);

    system("pause");
    return 0;
}
