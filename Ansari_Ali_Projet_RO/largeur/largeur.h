#ifndef LARGEUR_H
#define LARGEUR_H

#include <iostream>
using namespace std;
#include <deque>
#include<vector>
#define MAX 100

class graphe{

  vector <int> G[MAX];
  bool DejaMarquer[MAX];

  public:

 void ajouteArc(int S1 ,int S2){

    G[S1].push_back(S2);

 }


void BFS(int S)
{
   deque <int> tab;
   tab.push_back(S);
   DejaMarquer[tab[0]] = true;

while(!tab.empty()){
      cout<<tab[0]<<" ";

      for(int i = 0; i < G[tab[0]].size(); i++){
          if(!DejaMarquer[G[tab[0]][i]]){
              DejaMarquer[G[tab[0]][i]] = true;
              tab.push_back(G[tab[0]][i]);
          }
        }
     tab.pop_front();
}
}


};


#endif



