/* 
 * File:   battle.h
 * Author: tanner
 *
 * Created on June 17, 2013, 1:46 PM
 */

#ifndef BATTLE_H
#define	BATTLE_H

#include "pokemon.h"
#include "trainer.h"
#include <cstdlib>
#include <vector>

using namespace std;

class BattleChoice {
public:
    virtual char getPriority() = 0;
};

class Fighter {
private:
    Pokemon *pokemon;
    unsigned char evade;
    unsigned char accuracy;
public:
    Fighter(Pokemon *);
    Pokemon *getPokemon();
    unsigned char getEvade();
    unsigned char getAccuracy();
};

class Side {
private:
    Trainer *trainer;
    vector<Fighter *> fighters;
    unsigned char curr_fighter_index;
    BattleChoice *choice;
    unsigned char escape_count;
    
    unsigned char initFighterIndex();
public:
    Side(Trainer *);
    BattleChoice* getBattleChoice();
    Trainer *getTrainer();
    Fighter *getFighter();
};

class Battle {
private:
    vector<Side *> sides;
    
    void execute(Side *, Side *);
    void executeTurn();
    void requestExecution();
public:
    Battle(Trainer *, Trainer *);
    vector<Side *> getSides();
    void setBattleChoice(BattleChoice *, Side *);
};

#endif	/* BATTLE_H */

