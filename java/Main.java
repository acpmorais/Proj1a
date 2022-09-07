import java.util.Random;
import java.io.BufferedWriter;  
import java.io.FileWriter;
import java.io.IOException;

public class Main {

  public static void insertionSort(int array[]) {
    int size = array.length;

    for (int step = 1; step < size; step++) {
      int key = array[step];
      int j = step - 1;
      
      while (j >= 0 && key < array[j]) {
        array[j + 1] = array[j];
        --j;
      }
      array[j + 1] = key;
    }
  }
  
  public static void main(String[] args) {
    int [][]m = new int[1024][100];
    Random rnd = new Random();
    long time;

    try{
      BufferedWriter writer = new BufferedWriter(new FileWriter("tempo.txt"));
    
      for(int z=0; z<1024; z++){
  
        
        for(int i=0; i<1024; i++){
          for(int j=0; j<100; j++){
            m[i][j] = rnd.nextInt(1000);
          }
        }

        long start = System.currentTimeMillis(); 
        for(int i=0; i<1024; i++){
          insertionSort(m[i]);
        }
  
        long end = System.currentTimeMillis();
        time = end - start;
        writer.write(time + "\n");
      }
    writer.close();
    } catch (IOException e) {
      e.printStackTrace();
    }
    
  }
}