package game;

import player.NaivePlayer;

/**
 * Created by syang on 2017/3/24.
 */
public class Controller {
  private ChessBoard board;
  private NaivePlayer[] players;

  public Controller(){
    this(new ChessBoard());
  }

  Controller(ChessBoard board){
    this.board = board;
    players = new NaivePlayer[2];
  }

  public void setPlayers(NaivePlayer players1, NaivePlayer players2){
    this.players[0] = players1;
    this.players[1] = players2;
  }

  public int makePlayerDoAction(NaivePlayer player){
    int col, raw;
    do {
      col = player.doAction();
      if ((raw = putPiece(col, player.getPiece())) != -1){
        player.setLastPosition(col);
        break;
      }
    }while (true);
    return board.getWinner(col, raw);
  }

  public int putPiece(int col, char piece){
    return this.board.putPiece(col, piece);
  }

  public String speakRule(){
    String rules = "游戏规则：双方轮流选择棋盘的列号放进自己的棋子,\n" +
      "若棋盘上由四颗相同型号的棋子在一行、一列或一条斜线上连接起来，" +
      "则使用该型号棋子的玩家就赢了\n";
    System.out.println(rules);
    return rules;
  }

  public String printChessBoard(){
    return this.board.printChessBoard();
  }
}
