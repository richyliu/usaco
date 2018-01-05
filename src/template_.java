/*
ID: richy.l1
LANG: JAVA
TASK: INSERT_NAME
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class template {

	public static void main(String[] args) throws IOException {
		String fileName = "INSERT_NAME";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        // sometimes it's helpful to have first item seperated
        int firstItem = Integer.parseInt(reader.readLine());
        // length of input to read
        int len = 0;
        // length of each item
        int itemLength = 2;
        int[][] lines = new int[len][itemLength];
        
        // input
        for (int i = 0; i < len; i++) {
        	StringTokenizer st = new StringTokenizer(reader.readLine());
        	
        	lines[i][0] = Integer.parseInt(st.nextToken());
        	lines[1][1] = Integer.parseInt(st.nextToken());
        }
        System.out.println(Arrays.deepToString(lines));
        System.out.println(firstItem);
        
        
        // lines is available for use
        
        
        // save output
//        printer.write(output + "\n");
        
        // closing
        reader.close();
        printer.close();
	}

}
