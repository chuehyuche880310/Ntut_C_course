#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i,j,n;
  
  /*
  //二維陣列排成績 
  int st[4][6]={{1,70,80,50,0,1},{2,90,80,70,0,1},{3,60,80,70,0,1},{4,40,80,60,0,1}};
  printf("學號 國文 英文 數學 平均 名次\n");
  for(i=0;i<29;i++) printf("="); printf("\n");
  for(i=0;i<4;i++){
    st[i][4]=(int)(st[i][1]+st[i][2]+st[i][3])/3.0;
    for(j=0;j<6;j++) 
      printf("%4d ",st[i][j]);
    printf("\n");
  }
  for(i=0;i<29;i++) printf("="); printf("\n");
   
  for(i=0;i<4-1;i++)  //排名次 
    for(j=i+1;j<4;j++)
      if(st[i][4]>st[j][4]) st[j][5]++;
      else if(st[i][4]<st[j][4]) st[i][5]++;
  
  printf("學號 國文 英文 數學 平均 名次\n");
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
  printf("平均 ");
  for(i=0;i<3;i++) printf("%4d ",(int)(avg[i]/4.0+0.5)); printf("\n");//(avg[i]/4.0+0.5)為4捨5入 
  
  //年曆 三個換行 
  int mon1[6][7]={0}, mon2[6][7]={0}, mon3[6][7]={0}, m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  int y,dat,leap,k1,max,k2,k3;
  do{
    printf("請輸入年，輸入-1停止-->");scanf("%d",&n);if(n==-1)break;
    leap=(n-1)/4-(n-1)/100+(n-1)/400;//過了幾個閏年 
	if(n%4 == 0 && n%100 != 0 || n%400 == 0) m[1]++;//判斷是否閏年 
    dat=(n+leap)%7;//那一年的一月一日是星期幾 
    printf("西元%d年一月一日星期%d\n",n,dat);
    for(i=0;i<12;i+=3){//每一列 
      printf("\n\n%3d月",i+1); for(k1=0;k1<16;k1++)printf(" ");printf("\t%3d月",i+2);//印月份與空格 
      for(k1=0;k1<16;k1++)printf(" ");printf("\t%3d月\n",i+3);
      printf("日 一 二 三 四 五 六 \t 日 一 二 三 四 五 六 \t 日 一 二 三 四 五 六 \n");
      k1=0;
      for(j=1;j<=m[i];j++){mon1[k1][dat]=j; dat=(dat+1)%7; if(dat == 0)k1++;}
      k2=0;
      for(j=1;j<=m[i+1];j++){mon2[k2][dat]=j; dat=(dat+1)%7; if(dat == 0)k2++;}
      k3=0;
      for(j=1;j<=m[i+2];j++){mon3[k3][dat]=j; dat=(dat+1)%7; if(dat == 0)k3++;}
      max=(k1 > k2) ? k1 : k2; max=(max > k3) ? max : k3;//最大 
      for(k1=0; k1<=max;k1++){
        for(j=0;j<7;j++)
          if(mon1[k1][j]==0) printf("   ");else printf("%3d",mon1[k1][j]); printf("\t");
        for(j=0;j<7;j++)
          if(mon2[k1][j]==0) printf("   ");else printf("%3d",mon2[k1][j]); printf("\t");
        for(j=0;j<7;j++)
          if(mon3[k1][j]==0) printf("   ");else printf("%3d",mon3[k1][j]); printf("\n");
      } 
      for(k1=0;k1<6;k1++) for(k2=0;k2<7;k2++)mon1[k1][k2]=mon2[k1][k2]=mon3[k1][k2]=0;//清空 
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
  	
  	printf("輸入任意數字重複洗牌，直到-1停止-->");scanf("%d",&n);if(n==-1)break;
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
