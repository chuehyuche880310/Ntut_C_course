#include <stdio.h>
#include <stdlib.h>
int c1=0;
/*
int sum1(int n){int s=0,i;for (i=1;i<=n;i++) s+=i; return s;}//沒有遞回 
int sum2(int n){if (n==1) return 1;else return n+sum2(n-1);}//有遞回 
int fact1(int n){unsigned int s=1,i;for (i=1;i<=n;i++) s*=i; return s;}//沒有遞回 
int fact2(int n){if (n==1) return 1;else return n*fact2(n-1);}//有遞回
//unsigned long long int 沒有符號(只有正)的8bit整數 
int fibon1(int n){
  int i,s1=1,s2=1,s; 
  if(n==1||n==2)return 1;
  else { for(i=3;i<=n;i++){s=s1+s2; s1=s2; s2=s;}return s;}
        
}
int fibon2(int n){if (n==1||n==2)return 1;else return fibon2(n-1)+fibon2(n-2);}

int sum3(int m,int n){return m+n;}
int sum4(int m,int n){if (n==1)return m+1;else return 1+sum4(m,n-1);}
int mul1(int m,int n){ return m*n;}
int mul2(int m,int n){ if (n==1)return m;else return m+mul2(m,n-1);}

void hanoi(int n,char s1,char t1,char d1){
  //n  幾個碟子
  //s1 左邊柱子
  //t1 中間柱子
  //d1 右邊柱子 
  c1++;
  if(n==1)printf("搬動第1個碟子從%c搬到%c\n",s1,d1);
  else {
    hanoi(n-1,s1,d1,t1);printf("搬動第%d個碟子從%c搬到%c\n",n,s1,d1); hanoi(n-1,t1,s1,d1); 
  }  
}
*/ 

//HW1
int power1(int m,int n){//迴圈 
  int s=1;int i;
  for(i=1;i<=n;i++)s*=m;
  return s;
}
int power2(int m,int n){//遞回 
  if (n==1)return m;else return m*power2(m,n-1);
}

//HW2
int gcd1(int m,int n){
  int s;int i;
  for(i=1;i<=m;i++) if(m%i==0 && n%i==0) s=i;
  return s;
}
int gcd2(int m,int n){
  if (n==0)return m;else return gcd2(n,m%n);
}

int main(int argc, char *argv[])
{
  int a1,a2,a3,n,n1,n2,m,s;
  char  s1='S',t1='T',d1='D';
/* 
  do{
    printf("請輸入1個數-->"); scanf("%d",&n); if (n==-1) break;
    printf("1+2+...+%d=%d %d\n",n,sum1(n),sum2(n));
    printf("1*2*...*%d=%d %d\n",n,fact1(n),fact2(n));
    printf("印出費氏數列第%d項-->\n",n);
    for(s=1;s<=n;s++)printf("%3d ",fibon1(s)); printf("\n");
    for(s=1;s<=n;s++)printf("%3d ",fibon2(s)); printf("\n");  
  }while(1);
  
  do{
    printf("請輸入2個數-->");scanf("%d %d",&m,&n); if(n==-1||m==-1)break; 
    printf("(%3d+%3d)=%3d %3d\n",m,n,sum3(m,n),sum4(m,n));//兩數相加之和
    printf("(%3d*%3d)=%3d %3d\n",m,n,mul1(m,n),mul2(m,n));//兩數相乘之和
  }while(1); 
 
  do{
    printf("請輸入1個N-->");scanf("%d",&n);if(n==-1)break;
    hanoi(n,s1,t1,d1);
    printf("共搬了%d次\n",c1);c1=0;
  }while(1); 
*/
  //HW1
  do{
    printf("請輸入M的N次方-->");scanf("%d %d",&m,&n);if(m==-1||n==-1)break;       
    printf("%d的%d次方為%d %d\n",m,n,power1(m,n),power2(m,n));         
  }while(1);
    
  //HW2
  do{
  	printf("請輸入2數-->");scanf("%d %d",&m,&n);if(m==-1||n==-1)break; 
  	printf("<%d,%d> = %d %d\n",m,n,gcd1(m,n),gcd2(m,n));
  }while(1);
  
  system("PAUSE");	
  return 0;
}
