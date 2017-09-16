package ai;

import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Created by syang on 2017/3/20.
 */
public class HumanAI implements NaiveAI {

  private Scanner reader;
  @Override
  public int doAction(){
    int ret = -1;
    do {
      try {
        reader = new Scanner(System.in);
        ret = reader.nextInt() - 1;
        break;
      } catch (InputMismatchException ex) {
        System.out.println("请输入正确列数！");
      }
    }while (true);
    return ret;
  }

  @Override
  public String speak(int i){
    String words = "这是第" + i + "轮， 玩家放X棋子，请选择列号(1-8): ";
    System.out.print(words);
    return words;
  }

}
