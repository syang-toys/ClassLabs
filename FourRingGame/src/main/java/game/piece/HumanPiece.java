package game.piece;

/**
 * Created by syang on 2017/3/20.
 */
public class HumanPiece extends BasePiece {
  public HumanPiece(){
    super("X");
  }

  @Override
  public void setPosition(int x, int y){
    this.x = x;
    this.y = y;
  }
}
