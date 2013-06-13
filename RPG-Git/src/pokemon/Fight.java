package pokemon;

/**
 *
 * @author evinstk
 */
public class Fight implements BattleChoice {
    private Move move;
    private int priority;

    public Fight(Move move) {
        this.move = move;
        if (move.getName().equals("Quick Attack")) {
            priority = 1;
        }
        if (move.getName().equals("Counter")) {
            priority = -5;
        }
        priority = 0;
    }

    @Override
    public int getPriority() {
        return priority;
    }

    @Override
    public void execute(Battle battle, int executor, int defender) {
        move.use(battle.getFighter(executor), battle.getAccuracy(executor),
                    battle.getFighter(defender), battle.getEvade(defender));
    }
}
