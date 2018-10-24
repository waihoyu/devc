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
            //�������ǰ�ַ�ƥ��ɹ�����S[i] == P[j]������i++��j++      
            i++;  
            j++;  
        }  
        else  
        {  
            //�����ʧ�䣨��S[i]! = P[j]������i = i - (j - 1)��j = 0      
            i = i - j + 1;  
            j = 0;  
        }  
    }  
    //ƥ��ɹ�������ģʽ��p���ı���s�е�λ�ã����򷵻�-1  
    if (j == pLen)  
        return i - j;  
    else  
        return -1;  
}  

int main(int argc, char *argv[]) {
	char* s= "dabchie";
	char* p = "abc";
	int result = ViolentMatch(s,p); 
	printf("KMP��������㷨%d",result);
	return 0;
}
