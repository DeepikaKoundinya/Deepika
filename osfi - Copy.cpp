#include<stdio.h>
#include<conio.h>
int main()
{    
    printf("\n Process Scheduling");       
    int i,j,n,k,l,pos,random,random2,random3,min,maxp,maxloc;
    float wrandom;
    printf("\n\nEnter no of Process: ");
    scanf("%d",&n);
    int b[n],p[n],w[n],a[n],c[n];
    float priority[n];
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("For P %d:",i+1);
        scanf("%d",&b[i]);
        p[i]=i+1;          
	} 
	printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("For P %d:",i+1);
        scanf("%d",&a[i]);           
	}
	 /*-printf("\nEnter Priority:\n");
    for(i=0;i<n;i++)
    {
        printf("For P %d:",i+1);
        scanf("%d",&c[i]);
        p[i]=i+1;          
	} */
	w[0]=0;
	if(n>1)
	{
	min=a[0];
	pos=0;
	for(i=1;i<n;i++)
	{
	   if(a[i]<min)
		  {
		  min=a[i];
		  pos=i;
	      }	   
	}
	random=p[pos];
	random2=b[pos];
	random3=a[pos];
    for(i=pos-1;i>=0;i--)
	{
		p[i+1]=p[i];
		b[i+1]=b[i];
		a[i+1]=a[i];
	}
	p[0]=random;
	b[0]=random2;
	a[0]=random3;	
	for(i=1;i<n;i++)
	{   
	   wrandom=(b[i-1]+a[i-1]);
		for(j=i;j<n;j++)
		{   
		   
			if(a[j]<=wrandom)
		     {
			  priority[j]=1+((wrandom-a[j])/b[j]);
		     }
		   else
		     {
			  priority[j]=0;
		     }
		     
	   }	   
	   maxloc=i;
	   maxp=priority[i];
	   for(k=i+1;k<n;k++)
		{
			if(maxp<priority[k])
			{
				maxp=priority[k];
				maxloc=k;
			}
		}
		
		random=p[maxloc];
	   random2=b[maxloc];
	   random3=a[maxloc];
	   for(l=maxloc-1;l>=i;l--)
         	{
		p[l+1]=p[l];
		b[l+1]=b[l];
		a[l+1]=a[l];
	       }
	   p[i]=random;
	   b[i]=random2;
	   a[i]=random3;
	}
	wrandom=a[0];
	for(i=1;i<n;i++)
	{   
	   wrandom +=b[i-1];
		w[i]=wrandom-a[i];
		if(w[i]<0)
		w[i]=0;
	}	
    }
    printf("\n Process\t    Burst Time    \tWaiting Time\t Arrival Time\t\t\n");
    for(i=0;i<n;i++)
    {        
        printf("\n P%d\t\t\t   %d\t\t      %d\t    \t\t%d\t\t",p[i],b[i],w[i],a[i]);
    }
}
