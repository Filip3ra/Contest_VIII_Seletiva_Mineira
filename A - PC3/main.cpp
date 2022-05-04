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

    while(N != P != T != R != 0){

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
        winners.push_back(table[0][0]); 

        for(int i=1; i<table.size(); i++){
            if(table[i][1] > best){
                best = table[i][1];
                winner = table[i][0];
                multiple_winners = false;
                winners.clear();
                winners.push_back(winner);
            }
            else if(table[i][1] == best){
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