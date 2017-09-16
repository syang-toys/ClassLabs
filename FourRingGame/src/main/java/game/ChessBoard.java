package game;

import game.piece.BasePiece;
import game.piece.PieceFactory;

/**
 * Created by syang on 2017/3/20.
 */
public class ChessBoard {
  private BasePiece pieces[][];
  private PieceFactory pieceFactory;

  ChessBoard() {
    pieces = new BasePiece[6][8];
    pieceFactory = PieceFactory.getInstance();
  }

  private boolean inBoard(int col){
    return  col >=0 && col <=7;
  }

  private boolean inBoard(int col, int raw){
    return col >=0 && col <=7 && raw >=0 && raw <=5;
  }

  private int isLegalPosition(int col){
    if (!this.inBoard(col)) return -1;
    for (int i = 5; i >=0; i--){
      if (pieces[i][col] == null){
        return i;
      }
    }
    return -1;
  }

  public int putPiece(int col, Character player){
    int ret = isLegalPosition(col);
    if (ret != -1){
      pieces[ret][col] = pieceFactory.getPieceObject(player);
    }
    return ret;
  }

  public int getWinner(int col, int raw){
    String piece = pieces[raw][col].toString();
    if (checkLineH(piece, raw, col) || checkLineV(piece, raw, col) || checkLineOD(piece, raw, col) || checkLineOU(piece, raw, col)){
      if (piece.equals("O")) return 1;
      if (piece.equals("X")) return 2;
    }
    return 0;
  }

  private boolean checkLineV(String piece, int raw, int col){
    return checkLine(piece, raw, col, 0, 1);
  }

  private boolean checkLineH(String piece, int raw, int col){
    return checkLine(piece, raw, col,1, 0);
  }

  private boolean checkLineOD(String piece, int raw, int col){
    return checkLine(piece, raw, col,1, 1);
  }

  private boolean checkLineOU(String piece, int raw, int col){
    return checkLine(piece, raw, col,1, -1);
  }

  private boolean checkLine(String piece, int raw, int col, int H, int V){
    int num = 0;
    if (checkLattice(col - H, raw - V, piece)){
      num += 1;
    }
    if (checkLattice(col + H, raw + V, piece)){
      num += 2;
    }

    switch (num){
      case 1:{
        return checkLattice(col - 2 * H, raw - 2 * V, piece) && checkLattice(col - 3 * H, raw - 3 * V, piece);
      }case 2:{
        return checkLattice(col + 2 * H ,raw + 2 * V, piece) && checkLattice(col + 3 * H, raw + 3 * V, piece);
      }case 3:{
        return checkLattice(col - 2 * H, raw - 2 * V, piece) || checkLattice(col + 2 * H, raw + 2 * V, piece);
      }default:{
        return false;
      }
    }
  }

  private boolean checkLattice(int col, int raw, String piece){
    if (!inBoard(col, raw)) return false;
    else if (pieces[raw][col] == null) return false;
    else if (!piece.equals(pieces[raw][col].toString())) return false;
    return true;
  }

  public String printChessBoard(){
    StringBuffer board = new StringBuffer();
    board.append(" 1 2 3 4 5 6 7 8 \n");
    board.append("-----------------\n");
    for (int i = 0; i < 6; i++){
      for (int j = 0; j < 8; j++){
        board.append("|");
        if(pieces[i][j] != null){
          board.append(pieces[i][j].toString());
        }else {
          board.append(" ");
        }
      }
      board.append("|\n");
    }
    board.append("-----------------\n");

    System.out.println(board);
    return board.toString();
  }
}