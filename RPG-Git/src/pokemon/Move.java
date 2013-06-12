package pokemon;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;

/**
 *
 * @author evinstk
 */
public class Move {
    private final static String[] CATEGORIES = {"Status", "Physical", "Special"};
    private final static int ACCURACY_MAX = 100;
    private final static int ACCURACY_MIN = 1;
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

    public void use(Pokemon attacker, Pokemon defender) throws Exception {
        if (pp > 0) {
            pp--;
        } else {
            throw new Exception("No PP left!");
        }

        if (category == "Physical") {
            int level = attacker.getLevel();
            int cr_denominator;
            if (high_cr_ratio) {
                cr_denominator = 512;
            } else {
                cr_denominator = 64;
            }
            float probability = attacker.getStats().get("speed") / cr_denominator;
            int critical_hit;
            if (new Random().nextFloat() <= probability) {
                critical_hit = 2;
            }
            else {
                critical_hit = 1;
            }
            int attack = attacker.getStats().get("attack");
            int defense = defender.getStats().get("defense");
        }
    }
}
