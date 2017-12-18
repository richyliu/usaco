

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Marathon {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("marathon.in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter("marathon.out")));
        
        
        // global vars
        int numPoints = Integer.parseInt(reader.readLine());
        int totalDist = 0;
        
        // best distance saved by removing a point
        int bestDist = 0;
        int[] curPoint = new int[2];
        int[] prevPoint1 = new int[2]; // last point
        int[] prevPoint2 = new int[2]; // 2nd last point
        int curDist = -1;
        int prevDist1 = -1;
        
        for (int i = 0; i < numPoints; i++) {
        	// get current point
        	StringTokenizer st = new StringTokenizer(reader.readLine());
        	
        	curPoint[0] = Integer.parseInt(st.nextToken());
        	curPoint[1] = Integer.parseInt(st.nextToken());
        	
        	
        	// calc total distance, starting from second point
        	if (i > 0) {
        		curDist =
        				Math.abs(curPoint[0] - prevPoint1[0]) + // x
    	        		Math.abs(curPoint[1] - prevPoint1[1]);  // y
	        	totalDist += curDist;
        	}
        	
        	
        	// calc best distance starting from thirt point
        	if (i > 1) {
        		int newBestDist;
            	
            	if ((
            			newBestDist = prevDist1 + curDist - (
            				Math.abs(curPoint[0] - prevPoint2[0]) + // x
            				Math.abs(curPoint[1] - prevPoint2[1])   // y
            			)
            		) > bestDist) {
            		bestDist = newBestDist;
            	}
        	}
        	
        	
        	// shift points and dists
        	prevPoint2 = prevPoint1.clone();
        	prevPoint1 = curPoint.clone();
        	prevDist1 = curDist;
        }
        
        
        // save output
        System.out.println(totalDist - bestDist);
        printer.write((totalDist - bestDist) + "\n");
        
        
        reader.close();
        printer.close();
	}
	
}
