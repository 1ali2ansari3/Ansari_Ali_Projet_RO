#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

#include <iostream>
using namespace std;
#include<vector>
#include<deque>
#define MAX 50

class graphe
{

    int G[MAX][MAX];
    int I[MAX];
    bool DejaMarquer[MAX];


public:

void inistialisation()
    {
        for(int i=1; i<MAX; i++)
        {
            I[i]=0;
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


bool cheminAug(int S, int t){

      for (int i = 1; i < MAX; i++){
      DejaMarquer[i]=0;
      I[i]=0;
      }
      deque <int> tab;
      tab.push_back(S);
      DejaMarquer[S] = true;
      I[S]= -1;
      while (!tab.empty()){

        for (int i = 1; i < MAX; i++) {
            if(!DejaMarquer[i] && G[tab[0]][i] > 0) {

                if(i==t){
                    I[i] = tab[0];
                    return true;
                }
                tab.push_back(i);
                I[i] = tab[0];
                DejaMarquer[i] = true;
            }
        }
        tab.pop_front();
    }
    return false;
}

void ford_fulkerson(int S, int t){

     int Vfmax=0;
     int fi;
    while (cheminAug(S,t)) {
       fi = G[I[t]][t];
        for (int i = t; i != S; i = I[i]) {
            if(fi>G[I[i]][i])  fi=G[I[i]][i];
        }
        for (int i = t; i != S; i = I[i]) {

            G[I[i]][i] -= fi;
            G[i][I[i]] += fi;
        }

        Vfmax += fi;
    }

  cout<<"flow max = "<<Vfmax<<endl ;

}





};


#endif
