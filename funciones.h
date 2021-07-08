#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

float ** lee_mat2(char *nom_arch,int m, int n){
    float **MM,num,M;
    MM = crea_mat(m,n);
    fstream fd1;
    //std:cout.precision(15);
    fd1.open(nom_arch,ios::in);

    while (!fd1.eof()){
          

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                fd1>>num;
                if(num == M){
                    num = 10000;
                    MM[i][j] = num;
                }else{  
                    MM[i][j] = num;
                }            
            }
        }
    }
    fd1.close();
    cout<<"Matriz leida"<<endl;
    return MM;
    
}

float *lee_vect(char* nom_arch,int m){
    float *W;
    W = new float[m];
    fstream fd2;
    fd2.open(nom_arch,ios::in);
    while (!fd2.eof()){
        for (int i = 0; i < m; i++){
            fd2>>W[i];}}
    return W;      
}
float * crea_vect(int m){
    float *W;
    W = new float[m];
    return W;
}
float **crea_mat(int m, int n){
    float **M;
    M = new float*[m];
    for (int j = 0; j < m ; j++){
        M[j] =  new float[n];} 
    return M;
}
float **lee_mat(char *nomb_arch,int m, int n){
    float **M;
    M = crea_mat(m,n);
    fstream fd1;
    fd1.open(nomb_arch,ios::in);
    while (!fd1.eof()){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                fd1>>M[i][j];}}       }
    fd1.close();
    cout<<"Matriz leida"<<endl;
    return M;    
}
int muestra_vect(float *M,int m){
    for (int i = 0; i < m; i++){
        cout<<M[i]<<" ,";    }
    cout<<endl; 
    return 0;
}
int muestra_mat(float **M,int m,int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout<<M[i][j]<<" ,";        }
        cout<<endl;            }
    return 0;
}