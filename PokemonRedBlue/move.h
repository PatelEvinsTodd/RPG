/* 
 * File:   Move.h
 * Author: tanner
 *
 * Created on June 16, 2013, 5:30 PM
 */

#ifndef MOVE_H
#define	MOVE_H

#include <string>
#include "type.h"

using namespace std;

class Move {
private:
    int index;
    string *name;
    char type;
    char category;
    unsigned char pp;
    unsigned char max_pp;
    unsigned char power;
    unsigned char accuracy;
    bool high_cr_ratio;
public:
    Move();
    Move(unsigned char);
    ~Move();
};

#endif	/* MOVE_H */

