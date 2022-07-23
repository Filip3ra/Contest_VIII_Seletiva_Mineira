#include <iostream>
#include <vector>
#include <algorithm>

/*  -> Posso tentar fazer com que a submissão da mesma questão não resulte em 
    mais de uma contagem de pontos

    -> Posso tentar fazer com que a submissão da mesma questão, que previamente
    estivera correta, fique errada e perca os pontos obtidos

*/

using namespace std;

int main(int argc, char const *argv[]){

    int N, P, T, R;

    cin >> N >> P >> T >> R;


    vector<int> problems_values;
    int x = 0;

    while(N != 0 && P != 0 && T != 0 && R != 0){

        // Prenche o vetor de pontos
        for(int i=0; i<P; i++){
            cin >> x;
            problems_values.push_back(x);
        }

/*
        cout << "pontos: "; 
        for(int i=0;i<P; i++){
            cout << problems_values[i] << " ";
        }
        cout << endl;
*/

        // Leitura do judge
        int team, problem_number, time, status, score;
        
        vector<vector<int>> table;
        vector<int> row;   

        for(int i=0; i<R; i++){
            // leitura dos dados
            cin >> team >> problem_number >> time >> status;
            
            // calculo do score
            if(status == 0)
                score = problems_values[problem_number-1];
            else
                score = 0;

            
            //cout << "Team = " << team << "\nScore = " << score << "\n\n";   
            //cout << "SIZE = " << table.size() << endl; 

            // confere se já tem esse time na tabela
            bool flag = false;          
            for(int i=0; i<table.size(); i++){
                if(table[i][0] == team){
                    table[i][1] += score;
                    flag = true;
                }
            }

            // se não tiver o time, adiciona
            if(flag == false){
                // inicializo minha linha e jogo na tabela
                row.push_back(team);
                row.push_back(score);
                table.push_back(row);

                row.clear();
            }
            
        }

        int best = table[0][1];
        int winner = table[0][0];
        bool multiple_winners = false;
        vector<int> winners;

        for(int i=0; i<table.size(); i++){
            if(table[i][1] > best){
                best = table[i][1];
                winner = table[i][0];
                multiple_winners = false;
                winners.clear();
                winners.push_back(table[i][0]);
            }
            else if(table[i][1] == best){
                if(i>0)
                    multiple_winners = true;
                
                winners.push_back(table[i][0]);
            }
        }

        if(multiple_winners==false){
            cout << "Contest " << N << " Winner: Team " << winner << endl;
        }
        else{
            sort(winners.begin(), winners.end()); // ordena vetor
            cout << "Contest " << N << " Winner:";
            for(int i=0; i<winners.size(); i++){
                cout << " Team " << winners[i];
                if(i+1 < winners.size())
                    cout << " and";
                else
                    cout << endl;
            }
        }

        winners.clear();
        table.clear();
        problems_values.clear();
        row.clear();


/*
        for(int i=0; i<table.size(); i++){
            for(int j=0; j<table[i].size(); j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }
*/
        cin >> N >> P >> T >> R;

    }

    return 0;
}


/*
entrada

1 5 20 6
3 3 10 30 100
6 1 16024555 0
3 2 15895629 4
3 2 765629 0
17 4 1120132 0
3 2 1895629 3
6 3 9024555 0
2 5 20 7
3 10 10 30 100
6 1 16024555 0
3 2 15895629 5
3 2 765629 0
17 4 1120139 0
5 4 1895629 0
6 3 9024555 0
10 4 2895629 0
3 5 30 7
5 5 5 5 5
6 1 16024555 0
3 2 15895629 0
3 2 765629 0
17 4 1120139 0
5 4 1895629 0
6 3 9024555 0
10 4 2895629 0
4 5 20 11
10 20 30 40 50
8 5 16024555 0
7 2 15895629 5
7 2 765629 0
11 4 1120132 5
11 4 1120144 0
8 1 1245455 5
7 3 1895629 1
7 1 121545 0
7 3 121545 0
8 1 121545 0
11 2 12121 0


*/