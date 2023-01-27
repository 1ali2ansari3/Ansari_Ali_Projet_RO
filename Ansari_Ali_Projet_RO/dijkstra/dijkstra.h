#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
using namespace std;
#include<vector>
#define MAX 50

class graphe
{

    int G[MAX][MAX];
    int I[MAX],A[MAX];
    bool DejaMarquer[MAX];

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


    void dijkstra(int S)
    {
        int t=0,min1;
        vector <int> tab;
        I[S]=-1;
        tab.push_back(S);
        DejaMarquer[S] = true;
        while(t==0)
        {
            t=1;
            for(int i=0; i<tab.size(); i++)
            {
                for(int j=1; j<MAX; j++)
                {
                    if(!DejaMarquer[j] && G[tab[i]][j]!=0 && A[tab[i]]+G[tab[i]][j]<A[j])
                    {
                        A[j]=A[tab[i]]+G[tab[i]][j];
                        I[j]=tab[i];
                        t=0;
                    }
                    if(!DejaMarquer[j] && G[tab[i]][j]!=0 && A[j]==0)
                    {
                        A[j]=A[tab[i]]+G[tab[i]][j];
                        t=0;
                        I[j]=tab[i];
                    }
                }
            }

            if(t==0)
            {
                for(int j=1; j<MAX; j++)
                {
                    if(A[j]!=0 && !DejaMarquer[j])
                    {
                        min1=A[j]+1;
                    }
                }
                for(int j=1; j<MAX; j++)
                {
                    if(A[j]!=0 && A[j]<min1 && !DejaMarquer[j] )
                    {
                        min1=A[j];
                        S=j;
                    }
                }
                tab.push_back(S);
                DejaMarquer[S] = true;
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
