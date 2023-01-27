#ifndef PRIM_H
#define PRIM_H

#include <iostream>
using namespace std;
#include<vector>
#define MAX 50

class graphe{

  int G[MAX][MAX];

  bool DejaMarquer[MAX];

  public:
void inistialisation(){
  for(int i=1;i<MAX;i++){
   for(int j=1;j<MAX;j++){
        G[i][j]=0;

   }
  }
}
void ajouteArc(int S1,int S2,int S3){


    G[S1][S2]=S3;


}


void prim(int S){
    int t=0,min1,X,Y,P=0;
     vector <int> A;
     A.push_back(S);
     DejaMarquer[S] = true;
     while(t==0){
        t=1;
        for(int i=0;i<A.size();i++){
        for(int j=1;j<MAX;j++){
         if(!DejaMarquer[j] && G[A[i]][j]!=0)
            min1=G[A[i]][j]+1;
        }
        }
   for(int i=0;i<A.size();i++){
   for(int j=1;j<MAX;j++){
      if(!DejaMarquer[j] && G[A[i]][j]<min1 && G[A[i]][j]!=0){
        min1=G[A[i]][j];
        Y=j;
        X=A[i];
        t=0;
      }
   }
  }
  if(t==0){
  cout<<X<<"vers"<<Y<<endl;
  P=P+min1;
  A.push_back(Y);
  DejaMarquer[Y] = true;
  }
}
cout<<"poid = "<<P;
}

};


#endif

