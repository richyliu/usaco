/*
ID: richy.l1
LANG: JAVA
TASK: milk2
*/

import java.io.*;
import java.util.*;

public class milk2 {

  public static void main(String[] args) throws IOException {
    String fileName = "milk2";
    // declare file readers
    File f = new File(fileName + ".out");
    if(!f.exists())
      f.createNewFile();
    BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
    PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));

    int numCows = Integer.parseInt(reader.readLine());
    int[][] cows = new int[numCows][2];

    for (int i = 0; i < numCows; i++) {
      String[] line = reader.readLine().split(" ");
      cows[i] = new int[]{ Integer.parseInt(line[0]), Integer.parseInt(line[1]) };
    }
    Arrays.sort(cows, new Comparator<int[]>() {
      public int compare(int[] a, int[] b) {
        return Integer.compare(a[0], b[0]);
      }
    });

    System.out.println("[");
    for(int[] c : cows) {
      System.out.println("  [" + c[0] + ", " + c[1] + "],");
    }
    System.out.println("]");

    int latestNoMilk = cows[0][1];
    int firstIsMilk = cows[0][0];
    int noMilk = 0;
    int isMilk = 0;

    for (int i = 0; i < numCows; i++) {
      if(cows[i][0] > latestNoMilk) {
        int milkLen = latestNoMilk - firstIsMilk;
        if (milkLen > isMilk) isMilk = milkLen;
        firstIsMilk = cows[i][0];

        int len = cows[i][0] - latestNoMilk;
        if (len > noMilk) noMilk = len;
      }
      if (cows[i][1] > latestNoMilk) latestNoMilk = cows[i][1];
    }
    int milkLen = latestNoMilk - firstIsMilk;
    if (milkLen > isMilk) isMilk = milkLen;

    System.out.println("answer: " + isMilk + " " + noMilk);
    // save output
    printer.println(isMilk + " " + noMilk);

    // closing
    reader.close();
    printer.close();
  }

}
