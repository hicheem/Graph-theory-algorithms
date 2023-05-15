#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct arc
{
	char exi[5]; /*extrimite intiale*/
	char exf[5]; /*extrimite finale*/
	struct arc *suiv;
}arc;
typedef struct liste
{
	arc *debut;
}list;
list *rempDebListe(list *l)
{
	arc *e;
	l=malloc(sizeof(list));
	e=malloc(sizeof(arc));
	if(l==NULL || e==NULL)
		{
		printf("Erreur");
		}
		else
        {
            l->debut=e;
            printf("extrimite intial est : ");
            scanf("%s",&e->exi);
            printf("\nextrimite final est : ");
            scanf("%s",&e->exf);
            e->suiv=NULL;
        }
    return l;
}
void rempSuivListe(list *l)
{
    arc *nv,*p;
    arc *t=l->debut;
    nv=malloc(sizeof(arc));
    if(l==NULL || nv==NULL)
    {
        printf("ERREUR\n");
    }
    else
    {
        while(t!=NULL)
        {
            p=t;
            t=t->suiv;
        }
        printf("\nextrimite intial est : ");
        scanf("%s",&nv->exi);
        printf("\nextrimite final est : ");
        scanf("%s",&nv->exf);
        p->suiv=nv;
        nv->suiv=NULL;
    }
}
int nBsuccesseursSommet(list *l,char ei[5])
{
    arc *t=l->debut;
    int j=0;
    while(t!=NULL)
    {
        if( strcmp(ei,t->exi)==0 )
        {
          j=j+1;
        }
        t=t->suiv;
    }
    return j;
}
void affsuccesseursGraphe(list *l, char ei[5])
{
    arc *t=l->debut;
    printf("\nLes successeurs de sommet %s sont : {",ei);
    while(t!=NULL)
    {
       if( strcmp(ei,t->exi)==0 )
       {
           printf("\t%s",t->exf);
       }
       t=t->suiv;
    }
    printf("\t}\n");
}
int nBpredecesseursSommet(list *l,char ef[5])
{
    arc *t=l->debut;
    int j=0;
    while(t!=NULL)
    {
        if( strcmp(ef,t->exf)==0 )
        {
          j=j+1;
        }
        t=t->suiv;
    }
    return j;
}
void affpredecesseursGraphe(list *l, char ef[5])
{
    arc *t=l->debut;
    printf("\nLes predecesseurs de sommet %s sont : {",ef);
    while(t!=NULL)
    {
       if( strcmp(ef,t->exf)==0 )
       {
           printf("\t%s",t->exi);
       }
       t=t->suiv;
    }
    printf("\t}\n");
}
main()
{
    list *p;
    int x,i,k,l;
    char a[5];
    printf("Combien d'arc existe dans votre graphe ?");
    scanf("%d",&x);
    printf("arc N°1 \n");
    p=rempDebListe(p);
    for(i=2;i<=x;i++)
    {
        printf("arc N°%d",i);
        rempSuivListe(p);
    }
    printf("\n____________Les Donnees de Graphe____________\n");
    do
    {
        printf("1- Les succsseur \n 2- Les predecesseurs \n  3-Quitter \n");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            {
                printf("Donner Le sommet \n");
                scanf("%s",&a);
                l=nBsuccesseursSommet(p,a);
                if(l==0) printf("Le sommet %s n'a pas de successeur\n");
                else {
                    printf("Le sommet %s a %d successeurs\n",a,l);
                    affsuccesseursGraphe(p,a);
                    }
            }break;
            case 2:
            {
                printf("Donner Le sommet \n");
                scanf("%s",&a);
                l=nBpredecesseursSommet(p,a);
                if(l==0) printf("Le sommet %s n'a pas de predecesseur\n");
                else {
                    printf("Le sommet %s a %d predecesseurs\n",a,l);
                    affpredecesseursGraphe(p,a);
                    }
            }break;
        }
    }while(k!=3);
}
