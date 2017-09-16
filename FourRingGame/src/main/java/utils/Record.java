package utils;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

/**
 * Created by syang on 2017/3/21.
 */
public class Record {
  File record;
  FileWriter writer;

  public Record() {
    this.beginRecord();
  }

  private void beginRecord(){
    do {
      record = new File(getFileName());
    }while (record.exists());
    try {
      writer = new FileWriter(record);
    }catch (IOException ex){
      ex.printStackTrace();
    }
  }

  private String getRandomNumber(){
    int random = (int)(Math.random() * 100000);
    return  String.format("%05d", random);
  }
  private String getFileName(){
    return "四连环Log-" + getRandomNumber() + ".txt";
  }

  public void endRecord(){
    try {
      writer.close();
    }catch (IOException ex){
      ex.printStackTrace();
    }
  }

  public void write(String str){
    try {
      writer.write(str);
      writer.flush();
    }catch (IOException ex){
      ex.printStackTrace();
    }
  }
  public void writeln(String str){
    write(str + "\n");
  }
}