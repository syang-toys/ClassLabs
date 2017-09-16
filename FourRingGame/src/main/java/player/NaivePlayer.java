package player;

import ai.NaiveAI;
import game.ChessBoard;

/**
 * Created by syang on 2017/3/21.
 */
public abstract class NaivePlayer{
  protected NaiveAI AI;
  private char piece;
  private int lastPosition;

  public NaivePlayer(NaiveAI AI, char piece){
    this.AI = AI;
    this.piece = piece;
  }

  public abstract int doAction();

  public String speak(int i){
    return AI.speak(i);
  }

  public char getPiece(){
    return this.piece;
  }

  public void setLastPosition(int i){
    this.lastPosition = i + 1;
  }

  public String getLastPosition(){
    String str = "第" + this.lastPosition + "列";
    System.out.println(str);
    return str;
  }

}
