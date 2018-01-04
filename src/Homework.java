

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Homework {

	public static void main(String[] args) throws IOException {
		String fileName = "homework";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        int numScores = Integer.parseInt(reader.readLine());
        short[] scores = new short[numScores];
        
        float avg = 0;
        
        
        // input
        StringTokenizer st = new StringTokenizer(reader.readLine());
        short curIn = -1;
        
        for (int i = 0; i < numScores; i++) {
        	curIn = Short.parseShort(st.nextToken());
        	scores[i] = curIn;
        }
        
        System.out.println("numScores: " + numScores);
        System.out.println(Arrays.toString(scores));
        System.out.println();
        
        int oldLowIndex = 0;
        int lowestIndex = 0;
        float overallBestScore = -1;
        ArrayList<Integer> overallBestIndex = new ArrayList<Integer>(); 
        overallBestIndex.add(0);
        
        
        while(lowestIndex < numScores) {
	        // find lowest
        	// find avg
	        avg = 0;
	        for (int i = oldLowIndex; i < numScores; i++) {
	        	if (scores[i] < scores[lowestIndex]) {
	        		lowestIndex = i;
	        	}
	        	avg += scores[i];
	        }
	        System.out.println("lowestIndex: " + lowestIndex);
	        System.out.println("oldLowIndex: " + oldLowIndex);
	        
	        
	        if (oldLowIndex == lowestIndex) {
	        	avg = scores[oldLowIndex];
	        } else {
		        avg /= (numScores-oldLowIndex);
		        // subtract lowest
		        avg = (avg - scores[lowestIndex]/(float)(numScores-oldLowIndex)) * ((numScores-oldLowIndex)/(numScores-oldLowIndex-1.0f));
	        }
	        System.out.println("avg: " + avg);
	        
	        
	        // loop until hit lowestIndex
	        float bestScore = avg;
	        int bestScoreIndex = oldLowIndex;
	        float curAvg = avg;
	        
	        for (int i = oldLowIndex, l = (numScores-oldLowIndex-1); i < lowestIndex; i++, l--) {
	        	curAvg = (curAvg - scores[i]/(float)l) * (l/(l-1.0f));
	        	System.out.println(curAvg);
	        	
	        	// K has to be <= N-2
	        	if (bestScore < curAvg && i <= numScores-3) {
	        		bestScore = curAvg;
	        		bestScoreIndex = i+1;
	        	}
	        }
	        // nothing beat bestScoreIndex
//	        if (bestScoreIndex == oldLowIndex) {
//	        	bestScoreIndex--;
//	        }
	        
	        // check overall
	        if (overallBestScore < bestScore) {
	        	overallBestScore = bestScore;
	        	overallBestIndex.clear();
	        	overallBestIndex.add(bestScoreIndex);
	        } else if (overallBestScore == bestScore) {
	        	overallBestIndex.add(bestScoreIndex);
	        }
	        
	        System.out.println("bestScore: " + bestScore);
	        System.out.println("bestScoreIndex: " + bestScoreIndex);
	        System.out.println();

	        // increment to avoid checking twice
	        if (lowestIndex > numScores - 3) break;
	        
	        lowestIndex++;
	        oldLowIndex = lowestIndex;
        }
//        overallBestIndex++;
        
        System.out.println("final answer: " + overallBestIndex);
        
        for (int ind : overallBestIndex) {
        	printer.write(ind + "\n");        	
        }
        
        
        
        // closing
        reader.close();
        printer.close();
	}

}
