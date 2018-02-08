//
// Created by Lance Delago on 9/12/17.
//
#include "puzzle.h"
#include "fuse.cpp"
#include <iostream>
#include <string>
using namespace std;


int StartPuzzle(){
	int time = 8;
	string puzzle_solution = "world";
    cout<<"================\nWelcome to *BOOM* !\n================\nHow to play:\nKeep guessing characters\nand enter a final solution before the TNT ignites!!"<<endl;
    cout<<"Enter lowercase letters to guess,\n!: to propose a solution,\n0: to exit.\nBe sure to press enter after each command!"<<endl;
    Puzzle puzzleStart(puzzle_solution);
    Fuse bomb(time);

    while(true){
        bool ok = start_fuse(bomb);
    	bool ans;
    	char user_guess;
    	string s;
        cout << puzzleStart.to_string();
    	cin >> user_guess;
    	bool check = puzzleStart.guess(char(tolower(user_guess)));

        if(puzzleStart.solved()==true){
            cout << "**** WINNER ****"<<endl;
            return 0;
        }

        if(ok==false){
            cout << "*************\n****BOOM!****\n*************"<<endl;
            cout << "Sorry, the correct answer was: "<< puzzleStart.get_solution() << "\n" << endl;
            return 0;
        }
        
    	if(user_guess == '!'){
    		cout << "Enter Proposed Solution: ";
    		cin >> s;
    		ans = puzzleStart.solve(s);
    		if(ans){
    			cout << "**** WINNER ****"<<endl;
    			return 0;
    		}
    		else{
    			cout << "*************\n****BOOM!****\n*************"<<endl;
    			cout << "Sorry, the correct answer was: "<< puzzleStart.get_solution() << "\n" << endl;
    			return 0;
    		}
    	}
    	else if(user_guess == '0'){
    		return 0;
    	}
    	else{
    		if(check){
    		 	cout << "Correct!\n\n";
    		}
    		else{
    		 	cout << "Oops, try again\n\n";
    		}
    	}
    }
}