/*
 * File:   move.cpp
 * Author: evinstk
 * 
 * Created on June, 17, 2013, 10:22 AM
 */

#include "move.h"
#include "query.h"
#include <string>
#include <iostream>

using namespace std;

/* Null Move */
Move::Move() {
    index = 0;
    name = new string("---");
    type = -1;
    category = -1;
    max_pp = 0;
    pp = 0;
    power = 0;
    high_cr_ratio = false;
}

Move::Move(unsigned char move_index) {
    index = move_index;
    name = query::getMoveName(move_index);
    type = query::getType(move_index);
    category = query::getCategory(move_index);
    max_pp = query::getMaxPp(move_index);
    pp = max_pp;
    power = query::getPower(move_index);
    high_cr_ratio = query::getCrRatio(move_index);
}

Move::~Move() {
    delete name;
}
