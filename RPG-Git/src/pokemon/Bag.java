package pokemon;

/**
 *
 * @author evinstk
 */
public class Bag implements BattleChoice {
    Item item;
    
    @Override
    public int getPriority() {
        return 6;
    }
    
    @Override
    public void execute(Battle battle, int executor, int defender) {
        
    }
}
