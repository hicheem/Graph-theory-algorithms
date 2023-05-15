#include<stdio.h>
#include<stdlib.h>
main()
{
    int i,j,n,p,s,**M,*T,*TP;
    printf("Combien de sommets existe dans votre graphe ?\n");
    scanf("%d",&n);
    M=malloc(n*sizeof(int*));
    T=malloc(n*sizeof(int));
    TP=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        M[i]=malloc(n*sizeof(int));
    }
    printf("________remplissage Matrice booleen________\n");
    printf("Donner le cout de l'arc ou 0 sinon\n");
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("l'arc  x%d --> x%d ",i,j);
                scanf("%d",&M[i][j]);

            }
        }
    for(i=0;i<n;i++)
    {
        if(i==0)
            T[i]=0;
        else
            T[i]=-1;
    }
    printf("______Algorithe de FORD________\n");
    p=0;
    s=0;
    while(s<n)
    {

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                TP[j]=T[j];

            for(j=0;j<n;j++)
            {
                if(M[i][j]!=0  )
                {
                    if(T[j]!=-1)
                    {
                        if(T[j]-T[i]>M[i][j])
                            T[j]=T[i]+M[i][j];
                    }
                    else T[j]=T[i]+M[i][j];
                }
            }
            for(j=0;j<n;j++)
            {
                if(TP[j]==T[j])
                p=p+1;
            }
            if(p==n)
                s=s+1;
            p=0;

        }

    }
    printf("Les plus courts chemins du sommet x0 sont :\n");
    for(i=0;i<n;i++)
    {
        printf("T[x%d]=%d\n",i,T[i]);
    }
}
