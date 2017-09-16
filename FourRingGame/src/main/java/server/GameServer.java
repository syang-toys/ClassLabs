package server;

import game.Controller;
import player.ComputerPlayer;
import player.GameClient;
import player.NaivePlayer;
import utils.Record;

/**
 * Created by syang on 2017/3/20.
 */
public class GameServer {
  private static NaivePlayer players[];
  private static Controller controller;
  private static Record record;

  public static void main(String[] args){
    System.out.println("Game Start!");
    players = new NaivePlayer[2];
    controller = new Controller();
    record = new Record();

    int random = (int)(Math.random() * 2);
    players[random] = new ComputerPlayer();
    players[1 - random] = new GameClient();

    int isWin = 0;
    int turn = 0;
    record.writeln(((ComputerPlayer)players[random]).hello());
    record.writeln(controller.speakRule());

    do {
      turn++;
      for(NaivePlayer player : players){
        record.write(player.speak(turn));
        isWin = controller.makePlayerDoAction(player);
        record.writeln(player.getLastPosition());
        record.writeln(controller.printChessBoard());
        if (isWin != 0){
          break;
        }
      }
      if (isWin != 0) {
        break;
      }
    } while (turn <= 24);

    if (isWin == 0){
      print("Draw!");
    }
    else if (isWin == 1) {
      print("Game Over!");
    }else if (isWin == 2){
      print("You Win!");
    }else {
      print("ERROR! Please tell ask me where bug is. Thanks!");
    }

    record.endRecord();
  }

  private static void print(String str){
    record.writeln(str);
    System.out.println(str);
  }
}
