package pokemon;

/**
 *
 * @author evinstk
 */
public class Driver {
    public static void main(String[] args) {
        String[] moves = {"This one", "That one"};
        Pokemon bulbasaur = new Pokemon(1, 99, moves);
        System.out.println(bulbasaur);
        System.out.println(bulbasaur.getIV());
        System.out.println(bulbasaur.getEV());
        System.out.println(bulbasaur.getExp());
        System.out.println(bulbasaur.getStats());
    }
}
