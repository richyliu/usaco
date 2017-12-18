import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Shuffle {

	public static void main(String[] args) throws IOException {
		String fileName = "shuffle";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        
        int numCows = Integer.parseInt(reader.readLine());
        int[] cows = new int[numCows];
        
        // input
        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < numCows; i++) {
        	cows[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(numCows);
        System.out.println(Arrays.toString(cows));
        
        
        // true if 
        
        
        // save output
        printer.write("3\n");
        
        // closing
        reader.close();
        printer.close();
	}

}
