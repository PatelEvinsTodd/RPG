package pokemon;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Random;

/**
 * Pokemon class for all Pokemon types.
 * 
 * @author evinstk
 */
public class Pokemon {
    private static final int LEVEL_CAP = 100;
    private static final int EX_IV_MAX = 16;
    
    private final int index;
    private String name;
    private final Map<String, Short> base_stats;
    private final Map<String, Byte> iv;
    private Map<String, Integer> ev;
    int level;
    int exp;
    private List<Move> moves;
    final Type types[];
    final String experience_group;
    int hp;
    boolean fainted;
    Status status_ailment;
    
    /**
     * Constructs a Pokemon object according to name, level, and starting moves.
     * 
     * @param name name of the type of Pokemon to construct (e.g., "bulbasaur")
     * @param level level of the constructed Pokemon
     * @param move_names set of moves of the constructed Pokemon
     */
    public Pokemon(int index, int level, String[] move_names) {
        Random rand = new Random();
        HashMap<String, Byte> iv_builder = new HashMap<String, Byte>(4);
        String[] iv_keys = {"ATTACK", "DEFENSE", "SPEED", "SPECIAL"};
        String[] ev_keys = {"hp", "attack", "defense", "speed", "special"};

        this.index = index;
        
        name = pokemon.database.Query.getName(index);
        
        base_stats = pokemon.database.Query.getBaseStats(index);
        
        for (String key : iv_keys) {
            iv_builder.put(key, (byte)rand.nextInt(EX_IV_MAX));
            
        }
        byte iv_health = 0;
        //Simulates how health is determined in generation I games
        for (int i = 0; i < iv_builder.size(); i++) {
            byte[] adders = {8, 4, 2, 1};
            for (int j = 0; j < iv_keys.length; j++) {
                if (((String)iv_builder.keySet().toArray()[i] == iv_keys[j]) && 
                        (((byte)iv_builder.values().toArray()[i] % (byte)2) == 1)) {
                    iv_health += adders[j];
                }
            }
        }
        iv_builder.put("HP", iv_health);
        iv = Collections.unmodifiableMap(iv_builder);
        
        ev = new HashMap(5);
        for (String key : ev_keys) {
            ev.put(key, 0);
        }
        
        this.level = level;
        
        moves = new ArrayList<Move>(4);
        for (String move_name : move_names) {
            moves.add(new Move(1));
        }
        
        types = pokemon.database.Query.getType(index);
        
        experience_group = pokemon.database.Query.getExperienceGroup(name);
        
        initExp();
        
        hp = getStats().get("hp");
        
        fainted = false;
        
        status_ailment = Status.NORMAL;
    }
    
    public Map<String, Byte> getIV() {
        return iv;
    }
    
    public Map<String, Integer> getEV() {
        return ev;
    }
    
    public int getExp() {
        return exp;
    }
    
    /**
     * Initializes exp variable. Sets it to some value between the minimum
     * (inclusive) and maximum (exclusive) values for the current level.
     */
    private void initExp() {
        Random rand = new Random();
        exp = rand.nextInt(getMinExp(level + 1) - getMinExp(level)) + getMinExp(level);
    }
    
    /**
     * Takes a Pokemon level and returns minimum experience required to reach
     * it. The experience group is taken from the Pokemon's experience_group
     * variable.
     * 
     * @param level level to determine minimum experience for it
     * @return minimum experience required for the given level
     */
    private int getMinExp(int level){
        if (experience_group.equals("Fast")) {
            return ((4*((level)^3))/5);
        }
        else if (experience_group.equals("MediumFast")) {
            return ((level)^3);
        }
        else if (experience_group.equals("MediumSlow")) {
            return ((6/5)*((level)^3) - (15)*((level)^2) + (100)*(level) - 140);
        }
        else if (experience_group.equals("Slow")) {
            return (5*((level)^3)/4);
        }
        else {
            throw new Error("Unrecognized experience group");
        }
    }
    
    /**
     * Returns stats of the Pokemon. Stats are a function of base stats,
     * individual values, effort values, and level.
     * 
     * @return mapping of stat keys to values
     */
    public Map<String, Integer> getStats() {
        HashMap<String, Integer> ret = new HashMap<String, Integer>();
        
        Iterator iter = ev.keySet().iterator();
        while(iter.hasNext()) {
            String key = (String)iter.next();
            int value, m1, m2;
            if (key.equals("hp")) {
                m1 = 50;
                m2 = 10;
            }
            else {
                m1 = 0;
                m2 = 5;
            }
            value = (int) (((((iv.get(key.toUpperCase()) + base_stats.get(key.toUpperCase()) + (Math.sqrt(ev.get(key))/8) + m1) * level)/50) + m2));
            ret.put(key, value);
        }
        return ret;
    }
    
    /**
     * Returns current level of Pokemon. Needed outside of Pokemon object to
     * calculate damage.
     * 
     * @return Pokemon's level
     */
    public int getLevel() {
        return level;
    }
    
    /**
     * Returns type(s) of Pokemon. Needed for damage multiplier calculation.
     * 
     * @return Pokemon's types
     */
    public Type[] getTypes() {
        return types;
    }
    
    /**
     * Returns hp.
     * 
     * @return hp 
     */
    public int getHp() {
        return hp;
    }
    
    /**
     * Returns Pokemon's current moveset.
     * 
     * @return 
     */
    public List<Move> getMoves() {
        return moves;
    }
    
    /**
     * Reduces hp of Pokemon.
     * 
     * @param damage Damage dealt by attacking Pokemon 
     */
    public void takeDamage(int damage) {
        hp -= damage;
        if (hp <= 0) {
            hp = 0;
            fainted = true;
        }
    }
    
    public void gainExp(int exp) {
        this.exp = exp;
        checkLevelUp();
    }
    
    private void checkLevelUp() {
        if (exp >= getMinExp(level + 1)) {
            level++;
            checkLevelUp();
            return;
        }
        return;
    }
    
    public void setStatus(Status status_ailment) {
        this.status_ailment = status_ailment;
    }
    
    public Status getStatus() {
        return status_ailment;
    }
}
