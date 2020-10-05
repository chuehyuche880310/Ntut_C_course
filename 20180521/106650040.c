#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int p[7]={0}, n, d, sum, max, point, m1, m2, p1, p2, i, j;
	float avg;
	do{
		printf("块メ浑Ω计(程ぶ50Ω)块-1挡"); scanf("%d",&n); if(n == -1) break;
		if(n<50) printf("程ぶメ50Ω\n");
		else{
			p[1]=p[2]=p[3]=p[4]=p[5]=p[6]=point=max=p1=p2=m1=m2=0; //耴箂 
			for(j=1; j<=n; j++){
				d=rand()%6+1; //睹计 
				//だ摸参璸 
				switch(d){ 
					case 1: p[1]++; break;
					case 2: p[2]++; break;
					case 3: p[3]++; break;
					case 4: p[4]++; break;
					case 5: p[5]++; break;
					case 6: p[6]++; break;
				}
			}
			sum = p[1]*1+p[2]*2+p[3]*3+p[4]*4+p[5]*5+p[6]*6; //羆㎝ 
			avg = (float)sum/(float)n; //キА 
			//ゑぇ猭 
			if((p[1]>=p[2] && p[2]>=p[3]) || (p[1]>=p[3] && p[3]>=p[2])){m1=p[1]; p1=1;} 
			if((p[2]>=p[1] && p[1]>=p[3]) || (p[2]>=p[3] && p[3]>=p[1])){m1=p[2]; p1=2;} 
			if((p[3]>=p[2] && p[2]>=p[1]) || (p[3]>=p[1] && p[1]>=p[2])){m1=p[3]; p1=3;} 
			if((p[4]>=p[5] && p[5]>=p[6]) || (p[4]>=p[6] && p[6]>=p[5])){m2=p[4]; p2=4;} 
			if((p[5]>=p[4] && p[4]>=p[6]) || (p[5]>=p[6] && p[6]>=p[4])){m2=p[5]; p2=5;}
			if((p[6]>=p[5] && p[5]>=p[4]) || (p[6]>=p[4] && p[4]>=p[5])){m2=p[6]; p2=6;}
			if(m1>m2){max=m1; point=p1;} 
			if(m2>m1){max=m2; point=p2;} 
			//陪ボ挡狦 
			printf("翴计\t瞷Ω计\t参璸瓜\n");
			printf(" %1d\t",1); printf("%1d\t\t",p[1]); for(i=0; i<p[1]; i++) printf("*"); printf("\n");
			printf(" %1d\t",2); printf("%1d\t\t",p[2]); for(i=0; i<p[2]; i++) printf("*"); printf("\n");
			printf(" %1d\t",3); printf("%1d\t\t",p[3]); for(i=0; i<p[3]; i++) printf("*"); printf("\n");
			printf(" %1d\t",4); printf("%1d\t\t",p[4]); for(i=0; i<p[4]; i++) printf("*"); printf("\n");
			printf(" %1d\t",5); printf("%1d\t\t",p[5]); for(i=0; i<p[5]; i++) printf("*"); printf("\n");
			printf(" %1d\t",6); printf("%1d\t\t",p[6]); for(i=0; i<p[6]; i++) printf("*"); printf("\n");
			printf("翴计羆㎝%d 翴计キА%.2f\n",sum,avg);
			printf("瞷程Ω翴计%d瞷%dΩ\n",point,max);
		}
	}while(1);
	system("pause");
	return 0;
}
