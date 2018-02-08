//
// Created by Lance Delago on 9/12/17.
//
#include "fuse.h"
#include <iostream>
#include <string>
using namespace std;

bool start_fuse(Fuse &bomb){
	bool time = bomb.burn();
	bomb.to_string();
	return time;
}