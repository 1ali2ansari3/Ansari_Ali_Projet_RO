#include"profondeur.h"

int main()
{
    graphe G;
    int nbArc;

   cout<<"Nombre des arc :  ";
   cin>>nbArc;
   for(int i = 0; i< nbArc; i++) {
      int S1, S2;
      cout<<"somme  ";
      cin>>S1;
      cout<<"vers  ";
      cin>>S2;
      G.ajouteArc(S1,S2);
   }

   G.DFS(1);

   return 0;
}
