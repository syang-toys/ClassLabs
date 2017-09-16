package player;

import ai.HumanAI;

/**
 * Created by syang on 2017/3/20.
 */
public class GameClient extends NaivePlayer{

  public GameClient(){
    super(new HumanAI(), 'X');
  }

  @Override
  public int doAction(){
    return this.AI.doAction();
  }

}
