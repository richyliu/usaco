/*
ID: richy.l1
LANG: JAVA
TASK: ride
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Ride {

	public static void main(String[] args) throws IOException {
		String fileName = "ride";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        String comet, group; 
        
        // input
    	comet = reader.readLine();
    	group = reader.readLine();
        System.out.println(comet + ", " + group);
        
        
        // calc mods
        int cVal = 1;
        int gVal = 1;
        
        for (int i = 0; i < comet.length(); i++) {
        	cVal *= comet.charAt(i)-64;
        }
        for (int i = 0; i < group.length(); i++) {
        	gVal *= group.charAt(i)-64;
        }
        System.out.println(cVal + ", " + gVal);
        
        
        // output
        if (cVal % 47 == gVal % 47) {
        	printer.write("GO\n");
        } else {
        	printer.write("STAY\n");
        }
        
        
        // closing
        reader.close();
        printer.close();
	}

}

