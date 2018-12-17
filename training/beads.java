/*
ID: richy.l1
LANG: JAVA
TASK: beads
*/

import java.io.*;
import java.util.*;

public class beads {

  public static void main(String[] args) throws IOException {
    String fileName = "beads";
    // declare file readers
    File f = new File(fileName + ".out");
    if(!f.exists())
      f.createNewFile();
    BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
    PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));

    int numBeads = Integer.parseInt(reader.readLine());
    String beadsLine = reader.readLine();

    int[][] beads = new int[numBeads+1][2];
    beads[0] = new int[] {1, beadsLine.charAt(0)};
    int counter = 0;

    for (int i = 1; i < numBeads; i++) {
      char c = beadsLine.charAt(i);
      char p = beadsLine.charAt(i-1);
      if (c != p) {
        counter++;
        beads[counter] = new int[] {1, c};
      } else {
        beads[counter][0]++;
      }
    }
    counter++;
    System.out.println(counter);
    if (beads[counter-1][1] == beads[0][1]) {
      beads[counter] = beads[0];
      for (int i = 0; i < counter; i++) {
        beads[i] = beads[i+1];
      }
    }
    for (int i = 0; i < counter; i++) {
      System.out.println(beads[i][0] + ", " + beads[i][1]);
    }

    int max = 0;
    if (counter == 1) {
      counter = 0;
      max = beads[0][0];
    }
    for (int i = 0; i < counter; i++) {
      int bead = beads[i][1];
      int num = beads[i][0];
      int collected = 0;
      if (i > 0 && beads[i-1][1] == 'w') {
        collected = beads[i-1][0];
      }

      if (bead == 'r') {
        int j = i;
        System.out.println("coll: " + collected);
        for (; true; j++) {
          if (j == counter) {
            j = 0;
          }
          if (beads[j][1] == 'b') break;
          collected += beads[j][0];
        }
        System.out.println("coll: " + collected);
        for (; true; j++) {
          if (j == counter) {
            j = 0;
          }
          if (beads[j][1] == 'r' || j == i-1) break;
          collected += beads[j][0];
        }
        System.out.println("coll: " + collected);
      }
      if (bead == 'b') {
        int j = i;
        for (; true; j++) {
          if (j == counter) {
            j = 0;
          }
          if (beads[j][1] == 'r') break;
          collected += beads[j][0];
        }
        for (; true; j++) {
          if (j == counter) {
            j = 0;
          }
          if (beads[j][1] == 'b' || j == i-1) break;
          collected += beads[j][0];
        }
      }

      if (collected > max) max = collected;
      System.out.println(collected);
    }

    System.out.println("output: " + max);
    // save output
    printer.println(max);

    // closing
    reader.close();
    printer.close();
  }

}
