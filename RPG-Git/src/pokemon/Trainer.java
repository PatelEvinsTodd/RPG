package pokemon;

import java.util.Arrays;
import java.util.List;

/**
 *
 * @author evinstk
 */
public abstract class Trainer {
    private String name;
    private List<Pokemon> pokemon;
    private Battle current_battle;
    private int battle_side_index;
    
    Trainer(String name, Pokemon[] pokemon) {
        this.name = name;
        this.pokemon = Arrays.asList(pokemon);
        current_battle = null;
        battle_side_index = 0;
    }
    
    List<Pokemon> getPokemon() {
        return pokemon;
    }
}
