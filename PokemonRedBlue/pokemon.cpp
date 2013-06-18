/* 
 * File:   Pokemon.cpp
 * Author: evinstk
 *
 * Created on June 16, 2013, 8:19 PM
 */

#include "pokemon.h"
#include "query.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

Pokemon::Pokemon() {
    index = 0;
    name = new string("Empty");
    base_stats = NULL;
    iv = NULL;
    ev = NULL;
    level = 0;
    types = NULL;
    experience_group = -1;
    exp = 0;
    fainted = true;
    status_ailment = 0;
}

Pokemon::Pokemon(unsigned char index, int level) {
    this->index = index;
    
    name = query::getName(index);
    
    base_stats = query::getBaseStats(index);
    
    iv = new unsigned char[5];
    srand(time(NULL));
    for (size_t i = 1; i < sizeof(iv); i++) {
        iv[i] = (unsigned char)(rand() % 16);
    }
    int hp = 0;
    int adder = 8;
    for (size_t i = 0; i < 4; i++) {
        if ((iv[i + 1] % 2) == 1) {
            hp += adder;
        }
        adder /= 2;
    }
    iv[0] = hp;
    
    ev = new unsigned short[5];
    
    this->level = level;
    
    moves = query::getDefaultMoves(index);
    
    types = query::getTypes(index);
    
    experience_group = query::getExpGroup(index);
    
    initExp();
    
    this->hp = getHpStat();
    
    fainted = false;
    
    status_ailment = 0;
}

Pokemon::~Pokemon() {
    delete name;
    delete[] base_stats;
    delete[] iv;
    delete[] ev;
    delete[] types;
}

int Pokemon::getMinExp(unsigned char level) {
    if (experience_group == 0) {
        return ((4*((level)^3))/5);
    }
    else if (experience_group == 1) {
        return ((level)^3);
    }
    else if (experience_group == 2) {
        return ((6/5)*((level)^3) - (15)*((level)^2) + (100)*(level) - 140);
    }
    else if (experience_group == 3) {
        return (5*((level)^3)/4);
    }
}

#ifndef INIT_EXP
#define INIT_EXP
void Pokemon::initExp() {
    exp = rand() % (getMinExp(level + 1) - getMinExp(level)) + getMinExp(level);
}
#endif

string *Pokemon::getName() {
    return name;
}

unsigned char *Pokemon::getBaseStats() {
    return this->base_stats;
}

unsigned char *Pokemon::getIv() {
    return this->iv;
}

unsigned short *Pokemon::getEv() {
    return this->ev;
}

unsigned char Pokemon::getHp() {
    return hp;
}

unsigned char Pokemon::getStat(unsigned char stat_index) {
    unsigned char base_stat = getBaseStats()[stat_index];
    unsigned char individual_value = getIv()[stat_index];
    unsigned short effort_value = getEv()[stat_index];
    unsigned char curr_level = level;
    float m0, m1;
    if (stat_index == 0) {
        m0 = 50.f;
        m1 = 10.f;
    }
    else {
        m0 = 0.f;
        m1 = 5.f;
    }
    
    unsigned char ret = (unsigned char)((((float)(individual_value) + (float)(base_stat) + ((float)(sqrt(effort_value))/8.f) + m0) * (float)(curr_level)) / 50.f + m1);
    return ret;
}

unsigned char Pokemon::getHpStat() {
    return getStat(0);
}

unsigned char Pokemon::getAttackStat() {
    return getStat(1);
}

unsigned char Pokemon::getDefenseStat() {
    return getStat(2);
}

unsigned char Pokemon::getSpeedStat() {
    return getStat(3);
}

unsigned char Pokemon::getSpecialStat() {
    return getStat(4);
}

bool Pokemon::isFainted() {
    return fainted;
}
