#include "battle.h"
#include <vector>
#include <iostream>
#include <time.h>

Fight::Fight(Move * move) {
    this->move = move;
    if (*(move->getName()) == "Quick Attack") {
        priority = 1;
    }
    else if (*(move->getName()) == "Counter") {
        priority = -5;
    }
    else {
        priority = 0;
    }
}

char Fight::getPriority() {
    return priority;
}

void Fight::execute(Side* attacker, Side* defender) {
    Category category = move->getCategory();
    Pokemon *attacker_poke = attacker->getFighter()->getPokemon();
    unsigned char accuracy = attacker->getFighter()->getAccuracy();
    Pokemon *defender_poke = defender->getFighter()->getPokemon();
    unsigned char evade = defender->getFighter()->getEvade();
    unsigned char move_accuracy = move->getAccuracy();
    
    move->decreasePp();
    
    if (category == STATUS) {
        //Do status logic
        return;
    }
    srand(time(NULL));
    /* else */
    //Set level
    unsigned char level = attacker_poke->getLevel();

    //Set critical hit
    bool high_cr_ratio = move->getCrRatio();
    short cr_denominator;
    if (high_cr_ratio) {
        cr_denominator = 64;
    }
    else {
        cr_denominator = 512;
    }
    unsigned char attacker_speed = attacker_poke->getSpeedStat();
    float cr_probability = (float)(attacker_speed) / (float)(cr_denominator) * 100.f;
    unsigned char critical_hit;
    if ((rand() % 101) <= cr_probability) {
        critical_hit = 2;
    }
    else {
        critical_hit = 1;
    }

    //Set attack and defense powers
    unsigned char attack;
    unsigned char defense;
    if (category == PHYSICAL) {
        attack = attacker_poke->getAttackStat();
        defense = defender_poke->getDefenseStat();
    }
    else {
        attack = attacker_poke->getSpecialStat();
        defense = defender_poke->getSpecialStat();
    }
    
    //Set base power
    unsigned char base = move->getPower();
    
    //Set multiplier
    float multiplier = 1.f;
    Type *attacker_types = attacker_poke->getTypes();
    Type attack_type = move->getType();
    Type *defender_types = defender_poke->getTypes();
    if ((attack_type == attacker_types[0]) || (attack_type == attacker_types[1])) {
        multiplier *= 1.5f; //STAB
    }
    for (int i = 0; i < sizeof(defender_types); i++) {
        multiplier *= TypeTable::getModifier(attack_type, defender_types[i]);
    }
    
    //Set randomizer
    unsigned char random = (rand() % (256 - 217)) + 217;
    
    //Set possible damage dealt
    int damage = (((((float)(level) * 0.4f * (float)(critical_hit)) + 2.f) * (float)(attack) * (float)(base) / 50.f / (float)(defense)) + 2.f) * (float)(multiplier) * (float)(random) / 255;
    
    //Set hit or miss probability
    int hit_or_miss = (int)((float)(move_accuracy) * (float)(accuracy) / (float)(evade));
    
    //Do damage (possibly)
    if ((rand() % 102) < hit_or_miss) {
        defender_poke->takeDamage(damage);
    }
}

Fighter::Fighter(Pokemon * pokemon) {
    this->pokemon = pokemon;
    accuracy = 100;
    evade = 100;
}

Pokemon *Fighter::getPokemon() {
    return pokemon;
}

unsigned char Fighter::getAccuracy() {
    return accuracy;
}

unsigned char Fighter::getEvade() {
    return evade;
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

void Side::setBattleChoice(BattleChoice* choice) {
    this->choice = choice;
}

void Battle::setBattleChoice(BattleChoice *choice, size_t index) {
    sides[index]->setBattleChoice(choice);
    requestExecution();
}

Battle::Battle(Trainer* trainer1, Trainer* trainer2) {
    sides.push_back(new Side(trainer1));
    sides.push_back(new Side(trainer2));
}

vector<Side *> Battle::getSides() {
    return sides;
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
        sides[0]->getBattleChoice()->execute(sides[0], sides[1]);
        sides[1]->getBattleChoice()->execute(sides[1], sides[0]);
    }
    else {
        sides[1]->getBattleChoice()->execute(sides[1], sides[0]);
        sides[0]->getBattleChoice()->execute(sides[0], sides[1]);
    }
}

void Battle::requestExecution() {
    BattleChoice *choice0 = sides[0]->getBattleChoice();
    BattleChoice *choice1 = sides[1]->getBattleChoice();
    cout << (int)(choice0->getPriority()) << endl;
    if ((choice0) && (choice1)) {
        executeTurn();
    }
}