package pokemon;

import java.util.HashMap;

/**
 *
 * @author evinstk
 */
public abstract class TypeTable {
    private final static float SUPER_EFFECTIVE = 2f;
    private final static float RESISTANT = 0.5f;
    private final static float IMMUNE = 0f;
    
    private final static HashMap<Type, HashMap<Type, Float>> table = initTable();
    
    private static HashMap<Type, HashMap<Type, Float>> initTable() {
        HashMap<Type, HashMap<Type, Float>> ret = new HashMap<Type, HashMap<Type, Float>>();
        
        //If attack is NORMAL
        HashMap<Type, Float> normal = new HashMap<Type, Float>();
        normal.put(Type.ROCK, RESISTANT);
        normal.put(Type.GHOST, IMMUNE);
        ret.put(Type.NORMAL, normal);
        
        //If attack is FIRE
        HashMap<Type, Float> fire = new HashMap<Type, Float>();
        fire.put(Type.FIRE, RESISTANT);
        fire.put(Type.WATER, RESISTANT);
        fire.put(Type.GRASS, SUPER_EFFECTIVE);
        fire.put(Type.ICE, SUPER_EFFECTIVE);
        fire.put(Type.BUG, SUPER_EFFECTIVE);
        fire.put(Type.ROCK, RESISTANT);
        fire.put(Type.DRAGON, RESISTANT);
        ret.put(Type.FIRE, fire);
        
        //If attack is WATER
        HashMap<Type, Float> water = new HashMap<Type, Float>();
        water.put(Type.FIRE, SUPER_EFFECTIVE);
        water.put(Type.WATER, RESISTANT);
        water.put(Type.GRASS, RESISTANT);
        water.put(Type.GROUND, SUPER_EFFECTIVE);
        water.put(Type.ROCK, SUPER_EFFECTIVE);
        water.put(Type.DRAGON, RESISTANT);
        ret.put(Type.WATER, water);
        
        //If attack is ELECTRIC
        HashMap<Type, Float> electric = new HashMap<Type, Float>();
        electric.put(Type.WATER, SUPER_EFFECTIVE);
        electric.put(Type.ELECTRIC, RESISTANT);
        electric.put(Type.GRASS, RESISTANT);
        electric.put(Type.GROUND, IMMUNE);
        electric.put(Type.FLYING, SUPER_EFFECTIVE);
        electric.put(Type.DRAGON, RESISTANT);
        ret.put(Type.ELECTRIC, electric);
        
        //If attack is GRASS
        HashMap<Type, Float> grass = new HashMap<Type, Float>();
        grass.put(Type.FIRE, RESISTANT);
        grass.put(Type.WATER, SUPER_EFFECTIVE);
        grass.put(Type.GRASS, RESISTANT);
        grass.put(Type.POISON, RESISTANT);
        grass.put(Type.GROUND, SUPER_EFFECTIVE);
        grass.put(Type.FLYING, RESISTANT);
        grass.put(Type.BUG, RESISTANT);
        grass.put(Type.ROCK, SUPER_EFFECTIVE);
        grass.put(Type.DRAGON, RESISTANT);
        ret.put(Type.GRASS, grass);
        
        //If attack is ICE
        HashMap<Type, Float> ice = new HashMap<Type, Float>();
        ice.put(Type.FIRE, RESISTANT);
        ice.put(Type.WATER, RESISTANT);
        ice.put(Type.GRASS, SUPER_EFFECTIVE);
        ice.put(Type.ICE, RESISTANT);
        ice.put(Type.GROUND, SUPER_EFFECTIVE);
        ice.put(Type.FLYING, SUPER_EFFECTIVE);
        ice.put(Type.DRAGON, SUPER_EFFECTIVE);
        ret.put(Type.ICE, ice);
        
        //If attack is FIGHTING
        HashMap<Type, Float> fighting = new HashMap<Type, Float>();
        fighting.put(Type.NORMAL, SUPER_EFFECTIVE);
        fighting.put(Type.ICE, SUPER_EFFECTIVE);
        fighting.put(Type.POISON, RESISTANT);
        fighting.put(Type.FLYING, RESISTANT);
        fighting.put(Type.PSYCHIC, RESISTANT);
        fighting.put(Type.BUG, RESISTANT);
        fighting.put(Type.ROCK, SUPER_EFFECTIVE);
        fighting.put(Type.GHOST, IMMUNE);
        ret.put(Type.FIGHTING, fighting);
        
        //If attack is POISON
        HashMap<Type, Float> poison = new HashMap<Type, Float>();
        poison.put(Type.GRASS, SUPER_EFFECTIVE);
        poison.put(Type.POISON, RESISTANT);
        poison.put(Type.GROUND, RESISTANT);
        poison.put(Type.ROCK, RESISTANT);
        poison.put(Type.GHOST, RESISTANT);
        ret.put(Type.POISON, poison);
        
        //If attack is GROUND
        HashMap<Type, Float> ground = new HashMap<Type, Float>();
        ground.put(Type.FIRE, SUPER_EFFECTIVE);
        ground.put(Type.ELECTRIC, SUPER_EFFECTIVE);
        ground.put(Type.GRASS, RESISTANT);
        ground.put(Type.POISON, SUPER_EFFECTIVE);
        ground.put(Type.FLYING, IMMUNE);
        ground.put(Type.BUG, RESISTANT);
        ground.put(Type.ROCK, SUPER_EFFECTIVE);
        
        //If attack is FLYING
        HashMap<Type, Float> flying = new HashMap<Type, Float>();
        flying.put(Type.ELECTRIC, RESISTANT);
        flying.put(Type.GRASS, SUPER_EFFECTIVE);
        flying.put(Type.FIGHTING, SUPER_EFFECTIVE);
        flying.put(Type.BUG, SUPER_EFFECTIVE);
        flying.put(Type.ROCK, RESISTANT);
        ret.put(Type.FLYING, flying);
        
        //If attack is PSYCHIC
        HashMap<Type, Float> psychic = new HashMap<Type, Float>();
        psychic.put(Type.FIGHTING, SUPER_EFFECTIVE);
        psychic.put(Type.POISON, SUPER_EFFECTIVE);
        psychic.put(Type.PSYCHIC, RESISTANT);
        ret.put(Type.PSYCHIC, psychic);
        
        //If attack is BUG
        HashMap<Type, Float> bug = new HashMap<Type, Float>();
        bug.put(Type.FIRE, RESISTANT);
        bug.put(Type.GRASS, SUPER_EFFECTIVE);
        bug.put(Type.FIGHTING, RESISTANT);
        bug.put(Type.POISON, RESISTANT);
        bug.put(Type.FLYING, RESISTANT);
        bug.put(Type.PSYCHIC, SUPER_EFFECTIVE);
        bug.put(Type.GHOST, RESISTANT);
        ret.put(Type.BUG, bug);
        
        //If attack is ROCK
        HashMap<Type, Float> rock = new HashMap<Type, Float>();
        rock.put(Type.FIRE, SUPER_EFFECTIVE);
        rock.put(Type.ICE, SUPER_EFFECTIVE);
        rock.put(Type.FIGHTING, RESISTANT);
        rock.put(Type.GROUND, RESISTANT);
        rock.put(Type.FLYING, SUPER_EFFECTIVE);
        rock.put(Type.BUG, SUPER_EFFECTIVE);
        ret.put(Type.ROCK, rock);
        
        //If attack is GHOST
        HashMap<Type, Float> ghost = new HashMap<Type, Float>();
        ghost.put(Type.NORMAL, IMMUNE);
        ghost.put(Type.PSYCHIC, SUPER_EFFECTIVE);
        ghost.put(Type.GHOST, SUPER_EFFECTIVE);
        ret.put(Type.GHOST, ghost);
        
        //If attack is DRAGON
        HashMap<Type, Float> dragon = new HashMap<Type, Float>();
        dragon.put(Type.DRAGON, SUPER_EFFECTIVE);
        ret.put(Type.DRAGON, dragon);
        
        return ret;
    }
    
    public static float lookup(Type attack, Type defense) throws NullPointerException {
        float ret;
        try {
            ret = table.get(attack).get(defense);
        }
        catch (NullPointerException e) {
            ret = 1;
        }
        return ret;
    }
}
