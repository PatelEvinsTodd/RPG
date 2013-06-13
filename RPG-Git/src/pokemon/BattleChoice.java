/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pokemon;

/**
 *
 * @author tanner
 */
public interface BattleChoice {
    public int getPriority();
    public void execute(Battle battle, int executor, int defender);
}
