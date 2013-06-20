/* 
 * File:   Type.h
 * Author: tanner
 *
 * Created on June 16, 2013, 5:34 PM
 */

#ifndef TYPE_H
#define	TYPE_H

#include <map>

using namespace std;

enum Type {
    NO_TYPE,
    BUG,
    DRAGON,
    ELECTRIC,
    FIGHTING,
    FIRE,
    FLYING,
    GHOST,
    GRASS,
    GROUND,
    ICE,
    NORMAL,
    POISON,
    PSYCHIC,
    ROCK,
    WATER
};

class TypeTable {
private:
    static const float SUPER_EFFECTIVE = 2.f;
    static const float RESISTANT = 0.5f;
    static const float IMMUNE = -1.f;
    
    typedef std::map<Type, float> DefenseMap;
    typedef std::map<Type, DefenseMap> TypeMap;
    
    static TypeMap initTypeMap();
    static TypeMap table;
public:
    TypeTable();
    static float getModifier(Type, Type);
};

#endif	/* TYPE_H */

