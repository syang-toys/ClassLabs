package player;

import ai.RandomAI;

/**
 * Created by syang on 2017/3/21.
 */
public class ComputerPlayer extends NaivePlayer {

  public ComputerPlayer(){
    super(new RandomAI(), 'O');
  }

  @Override
  public int doAction(){
    return this.AI.doAction();
  }

  public String hello(){
    String hello = "Hi,我是劳拉，我们来玩一局四连环，我用O型棋子，你用X型棋子。";
    System.out.println(hello);
    return hello;
  }
}
