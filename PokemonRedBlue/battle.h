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

class Side;
class Battle;

class BattleChoice {
public:
    virtual void execute(Side *, Side *) = 0;
    virtual char getPriority() = 0;
};

class Fight : public BattleChoice {
private:
    Move *move;
    char priority;
public:
    Fight(Move *);
    void execute(Side *, Side *);
    char getPriority();
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
    void setBattleChoice(BattleChoice *);
};

class Battle {
private:
    vector<Side *> sides;
    
    void execute();
    void executeTurn();
    void requestExecution();
public:
    Battle(Trainer *, Trainer *);
    vector<Side *> getSides();
    void setBattleChoice(BattleChoice *, size_t);
};

#endif	/* BATTLE_H */

