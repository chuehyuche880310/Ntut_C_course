#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//2���}�C 
	int aa[3][4]={{1,2,3},{4,5,6},{7,8,9}}, i, j;
	for(i=0; i<3; i++){
		for(j=0; j<4; j++) printf("%d ",aa[i][j]); printf("\n");
	}
	//2���}�C99���k�� 
	int bb[10][10]={0};
	for(i=0; i<10; i++){ //0~2
		bb[i][0]=i;
		for(j=0; j<10; j++){
			bb[0][j]=j;
			if(j > 0 && i > 0) bb[i][j]=bb[0][j]*bb[i][0];
			if(bb[i][j] != 0) printf("%2d ",bb[i][j]); else printf("  ");
		}printf("\n");
	}
	//�ڴ��d�T���� 
	int s;
	do{
		printf("�п�J��X����ƭȡG"); scanf("%d",&s); if(s == -1) break;
		if(s >= 2){
			bb[0][0]=bb[1][0]=bb[1][1]=1; printf("%3d\n%3d %3d\n",1,1,1);
			for(i=2; i<=s; i++){
				bb[i][0]=bb[i][i]=1;
				for(j=1; j<=i-1; j++){
					bb[i][j]=bb[i-1][j-1]+bb[i-1][j];
				}
				for(j=0; j<=i; j++) printf("%3d ",bb[i][j]); printf("\n");
			}
		}
	}while(1);
	//�]��}
	int cc[21][21]={0}, k, m, n; 
	long long int d;
	do{
		printf("�п�J�]��}�X����G"); scanf("%d",&s); if(s == -1) break;
		i=0; j=s/2;
		for(k=1; k<=s*s; k++){
			cc[i][j]=k;
			if(k%s == 0) i++;
			else {
				i--; j++;
				if(i < 0) i=s-1;
				if(j > s-1) j=0;
			} 
			for(m=0; m<s; m++){
				for(n=0; n<s; n++) printf("%3d ",cc[m][n]); printf("\n");
			} printf("\n");
			for (d=0; d<214748364; d++);
		}
	}while(1);
	
	system("pause");
	return 0;
}
