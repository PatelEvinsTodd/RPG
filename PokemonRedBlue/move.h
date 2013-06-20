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
#include "category.h"

using namespace std;

class Move {
private:
    unsigned char index;
    string *name;
    Type type;
    Category category;
    unsigned char pp;
    unsigned char max_pp;
    unsigned char power;
    unsigned char accuracy;
    bool high_cr_ratio;
public:
    Move();
    Move(unsigned char);
    ~Move();
    
    unsigned char getIndex() const;
    string *getName() const;
    Category getCategory() const;
    bool getCrRatio() const;
    unsigned char getPower() const;
    Type getType() const;
    unsigned char getAccuracy() const;
    
    void decreasePp();
};

#endif	/* MOVE_H */

