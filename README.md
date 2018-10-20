# 数据结构与算法（C语言实现）

## 目录
1. [二进制转化十进制](#jump1)
2. [拉丁方阵问题](#jump2)
3. [逆波兰计算器](#jump3)

## 详解


### 1. 二进制转化十进制 <a name="jump1" />

> 二进制转化十进制。 

```c

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	
	/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	#define STACK_INIT_SIZE 20
	#define STACKINCREMENT 10
	
	typedef char ElemType;
	typedef struct
	{
		ElemType *base;
		ElemType *top;
		int stackSize;
	} sqStack;
	
	void InitStack(sqStack *s){
		s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
		if(!s->base){
			exit(0);
		}
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
	
	void Push(sqStack *s, ElemType e){
		if(s->top - s->base >= s->stackSize){
			s->base = (ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));
			if(!s->base)
			{
				exit(0);
			}
		}
		*(s->top) = e;
		s->top++;
	} 
	
	void Pop(sqStack *s, ElemType *e){
		if(s->top == s->base){
			return;
		}
		*e = *--(s->top);
	}
	
	int StackLen(sqStack s){
		return (s.top - s.base);
	}
	
	int main(int argc, char *argv[]) {
		ElemType c;
		sqStack s;
		int len, i, sum = 0;
		InitStack(&s);
		printf("请输入二进制数，输入#符号表示结束！\n");
		scanf("%c",&c);
		while(c != '#'){
			Push(&s,c);
			scanf("%c",&c);
		}
		getchar(); //把‘\n’从缓冲区去掉 
		len = StackLen(s);
		printf("栈的当前容量是：%d\n",len);
		for(i=0;i<len;i++){
			Pop(&s,&c);
			sum = sum + (c-48) * pow(2,i);
		}
		printf("转化为为十进制数是：%d\n",sum);
		return 0;
	}

```

### 2.  拉丁方阵问题  <a name="jump2" />
> 拉丁方阵是一种N*N的方阵，方阵中恰有N种不同的元素，每种元素恰有N个，并且每种元素在一行和一列中，恰好出现一次。著名数学家和物理学家欧拉使用拉丁字母来作为拉丁方阵里元素的符号，拉丁方阵因此而得名。

```c


```



### 3.  逆波兰计算器  <a name="jump3" />

>  写一个逆波兰计算器，需要实现以下要求：
实现对逆波兰输入的表达式进行计算。支持带小数点的数据。
正常的表达式---> 逆波兰表达式
 -a+b   -->  a  b  +
 -a+(b-c)  -->  a b c - +
 -a+(b-c)*d  --> a b c - d * +
 -a+d*(b-c) --> a d b c - * +

```c

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <ctype.h>
	
	/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	#define STACK_INIT_SIZE 20
	#define STACKINCREMENT  10
	#define MAXBUFFER       10
	
	typedef double ElemType;
	typedef struct
	{
		ElemType *base;
		ElemType *top;
		int stackSize;
	} sqStack;
	
	void InitStack(sqStack *s){
		s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
		if(!s->base){
			exit(0);
		}
		s->top = s->base;
		s->stackSize = STACK_INIT_SIZE;
	}
	
	void Push(sqStack *s, ElemType e){
		if(s->top - s->base >= s->stackSize){
			s->base = (ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));
			if(!s->base)
			{
				exit(0);
			}
		}
		*(s->top) = e;
		s->top++;
	} 
	
	void Pop(sqStack *s, ElemType *e){
		if(s->top == s->base){
			return;
		}
		*e = *--(s->top);
	}
	
	int StackLen(sqStack s){
		return (s.top - s.base);
	}
	
	int main(int argc, char *argv[]) {
		sqStack s;
		char c;
		double d, e;
		char str[MAXBUFFER];
		int i = 0;
		
		InitStack(&s);
		printf("请按逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开，以#作为结束标志：\n");
		scanf("%c",&c);
		while(c != '#'){
			while(isdigit(c) || c =='.'){
				str[i++] =c;
				str[i] = '\0'; //必须加上 
				if(i>=10){
				   printf("出错：输入的单个数据过大！\n");
				   return -1;	
				}
				scanf("%c",&c);
				if(c == ' '){
					d = atof(str);
					Push(&s,d);
					i = 0;
					break;
				}
				scanf("%c",&c);
			}
			switch(c){
				case '+':
				   Pop(&s, &e); 
				   Pop(&s,&d);
				   Push(&s,d+e);
				   break;
				case '-':
					Pop(&s,&e);
					Pop(&s,&d);
					Push(&s,d-e);
					break;
				case '*':
					Pop(&s,&e);
					Pop(&s,&d);
					Push(&s,d*e);
					break;
				case '/':
					Pop(&s,&e);
					Pop(&s,&d);
					if(e != 0){
						Push(&s, d/e);
					}
					else{
						printf("\n出错：除数为零！\n");
						return -1;
					}
					break;
			}
		   scanf("%c",&c);
		} 
		Pop(&s,&d);
		printf("\n 最终的计算结果为：%f\n",d);
		return 0;
	}


```