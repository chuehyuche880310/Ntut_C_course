#include <stdio.h>
#include <stdlib.h>

void sort(int a[],int n){//氣泡排序法 ------------
  int i,max,k,m,s,p=0;
  printf("排序前-->"); for(s=0;s<n;s++)printf("%2d ",a[s]); printf("\n");
  for (i=0;i<n-1;i++){
    for(k=0,max=0;k<n-1-i;k++){
      if (a[k] > a[k+1]) {m=a[k];a[k]=a[k+1];a[k+1]=m; max=1;}//m為暫存 
      p++;
    }
    for(s=0;s<n;s++)printf("%2d ",a[s]); printf("\n");
    if (max==0)break;
  } 
  printf("排序後-->"); for(s=0;s<n;s++)printf("%2d ",a[s]); printf("\n");  
  printf("共比較%d次\n",p);
} 

void sch(int a[],int n,int n1){//循序搜尋法 -----------------------
  int i,s,p=0;
  for (i=0,s=0;i<n;i++){
    p++;
    if(n1==a[i]) {s=1;break;}; 
  }
  if(s==1)  printf("以循序搜尋法找到%d在第%d位置\n搜尋了%d次\n",n1,i,p); else printf("%d找不到\n",n1); 
}

void sch1(int a[],int n,int n1){//二分搜尋法 ----------------------
  int left=0,s=0,right=n-1,mid,p=0;
  while(left<=right){
    p++;
    mid=(left+right)/2;
    if(a[mid]==n1){s=1;break;}
    else if (a[mid]< n1) left=mid+1;
    else right=mid-1;
  }
  if(s==1) printf("以二分搜尋法找到%d在第%d位置\n搜尋了%d次\n",n1,mid,p); else printf("%d找不到\n",n1);
}

int main(int argc, char *argv[])/////////////上課做 
{
  int i,t,kk,s,n,n1,m,max;  
  /*
  //龜兔賽跑
  int tut[70]={0},rab[70]={0},pos_t,pos_r;srand(time(NULL));
  do{
    printf("龜兔賽跑開始，輸入-1停止-->"); scanf("%d",&t); if(t == -1)break;
    pos_t=pos_r=0;
    while(pos_t<69 && pos_r<69){
      t=rand()%10+1; //烏龜 
      if (t <= 5) pos_t+=3;if(t == 6 || t == 7) pos_t-=6; 
      if (t >= 8) pos_t++;
      if (pos_t<0) pos_t=0; if(pos_t >=69)pos_t=69;
      tut[pos_t]=1; t=rand()%10+1; //兔子 
      if (t == 3 && t == 4) pos_r+=9; 
      if(t == 5) pos_r-=12;
      if (t >= 6 && t <= 8) pos_r++; 
      if(t >= 9) pos_r-=2;
      if (pos_r < 0) pos_r=0; if (pos_t < 0) pos_t=0;
      tut[pos_t]=1; rab[pos_r]=1;
      for(i=0;i<70;i++)printf("=");printf("\n");
      for(i=0;i<70;i++)if(tut[i]==1) printf("T"); else printf(" "); printf("\n");
      for(i=0;i<70;i++)if(rab[i]==1)printf("R"); else printf(" "); printf("\n");
      for(i=0;i<70;i++)printf("=");printf("\n");
      for(i=0;i<70;i++)tut[i]=rab[i]=0;
      for(kk=1; kk<214748364;kk++);//假回圈 
      system("CLS");//清螢幕 
    }
    if (pos_t > 69)printf("烏龜贏(%d,%d)\n",pos_t,pos_r);
    if (pos_r > 69)printf("兔子贏(%d,%d)\n",pos_r,pos_t);
  }while(1);
   
  
  int a[]={2,6,4,12,89,10,68,37,8,45},b[10]={23,4,65,7,12,2};
  int left,right,mid;
  do{
    //循序搜尋  
    printf("欲搜尋的數值-->"); for(s=0;s<10;s++)printf("%2d ",a[s]); printf("\n");
    printf("請輸入要找的數值-->"); scanf("%d",&n); if(n==-1)break;
    for (i=0,s=0;i<10;i++) if(n==a[i]) {s=1;break;};
    if(s==1) printf("找到%d在第%d位置\n",n,i); else printf("%d找不到\n",n); 
    for(i=0;i<10;i++)b[i]=a[i];sort(a,10);
    printf("欲搜尋的數值-->"); for(s=0;s<10;s++) printf("%2d ",a[s]); printf("\n");
    //二分搜尋 
    left=0;right=9;s=0;
    while(left<=right){
      mid=(left+right)/2;
      if(a[mid]==n){s=1;break;}
      else if (a[mid]< n) left=mid+1;
      else right=mid-1;
    }
    if(s==1) printf("找到%d在第%d位置\n",n,mid); else printf("%d找不到\n",n);
    for(i=0;i<10;i++)a[i]=b[i];    
  }while(1);
  
  //氣泡排序法 
  sort(a,10);sort(b,6);
  
  //投骰子 
  int fr[7]={0},maxi;
  srand(time(NULL)); int die[200];
  do{
	printf("請輸入要丟骰子的次數："); scanf("%d",&n); if(n == -1) break;
	for(i=1; i<=6; i++) fr[i]=0;
	for(i=0,s=0; i<n; i++){
		m=rand()%6+1; ++fr[m]; s+=m; die[i]=m;
	}
	for(i=1; i<=6; i++) printf("%d出現%d次\n",i,fr[i]); sort(die,n);
	for(i=1; i<=6; i++) {
		printf("%1d | ",i);
		if(i == 1) { max=fr[1]; maxi=1; }
		else if(max < fr[i]) { max=fr[i]; maxi=i; }
		for(m=1; m<=fr[i]; m++) printf("*"); printf("\n");
	}
	printf("sum=%d avg=%f 出現次數最多的骰子點數為%d 出現次數為%d，中位數為%d\n",
                                           s,s*1.0/n,maxi,max,die[n/2]);
  }while(1);
  */
  ///////////////////////////////////////
  
  //HW1 
  srand(time(NULL));
  do{
  	printf("請輸入一數值-->"); scanf("%d",&n); if(n==-1) break;
  	int c[n];
  	for(i=0;i<n;i++){
  	  c[i]=0;
	}
  	for(i=0;i<n;i++) {
	  t=rand()%60+1;//1~60 c[i]=t;
	  c[i]=t;  	
    }
    sort(c,n);
    //HW2
    do{
      printf("欲搜尋的數值-->"); for(s=0;s<n;s++)printf("%2d ",c[s]); printf("\n");
	  printf("請輸入要找的數值-->"); scanf("%d",&n1); if(n1==-1)break;
	  sch(c,n,n1);sch1(c,n,n1);
	}while(1);
  }while(1); 
  
  
  system("PAUSE");	
  return 0;
}
