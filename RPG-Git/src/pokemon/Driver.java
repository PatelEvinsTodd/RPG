package pokemon;

/**
 *
 * @author evinstk
 */
public class Driver {
    public static void main(String[] args) {
        String[] moves = {"This one", "That one"};
        Pokemon bulbasaur = new Pokemon(1, 54, moves);
        System.out.println(bulbasaur);
        System.out.println(bulbasaur.getIV());
        System.out.println(bulbasaur.getEV());
        System.out.println(TypeTable.lookup(Type.DRAGON, Type.BUG));
        System.out.println(bulbasaur.getExp());
        System.out.println("Tanner: " + bulbasaur.getStats());
        Pokemon rikeen_bulb = new Pokemon(1, 28, moves);
        System.out.println("Rikeen: " + rikeen_bulb.getStats());
        
        Pokemon[] poke_array1 = { bulbasaur };
        Pokemon[] poke_array2 = { rikeen_bulb };
        Player tanner = new Player("Tanner", poke_array1);
        Player rikeen = new Player("Rikeen", poke_array2);
        
        Battle battle = new Battle(tanner, rikeen);
        battle.choose(new Fight(bulbasaur.getMoves().get(0)), tanner);
        battle.choose(new Fight(rikeen_bulb.getMoves().get(0)), rikeen);
        System.out.println(bulbasaur.getHp());
        System.out.println(rikeen_bulb.getHp());
        battle.choose(new Fight(bulbasaur.getMoves().get(0)), tanner);
        battle.choose(new Fight(rikeen_bulb.getMoves().get(0)), rikeen);
        System.out.println(rikeen_bulb.getHp());
    }
}
