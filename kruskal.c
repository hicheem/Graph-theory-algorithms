#include<stdio.h>
#include<stdlib.h>

void choixmin(int n,int **M,int **ind,int **EC,int *indice1,int *indice2 ,int max )
{
	int i,j,min;
        min=max;

		for(i=0;i<n;i++)
			{
                for(j=0;j<i;j++)
				{
					if( (M[i][j]<min ) && (ind[i][j]==0) && (M[i][j]!=0) )
					{
						min=M[i][j];
						*indice1=i;
						*indice2=j;
					}
				}
			}
			ind[*indice1][*indice2]=min;
			ind[*indice2][*indice1]=min;
			EC[*indice1][*indice2]=min;
			EC[*indice2][*indice1]=min;
}
int verCycle(int l,int n,int **ind,int **EC,int *indice1,int *indice2 )
{
    int i,d=0,v=0,s=0,k,*T;
    T=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        if(l==1)
        {
            if(EC[*indice2][i]!=0 && i!=*indice1)
            {
                T[i]=1;
                EC[*indice2][i]=0;
                s=s+1;
            }
        }
        else{
            if(EC[*indice2][i]!=0 )
            {
                T[i]=1;
                EC[*indice2][i]=0;
                s=s+1;
            }
        }
    }
    if(s!=0)
    {

        for(i=0;i<n;i++)
        {
            if(T[i]==1 && i!=*indice2)
            {
                if(i==*indice1)
                    {
                        i=n+1;
                        return 1;
                    }
                else {
                        v=v+1;
                        d=0;
                    }
            }
        }
        if(v!=0)
        {
            for(i=0;i<n;i++)
            {
                if(T[i]==1)
                {
                    l=l+1;
                    verCycle(l,n,ind,EC,indice1,&i);
                }
                else return 0;
            }
        }
    }
    return d;
}



main()
{
    int i,j,l=1,n,k,s,p,c,max,**M,**EC,**ind,indice1,indice2;
    printf("Combien de sommets ?\t");
    scanf("%d",&n);
    M=malloc(n*sizeof(int*));
    ind=malloc(n*sizeof(int*));
    EC=malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        {
            M[i]=malloc(n*sizeof(int));
            EC[i]=malloc(n*sizeof(int));
            ind[i]=malloc(n*sizeof(int));
        }
    printf("Remplissage du matrice booleene \n doneer le cout de l'arete s'il existe \n 0 sinon\n");
    for(i=0;i<n;i++)
    {   for(j=0;j<i;j++)
            {

                printf("arete entre x%d <--> x%d\t",i+1,j+1);
                scanf("%d",&M[i][j]);
            }
    }

    printf("________Kruskal_________\n");

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
                ind[i][j]=0;
                EC[i][j]=0;
            }

    max=0;
    for(i=0;i<n;i++)
        for(j=0;j<i;j++)
            {
                if(max<M[i][j])
                max=M[i][j];
            }

    k=2;
    choixmin(n,M,ind,EC,&indice1,&indice2,max);
    choixmin(n,M,ind,EC,&indice1,&indice2,max);

    while(k<n)
    {
        choixmin(n,M,ind,EC,&indice1,&indice2,max);
        k=k+1;
        c=verCycle(l,n,ind,EC,&indice1,&indice2);
        if(c==1)
        {
            ind[indice1][indice2]=M[indice1][indice2];
        }
        else {
                k=k-1;
                ind[indice1][indice2]=0;
                ind[indice2][indice1]=0;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
            EC[i][j]=ind[i][j];
            }
        }
    }
    k=0;
    for(i=0;i<n;i++)
    {
        printf("\n\n");
        for(j=0;j<i;j++)
        {
            if(ind[i][j]!=0)
            {
                printf("%d arc choisser est x%d <-> x%d son cout: %d \n",k,i+1,j+1,ind[i][j]);
                k=k+1;
            }
        }
    }

}


