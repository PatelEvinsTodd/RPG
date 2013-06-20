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
#include "type.h"

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
    
    PokemonParty *party = new PokemonParty(pokemon);
    Trainer *tanner = new Trainer("Tanner", party);
    Pokemon *pokedude = party->getParty()[0];
    PokemonParty *p = tanner->getParty();
    
    Battle *battle = new Battle(tanner, tanner);
    Side * my_side = battle->getSides()[0];
    battle->setBattleChoice(new Fight(pokedude->getMove(0)), 0);
    battle->setBattleChoice(new Fight(pokedude->getMove(0)), 1);
    cout << "Before attack: " << (int)(hp) << endl;
    cout << "After hitting himself twice: " << (int)(pokedude->getHp()) << endl;
    
    cout << TypeTable::getModifier(NORMAL, GHOST) << endl;
}

