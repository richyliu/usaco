import java.util.*;
// import java.io.BufferedReader;
// import java.io.InputStreamReader;


public class ps_1138_a {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    List<Integer> sushies = new ArrayList<Integer>();

    int n = input.nextInt();

    int cur = 0;
    int curNum = 0;
    for (int i = 0; i < n; i++) {
      int c = input.nextInt();
      if (cur == 0) cur = c;
      if (c == cur) curNum++;
      else {
        sushies.add(curNum);
        cur = c;
        curNum = 1;
      }
    }
    sushies.add(curNum);

    if (sushies.size() == 1) {
      System.out.println(sushies.get(0));
      return;
    }

    int max = 0;
    for (int i = 0; i < sushies.size() - 1; i++) {
      int a = sushies.get(i);
      int b = sushies.get(i+1);
      int len = Math.min(a, b);
      if (len > max) max = len;
    }
    System.out.println(max*2);
  }
}
