/* 
 * File:   query.h
 * Author: tanner
 *
 * Created on June 17, 2013, 9:09 AM
 */

#ifndef QUERY_H
#define	QUERY_H

#include "move.h"
#include "category.h"
#include <string>
#include <vector>

using namespace std;

class query {
public:
    //Pokemon
    static string *getName(unsigned char);
    static unsigned char *getBaseStats(unsigned char);
    static vector<Move *> getDefaultMoves(unsigned char);
    static Type *getTypes(unsigned char);
    static char getExpGroup(unsigned char);
    
    //Move
    static string *getMoveName(unsigned char);
    static Type getType(unsigned char);
    static Category getCategory(unsigned char);
    static unsigned char getMaxPp(unsigned char);
    static unsigned char getPower(unsigned char);
    static unsigned char getAccuracy(unsigned char);
    static bool getCrRatio(unsigned char);
};

#endif	/* QUERY_H */

