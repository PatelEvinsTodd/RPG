package pokemon;

/**
 *
 * @author evinstk
 */
public class PokeChoice implements BattleChoice {
    @Override
    public int getPriority() {
        return 6;
    }
    
    @Override
    public void execute(Battle battle, int executor, int defender) {
        
    }
}
