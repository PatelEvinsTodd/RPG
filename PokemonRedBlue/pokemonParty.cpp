#include "pokemonParty.h"
#include <iostream>

PokemonParty::PokemonParty(Pokemon* poke0, Pokemon* poke1, Pokemon* poke2,
        Pokemon* poke3, Pokemon* poke4, Pokemon* poke5) {
    if (poke0 != NULL) {
        pokemon.push_back(poke0);
    }
    if (poke1 != NULL) {
        pokemon.push_back(poke1);
    }
    if (poke2 != NULL) {
        pokemon.push_back(poke2);
    }
    if (poke3 != NULL) {
        pokemon.push_back(poke3);
    }
    if (poke4 != NULL) {
        pokemon.push_back(poke4);
    }
    if (poke5 != NULL) {
        pokemon.push_back(poke5);
    }
}

vector<Pokemon*> PokemonParty::getParty() const {
    return pokemon;
}
