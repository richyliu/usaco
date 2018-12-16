import java.io.*;
import java.util.*;

public class Convention {

  public static void main(String[] args) throws IOException {
    String fileName = "convention";
    // declare file readers
    File f = new File(fileName + ".out");
    if(!f.exists())
      f.createNewFile();
    BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
    PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));

    StringTokenizer st = new StringTokenizer(reader.readLine());
    int numCows = Integer.parseInt(st.nextToken());
    int numBuses = Integer.parseInt(st.nextToken());
    int maxCowPerBus = Integer.parseInt(st.nextToken());
    ArrayList<Integer> cows = new ArrayList<Integer>();

    // input
    st = new StringTokenizer(reader.readLine());
    for (int i = 0; i < numCows; i++) {
      cows.add(Integer.parseInt(st.nextToken()));
    }
    Collections.sort(cows);
    System.out.println(cows);

    // calc differences
    ArrayList<Integer> diffs = new ArrayList<Integer>();
    for (int i = 0; i < numCows-1; i++) {
      diffs.add(cows.get(i+1) - cows.get(i));
    }
    Collections.sort(diffs);
    Collections.reverse(diffs);
    for (int i = 0; i < diffs.size() - 1; i++) {
      if (diffs.get(i) == diffs.get(i + 1)) {
        diffs.remove(i);
        i--;
      }
    }
    System.out.println(diffs);

    int minWait = 10000000;
    for (int outer = 0; outer < diffs.size(); outer++) {
      int max = diffs.get(outer);
      // index of start
      int start = 0;
      int curWait = -1;
      int usedBuses = 0;
      boolean exit = false;
      int maxWait = -1;
      for (int i = 1; i < numCows; i++) {
        curWait = cows.get(i) - cows.get(start);
        System.out.println("i: " + i + " start: " + start);
        if (i - start > maxCowPerBus || curWait > max) {
          System.out.println("foo" + curWait + " > " + max);
          // somethign
          start = i;
          usedBuses++;
          if (curWait > maxWait) {
            System.out.println("here: " + curWait);
            maxWait = curWait;
          }
        }
        if (usedBuses > numBuses && i < numCows) {
          System.out.println("used too much: " + usedBuses);
          System.out.println("used too much (answ): " + diffs.get(outer-1));
          minWait = diffs.get(outer-1);
          exit = true;
          break;
        }
      }
      if (exit) break;
      System.out.println("not good " + curWait);
      System.out.println("not good2 " + maxWait);
      minWait = curWait;
    }

    // save output
    System.out.println("out: " + minWait);
    printer.write(minWait + "\n");

    // closing
    reader.close();
    printer.close();
  }

}
