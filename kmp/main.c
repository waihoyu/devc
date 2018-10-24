#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ViolentMatch(char* s, char* p)  
{  
    int sLen = strlen(s);  
    int pLen = strlen(p);  
  
    int i = 0;  
    int j = 0;  
    while (i < sLen && j < pLen)  
    {  
        if (s[i] == p[j])  
        {  
            //①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++      
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0      
            i = i - j + 1;  
            j = 0;  
        }  
    }  
    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1  
    if (j == pLen)  
        return i - j;  
    else  
        return -1;  
}  

int main(int argc, char *argv[]) {
	char* s= "dabchie";
	char* p = "abc";
	int result = ViolentMatch(s,p); 
	printf("KMP暴力求解算法%d",result);
	return 0;
}
