#include<stdio.h>
#include<stdlib.h>

int verifiersuccesseur(int i,int k,int n, int **M,int *T,int f)
{
	int j,c;
	c=0;
	for(j=i+1;j<n;j++)
	{
		if(T[j]==-1) /* -1 == La case est vide  */
		{
            if(M[k][j]==1)
                { T[j]=f;
                c=c+1; } /* si c=0 donc il y'a pas des 1 dans la ligne concerner */
        }
	}
    return c;
 }
 int verifierpredecesseur(int p,int k,int n, int **M,int *T,int f)
{
	int j,c;
	c=0;
	for(j=p+1;j<n;j++)
	{
		if(T[j]==-1)
		{
            if(M[j][k]==1)
                { T[j]=f;
                c=c+1; }
        }
	}
    return c;
 }
void calculsuccesseur(int i,int c,int n,int **M, int *T, int f)
{
	int t,j,k,d;
        t=0;
	    for (j=i+1;j<n ;j++)
        {
            if(T[j]==f)
            {
                k=j;
                d=verifiersuccesseur(i,k,n,M,T,f+1);
            }else
                if(T[j]==-1 ) t=t+1; /*Pour verifier s'il y'a des cases vides */
        }
        if(d!=0 && t!=0)
        {
            calculsuccesseur(i,c,n,M,T,f+1);
        }

}
void calculpredecesseur(int i,int c,int n,int **M, int *T, int f)
{
	int t,j,k,d;
        t=0;
	    for (j=i+1;j<n ;j++)
        {
            if(T[j]==f)
            {
                k=j;
                d=verifierpredecesseur(i,k,n,M,T,f+1);
            }else
                if(T[j]==-1 ) t=t+1; /*Pour verifier s'il y'a des cases vide */
        }
        if(d!=0 && t!=0)
        {
            calculpredecesseur(i,c,n,M,T,f+1);
        }

}
main()
{
	int i,j,k,n,p,v=0,c,a=1,*S,*P,*L,f;
    int **M;
	printf("Combien de sommets ?\n\n");
	scanf("%d",&n);
	M=malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        {
            M[i]=malloc(n*sizeof(int));
        }
    S=malloc(n*sizeof(int));
    P=malloc(n*sizeof(int));
    L=malloc(n*sizeof(int));
	printf("__________Remplissage du matrice booleen__________\n\n");
	for(i=0;i<n;i++)
	{
		for (j=0; j<n; j++)
		{
			printf("existe arc entre? x%d  &  x%d ?\t\t",i+1,j+1);
			scanf("%d",&M[i][j]);
		}
	}
	for(i=0;i<n;i++)
        L[i]=-1;

	printf("__________Les composantes sont: __________\n");
	p=0;
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
            {
                S[j]=-1;
                P[j]=-1;
            }
        S[i]=0;
		f=1;
		k=i;
		verifiersuccesseur(i,k,n,M,S,f);
        calculsuccesseur(i,c,n,M,S,f);
        P[i]=0;
		f=1;
		k=p;
		verifierpredecesseur(p,k,n,M,P,f);
        calculpredecesseur(p,c,n,M,P,f);
        if(L[i]!=i)/*Pour ne pas repeter le sommet plus d'une fois*/
        {
            printf("Composante %d { ",a);
            for(j=0;j<n;j++)
            {
                if(S[j]!=-1 && P[j]!=-1 && L[j]!=j)/* L[j]!=j  Pour ne pas repeter le sommet plus d'une fois */
                {
                    printf("x%d ",j+1);
                    L[j]=j;
                    v=v+1; /* si(v=n) compteur pour verifier si tous les sommets sont marquer donc arreter le boucle */
                }
            }
            printf("}\n");
            a=a+1;
        }
        p=p+1;
        if(v==n)i=n+1;

    }
}
