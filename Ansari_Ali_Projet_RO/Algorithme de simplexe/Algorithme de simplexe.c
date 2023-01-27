#include<stdio.h>


int main()
{
    int n,m,R;
/******************************************************/
    printf("Donne le nombre des Variables de decision :  ");
    scanf("%d",&n);
    printf("Donne le nombre des Contraintes :  ");
    scanf("%d",&m);
    printf("\Pour maximise entre 1 \nPour minimise entre 0 \n");
    scanf("%d",&R);
/******************************************************/
    int i,j;
    float T[m+1][n+1];
    printf("inisialise les Contraintes : \n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("T[%d][%d] = ",i+1,j+1);
            scanf("%f",&T[i][j]);
        }
        printf("b[%d] = ",i);
        scanf("%f",&T[i][n]);
    }
    printf("Donne Fonction objectif : \n ");
    for(j=0; j<n; j++)
    {
        printf("F[%d] = ",j);
        scanf("%f",&T[m][j]);

    }
    T[m][n]=0;
/******************************************************/
int b=1;
for(i=0; i<m; i++)
    {
    if(T[i][n] < 0) b=0;
    }
/******************************************************/
if(b!=0){
    printf("tableau Initiale : \n");
    for(i=1; i<=n; i++)
    {
        printf("X%d\t",i);
    }
    printf("b \n");
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            printf("%.2f\t",T[i][j]);
        }
        printf("\n");
    }
/******************************************************/
    float T2[m+1][n+m+1];
    for(i=0; i<=m; i++)
    {
        for(j=0; j<n; j++)
        {
            T2[i][j]=T[i][j];
        }
        T2[i][n+m]=T[i][n];
    }
    for(i=0; i<=m; i++)
    {
        for(j=n; j<n+m; j++)
        {
            if(i==j-n)
                T2[i][j]=1;
            else
                T2[i][j]=0;
        }
    }
/******************************************************/
    printf("tableau Initiale 2 : \n");
    for(i=1; i<=n+m; i++)
    {
        printf("X%d\t",i);
    }
    printf("b \n");
    for(i=0;i<=m;i++)
    {
        for(j=0; j<=n+m; j++)
        {
            printf("%.2f\t",T2[i][j]);
        }
        printf("\n");
    }
    printf("sommet de depart :  ");
    float X[n+m];
    for(i=0; i<n+m; i++)
    {
        if(i<n)
            X[i]=0;
        else
            X[i]=T2[i-n][n+m];
    }
    printf("(");
    for(i=0; i<n+m; i++)
    {
        printf("  %.2f  ",X[i]);
    }
    printf(")\n");
    /******************************************************************/
    float max,minA;
    int cr,ar=0,t;
    float min;
    float K[m];
    int ei;
    float T3[m+1][n+m+1];
    int trouve;
    int ca[100][2],u=0,v;

    if(R==1){
    do
    {
        v=0;
        max=0;
        for(i=0; i<n+m; i++)
        {
            if(T2[m][i]>max)
            {
                max = T2[m][i];
                cr=i;
            }
        }
        for(i=0; i<m; i++)
        {
            if(T2[i][cr]>0)
            {
                K[i]=T2[i][n+m]/T2[i][cr];
                ei=i;
            }
            else
                K[i]=-1;
        }
        min = K[ei];
        ar=ei;
        for(i=0; i<m; i++)
        {
            if(K[i]<min && K[i]!=-1)
            {
                min=K[i];
                ar=i;
            }
        }
        for(i=0; i<m; i++)
        {
            if(K[i]!=-1)
            {
                t=0;
            }
        }

        printf("variable entrente = %.2f   \nvariable sortonte =   %.2f \n",max,min);
        printf("position de entrente:  %d  \nposition de sortonte:  %d \n",cr,ar);
        ca[u][v]=cr;
        ca[u][v+1]=ar;
        u++;
        trouve=0;
        for(i=0; i<m; i++)
        {
            T3[i][n+m]=T2[i][n+m]-(T2[ar][n+m]*T2[i][cr]/T2[ar][cr]);
        }
        for(i=0; i<n+m; i++)
        {
            T3[m][i]=T2[m][i]-(T2[m][cr]*T2[ar][i]/T2[ar][cr]);
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n+m; j++)
            {
                T3[i][j]=T2[i][j]-(T2[i][cr]*T2[ar][j]/T2[ar][cr]);
            }
        }
        T3[m][n+m] = T2[m][n+m]-(T2[m][cr]*T2[ar][n+m]/T2[ar][cr]);
        for(i=0; i<=n+m; i++)
        {
            T3[ar][i]=T2[ar][i]/T2[ar][cr];
        }
        for(i=0; i<=m; i++)
        {
            for(j=0; j<=n+m; j++)
            {
                printf("%.2f\t",T3[i][j]);
            }
            printf("\n");
        }
        for(i=0; i<n+m; i++)
        {
            if(i<n)
                X[i]=0;
            else
                X[i]=T3[i-n][n+m];
        }
        for(i=0; i<u; i++)
        {
        X[ca[i][0]]=T3[ca[i][1]][n+m];
        X[ca[i][1]+n]=0;
        }
        printf("(");
        for(i=0; i<n+m; i++)
        {
            printf("  %.2f  ",X[i]);
        }
        printf(")\n");
        for(i=0; i<=m; i++)
        {
            for(j=0; j<=n+m; j++)
            {
                T2[i][j]=T3[i][j];
            }
        }
        for(i=0; i<n+m; i++)
        {
            if(T3[m][i]>0)  trouve=1;
        }
        for(i=0; i<m; i++)
        {
            if(T3[i][n+m]<0)
            {
                trouve=0;
                printf("pas de solition \n");
            }
        }
        if(t!=0)
        {
            printf("pas de solition \n ");
        }
    }while(trouve!=0 && t==0);
    }

