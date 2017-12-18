

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Piggyback {

	public static void main(String[] args) throws IOException {
		String fileName = "piggyback";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        StringTokenizer st1 = new StringTokenizer(reader.readLine());
    	
        // "energy"
    	int bessie = Integer.parseInt(st1.nextToken());
    	int elsie = Integer.parseInt(st1.nextToken());
    	int together = Integer.parseInt(st1.nextToken());
    	// N, the field they need to end at 
    	int endField = Integer.parseInt(st1.nextToken());
    	int numConnections = Integer.parseInt(st1.nextToken());
    	
    	// where bessie and elsie meet and travel together
    	int meetingPoint = -1;
    	int[][] connections = new int[numConnections][2];
    	
    	int[] bessieDists = new int[endField]; // item 1 and -1 are blank
    	int[] elsieDists = new int[endField]; // item 0 and -1 are blank
    	int[] endDists = new int[endField]; //item 0 and 1 are blank
        
    	
        // input
        for (int i = 0; i < numConnections; i++) {
        	StringTokenizer st = new StringTokenizer(reader.readLine());
        	
        	connections[i][0] = Integer.parseInt(st.nextToken());
        	connections[1][1] = Integer.parseInt(st.nextToken());
        }
        System.out.println(Arrays.deepToString(connections));
        System.out.println(bessie + ", " + elsie + ", " + together + ", " + endField);
        
        
        // calculate all dists
        for (int i = 0; i < bessieDists.length; i++) {
        	if (i == 1 || i == bessieDists.length-1) continue;
        	
        	
        }
        
        
        // try all values of meetingPoint, from 3 to N
        for (int i = 2; i < endField; i++) {
        	// try i
        }
        
        
        // closing
        reader.close();
        printer.close();
	}

}
