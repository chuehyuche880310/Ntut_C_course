#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,j,k;
	int n,n1;
	do{
	printf("請輸入一數N----->");
	scanf("%d",&n);
    if(n==-1)
    break;
		

		for(i=1;i<=n;i++)
		{
			for(k=n;k>=i;k--)
			{
			  printf(" ");
			}
			
			for(j=1;j<=i*2-1;j++)
			{
				printf("*");
				
			}
			 printf("\n");
			
		}
 			for(i=2;i<=n;i++) //i=2
		{
			
			    for(k=1;k<=i;k++) 
	           {
	           	printf(" ");
			   }
			
	           for(j=n;j>=i*2-n;j--)
	           {
	           	printf("*");
			   }
	           
	          
	        
	        printf("\n");
	
		}
	
	}while(1) ;
	
	/////////////////////////////////////////////////////////////////////////////
	
	int a3;
	int s=0;
	
	do{	
	printf("\n");
	printf("請輸入一數N以列出到此數之所有質數-->");
	scanf("%d",&n1)	;
	if(n1==-1)
    break;
	s=0;
	for(i=2;i<=n1;i++)
	{
		a3=0;
		
		for(j=2;j<=i;j++)
		 {
		
		if(i%j==0)
		{
			a3++;
		}
		
		
     	 }
	if(a3==1)
		{
			
			printf(" ");
			printf("%2d",i);
			s++;
		}
		
	if(s%7==0)
		{
		printf("\n");
		}	
		
	}
		
		
		
		
	}while(1);
	
	
	
	////////////////////////////////////
	
	
	system("PAUSE");
	return 0;
}
