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
    int fibo[50] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,
                2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,
                317811,514229,832040,1346269,2178309,3524578,5702887,9227465,
                14930352,24157817,39088169,63245986,102334155,165580141,267914296,
                433494437,701408733,1134903170,1836311903};

    cin >> W >> F >> S;

    while ( W && F && S != 0){
        
        for (int i = 0; i < W; i++){
            cin >> w;
            if(isFibonacci(w))  // se w for fibonacci então é um pacote que será empacotado
                qtd_packages++;
            else{
                for (int i = 0; i < 50; i++){
                    if(w<fibo[i]){
                        cont = fibo[i] - w;
                        i = 100;
                    }
                }
                myvec.push_back(cont);
                cont = 0;     
            }           
            
        }
        
        sort(myvec.begin(), myvec.end()); // ordeno o vetor de filling 

        for (int i = 0; i < myvec.size(); i++){

            F = F - myvec[i];
            if( F >= 0)
                ++qtd_packages; // vou empacotar todos que couberem dentro da qtd de filling
        }

        cout << qtd_packages << endl;

        qtd_packages = 0;
        myvec.clear();

        cin >> W >> F >> S;
    }
    


    return 0;
}






