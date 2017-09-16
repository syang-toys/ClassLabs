package game.piece;

/**
 * Created by syang on 2017/3/20.
 */
public abstract class BasePiece {
  protected String piece;
  protected int x;
  protected int y;

  public BasePiece(String piece){
    this.piece = piece;
  }

  public abstract void setPosition(int x, int y);

  public void show(){
    System.out.println(this.piece);
  }
}
