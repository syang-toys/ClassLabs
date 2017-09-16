package ai;

/**
 * Created by syang on 2017/3/20.
 */
public class RandomAI implements NaiveAI {
  @Override
  public int doAction(){
    return (int) (Math.random() * 8);
  }

  @Override
  public String speak(int i) {
    String words = "轮到我啦，这是第" + i + "轮，我把O棋子放在";
    System.out.print(words);
    return words;
  }
}