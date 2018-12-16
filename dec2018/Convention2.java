import java.io.*;
import java.util.*;

public class Convention2 {

  public static void main(String[] args) throws IOException {
    String fileName = "convention2";
    // declare file readers
    File f = new File(fileName + ".out");
    if(!f.exists())
      f.createNewFile();
    BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
    PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));

    StringTokenizer st = new StringTokenizer(reader.readLine());
    int numCows = Integer.parseInt(st.nextToken());
    ArrayList<Cow> cows = new ArrayList<Cow>();

    // input
    for (int i = 0; i < numCows; i++) {
      st = new StringTokenizer(reader.readLine());

      cows.add(new Cow(
            Integer.parseInt(st.nextToken()),
            Integer.parseInt(st.nextToken()),
            i
            ));
    }
    // ArrayList<Cow> sortedCows = new ArrayList<Cow>(cows);
    Collections.sort(cows);
    System.out.println(cows);


    int maxWait = -1;
    int nextAvail = 0;
    // int on = 0;

    while (cows.size() > 0) {
      nextAvail = cows.get(0).arrival + cows.get(0).spend;
      cows.remove(0);
      System.out.println("outer");

      while(true) {
        if (0 == cows.size()) break;
        System.out.println("nextavail: " + nextAvail);
        System.out.println(cows);

        int highestSeniority = 0;
        for (int i = 0; i < cows.size(); i++) {
          if (cows.get(i).seniority < cows.get(highestSeniority).seniority) {
            highestSeniority = i;
          }
          if (cows.get(i).arrival > nextAvail) break;
        }
        if (cows.get(highestSeniority).arrival > nextAvail) break;

        int wait = nextAvail - cows.get(highestSeniority).arrival;
        if (wait > maxWait) maxWait = wait;
        System.out.println(maxWait);

        nextAvail += cows.get(highestSeniority).spend;
        cows.remove(highestSeniority);
      }
    }


    // save output
    System.out.println("Answer: " + maxWait);
    printer.write(maxWait + "\n");

    // closing
    reader.close();
    printer.close();
  }

}

class Cow implements Comparable<Cow> {
  public int arrival, spend, seniority;
  public Cow(int arrival, int spend, int seniority) {
    this.arrival = arrival;
    this.spend = spend;
    this.seniority = seniority;
  }
  public String toString() {
    return "Arrival: " + this.arrival + ", Spend: " + this.spend + " Seniority: " + this.seniority + "\n";
  }
  public int compareTo(Cow other) {
    return this.arrival - other.arrival;
  }
}
