#ifndef KRUSKAL_H
#define KRUSKAL_H

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


void kruskal(){

  int k=0,A[MAX*MAX+1],I[MAX*MAX+1],F[MAX*MAX+1];
  for(int i=1;i<MAX;i++){
  for(int j=i+1;j<MAX;j++){
        if(G[i][j]!=0){
        A[k]=G[i][j];
        I[k]=i;
        F[k]=j;
        k++;
        }
   }
  }
  int C,CI,CF;
  for(int i=0;i<k;i++){
  for(int j=i+1;j<k;j++){
    if(A[i]>A[j]){
      C=A[i];
      A[i]=A[j];
      A[j]=C;

      CI=I[i];
      I[i]=I[j];
      I[j]=CI;

      CF=F[i];
      F[i]=F[j];
      F[j]=CF;
    }
  }
}
int P=0;
 for(int i=0;i<k;i++){
   if(!DejaMarquer[I[i]] || !DejaMarquer[F[i]]){
    cout<<I[i]<<"vers"<<F[i]<<endl;
    P=P+A[i];
    DejaMarquer[I[i]]=true;
    DejaMarquer[F[i]]=true;
   }
  }
  cout<<"poid = "<<P;
}

};


#endif

