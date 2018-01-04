/*
ID: richy.l1
LANG: JAVA
TASK: friday
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

public class friday {

	public static void main(String[] args) throws IOException {
		String fileName = "friday";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        int numYears = Integer.parseInt(reader.readLine());
        // number of times friday the 13th falls on each of the sun...sat days
        int[] count = new int[7];
        
        boolean leap = false;
        int curDay = 4; // dec 13th was a thursday
        for (int year = 1900; year < 1900 + numYears; year++) {
        	if (year % 400 == 0) leap = true;
        	else if (year % 100 == 0) leap = false;
        	else if (year % 4 == 0) leap = true;
        	else leap = false;
        	
        	for (int month = 0; month < 12; month++) {
        		// length of previous month
        		int length = 0;
        		if (month == 4 || month == 6 || month == 9 || month == 11)
        			length = 30;
        		else if (month == 2)
        			length = leap ? 29 : 28;
        		else
        			length = 31;
        		
        		curDay = (curDay + length) % 7;
        		count[curDay]++;
        	}
        }
        System.out.println(Arrays.toString(count));
        
        // save output
        for (int i = 0; i < count.length; i++) {
        	printer.write(count[i] + ((i == count.length - 1) ? "" : " "));
        }
        printer.write("\n");
        
        
        // closing
        reader.close();
        printer.close();
	}

}
