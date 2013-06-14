package pokemon;

import java.util.Map;
import java.util.Random;

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
    public void execute(Battle battle, int executor, int defender_index) {
        move.decreasePp();
        Category category = move.getCategory();
        if (category == category.STATUS) {
            //Do status logic here
            return;
        }
        Random rand = new Random();
        Pokemon attacker = battle.getFighter(executor);
        Pokemon defender = battle.getFighter(defender_index);
        Map<String, Integer> attacker_stats = attacker.getStats();
        Map<String, Integer> defender_stats = defender.getStats();
        int attack;
        int defense;
        if (category == category.PHYSICAL) {
            attack = attacker_stats.get("attack");
            defense = defender_stats.get("defense");
        }
        else {
            attack = attacker_stats.get("special");
            defense = defender_stats.get("special");
        }
        int power = move.getPower();
        int move_accuracy = move.getAccuracy();
        int accuracy = battle.getAccuracy(executor);
        int evade = battle.getAccuracy(defender_index);
        Status status = attacker.getStatus();
        int level = attacker.getLevel();
        boolean high_cr_ratio = move.getCrRatio();
        int cr_denominator;
        if (high_cr_ratio) {
            cr_denominator = 64;
        } else {
            cr_denominator = 512;
        }
        float probability = (float) (attacker.getStats().get("speed")) / cr_denominator;
        int critical_hit;
        if (rand.nextFloat() <= probability) {
            critical_hit = 2;
        }
        else {
            critical_hit = 1;
        }
        float multiplier = getMultiplier(attacker.getTypes(), defender.getTypes());
        int random = (rand.nextInt(256 - 217) + 217);
        int damage_dealt = (int) (((((((float)(level) * 0.4f * (float)(critical_hit)) + 2f) * (float)(attack) * (float)(power) / 50f / (float)(defense)) + 2f) * multiplier * (float)(random)) / 255f);
        if (status.equals(Status.BURN)) {
            int damageTaken = attacker_stats.get("hp") / 16;
            damage_dealt /= 2;
            attacker.takeDamage(1);
        }
        float hit_or_miss = (float) (move_accuracy) * (float) (accuracy) / (float) (evade) / 100f;
        if (rand.nextFloat() <= hit_or_miss) {
            defender.takeDamage(damage_dealt);
        }
    }

    private float getMultiplier(Type[] attacker_types, Type[] defense) {
        float ret = 1f;
        Type type = move.getType();
        
        if (attacker_types[0] == type || attacker_types[1] == type) {
            ret *= 1.5f;
        }
        ret *= TypeTable.lookup(type, defense[0]);
        ret *= TypeTable.lookup(type, defense[1]);
        return ret;
    }
    
    private void accountStatus(Pokemon attacker) {
        Status status_ailment = attacker.getStatus();
        
        if (status_ailment.equals(Status.BURN)) {
            
        }
    }
}
