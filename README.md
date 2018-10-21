# 数据结构与算法（C语言实现）

## 目录
1. [二进制转化十进制](#jump1)
2. [拉丁方阵问题](#jump2)
3. [逆波兰计算器](#jump3)
3. [中缀表达式转换为后缀表达式](#jump4)
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

> 
  -a+b   -->  a  b  +
> 
  -a+(b-c)  -->  a b c - +
> 
  -a+(b-c)*d  --> a b c - d * +
> 
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

### 4.  中缀表达式转换为后缀表达式  <a name="jump4" />
> 中缀表达式转换为后缀表达式

参考文献 
https://www.cnblogs.com/chensongxian/p/7059802.html

```c

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include <ctype.h>
	
	/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	#define STACK_INIT_SIZE 20
	#define STACKINCREMENT  10
	#define MAXBUFFER       10
	
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
		sqStack s;
		char c, e;
		InitStack(&s);
		printf("\n 请输入中缀表达式，以#作为结束标志：\n");
		scanf("%c", &c);
	    while( c!='#'){
	    	while(c>='0'&&c<='9'){
	    		printf("%c", c);
	    		scanf("%c",&c);
	    		if( c<'0' || c>'9'){
	    			printf(" ");
				}
			}
			 if (')' == c){
				Pop(&s, &e);
				while( '(' != e){
					printf("%c ", e);
					Pop(&s, &e);
				}
			}else if( '+'==c || '-'==c){
				if(!StackLen(s)){
					Push(&s, c); 
				}
				else{
					do{
						Pop(&s, &e);
						if( '('==e){
							Push(&s, e);
						}
						else{
							printf("%c ", e);
						}
					}while(StackLen(s) && '('!=e);
					Push(&s,c);
				}
			}else if ('*'==c || '/'==c || '('==c){
				Push(&s, c);
			}else if('#' == c){
				break;
			}else{
				printf("\n出错：输入格式错误！\n");
				return -1;
			}
	    	scanf("%c",&c);
		} 
		while(StackLen(s)){
			Pop(&s, &e);
			printf("%c", e);
		}
		return 0;
	}
	
	//   1+(2-3)*4+10/5#


```


# Algorithm  算法
## Algorithm  算法案例练习
<hr>

##  1、十进位数转换其他进制数 
###  自己实现的代码
    /**
    * 题目：给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数。
    */
    /**
    * 算法思路，利用了求余、求模运算
    * 把每次的模unshift到一个数组里面
    * 缺点：自己实现的，方法笨拙
    */
    function Hexade(bin, number) {
    var tmpNum = number;
    var arr = [];
    var str = '';
    var bin = bin || 10;
    while (tmpNum != 0 && tmpNum != 1) {
        b = tmpNum % bin;
        if (bin > 10 && bin <= 16 && b > 9) {
            b = String.fromCharCode(b - 10 + 65);
            arr.unshift(b);
        } else
            arr.unshift(b);
        tmpNum = Math.floor(tmpNum / bin)
    }
    arr.unshift(tmpNum)
    console.log(arr);
    }
    Hexade(15, 44444445);
 <hr>

##  2、冒泡排序 


 <hr>

##  3、选择排序





 <hr>

##  4、插入排序





 <hr>

##  5、归并排序







 <hr>

##  6、快速排序






 <hr>

##  7、KMP算法


<hr>

##  8、输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 
    /**
    * 题目：输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2 。
    */
    /**
    * 算法思路：从五开始，每次加五，循环整除五，整除5次数+1，直到不能整除
    */
    var countZero = function(num) {
        var counter = 0;
        var tmp = 0;
        for (var a = 5; a <= num; a += 5) {
            tmp = a;
            while (tmp % 5 == 0) {
                counter++;
                tmp = tmp / 5;
            }

        }
        console.log(counter);
    }

    countZero(25);
    
<hr>

##  9、红包算法
    /**
    * 题目： 发红包算法。发红包的（1人），收红包的（n）
    *    典型计算问题，运算的公式或者过程抽象，
    *    计算规则 1、随机  Math.random() 
    *            2、所有人抢到的金额之和等于红包金额
    */
    /**
    * 算法思路：
    */
    class RadomHongbao {
        constructor(num) {
            this.num = this.getNum(num);
            // 得到一确定的小数位的位数
            try {
                this.multiple = this.num.toString().split('.')[1].length
            } catch (e) {
                this.multiple = 0;
            }
            //将小数放大 指数倍成整数
            this.calcNum = this.num * Math.pow(10, this.multiple);
        }
        split(n, precision) {
            let arr = this.average(n, precision);
            let arrResult = arr;
            for (let i = 0; i < arr.length; i++) {
                let item = arr[i];
                let num = Math.floor(Math.random() * item);
                let numLeft = Math.floor(Math.random() * num);
                let numRight = num - numLeft;
                arrResult[i] -= num;
                let iLeft = (i === 0) ? (arr.length - 1) : i - 1;
                let iRight = (i === arr.length - 1) ? 0 : i + 1;
                arrResult[iLeft] += numLeft;
                arrResult[iRight] += numRight;
            }
            return arrResult;
        }
        average(n, precision) {
            let avg = Math.floor(this.calcNum / n);
            let rest = this.calcNum % n;
            console.log(rest);
            let result = Array(n).fill(avg);
            let gap = Math.round((n - rest) / rest) + 1;
            let index = 0;
            while (rest > 0) {
                index = (--rest) * gap;
                result[index >= n ? (n - 1) : index]++;
            }

            return result.map((item) => {
                return (item / Math.pow(10, this.multiple))
            });
        }
        getNum(num, defaultNum = 0) {
            return this.isNumber(num) ? num : defaultNum;
        }
        isNumber(num) {
            //各种可能出现问题的，排除
            let number = +num; //加号 的作用  
            if ((number - num) !== 0) {
                return false;
            }
            if (number === num) {
                return true;
            }
            if (typeof num === 'string') {
                return false;
            }
            return true;
        }
    }

    const hongbao = new RadomHongbao(200);
    console.log(hongbao.split(10, 0));
<hr>



<hr>


##  10、荷兰国旗问题
    /**
    * 题目： 荷兰国旗问题          
    */
    /**
    * 算法思路：
    */
