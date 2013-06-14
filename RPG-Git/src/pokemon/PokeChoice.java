package pokemon;

/**
 *
 * @author evinstk
 */
public class PokeChoice implements BattleChoice {
    private int next_pokemon;
    
    public PokeChoice(int next_pokemon) {
        this.next_pokemon = next_pokemon;
    }
    
    @Override
    public int getPriority() {
        return 6;
    }
    
    @Override
    public void execute(Battle battle, int executor, int defender) {
        battle.setFighter(executor, next_pokemon);
    }
}
