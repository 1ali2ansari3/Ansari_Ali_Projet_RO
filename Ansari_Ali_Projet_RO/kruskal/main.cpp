#include"kruskal.h"

int main()
{

    graphe G;
    int nbArc;
    G.inistialisation();
   cout<<"Nombre des arc :  ";
   cin>>nbArc;
   for(int i = 0; i< nbArc; i++) {
      int S1,S2,S3;
      cout<<"somme  ";
      cin>>S1;
      cout<<"vers  ";
      cin>>S2;
      cout<<"cout  ";
      cin>>S3;
      G.ajouteArc(S1,S2,S3);
   }


   G.kruskal();

   return 0;
}
