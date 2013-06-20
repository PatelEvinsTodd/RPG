#include "type.h"

TypeTable::TypeMap TypeTable::initTypeMap() {
    TypeMap ret;
    
    //If attack is normal
    DefenseMap normal;
    normal[ROCK] = RESISTANT;
    normal[GHOST] = IMMUNE;
    ret[NORMAL] = normal;
    
    //If attack is FIRE
    DefenseMap fire;
    fire[FIRE] = RESISTANT;
    fire[WATER] = RESISTANT;
    fire[GRASS] = SUPER_EFFECTIVE;
    fire[ICE] = SUPER_EFFECTIVE;
    fire[BUG] = SUPER_EFFECTIVE;
    fire[ROCK] = RESISTANT;
    fire[DRAGON] = RESISTANT;
    ret[FIRE] = fire;

    //If attack is WATER
    DefenseMap water;
    water[FIRE] = SUPER_EFFECTIVE;
    water[WATER] = RESISTANT;
    water[GRASS] = RESISTANT;
    water[GROUND] = SUPER_EFFECTIVE;
    water[ROCK] = SUPER_EFFECTIVE;
    water[DRAGON] = RESISTANT;
    ret[WATER] = water;

    //If attack is ELECTRIC
    DefenseMap electric;
    electric[WATER] = SUPER_EFFECTIVE;
    electric[ELECTRIC] = RESISTANT;
    electric[GRASS] = RESISTANT;
    electric[GROUND] = IMMUNE;
    electric[FLYING] = SUPER_EFFECTIVE;
    electric[DRAGON] = RESISTANT;
    ret[ELECTRIC] = electric;

    //If attack is GRASS
    DefenseMap grass;
    grass[FIRE] = RESISTANT;
    grass[WATER] = SUPER_EFFECTIVE;
    grass[GRASS] = RESISTANT;
    grass[POISON] = RESISTANT;
    grass[GROUND] = SUPER_EFFECTIVE;
    grass[FLYING] = RESISTANT;
    grass[BUG] = RESISTANT;
    grass[ROCK] = SUPER_EFFECTIVE;
    grass[DRAGON] = RESISTANT;
    ret[GRASS] = grass;

    //If attack is ICE
    DefenseMap ice;
    ice[FIRE] = RESISTANT;
    ice[WATER] = RESISTANT;
    ice[GRASS] = SUPER_EFFECTIVE;
    ice[ICE] = RESISTANT;
    ice[GROUND] = SUPER_EFFECTIVE;
    ice[FLYING] = SUPER_EFFECTIVE;
    ice[DRAGON] = SUPER_EFFECTIVE;
    ret[ICE] = ice;

    //If attack is FIGHTING
    DefenseMap fighting;
    fighting[NORMAL] = SUPER_EFFECTIVE;
    fighting[ICE] = SUPER_EFFECTIVE;
    fighting[POISON] = RESISTANT;
    fighting[FLYING] = RESISTANT;
    fighting[PSYCHIC] = RESISTANT;
    fighting[BUG] = RESISTANT;
    fighting[ROCK] = SUPER_EFFECTIVE;
    fighting[GHOST] = IMMUNE;
    ret[FIGHTING] = fighting;

    //If attack is POISON
    DefenseMap poison;
    poison[GRASS] = SUPER_EFFECTIVE;
    poison[POISON] = RESISTANT;
    poison[GROUND] = RESISTANT;
    poison[ROCK] = RESISTANT;
    poison[GHOST] = RESISTANT;
    ret[POISON] = poison;

    //If attack is GROUND
    DefenseMap ground;
    ground[FIRE] = SUPER_EFFECTIVE;
    ground[ELECTRIC] = SUPER_EFFECTIVE;
    ground[GRASS] = RESISTANT;
    ground[POISON] = SUPER_EFFECTIVE;
    ground[FLYING] = IMMUNE;
    ground[BUG] = RESISTANT;
    ground[ROCK] = SUPER_EFFECTIVE;
    ret[GROUND] = ground;

    //If attack is FLYING
    DefenseMap flying;
    flying[ELECTRIC] = RESISTANT;
    flying[GRASS] = SUPER_EFFECTIVE;
    flying[FIGHTING] = SUPER_EFFECTIVE;
    flying[BUG] = SUPER_EFFECTIVE;
    flying[ROCK] = RESISTANT;
    ret[FLYING] = flying;

    //If attack is PSYCHIC
    DefenseMap psychic;
    psychic[FIGHTING] = SUPER_EFFECTIVE;
    psychic[POISON] = SUPER_EFFECTIVE;
    psychic[PSYCHIC] = RESISTANT;
    ret[PSYCHIC] = psychic;

    //If attack is BUG
    DefenseMap bug;
    bug[FIRE] = RESISTANT;
    bug[GRASS] = SUPER_EFFECTIVE;
    bug[FIGHTING] = RESISTANT;
    bug[POISON] = RESISTANT;
    bug[FLYING] = RESISTANT;
    bug[PSYCHIC] = SUPER_EFFECTIVE;
    bug[GHOST] = RESISTANT;
    ret[BUG] = bug;

    //If attack is ROCK
    DefenseMap rock;
    rock[FIRE] = SUPER_EFFECTIVE;
    rock[ICE] = SUPER_EFFECTIVE;
    rock[FIGHTING] = RESISTANT;
    rock[GROUND] = RESISTANT;
    rock[FLYING] = SUPER_EFFECTIVE;
    rock[BUG] = SUPER_EFFECTIVE;
    ret[ROCK] = rock;

    //If attack is GHOST
    DefenseMap ghost;
    ghost[NORMAL] = IMMUNE;
    ghost[PSYCHIC] = SUPER_EFFECTIVE;
    ghost[GHOST] = SUPER_EFFECTIVE;
    ret[GHOST] = ghost;

    //If attack is DRAGON
    DefenseMap dragon;
    dragon[DRAGON] = SUPER_EFFECTIVE;
    ret[DRAGON] = dragon;
    
    return ret;
}

TypeTable::TypeMap TypeTable::table(TypeTable::initTypeMap());

float TypeTable::getModifier(Type attack_type, Type defense_type) {
    float ret = table[attack_type][defense_type];
    if (ret == -1) {
        ret = 0;
    }
    else if (ret == 0) {
        ret = 1;
    }
    return ret;
}
