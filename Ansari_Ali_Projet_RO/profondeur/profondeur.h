#ifndef PROFONDEUR_H
#define PROFONDEUR_H

#include <iostream>

using namespace std;

#include<vector>
#define MAX 100

class graphe{

  vector <int> G[MAX];
  bool DejaMarquer[MAX];

  public:

 void ajouteArc(int S1 ,int S2){

    G[S1].push_back(S2);
}

void DFS(int S)
{
  cout<<S<<" ";

  DejaMarquer[S] = true;

  for(int i=0;i<G[S].size();i++){
      if(!DejaMarquer[G[S][i]])
      DFS(G[S][i]);
  }

}
};


#endif
