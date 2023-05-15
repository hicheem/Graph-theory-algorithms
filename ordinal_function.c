#include<stdio.h>
#include<stdlib.h>
main()
{
    int **M,**A,n,i,j,k,s,p,t;
    printf("Combien de sommets existe dans votre graphe ? \n");
    scanf("%d",&n);
    printf("___________Remplissage du matrice booleen___________\n");
    printf("1 existe l'arc xi-->xj \n0 n'existe pas l'arc xi-->xj \n");
    M=malloc(n*sizeof(int*));
    A=malloc(n*sizeof(int*));
    if(M==NULL || A==NULL)
    {
        printf("Allocation echoue\n");
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
            M[i]=malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("existe l'arc ? x%d-->x%d ",i+1,j+1);
                scanf("%d",&M[i][j]);
            }
        }
        p=0;
        t=0;
        while(t<n)
        {
            A[p]=malloc(n*sizeof(int));
            if(A[p]==NULL)
            {
                printf("Allocation echouee\n");
                return 0;
            }
            else
            {
                printf("Niveau %d = { ",p);
                for(i=0;i<n;i++)
                {
                    s=0;
                    for(j=0;j<n;j++)
                        {
                            if(M[j][i]!=-1)
                                {
                                    s=s+M[j][i];
                                }
                                else
                                    A[p][j]=-1;
                        }
                    A[p][i]=s;
                }
                for(i=0;i<n;i++)
                {
                    if(A[p][i]==0)
                    {
                        printf("x%d ",i+1);
                        k=i;
                        for(j=0;j<n;j++)
                            M[k][j]=-1;
                        t=t+1;
                    }
                }
                printf("}\n");
                p=p+1;
                if(t==0)
                {
                    printf("n'existe pas des niveaux dans votre graphe! :( :(!");
                    t=n+1;
                }
            }
        }
    }
}
