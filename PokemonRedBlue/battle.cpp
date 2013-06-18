#include "battle.h"
#include <vector>
#include <iostream>

Fighter::Fighter(Pokemon * pokemon) {
    this->pokemon = pokemon;
    accuracy = 100;
    evade = 100;
}

Pokemon *Fighter::getPokemon() {
    return pokemon;
}

unsigned char Side::initFighterIndex() {
    unsigned char ret = -1;
    size_t index = 0;
    std::vector<Fighter *>::const_iterator it = fighters.begin();
    
    while ((ret == -1) || it != fighters.end()) {
        if (!((*it)->getPokemon()->isFainted())) {
            ret = index;
        }
        index++;
        ++it;
    }
    return ret;
}

Side::Side(Trainer* trainer) {
    this->trainer = trainer;
    vector<Pokemon *> v = trainer->getParty()->getParty();
    
    for(std::vector<Pokemon *>::const_iterator it = v.begin(); it != v.end(); ++it) {
        fighters.push_back(new Fighter(*it));
    }
    
    curr_fighter_index = initFighterIndex();
}

Fighter *Side::getFighter() {
    return fighters[curr_fighter_index];
}

BattleChoice *Side::getBattleChoice() {
    return choice;
}

Battle::Battle(Trainer* trainer1, Trainer* trainer2) {
    sides.push_back(new Side(trainer1));
    sides.push_back(new Side(trainer2));
}

vector<Side *> Battle::getSides() {
    return sides;
}

void Battle::execute(Side *attacker, Side *defender) {
    
}

void Battle::executeTurn() {
    unsigned char first_move;
    char priority0 = sides[0]->getBattleChoice()->getPriority();
    char priority1 = sides[1]->getBattleChoice()->getPriority();
    
    if (priority0 > priority1) {
        first_move = 0;
    }
    else if (priority1 > priority0) {
        first_move = 1;
    }
    
    unsigned char speed0 = sides[0]->getFighter()->getPokemon()->getSpeedStat();
    unsigned char speed1 = sides[1]->getFighter()->getPokemon()->getSpeedStat();
    
    if (speed0 > speed1) {
        first_move = 0;
    }
    else if (speed1 > speed0) {
        first_move = 1;
    }
    else {
        first_move = 0;
    }
    
    if (first_move == 0) {
        execute(sides[0], sides[1]);
        execute(sides[1], sides[0]);
    }
    else {
        execute(sides[1], sides[0]);
        execute(sides[0], sides[1]);
    }
}

void Battle::requestExecution() {
    BattleChoice *choice0 = sides[0]->getBattleChoice();
    BattleChoice *choice1 = sides[1]->getBattleChoice();
    
    if ((choice0 != NULL) && (choice1 != NULL)) {
        executeTurn();
    }
}