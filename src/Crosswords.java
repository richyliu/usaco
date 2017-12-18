
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Crosswords {

	public static void main(String[] args) throws IOException {
		String fileName = "crosswords";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        ArrayList<String> lines = new ArrayList<String>();
        // sometimes it's helpful to have first item seperated
        String firstLine = reader.readLine();
        int height = Integer.parseInt(firstLine.split(" ")[0]);
        int width = Integer.parseInt(firstLine.split(" ")[1]);
        
        // input
        String line;
        while((line = reader.readLine()) != null) {
        	lines.add(line);
        }
        System.out.println(lines);
        System.out.println(height + ", " + width);
        
        
        // true means it is blocked
        boolean[][] grid = new boolean[height][width]; 
        for (int i = 0; i < height; i++) {
        	for (int j = 0; j < width; j++) {
        		grid[i][j] = lines.get(i).charAt(j) == '#';
        	}
        }
        System.out.println(Arrays.deepToString(grid));
        
        
        ArrayList<List<Integer>> results = new ArrayList<List<Integer>>();
        
        for (int i = 0; i < height; i++) {
        	for (int j = 0; j < width; j++) {
        		// ignore filled squares
        		if (grid[i][j]) continue;
        		
        		// horizontal check for empty (don't check last 2 boxes)
        		if (j < width - 2) {
        			// if edge
        			if (j == 0) {
        				// and right 2 are empty
        				if (!grid[i][j+1] && !grid[i][j+2]) {
        					results.add(Arrays.asList(i, j));
        					continue;
        				}
        			// otherwise if left fill and right 2 are empty
        			} else if (grid[i][j-1] && !grid[i][j+1] && !grid[i][j+2]) {
        				results.add(Arrays.asList(i, j));
    					continue;
        			}
        		}
        		
        		// verical check for empty (don't check last 2 boxes)
        		if (i < height - 2) {
        			// if edge
        			if (i == 0) {
        				// and down 2 are empty
        				if (!grid[i+1][j] && !grid[i+2][j])
        					results.add(Arrays.asList(i, j));
    					continue;
        			// otherwise if left fill and down 2 are empty
        			} else if (grid[i-1][j] && !grid[i+1][j] && !grid[i+2][j]) {
        				results.add(Arrays.asList(i, j));
    					continue;
        			}
        		}
        	}
        }
        System.out.println(results);
        
        
        // return string
        String ret = results.size() + "\n";
        for (List<Integer> list : results) {
        	ret += (list.get(0)+1) + " " + (list.get(1)+1) + "\n";
        }
        System.out.println(ret);
        printer.write(ret);
        
        
        // closing
        reader.close();
        printer.close();
	}

}
