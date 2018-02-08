
//
#include <iostream>
#include <string>
using namespace std;

class Puzzle{

    public:
        //constructor
        Puzzle(string word){
            solution = word;
            int wordlen = sizeof(solution)/sizeof(solution[0]);
            for (int i = 0; i < wordlen; i++){
                guesses[int(solution[i])] = true;
            }
        }
        //user guesses and updates guesses bool array
        bool guess(char c){
            int x = int(c);
            bool answer;  
            int len = sizeof(solution)/sizeof(solution[0]);
            
            for (int i = 0; i < len; i++){
                if(solution[i] == c){
                    guesses[x] = false;
                    answer = true;
                    break;
                    
                }
                else{
                    answer = false;
                }
            }
            return answer;
        }
        //user solve attempt
        bool solve(string proposed_solution){
            if(proposed_solution == solution){
                return true;
            }
            else{
                return false;
            }

        }
        //updates solution area ex"HE__O"
        string to_string(){
            int x;
            string puzzleChart = "_ _ _ _ _:";
            int len = sizeof(solution)/sizeof(solution[0]);
            for(int i = 0; i < len; i++){
                x = int(solution[i]);
                if(!(guesses[x])){
                    puzzleChart[(i*2)] = solution[i];   
                }
             }
             return puzzleChart;
           }

        //reutrns the solution when needed
        string get_solution(){
            return solution;
        }

        bool solved(){
            int wordlen = sizeof(solution)/sizeof(solution[0]);
            for (int i = 0; i < wordlen; i++){
                if(guesses[int(solution[i])]){
                    return false;
                }
            }
            return true;
        }
        
    private:
        string solution;
        bool guesses[255];
};


