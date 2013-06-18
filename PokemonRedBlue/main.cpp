/* 
 * File:   main.cpp
 * Author: tanner
 *
 * Created on June 16, 2013, 7:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "battle.h"
#include "pokemon.h"
#include "trainer.h"
#include "pokemonParty.h"

using namespace std;

/*
 * 
 */
int main() {
    Pokemon *pokemon = new Pokemon(1, 50);
    unsigned char* base_stats = pokemon->getBaseStats();
    string* name = pokemon->getName();
    unsigned short* ev = pokemon->getEv();
    unsigned char hp = pokemon->getHp();
    Pokemon *pokemon2 = new Pokemon(1, 3);
    /*delete pokemon2;*/
    unsigned char speed = pokemon->getSpeedStat();
    
    cout << *name << endl;
    cout << (int)(base_stats[2]) << endl;
    cout << (ev[2]) << endl;
    cout << (int)(hp) << endl;
    cout << (int)(speed) << endl;
    
    PokemonParty *party = new PokemonParty(new Pokemon(1, 3));
    Trainer *tanner = new Trainer("Tanner", party);
    Pokemon *pokedude = party->getParty()[0];
    cout << pokedude->getName() << endl;
    PokemonParty *p = tanner->getParty();
    
    Battle *battle = new Battle(tanner, tanner);
    Side * my_side = battle->getSides()[0];
    cout << my_side->getFighter()->getPokemon()->getName() << endl;;
}

