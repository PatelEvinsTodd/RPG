/* 
 * File:   trainer.h
 * Author: tanner
 *
 * Created on June 17, 2013, 1:47 PM
 */

#ifndef TRAINER_H
#define	TRAINER_H

#include "pokemonParty.h"
#include <string>

class Trainer{
private:
    string name;
    PokemonParty *party;
public:
    Trainer(string name, PokemonParty* party);
    PokemonParty *getParty();
};

#endif	/* TRAINER_H */

