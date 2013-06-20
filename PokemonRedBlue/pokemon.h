/* 
 * File:   Pokemon.h
 * Author: evinstk
 *
 * Created on June 16, 2013, 5:04 PM
 */

#ifndef POKEMON_H
#define	POKEMON_H

#include "move.h"
#include "type.h"
#include "expGroup.h"
#include "status.h"
#include <string>
#include <vector>

using namespace std;

class Pokemon {
private:
    unsigned char index;
    string *name;
    //Arrays: HP, Attack, Defense, Speed, Special
    unsigned char *base_stats;
    unsigned char *iv;
    unsigned short *ev;
    unsigned char level;
    unsigned int exp;
    vector<Move *> moves;
    Type *types;
    char experience_group;
    unsigned char hp;
    bool fainted;
    char status_ailment;
    
    int getMinExp(unsigned char);
    void initExp();
    unsigned char getStat(unsigned char);
    
public:
    //Null Pokemon
    Pokemon();
    
    //Actual Pokemon
    Pokemon(unsigned char, int);
    
    ~Pokemon();
    
    //Getters
    string *getName();
    unsigned char *getBaseStats();
    unsigned char *getIv();
    unsigned short *getEv();
    unsigned char getLevel();
    unsigned char getHp();
    unsigned char getHpStat();
    unsigned char getAttackStat();
    unsigned char getDefenseStat();
    unsigned char getSpeedStat();
    unsigned char getSpecialStat();
    Move *getMove(size_t);
    Type *getTypes();
    bool isFainted();
    
    //Setters
    void takeDamage(int);
};

#endif	/* POKEMON_H */

