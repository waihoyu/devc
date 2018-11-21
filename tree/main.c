#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_TREE_SIZE 100


//双亲孩子表示法
 
typedef char ElemType;

typedef struct CTNode
{
    int child; //孩子结点的下标 
	struct CTNode *next;	 //指向下一个孩子结点的指针 
} *ChildPtr;

//表头结构
typedef struct 
{
  ElemType data;	//存放在书中的结点结构 
  int parent;
  ChildPtr first;
} CTBox;


//树结构
typedef struct
{
  CTBox nodes[MAX_TREE_SIZE]	
} ;

int main(int argc, char *argv[]) {
	
	
	
	
	return 0;
}
