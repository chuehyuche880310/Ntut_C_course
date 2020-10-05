#include <stdio.h>
#include <stdlib.h> 
int ca[4][13]={0};char col[4]={'S','H','D','C'},
    ot[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int card5[5][2];

void shuffle(){
     int i,j,k;
     for (i=1;i<=52;i++){
         do {j=rand()%4;k=rand()%13;}while(ca[j][k]!=0); ca[j][k]=i;
     }
}

void print5(int k[5][2]){
     int i,j;for (i=0;i<5;i++) printf("%c-%c ",col[k[i][0]],ot[k[i][1]]);printf("\n");
}

void print()
{
     int j,k,i,m;
     for(j=0;j<4;j++){
          for (k=0;k<13;k++)printf("%2d ",ca[j][k]);printf("\n");
     }
     for (i=1,m=0;i<=52;i++)
         for(j=0;j<4;j++)
              for (k=0;k<13;k++)
                  if (ca[j][k]==i){
                       printf("%c-%c ",col[j],ot[k]);m++;if(m%13==0) printf("\n");
                  }//all cards
     for(i=1;i<=5;i++)
         for (j=0;j<4;j++)
             for (k=0;k<13;k++)
                 if (ca[j][k]==i){card5[i-1][0]=j;card5[i-1][1]=k;}
     print5(card5);
}

void pair(){//7.12 a
     int i,po[13]={0}; for (i=0;i<5;i++) po[card5[i][1]]++;
     for (i=1;i<13;i++) if (po[i]==2) printf("有%d對子\n",i+1);
}

void pair2(){
     int i,c,po[13]={0}; for (i=0;i<5;i++) po[card5[i][1]]++;
     for (i=1,c=0;i<13;i++) if (po[i]==2) {printf("有%d對子\n",i+1);c++;}
     if (c==2) printf("有雙對子\n",i+1);
}

void pair3(){
     int i,po[13]={0}; for (i=0;i<5;i++) po[card5[i][1]]++;
     for (i=1;i<13;i++) if (po[i]==3) printf("有%c三條\n",ot[i]);
}

void pair4(){
     int i,po[13]={0}; for (i=0;i<5;i++) po[card5[i][1]]++;
     for (i=1;i<13;i++) if (po[i]==4) printf("有%c鐵支\n",ot[i]);
}

void sameflower(){
     int i,c,po[4]={0};for (i=0;i<5;i++) po[card5[i][0]]++;
     for (i=0,c=0;i<13;i++) if (po[i]==5) printf("有%c同花\n",col[i]);
}

void fullh(){
     int i,j,k,m;
     for (i=0;i<5;i++)
         for (j=0;j<5-i-1;j++) 
             if (card5[j][1]>card5[j+1][1]){ 
                  k=card5[j][1];
                  card5[j][1]=card5[j+1][1];
                  card5[j+1][1]=k;
             } print5(card5);
     for (i=0,m=0;i<=3;i--) if ((card5[i][i]+1)!= card5[i+1][1]) {m=1;break;}
     if (m==0) printf("有順子\n");
     else if (card5[0][1]==0 && card5[1][1]==9 && card5[2][1]==10 &&   
        card5[3][1]==11 && card5[4][1]==12) printf("有順子\n");
}

int main(int argc, char *argv[])
{
  int i,j,r,c,k,m,n;
  do
  {
      printf("請輸入-1停止:");scanf("%d",&n); if (n==-1) break;srand(time(NULL));
      shuffle();print();pair();//{S-9 D-9 C-7 C-3 S-7} 7.12 a,b
      card5[0][0]=card5[4][0]=0;card5[2][0]=card5[3][0]=3;card5[1][0]=2;
      card5[0][1]=card5[1][1]=8;card5[2][1]=card5[4][1]=6;card5[3][1]=2;
      print5(card5);pair2();
      card5[0][0]=0;card5[4][0]=1;card5[2][0]=3;card5[3][0]=card5[1][0]=2;
      card5[0][1]=card5[1][1]=card5[2][1]=4;card5[4][1]=6;card5[3][1]=2;
      print5(card5);pair3();
      card5[0][0]=0;card5[1][0]=1;card5[2][0]=3;card5[3][0]=card5[4][0]=2;
      card5[0][1]=card5[1][1]=card5[2][1]=card5[4][1]=6;card5[3][1]=2;
      print5(card5);pair4();
      card5[0][0]=card5[4][0]=card5[2][0]=card5[3][0]=card5[1][0]=2;//D 7.12e
      card5[0][1]=7;card5[1][1]=8;card5[2][1]=4;card5[4][1]=6;card5[3][1]=2;
      print5(card5);sameflower();
      card5[0][0]=card5[4][0]=0;card5[2][0]=card5[3][0]=3;card5[1][0]=2;
      card5[0][1]=12;card5[1][1]=0;card5[2][1]=11;card5[4][1]=9;card5[3][1]=10;
      fullh();
      for (j=0;j<4;j++) for (k=0;k<13;k++) ca[j][k]=0;
  }while(1);
  system("PAUSE");	
  return 0;
}
