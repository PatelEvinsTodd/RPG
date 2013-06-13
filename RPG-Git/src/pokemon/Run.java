package pokemon;

import java.util.Random;

/**
 *
 * @author evinstk
 */
public class Run implements BattleChoice {
    @Override
    public int getPriority() {
        return 6;
    }
    
    @Override
    public void execute(Battle battle, int executor, int defender) {
        battle.addEscapeCount(executor);
        
        float exec_speed = battle.getFighter(executor).getStats().get("speed");
        float def_speed = battle.getFighter(defender).getStats().get("speed") / 4;
        float count = battle.getEscapeCount(executor);
        
        float probability = (exec_speed * 32 / def_speed) + (30 * count);
        
        if (new Random().nextInt(256) < probability) {
            battle.endBattle();
        }
    }
}
