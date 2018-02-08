//
// Created by Lance Delago on 9/12/17.
//
#include <iostream>
#include <string>
using namespace std;

class Fuse {

   public:
       //constructor
       Fuse(int x){
       		time = x;
       }
       //returns true if any guesses remain
       bool burn(){
       		time = time-1;
       		if(time > 0){
       			return true;
       		}
       		else{
       			return false;
       		}
       }
       //returns the "image" of the fuse and its remaining guesses
       void to_string(){
            cout << "------\n||TNT||\n------";
            for(int i = time; i >= 0; i--){
                  cout << "~";
            }
            cout<<"*";
            cout << "\n";
       }
   private:
       int time;
};


