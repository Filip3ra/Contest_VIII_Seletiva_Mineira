#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
 
// Retorna true se x é um quadrado perfeito
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x);
}
 
// Retorna true se n é um número fibonacci, false caso contrário
bool isFibonacci(int n)
{
    // n é Fibonacci se a equação 5*n*n + 4 ou 5*n*n - 4 ou ambas forem quadrados perfeitos
    return isPerfectSquare(5*n*n + 4) ||
           isPerfectSquare(5*n*n - 4);
}

int main(int argc, char const *argv[]){

    int W, F, S, w;
    int qtd_packages = 0;
    int cont = 0;
    vector<int> myvec;

    W = F = S = 1;

    while ( W && F && S != 0){

        cin >> W >> F >> S;
        
        for (int i = 0; i < W; i++){
            cin >> w;
            if(isFibonacci(w))  // se w for fibonacci então é um pacote que será empacotado
                qtd_packages++;
            else{
                ++cont;
                while(!isFibonacci(w+cont)) // se não, calcula quanto de filling vou precisar usar
                    ++cont;
            }           
            myvec.push_back(cont);
            cont = 0;     
        }
        
        sort(myvec.begin(), myvec.end()); // ordeno o vetor de filling 

        for (int i = 1; i < myvec.size(); i++){

            F = F - myvec[i];            
            if( F >= 0)
                ++qtd_packages; // vou empacotar todos que couberem dentro da qtd de filling
        }

        cout << qtd_packages << endl;

        qtd_packages = 0;
        myvec.clear();
    }
    


    return 0;
}


/*
    int a;

    cout << "qtd = " << qtd_packages << "\n" << "restantes = ";
    while(!myvec.empty()){
        a = myvec.back();
        myvec.pop_back();
        cout << a << " ";
    }

*/




