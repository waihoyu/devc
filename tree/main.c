#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_TREE_SIZE 100


//˫�׺��ӱ�ʾ��
 
typedef char ElemType;

typedef struct CTNode
{
    int child; //���ӽ����±� 
	struct CTNode *next;	 //ָ����һ�����ӽ���ָ�� 
} *ChildPtr;

//��ͷ�ṹ
typedef struct 
{
  ElemType data;	//��������еĽ��ṹ 
  int parent;
  ChildPtr first;
} CTBox;


//���ṹ
typedef struct
{
  CTBox nodes[MAX_TREE_SIZE]	
} ;

int main(int argc, char *argv[]) {
	
	
	
	
	return 0;
}
