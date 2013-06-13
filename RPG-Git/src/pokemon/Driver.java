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
        System.out.println(bulbasaur.getStats());
        
        Pokemon[] poke_array1 = { bulbasaur };
        Pokemon[] poke_array2 = { new Pokemon(1, 28, moves) };
        
        Battle battle = new Battle(new Player("Tanner", poke_array1), new Player("Rikeen", poke_array2));
    }
}
