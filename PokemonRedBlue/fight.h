/* 
 * File:   fight.h
 * Author: tanner
 *
 * Created on June 17, 2013, 7:10 PM
 */

#ifndef FIGHT_H
#define	FIGHT_H

#include "battle.h"

class Fight: public BattleChoice {
private:
    Move *move;
    char priority;
public:
    char getPriority();
    void execute(side *, side *);
};

#endif	/* FIGHT_H */

