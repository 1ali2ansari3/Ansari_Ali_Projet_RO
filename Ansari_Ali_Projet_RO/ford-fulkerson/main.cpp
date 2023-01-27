#include"ford-fulkerson.h"


int main()
{

    graphe G;
    int nbArc;

    cout<<"Nombre des arc :  ";
    cin>>nbArc;
    for(int i = 0; i< nbArc; i++)
    {
        int S1,S2,S3;
        cout<<"somme  ";
        cin>>S1;
        cout<<"vers  ";
        cin>>S2;
        cout<<"capacites  ";
        cin>>S3;

        G.ajouteArc(S1,S2,S3);
    }


   G.ford_fulkerson(1,4);

    return 0;
}
