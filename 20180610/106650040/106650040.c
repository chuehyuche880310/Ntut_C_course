#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i,j,n;
  
  /*
  //�G���}�C�Ʀ��Z 
  int st[4][6]={{1,70,80,50,0,1},{2,90,80,70,0,1},{3,60,80,70,0,1},{4,40,80,60,0,1}};
  printf("�Ǹ� ��� �^�� �ƾ� ���� �W��\n");
  for(i=0;i<29;i++) printf("="); printf("\n");
  for(i=0;i<4;i++){
    st[i][4]=(int)(st[i][1]+st[i][2]+st[i][3])/3.0;
    for(j=0;j<6;j++) 
      printf("%4d ",st[i][j]);
    printf("\n");
  }
  for(i=0;i<29;i++) printf("="); printf("\n");
   
  for(i=0;i<4-1;i++)  //�ƦW�� 
    for(j=i+1;j<4;j++)
      if(st[i][4]>st[j][4]) st[j][5]++;
      else if(st[i][4]<st[j][4]) st[i][5]++;
  
  printf("�Ǹ� ��� �^�� �ƾ� ���� �W��\n");
  for(i=0;i<29;i++) printf("="); printf("\n");
  for(i=0;i<4;i++){
    st[i][4]=(int)(st[i][1]+st[i][2]+st[i][3])/3.0;
    for(j=0;j<6;j++)
      printf("%4d ",st[i][j]);
    printf("\n");
  }
  for(i=0;i<29;i++) printf("="); printf("\n");
  int avg[3]={0};
  for(i=0;i<4;i++)
    for(j=1;j<4;j++) avg[j-1]+=st[i][j];
  printf("���� ");
  for(i=0;i<3;i++) printf("%4d ",(int)(avg[i]/4.0+0.5)); printf("\n");//(avg[i]/4.0+0.5)��4��5�J 
  
  //�~�� �T�Ӵ��� 
  int mon1[6][7]={0}, mon2[6][7]={0}, mon3[6][7]={0}, m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int y,dat,leap,k1,max,k2,k3;
  do{
    printf("�п�J�~�A��J-1����-->");scanf("%d",&n);if(n==-1)break;
    leap=(n-1)/4-(n-1)/100+(n-1)/400;//�L�F�X�Ӷ|�~ 
	if(n%4 == 0 && n%100 != 0 || n%400 == 0) m[1]++;//�P�_�O�_�|�~ 
    dat=(n+leap)%7;//���@�~���@��@��O�P���X 
    printf("�褸%d�~�@��@��P��%d\n",n,dat);
    for(i=0;i<12;i+=3){//�C�@�C 
      printf("\n\n%3d��",i+1); for(k1=0;k1<16;k1++)printf(" ");printf("\t%3d��",i+2);//�L����P�Ů� 
      for(k1=0;k1<16;k1++)printf(" ");printf("\t%3d��\n",i+3);
      printf("�� �@ �G �T �| �� �� \t �� �@ �G �T �| �� �� \t �� �@ �G �T �| �� �� \n");
      k1=0;
      for(j=1;j<=m[i];j++){mon1[k1][dat]=j; dat=(dat+1)%7; if(dat == 0)k1++;}
      k2=0;
      for(j=1;j<=m[i+1];j++){mon2[k2][dat]=j; dat=(dat+1)%7; if(dat == 0)k2++;}
      k3=0;
      for(j=1;j<=m[i+2];j++){mon3[k3][dat]=j; dat=(dat+1)%7; if(dat == 0)k3++;}
      max=(k1 > k2) ? k1 : k2; max=(max > k3) ? max : k3;//�̤j 
      for(k1=0; k1<=max;k1++){
        for(j=0;j<7;j++)
          if(mon1[k1][j]==0) printf("   ");else printf("%3d",mon1[k1][j]); printf("\t");
        for(j=0;j<7;j++)
          if(mon2[k1][j]==0) printf("   ");else printf("%3d",mon2[k1][j]); printf("\t");
        for(j=0;j<7;j++)
          if(mon3[k1][j]==0) printf("   ");else printf("%3d",mon3[k1][j]); printf("\n");
      } 
      for(k1=0;k1<6;k1++) for(k2=0;k2<7;k2++)mon1[k1][k2]=mon2[k1][k2]=mon3[k1][k2]=0;//�M�� 
    }
  }while(1);
  */
  
  //HW1 
  do{
  	int j=0,ro,co;
  	int card[4][13]={0};
  	const char *pattern[4]={"H","D","C","S"};
  	const char *number[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
  	srand(time(NULL));
  	
  	printf("��J���N�Ʀr���Ƭ~�P�A����-1����-->");scanf("%d",&n);if(n==-1)break;
  	for(i=1;i<=52;i++){
  	  do{
  	    ro=rand()%4;
  	    co=rand()%13;
	  }while(card[ro][co] != 0);
	  card[ro][co]=i;
	}
	 
	for(i=1;i<=52;i++)
	  for(ro=0;ro<4;ro++)
	    for(co=0;co<13;co++){
	      if(card[ro][co]==i){
		    printf("%s%2s   ",pattern[ro],number[co]);j++;
		  }
		  if(j==13){printf("\n");j=0;}
	    }
	printf("\n");
  }while(1);
  
  system("PAUSE");
  return 0;
}
