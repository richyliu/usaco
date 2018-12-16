import java.io.*;
import java.util.*;

public class Template {

  public static void main(String[] args) throws IOException {
    String fileName = "angry";
    // declare file readers
    File f = new File(fileName + ".out");
    if(!f.exists())
      f.createNewFile();
    BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
    PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));

    StringTokenizer st = new StringTokenizer(reader.readLine());
    int numHay = Integer.parseInt(st.nextToken());
    int numCows = Integer.parseInt(st.nextToken());
    ArrayList<Integer> hays = new ArrayList<Integer>();

    // input
    for (int i = 0; i < numHay; i++) {
      st = new StringTokenizer(reader.readLine());

      hays.add(Integer.parseInt(st.nextToken()));
    }
    System.out.println(hays);


    // save output
    System.out.println("Answer: " + answer);
    printer.write(answer + "\n");

    // closing
    reader.close();
    printer.close();
  }

}
