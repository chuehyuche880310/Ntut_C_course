#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float s,rate;
    int a1,a2,a3,m,n;
  /*  
    printf("�п�J���� �Q�v �� �~--->");scanf("%d %f %d",&a1,&rate,&n);
    printf("Year   Amount on deposite\n");
    
    for(a2=1;a2<=n;a2++)
    {
     s=a1*pow(1+rate,a2);printf("%4d%21.2f\n",a2,s);                             
    }
    
    
    
    /////////////////////////////////////////////////////////////
    
    
  printf("�п�J�褸�~-->");scanf("%d",&a1);
  a2=(a1-1)/4-(a1-1)/100+(a1-1)/400; int dd = (a1+a2)%7; printf("�褸%d�~1��1��P��",a1);
  
  switch(dd){ 
  case 0: printf("��\n");break;
  case 1: printf("�@\n");break;
  case 2: printf("�G\n");break;
  case 3: printf("�T\n");break;
  case 4: printf("�|\n");break;
  case 5: printf("��\n");break;
  case 6: printf("��\n");break;
  }
  
  printf(" �� �@ �G �T �| �� ��\n");
  for(a2=1;a2<=dd;a2++)printf("   ");
  for(a2=1;a2<=31;a2++)
   {  printf("%3d",a2); dd=(dd+1)%7; if(dd==0) printf("\n"); }
   
   printf("\n");
   
  //////////////////////////////////////////////////////////////////////// 
  
  
  do{
     printf("�п�J�@�ƭ�-->"); scanf("%d",&a1); if(a1 == -1) break;                                                                      
     for(a2=2,a3=0;a2<a1;a2++) if(a1%a2 ==0){a3=1;break;}
     if(a3 == 1) printf("%d���O���\n",a1); else printf("%d�O���\n",a1);                                                                      
   } while(1);                                                                     
                     
  /////////////////////////////////////////////////////////////////////////
  
  
  
  a1=1;a2=1;
  do{
      printf("%5d",a1); if(a2%7==0) {a2=0; printf("\n");} a2++; 
      }while(a1++ <= 100); 
  
  /////////////////////////////////////////////////////////////////////////
  
 
  for(a1=0,m=0;a1<=9;a1++)
    for(a2=0;a2<=9;a2++)
      for(a3=0;a3<=9;a3++)
        for(n=0;n<=9;n++){
         printf("%1d %1d %1d %1d",a1,a2,a3,n);m++; if(m%8==0) printf("\n");
         }
   ////////////////////////////////////////////////////////////////////////                       
   */ 
    printf("�ŦX�����w�z���T��p�U:\n");
    
    for(a1=1,m=0;a1<=100;a1++)
      for(a2=1;a2<=100;a2++)
        for(a3=1; a3<=100;a3++)
        
          if((a1*a1+a2*a2 ==a3*a3) ||(a3*a3+a2*a2 == a1*a1) || (a3*a3+a1*a1 ==a2*a2))
             { printf(" %4d %4d %4d \t",a1,a2,a3); m++; if(m%4 == 0) printf("\n");
              }
    
    
    
  system("PAUSE");	
  return 0;
}