/******************************************************************/
else if(R==0){
       do
    {
        v=0;
        minA=0;
        for(i=0; i<n+m; i++)
        {
            if(T2[m][i]<minA)
            {
                minA = T2[m][i];
                cr=i;
            }
        }
        for(i=0; i<m; i++)
        {
            if(T2[i][cr]>0)
            {
                K[i]=T2[i][n+m]/T2[i][cr];
                ei=i;
            }
            else
                K[i]=-1;
        }
        min = K[ei];
        ar=ei;
        for(i=0; i<m; i++)
        {
            if(K[i]<min && K[i]!=-1)
            {
                min=K[i];
                ar=i;
            }
        }
        for(i=0; i<m; i++)
        {
            if(K[i]!=-1)
            {
                t=0;
            }
        }

        printf("variable entrente = %.2f   \nvariable sortonte =   %.2f \n",minA,min);
        printf("position de entrente:  %d  \nposition de sortonte:  %d \n",cr,ar);
        ca[u][v]=cr;
        ca[u][v+1]=ar;
        u++;
        trouve=0;
        for(i=0; i<m; i++)
        {
            T3[i][n+m]=T2[i][n+m]-(T2[ar][n+m]*T2[i][cr]/T2[ar][cr]);
        }
        for(i=0; i<n+m; i++)
        {
            T3[m][i]=T2[m][i]-(T2[m][cr]*T2[ar][i]/T2[ar][cr]);
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<n+m; j++)
            {
                T3[i][j]=T2[i][j]-(T2[i][cr]*T2[ar][j]/T2[ar][cr]);
            }
        }
        T3[m][n+m] = T2[m][n+m]-(T2[m][cr]*T2[ar][n+m]/T2[ar][cr]);
        for(i=0; i<=n+m; i++)
        {
            T3[ar][i]=T2[ar][i]/T2[ar][cr];
        }
        for(i=0; i<=m; i++)
        {
            for(j=0; j<=n+m; j++)
            {
                printf("%.2f\t",T3[i][j]);
            }
            printf("\n");
        }
        for(i=0; i<n+m; i++)
        {
            if(i<n)
                X[i]=0;
            else
                X[i]=T3[i-n][n+m];
        }
        for(i=0; i<u; i++)
        {
        X[ca[i][0]]=T3[ca[i][1]][n+m];
        X[ca[i][1]+n]=0;
        }
        printf("(");
        for(i=0; i<n+m; i++)
        {
            printf("  %.2f  ",X[i]);
        }
        printf(")\n");
        for(i=0; i<=m; i++)
        {
            for(j=0; j<=n+m; j++)
            {
                T2[i][j]=T3[i][j];
            }
        }
        for(i=0; i<n+m; i++)
        {
            if(T3[m][i]<0)  trouve=1;
        }
        for(i=0; i<m; i++)
        {
            if(T3[i][n+m]<0)
            {
                trouve=0;
                printf("pas de solition \n");
            }
        }
        if(t!=0)
        {
            printf("pas de solition \n ");
        }
    }while(trouve!=0 && t==0);
}
/******************************************************************/
else{
    printf("errure");
}
}
else
    printf("applique la methode deux phase");

}


