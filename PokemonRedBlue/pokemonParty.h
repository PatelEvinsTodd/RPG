/* 
 * File:   pokemonParty.h
 * Author: tanner
 *
 * Created on June 17, 2013, 2:40 PM
 */

#ifndef POKEMONPARTY_H
#define	POKEMONPARTY_H

#include "pokemon.h"
#include <cstdlib>

class PokemonParty {
private:
    vector<Pokemon*> pokemon;
public:
    PokemonParty(Pokemon *poke0 = NULL, Pokemon *poke1 = NULL,
            Pokemon *poke2 = NULL, Pokemon *poke3 = NULL,
            Pokemon *poke4 = NULL, Pokemon *poke5 = NULL);
    vector<Pokemon*> getParty() const;
};

#endif	/* POKEMONPARTY_H */

