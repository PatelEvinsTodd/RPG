package pokemon;

import java.util.HashMap;
import java.util.Map;

/**
 * Battle class. GUI interfaces with instance of this class to handle Pokemon
 * battles.
 * 
 * @author evinstk
 */
public class Battle {
    private Side[] sides;
    
    class Side {
        public Trainer trainer;
        public Pokemon fighter;
        public int evade;
        public int accuracy;
        public BattleChoice choice;
        int priority;
        int escape_count;
        Map<Pokemon, Integer[]> cache;
        
        Side (Trainer trainer) {
            this.trainer = trainer;
            fighter = trainer.getPokemon().get(0);
            evade = 100;
            accuracy = 100;
            choice = null;
            priority = 0;
            escape_count = 0;
            cache = new HashMap<Pokemon, Integer[]>();
        }
    }
    
    Battle(Trainer trainer1, Trainer trainer2) {
        sides = new Side[2];
        sides[0] = new Side(trainer1);
        sides[1] = new Side(trainer2);
    }
    
    public void choose(BattleChoice choice, Trainer trainer) {
        if (sides[0].trainer == trainer) {
            sides[0].choice = choice;
            sides[0].priority = sides[0].choice.getPriority();
        }
        else {
            sides[1].choice = choice;
            sides[1].priority = sides[1].choice.getPriority();
        }
        if ((!(sides[0].choice == null)) && (!(sides[1].choice == null))) {
            executeTurn();
        }
    }
    
    public void executeTurn() {
        if (sides[0].priority > sides[1].priority) {
            sides[0].choice.execute(this, 0, 1);
            sides[1].choice.execute(this, 1, 0);
        }
        if (sides[1].priority > sides[0].priority) {
            sides[1].choice.execute(this, 1, 0);
            sides[0].choice.execute(this, 0, 1);
        }
        if (sides[1].fighter.getStats().get("speed") > sides[0].fighter.getStats().get("speed")) {
            sides[1].choice.execute(this, 1, 0);
            sides[0].choice.execute(this, 0, 1);
        }
        else {
            sides[0].choice.execute(this, 0, 1);
            sides[1].choice.execute(this, 1, 0);
        }
    }
    
    public Pokemon getFighter(int index) {
        return sides[index].fighter;
    }
    
    public int getAccuracy(int index) {
        return sides[index].accuracy;
    }
    
    public int getEvade(int index) {
        return sides[index].evade;
    }
    
    public int getEscapeCount(int index) {
        return sides[index].escape_count;
    }
    
    public void addEscapeCount(int index) {
        sides[index].escape_count++;
    }
    
    public void setFighter(int side_index, int fighter_index) {
        sides[side_index].fighter = sides[side_index].trainer.getPokemon().get(fighter_index);
    }
    
    public void endBattle() {
        sides[0] = null;
        sides[1] = null;
    }
}
