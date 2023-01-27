#ifndef WELSHPOWELL_H
#define WELSHPOWELL_H

#include <iostream>
using namespace std;
#include<vector>
#define MAX 20

class graphe
{

    vector <int> G[MAX];
    int I[MAX],A[MAX];
    bool DejaMarquer[MAX];

public:

    void ajouteArc(int S1,int S2)
    {

        G[S1].push_back(S2);

    }

    void Welsh_powell()
    {
        int C;
        int SI[MAX];
        for(int i=1; i<MAX; i++)
        {
            A[i]=i;
            I[i]=0;
            SI[i]=G[i].size();
        }
        cout<<endl;
        for(int i=1; i<MAX; i++)
        {
            for(int j=i+1; j<MAX; j++)
            {
                if(SI[i]<SI[j])
                {
                    C=A[i];
                    A[i]=A[j];
                    A[j]=C;

                    C=SI[i];
                    SI[i]=SI[j];
                    SI[j]=C;
                }
            }
        }
        for(int i=1; i<MAX; i++)
        {
            SI[i]=G[i].size();
        }



        int couleur=0,trouve=0;
        vector <int> B;
        for(int i = 1; i<MAX; i++)
        {

            couleur++;

            if(SI[A[i]]!=0 && !DejaMarquer[A[i]])
            {

                B.push_back(A[i]);
                DejaMarquer[A[i]]=true;
                I[A[i]]=couleur;
                for(int j = 1; j<MAX; j++)
                {
                    if(SI[j]!=0 && !DejaMarquer[j])
                    {

                        for(int t = 0; t<B.size(); t++)
                        {

                            for(int k = 0; k<SI[B[t]]; k++)
                            {

                                if(j==G[B[t]][k])
                                {
                                    trouve=1;
                                }

                            }
                        }

                        if(trouve!=1)
                        {
                            I[j]=couleur;
                            DejaMarquer[j]=true;
                            B.push_back(j);

                        }
                        trouve=0;
                    }
                }
            }
            B.clear();
        }
        for(int i=1; i<MAX; i++)
        {
            if(I[i]!=0)
            {

                cout<<"sommet "<<i<<"coulore "<<I[i]<<endl;
            }
        }

    }


};


#endif
