#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef char ElemType;

typedef struct BiTNode
{
   char data;
   struct BiTNode *lchild , *rchild;	
}BiTNode, *BiTree;

//����һ�ö�����
CreateBiTree(BiTree *T){
	char c;
	scanf("%c", &c);
	if(' ' == c)
	{
	   *T = NULL;
	}
	else
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
} 

//���ʶ��������ľ������ 
visit(char c,int level){
  printf("%c λ�ڵ� %d �� \n",c,level);	
}
//ǰ�����������
PreOrderTraverse(BiTree T,int level){
	if(T){
		visit(T->data,level);
		PreOrderTraverse(T->lchild,level+1); 
		PreOrderTraverse(T->rchild,level+1); 
	}
} 

int main(int argc, char *argv[]) {
	int level = 1; 
	BiTree tree = NULL;
	CreateBiTree(&tree);
	PreOrderTraverse(tree, level);
//	printf("λ�ڵ� �� \n");	
	return 0;
}
