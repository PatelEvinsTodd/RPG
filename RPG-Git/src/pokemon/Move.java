package pokemon;

import java.util.Arrays;

/**
 *
 * @author evinstk
 */
public class Move {
    private final static int ACCURACY_MAX = 100;
    private final static int ACCURACY_MIN = 1;
    private final static float STAB = 1.5f;
    private int index;
    private String name;
    private Type type;
    private Category category;
    private int pp;
    private int max_pp;
    private int power;
    private int accuracy;
    private boolean high_cr_ratio;

    public Move(int index) {
        Object[] fetchedData = pokemon.database.Query.getMoveData(index);
        this.index = (int) fetchedData[0];
        name = (String) fetchedData[1];
        type = (Type) fetchedData[2];
        category = (Category) fetchedData[3];
        pp = (int) fetchedData[4];
        max_pp = (int) fetchedData[4];
        power = (int) fetchedData[5];
        accuracy = (int) fetchedData[6];
        high_cr_ratio = (boolean) fetchedData[7];

        if ((accuracy > 100) || (accuracy < 1)) {
            throw new Error("Invalid move accuracy");
        }
    }
    
    public String getName() {
        return name;
    }
    
    public void decreasePp() {
        if (pp == 0) {
            return;
        }
        pp--;
    }
    
    public void resetPp() {
        pp = max_pp;
    }
    
    public Category getCategory() {
        return category;
    }
    
    public boolean getCrRatio() {
        return high_cr_ratio;
    }
    
    public int getPower() {
        return power;
    }
    
    public int getAccuracy() {
        return accuracy;
    }
    
    public Type getType() {
        return type;
    }
}
