#include "trainer.h"
#include <string>

Trainer::Trainer(string name, PokemonParty* party) {
    this->name = name;
    this->party = party;
}

PokemonParty *Trainer::getParty() {
    return party;
}
