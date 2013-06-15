package pokemon.database;

import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import pokemon.Category;
import pokemon.Type;

/**
 *
 * @author evinstk
 */
public class Query {
    public static String getName(int index) {
        return "Bulbasaur";
    }
    
    public static Map<String, Short> getBaseStats(int index) {
        Map<String, Short> builder = new HashMap<String, Short>(5);
        
        //Dummy code. These are Bulbasaur's base stats.
        builder.put("HP", (short)45);
        builder.put("ATTACK", (short)49);
        builder.put("DEFENSE", (short)49);
        builder.put("SPEED", (short)45);
        builder.put("SPECIAL", (short)65);
        Map<String, Short> ret = Collections.unmodifiableMap(builder);
        return ret;
    }
    
    public static Type[] getType(int index) {
        //Dummy code
        Type [] ret = {Type.GRASS, Type.NO_TYPE};
        return ret;
    }
    
    public static String getExperienceGroup(String name) {
        return "MediumSlow";
    }
    
    public static Object[] getMoveData(int index) {
        Object[] ret = {1, "Pound", Type.NORMAL, Category.PHYSICAL, 35, 40, 100, false};
        return ret;
    }
}
