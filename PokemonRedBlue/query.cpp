/*
 * File:   query.cpp
 * Author: evinstk
 * 
 * Created on June 17, 2013, 9:15 AM
 */

#include <string>
#include "query.h"
#include "move.h"
#include "type.h"
#include "category.h"

string *query::getName(unsigned char index) {
    string *ret = new string("Bulbasaur");
    return ret;
}

unsigned char *query::getBaseStats(unsigned char index) {
    unsigned char *ret = new unsigned char[5];
    ret[0] = 45;
    ret[1] = 49;
    ret[2] = 49;
    ret[3] = 45;
    ret[4] = 65;
    return ret;
}

char query::getExpGroup(unsigned char index) {
    return 2;
}

vector<Move *> query::getDefaultMoves(unsigned char index) {
    vector<Move *> ret;
    Move *move = new Move(1);
    ret.push_back(move);
    return ret;
}

Type *query::getTypes(unsigned char index) {
    Type *ret = new Type[2];
    ret[0] = GRASS;
    ret[1] = NO_TYPE;
    return ret;
}

string *query::getMoveName(unsigned char move_index) {
    string *ret = new string("Pound");
    return ret;
}

Type query::getType(unsigned char move_index) {
    Type ret = NORMAL;
}

Category query::getCategory(unsigned char move_index) {
    return PHYSICAL;
}

unsigned char query::getMaxPp(unsigned char move_index) {
    return 35;
}

unsigned char query::getPower(unsigned char move_index) {
    return 40;
}

unsigned char query::getAccuracy(unsigned char move_index) {
    return 100;
}

bool query::getCrRatio(unsigned char move_index) {
    return false;
}