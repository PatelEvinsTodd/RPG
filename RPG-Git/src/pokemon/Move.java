package pokemon;

import java.util.Arrays;
import java.util.List;
import java.util.Random;

/**
 *
 * @author evinstk
 */
public class Move {
    private final static String[] CATEGORIES = {"Status", "Physical", "Special"};
    private final static int ACCURACY_MAX = 100;
    private final static int ACCURACY_MIN = 1;
    private final static float STAB = 1.5f;
    private int index;
    private String name;
    private Type type;
    private String category;
    private int pp;
    private int power;
    private int accuracy;
    private boolean high_cr_ratio;

    public Move(int index) {
        Object[] fetchedData = pokemon.database.Query.getMoveData(index);
        this.index = (int) fetchedData[0];
        name = (String) fetchedData[1];
        type = (Type) fetchedData[2];
        category = (String) fetchedData[3];
        pp = (int) fetchedData[4];
        power = (int) fetchedData[5];
        accuracy = (int) fetchedData[6];
        high_cr_ratio = (boolean) fetchedData[7];

        if ((accuracy > 100) || (accuracy < 1)) {
            throw new Error("Invalid move accuracy");
        }
        if (!Arrays.asList(CATEGORIES).contains(category)) {
            throw new Error("Invalid move category");
        }
    }

    public void use(Pokemon attacker, int accuracy, Pokemon defender, int evade) {
        pp--;
        
        if (category == "Status") {
            //Do status logic here
            return;
        }

        int attack;
        int defense;
        if (category == "Physical") {
            attack = attacker.getStats().get("attack");
            defense = defender.getStats().get("defense");
        }
        else {
            attack = attacker.getStats().get("special");
            defense = defender.getStats().get("special");
        }
        Random rand = new Random();
        int level = attacker.getLevel();
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

        float hit_or_miss = (float) (this.accuracy) * (float) (accuracy) / (float) (evade) / 100f;
        if (rand.nextFloat() <= hit_or_miss) {
            defender.takeDamage(damage_dealt);
            return;
        }
        else {
            return;
        }
    }
    
    private float getMultiplier(Type[] attacker_types, Type[] defense) {
        float ret = 1f;
        
        if (attacker_types[0] == type || attacker_types[1] == type) {
            ret *= 1.5f;
        }
        ret *= TypeTable.lookup(type, defense[0]);
        ret *= TypeTable.lookup(type, defense[1]);
        return ret;
    }
    
    public String getName() {
        return name;
    }
}
