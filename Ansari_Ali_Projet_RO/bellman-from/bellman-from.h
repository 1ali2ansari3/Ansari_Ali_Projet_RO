#ifndef BELLMANFROM_H
#define BELLMANFROM_H

#include <iostream>
using namespace std;
#include<vector>
#define MAX 50

class graphe
{

    int G[MAX][MAX];
    int I[MAX],A[MAX];


public:
    void inistialisation()
    {
        for(int i=1; i<MAX; i++)
        {
            I[i]=0;
            A[i]=0;
            for(int j=1; j<MAX; j++)
            {
                G[i][j]=0;
            }
        }
    }

    void ajouteArc(int S1,int S2,int S3)
    {

        G[S1][S2]=S3;

    }


    void bellman_from(int S)
    {
        int t=0,v;
        I[S]=-1;
        while(t==0)
        {
            t=1;
            v=0;
            while(v<MAX)
            {

                for(int j=1; j<MAX; j++)
                {
                    if( G[S][j]!=0 && A[S]+G[S][j]<A[j] && I[j]!=-1)
                    {
                        A[j]=A[S]+G[S][j];
                        I[j]=S;
                        t=0;
                    }
                    if(G[S][j]!=0 && A[j]==0 && I[j]!=-1)
                    {
                        A[j]=A[S]+G[S][j];
                        t=0;
                        I[j]=S;
                    }
                }
                int u=0;
                while(u==0)
                {
                    v++;
                    if(S<MAX)
                    {
                        S=S+1;
                    }
                    else
                    {
                        S=1;
                    }
                    for(int j=1; j<MAX; j++)
                    {
                        if(G[S][j]!=0)
                        {
                            u=1;
                        }
                    }
                }
            }
        }
    }




    void affiche()
    {
        for(int i=1; i<MAX; i++)
        {
            if(I[i]!=0)
            {
                cout <<"somme "<< i <<" cout "<<A[i]<<" de "<< I[i]<<endl;
            }
        }
    }

};


#endif

