#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,t,n,pos_t,pos_r;
	long long int kk;
	srand(time(NULL));
	do{
		printf("龜兔賽跑開始！請輸入場地大小："); scanf("%d",&n); if(n == -1) break;
		int tr[10][n];
		for(j=0; j<n; j++) tr[0][j]=tr[1][j]=0;
		pos_t=pos_r=t=0;
		while(pos_t < n-1 && pos_r < n-1) {
			t=rand()%10+1; 
			if(t <= 5) pos_t += 3; 
			if(t == 6 || t == 7) pos_t -= 6; 
			if(t >= 8) pos_t++;
			if(pos_t < 0) pos_t=0; if(pos_t >= n-1) pos_t=n-1;
			tr[0][pos_t]=1;
			t=rand()%10+1;
			if(t == 3 || t == 4) pos_r += 9; 
			if(t == 5) pos_r -= 12;
			if(t >= 6 && t <= 8) pos_r++; 
			if(t >= 9) pos_r -= 2;
			if(pos_r < 0) pos_r=0; if(pos_r >= n-1) pos_r=n-1;
			tr[1][pos_r]=1;
			system("CLS");
			for(i=0; i<n; i++) printf("="); printf("\n");
			for(i=0; i<n; i++) if(tr[0][i]==1) printf("T"); else printf(" "); printf("\n");
			for(i=0; i<n; i++) if(tr[1][i]==1) printf("R"); else printf(" "); printf("\n");
			for(i=0; i<n; i++) printf("="); printf("\n");
			for(i=0; i<n; i++) tr[0][i]=tr[1][i]=0;
			for(kk=1; kk<214748364; kk++);
		}
		if(pos_t >= n-1) printf("烏龜贏(%d)，兔子輸(%d)\n",pos_t,pos_r);
		if(pos_r >= n-1) printf("兔子贏(%d)，烏龜輸(%d)\n",pos_r,pos_t);
		printf("是否繼續比賽？否就輸入0："); scanf("%d",&n); if(n == 0) break;
	}while(1);
	system("pause");
	return 0;
}
