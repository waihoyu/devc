#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//����row:��ʾ��ʼ��
//����n: ��ʾ����
//������(*chess)[8]:��ʾ ָ������ÿһ�е�ָ�롣 
int count = 0;
notDanger(int row,int j,int  (*chess)[8]){
	int i,k,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
	//�жϷ��� 
	for(i=0;i<8;i++){
		if(*(*(chess+i)+j) != 0){
          flag1 =1;
          break;
		}
	}
	//�ж����Ϸ� 
	for(i=row,k=j;i>=0 && k>=0;i--,k--){
		if(*(*(chess+i)+k) != 0){
          flag2 =1;
          break;
		}
	}

	for(i=row,k=j;i<8&&k<8;i++,k++){
		if(*(*(chess+i)+k) != 0){
          flag3 =1;
          break;
		}
	}
    //���Ϸ� 
	for(i=row,k=j;i>=0 && k<8;i--,k++){
		if(*(*(chess+i)+k) != 0){
          flag4 =1;
          break;
		}
	}
	//�ж����·� 
	for(i=row,k=j;i<8 && k>=0;i++,k--){
		if(*(*(chess+i)+k) != 0){
          flag5=1;
          break;
		}
	}
	
	if(flag1||flag2||flag3||flag4||flag5){
		return 0;
	}		
		return 1;
}

EightQueens(int row,int n,int (*chess)[8]){
	int chess2[8][8],i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			chess2[i][j]=chess[i][j];
		}
	}
	if(8 == row){
		printf("\n��%d��\n\n",count+1);
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				printf("%d",*(*(chess2+i)+j));
			}
			printf("\n");
		} 
			printf("\n\n");
			count++;
	}else{
		//�ж����λ���Ƿ���Σ�ա����û��Σ�գ��������¡�
		for(j=0;j<n;j++){ //�ж��Ƿ�Σ�� 
			if(notDanger(row,j,chess)){
				for(i=0;i<8;i++){
				  *(*(chess2+row)+i) = 0;
				}
				*(*(chess2+row)+j) = 1;
				EightQueens(row+1,n,chess2);
			} 
		} 
	}
}
int main(int argc, char *argv[]) {
	int chess[8][8],i,j;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			chess[i][j]=0;
		}
	}
	EightQueens(0,8,chess);
	printf("\n\n�ܹ���%d�ֽ��������\n\n",count);
	return 0;
}
