#include <stdio.h>
#include <stdlib.h>

void sort(int a[],int n){//��w�ƧǪk ------------
  int i,max,k,m,s,p=0;
  printf("�Ƨǫe-->"); for(s=0;s<n;s++)printf("%2d ",a[s]); printf("\n");
  for (i=0;i<n-1;i++){
    for(k=0,max=0;k<n-1-i;k++){
      if (a[k] > a[k+1]) {m=a[k];a[k]=a[k+1];a[k+1]=m; max=1;}//m���Ȧs 
      p++;
    }
    for(s=0;s<n;s++)printf("%2d ",a[s]); printf("\n");
    if (max==0)break;
  } 
  printf("�Ƨǫ�-->"); for(s=0;s<n;s++)printf("%2d ",a[s]); printf("\n");  
  printf("�@���%d��\n",p);
} 

void sch(int a[],int n,int n1){//�`�Ƿj�M�k -----------------------
  int i,s,p=0;
  for (i=0,s=0;i<n;i++){
    p++;
    if(n1==a[i]) {s=1;break;}; 
  }
  if(s==1)  printf("�H�`�Ƿj�M�k���%d�b��%d��m\n�j�M�F%d��\n",n1,i,p); else printf("%d�䤣��\n",n1); 
}

void sch1(int a[],int n,int n1){//�G���j�M�k ----------------------
  int left=0,s=0,right=n-1,mid,p=0;
  while(left<=right){
    p++;
    mid=(left+right)/2;
    if(a[mid]==n1){s=1;break;}
    else if (a[mid]< n1) left=mid+1;
    else right=mid-1;
  }
  if(s==1) printf("�H�G���j�M�k���%d�b��%d��m\n�j�M�F%d��\n",n1,mid,p); else printf("%d�䤣��\n",n1);
}

int main(int argc, char *argv[])/////////////�W�Ұ� 
{
  int i,t,kk,s,n,n1,m,max;  
  /*
  //�t���ɶ]
  int tut[70]={0},rab[70]={0},pos_t,pos_r;srand(time(NULL));
  do{
    printf("�t���ɶ]�}�l�A��J-1����-->"); scanf("%d",&t); if(t == -1)break;
    pos_t=pos_r=0;
    while(pos_t<69 && pos_r<69){
      t=rand()%10+1; //�Q�t 
      if (t <= 5) pos_t+=3;if(t == 6 || t == 7) pos_t-=6; 
      if (t >= 8) pos_t++;
      if (pos_t<0) pos_t=0; if(pos_t >=69)pos_t=69;
      tut[pos_t]=1; t=rand()%10+1; //�ߤl 
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
      for(kk=1; kk<214748364;kk++);//���^�� 
      system("CLS");//�M�ù� 
    }
    if (pos_t > 69)printf("�Q�tĹ(%d,%d)\n",pos_t,pos_r);
    if (pos_r > 69)printf("�ߤlĹ(%d,%d)\n",pos_r,pos_t);
  }while(1);
   
  
  int a[]={2,6,4,12,89,10,68,37,8,45},b[10]={23,4,65,7,12,2};
  int left,right,mid;
  do{
    //�`�Ƿj�M  
    printf("���j�M���ƭ�-->"); for(s=0;s<10;s++)printf("%2d ",a[s]); printf("\n");
    printf("�п�J�n�䪺�ƭ�-->"); scanf("%d",&n); if(n==-1)break;
    for (i=0,s=0;i<10;i++) if(n==a[i]) {s=1;break;};
    if(s==1) printf("���%d�b��%d��m\n",n,i); else printf("%d�䤣��\n",n); 
    for(i=0;i<10;i++)b[i]=a[i];sort(a,10);
    printf("���j�M���ƭ�-->"); for(s=0;s<10;s++) printf("%2d ",a[s]); printf("\n");
    //�G���j�M 
    left=0;right=9;s=0;
    while(left<=right){
      mid=(left+right)/2;
      if(a[mid]==n){s=1;break;}
      else if (a[mid]< n) left=mid+1;
      else right=mid-1;
    }
    if(s==1) printf("���%d�b��%d��m\n",n,mid); else printf("%d�䤣��\n",n);
    for(i=0;i<10;i++)a[i]=b[i];    
  }while(1);
  
  //��w�ƧǪk 
  sort(a,10);sort(b,6);
  
  //���l 
  int fr[7]={0},maxi;
  srand(time(NULL)); int die[200];
  do{
	printf("�п�J�n���l�����ơG"); scanf("%d",&n); if(n == -1) break;
	for(i=1; i<=6; i++) fr[i]=0;
	for(i=0,s=0; i<n; i++){
		m=rand()%6+1; ++fr[m]; s+=m; die[i]=m;
	}
	for(i=1; i<=6; i++) printf("%d�X�{%d��\n",i,fr[i]); sort(die,n);
	for(i=1; i<=6; i++) {
		printf("%1d | ",i);
		if(i == 1) { max=fr[1]; maxi=1; }
		else if(max < fr[i]) { max=fr[i]; maxi=i; }
		for(m=1; m<=fr[i]; m++) printf("*"); printf("\n");
	}
	printf("sum=%d avg=%f �X�{���Ƴ̦h����l�I�Ƭ�%d �X�{���Ƭ�%d�A����Ƭ�%d\n",
                                           s,s*1.0/n,maxi,max,die[n/2]);
  }while(1);
  */
  ///////////////////////////////////////
  
  //HW1 
  srand(time(NULL));
  do{
  	printf("�п�J�@�ƭ�-->"); scanf("%d",&n); if(n==-1) break;
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
      printf("���j�M���ƭ�-->"); for(s=0;s<n;s++)printf("%2d ",c[s]); printf("\n");
	  printf("�п�J�n�䪺�ƭ�-->"); scanf("%d",&n1); if(n1==-1)break;
	  sch(c,n,n1);sch1(c,n,n1);
	}while(1);
  }while(1); 
  
  
  system("PAUSE");	
  return 0;
}
