package game.piece;

import java.util.Hashtable;

/**
 * Created by syang on 2017/3/20.
 */
public class PeiceFactory {
  private static PeiceFactory peiceFactory = new PeiceFactory();
  private final Hashtable<Character, BasePiece> cache = new Hashtable<Character, BasePiece>();

  private PeiceFactory(){
  }

  public static PeiceFactory getInstance(){
    return peiceFactory;
  }

  public BasePiece getPieceObject(Character c){
    BasePiece basePiece = this.cache.get(c);
    if (basePiece == null){
      switch (c){
        case 'O':{
          basePiece = new AIPiece();
          break;
        }
        case 'X':{
          basePiece = new HumanPiece();
          break;
        }
        default:{
          System.out.println("Piece Error!");
          break;
        }
      }
      if (basePiece != null){
        this.cache.put(c, basePiece);
      }
    }
    return basePiece;
  }
}
