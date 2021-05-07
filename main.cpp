#include<iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
int* getUnion(int a[], int n, int b[], int m)
{
    static int arr[99];
    set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
   
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    
      int k=0;
       arr[k]=s.size();
       k=1;
    for (auto itr = s.begin(); itr != s.end(); itr++){
        arr[k]=*itr;
        k++;
        
                     
    }
   
    return arr;
       
}
 
void pmat(int mat[9][9]){
    
     for(int i=0;i<9;i++){
     for(int j=0;j<9;j++){
         
         cout<<mat[i][j]<<"  ";
         if((j+1)%3==0){
             cout<<"    ";
         }
     }
     if((i+1)%3==0){
             cout<<endl;
         }
     cout<<endl;
 }
}
int* np(int i,int mat[9][9]){
    return mat[i];
}
int* np1(int j,int mat[9][9]){
    static int arr[99];
    for(int k=0;k<9;k++){
        arr[k]=mat[k][j];
    }
return arr;
    
}

int* np3(int i,int j,int mat[9][9]){
   
   static int arr[90];
   int k=0;

    if(i<3){
        if(j<3){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            }
        }
        else if(j>=3&&j<6){
             for(int i=0;i<3;i++){
                for(int j=3;j<6;j++){
                    arr[k]=mat[i][j];
                    k++;                }
            }
        }
        else if(j>=6){
             for(int i=0;i<3;i++){
                for(int j=6;j<9;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            }
        }
    }
    else if(i>=3&&i<6){
         if(j<3){
            for(int i=3;i<6;i++){
                for(int j=0;j<3;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            } 
        }
        else if(j>=3&&j<6){
             for(int i=3;i<6;i++){
                for(int j=3;j<6;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            }
        }
        else if(j>=6){
             for(int i=3;i<6;i++){
                for(int j=6;j<9;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            }
        }
    }
    else if(i>=6){
         if(j<3){
            for(int i=6;i<9;i++){
                for(int j=0;j<3;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            } 
        }
        else if(j>=3&&j<6){
             for(int i=6;i<9;i++){
                for(int j=3;j<6;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            }
        }
        else if(j>=6){
             for(int i=6;i<9;i++){
                for(int j=6;j<9;j++){
                    arr[k]=mat[i][j];
                    k++;
                }
            }
        }
    }
    return arr;
}
int main(){
   auto start = high_resolution_clock::now();
    int* a1;
    int* a2;
    int* a3;
    int* u1;
    int* u2;
    int* dis;
    int st1[9]={1,2,3,4,5,6,7,8,9};
 int mat[9][9]={
{0, 7, 0 ,0 ,2 ,0 ,0 ,4, 6},                                                                                                                              
{0, 6, 0, 0, 0, 0, 8, 9, 0},                                                                                                                               
{2, 0, 0, 8, 0, 0, 7, 1, 5},                                                                                                                               
{0, 8, 4, 0, 9, 7, 0, 0, 0},                                                                                                                           
{7, 1, 0, 0, 0, 0, 0, 5, 9},                                                                                                                               
{0, 0, 0, 1, 3, 0, 4, 8, 7},                                                                                                                              
{6, 9, 7, 0, 0, 2, 0, 0, 0},                                                                                                                               
{0, 5, 8, 0, 0, 0, 0, 6, 0},                                                                                                                               
{4, 3, 0, 0, 8, 0, 0, 7, 0}} ;
 
 pmat(mat);
 for(int v=0;v<6;v++){
 for(int i=0;i<9;i++){
     for(int j=0;j<9;j++){
         if(mat[i][j]==0){
            int y=0;

            a1=np(i,mat);
            a2=np1(j,mat);
            a3=np3(i,j,mat);
            u1=getUnion(a1, 9, a2, 9);
            int size1=u1[0];
            int temp1[size1];
            int k=0;
            for ( int i = 1; i < size1+1; i++ ) {
              temp1[k]=u1[i];
              k++;
              }
            u2=getUnion(temp1, size1,a3, 9);
            int size2=u2[0];
              int ya;
              for(int j=0;j<9;j++){
                  
                int f=0;
               for(int i=1;i<size2+1;i++){
       
                  if(u2[i]==st1[j]){
                   f=f+1;
                   }
                   
               }
              int b=0;
              if(f==0){
                  y=y+1;
              ya=st1[j];

              }
              
              }
              if(y==1){
                  mat[i][j]=ya;
                  
              }
         }

     }
 
 }
 
}
cout<<"SOLUTION:"<<endl;
     pmat(mat);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   cout << "\nTime taken by function : "<< duration.count() << " microseconds";

     return 0;

 }
