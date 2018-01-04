/*
ID: richy.l1
LANG: JAVA
TASK: beads
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

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
        String beads = reader.readLine();
        
        
        System.out.println(numBeads);
        System.out.println(beads);
        
        // double the beads to allow wraparound
        beads += beads;
        
        int longestBeads = 0;
        int longestMid = 0;
        
        int start = 0;
        int mid = 0;
        int end = 0;
        boolean lastRed = beads.charAt(numBeads-1) == 114;
        boolean curRed = false;
        
        for (int i = 0; i < numBeads*2; i++) {
        	if (beads.charAt(i) == 114) curRed = true;
        	else if (beads.charAt(i) == 98) curRed = false;
        	else if (beads.charAt(i) == 119) continue;
        	
        	// beads switch color
        	if (lastRed != curRed) {
        		start = mid;
        		mid = end;
        		end = i;
        	}
        	// longest so far?
        	if (end - start > longestBeads) {
        		longestBeads = end - start;
        		longestMid = mid;
        		System.out.println(start + ", " + mid + ", " + end + ", " + longestBeads);
        	}
        	lastRed = curRed;
        	System.out.println(start + ", " + mid + ", " + end + "; " + longestMid + ", " + longestBeads);
        }
        
        
        // save output
        printer.write(longestBeads + "\n");
        
        // closing
        reader.close();
        printer.close();
	}

}
