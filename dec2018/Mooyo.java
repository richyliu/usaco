import java.io.*;
import java.util.*;

public class Mooyo {

  public static void main(String[] args) throws IOException {
    String fileName = "mooyo";
    // declare file readers
    File f = new File(fileName + ".out");
    if(!f.exists())
      f.createNewFile();
    BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
    PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));

    StringTokenizer st = new StringTokenizer(reader.readLine());
    int numRows = Integer.parseInt(st.nextToken());
    int contig = Integer.parseInt(st.nextToken());
    int[][] board = new int[numRows][10];

    // input
    for (int i = 0; i < numRows; i++) {
      String line = reader.readLine();

      for (int j = 0; j < 10; j++) {
        board[i][j] = Integer.parseInt(line.charAt(j) + "");
      }
    }
    for (int i = 0; i < board.length; i++) {
      for (int j = 0; j < 10; j++) {
        System.out.print(board[i][j]);
      }
      System.out.println();
    }


    // save output
    // System.out.println("Answer: " + answer);
    // printer.write(answer + "\n");

    // closing
    reader.close();
    printer.close();
  }

}
