#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){

    int N, P, T, R;

    cin >> N >> P >> T >> R;

    int problems_values[15];

    while(N != P != T != R != 0){

        // Prenche o vetor de pontos
        for(int i=0; i<P; i++){
            cin >> problems_values[i];
        }


        cout << "pontos: "; 
        for(int i=0;i<P; i++){
            cout << problems_values[i] << " ";
        }
        cout << endl;


        // Leitura do judge
        int team, problem_number, time, status, score;
        int winner[2] = {-1,-1};
        vector<vector<int>> table;
        vector<int> row;   
        vector<int> winners;

        for(int i=0; i<R; i++){
            // leitura dos dados
            cin >> team >> problem_number >> time >> status;
            
            // calculo do score
            if(status == 0)
                score = problems_values[problem_number-1];
            else
                score = 0;

            cout << "Team = " << team << "\nScore = " << score << "\n\n";

            

            
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

        for(int i=1; i<table.size(); i++){
            if(table[i][1] == best){
                
            }

        }


        for(int i=0; i<table.size(); i++){
            for(int j=0; j<table[i].size(); j++){
                cout << table[i][j] << " ";
            }
            cout << endl;
        }

        cin >> N >> P >> T >> R;

    }

    return 0;
}