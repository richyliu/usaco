/*
ID: richy.l1
LANG: JAVA
TASK: gift1
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

public class gift1 {

	public static void main(String[] args) throws IOException {
		String fileName = "gift1";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        int numPeople = Integer.parseInt(reader.readLine());
        String[] people = new String[numPeople];
        // total amount each person has
        int[] money = new int[numPeople];
        
        
        // get names of people first
        for (int i = 0; i < numPeople; i++) {
        	people[i] = reader.readLine();
        }
        
        // update everyone's money 
        for (int i = 0; i < numPeople; i++) {
        	int index = java.util.Arrays.asList(people).indexOf(reader.readLine());
        	
        	StringTokenizer st = new StringTokenizer(reader.readLine());
        	// how much this person is giving to everyone
        	int given = Integer.parseInt(st.nextToken());
        	// between how many people is this money split between
        	int numSplit = Integer.parseInt(st.nextToken());
        	
        	// how much each person gets
        	int each = 0;
        	int leftover = 0;
        	if (given != 0 && numSplit != 0) {
        		each = given / numSplit;
        		leftover = given % numSplit;
        	} else if (numSplit == 0) {
        		leftover = given;
        	}
    		 
        	
        	money[index] -= given - leftover;
        	
        	for (int j = 0; j < numSplit; j++) {
        		index = java.util.Arrays.asList(people).indexOf(reader.readLine());
        		money[index] += each;
        	}
        	System.out.println(Arrays.toString(money));
        }
        System.out.println(numPeople);
        System.out.println(Arrays.toString(people));
        System.out.println(Arrays.toString(money));
        
        
        // save output
        for (int i = 0; i < numPeople; i++) {
        	printer.write(people[i] + " " + money[i] + "\n");	
        }
        
        
        // closing
        reader.close();
        printer.close();
	}

}
