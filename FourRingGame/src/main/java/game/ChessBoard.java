package game;

import game.piece.BasePiece;

/**
 * Created by syang on 2017/3/20.
 */
public class ChessBoard {
  private BasePiece pieces[][];

  ChessBoard(){
    pieces = new BasePiece[6][8];
  }

  public boolean inBoard(int x, int y){
    return x >=0 && x <= 7 && y >=0 && y <=5;
  }


}
