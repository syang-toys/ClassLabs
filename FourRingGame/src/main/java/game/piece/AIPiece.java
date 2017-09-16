package game.piece;

/**
 * Created by syang on 2017/3/20.
 */
public class AIPiece extends BasePiece {

  public AIPiece(){
    super("O");
  }

  @Override
  public void setPosition(int x, int y){
    this.x = x;
    this.y = y;
  }
}
