import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.StringTokenizer;

public class Measurement {

	public static void main(String[] args) throws IOException {
		String fileName = "measurement";
		// declare file readers
		File f = new File(fileName + ".out");
        if(!f.exists())
            f.createNewFile();
		BufferedReader reader = new BufferedReader(new FileReader(fileName + ".in"));
        PrintWriter printer = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
        
        
        String line = reader.readLine();
        // num measurements
        int numMeas = Integer.parseInt(line.split(" ")[0]);
        long startMilk = Integer.parseInt(line.split(" ")[1]);
        
        long meas[][] = new long[numMeas][3];
        long curId = 0;
        int curMilk = 0;
        
        // input
        for (int i = 0; i < numMeas; i++) {
        	StringTokenizer st = new StringTokenizer(reader.readLine());
        	
        	meas[i][0] = Long.parseLong(st.nextToken());
        	meas[i][1] = Long.parseLong(st.nextToken());
        	meas[i][2] = Long.parseLong(st.nextToken());
        }
        System.out.println(numMeas);
        System.out.println(startMilk);
        System.out.println(Arrays.deepToString(meas));
        
        
        // quicksort by time
        MyQuickSort qs = new MyQuickSort();
        qs.sort(meas);
        System.out.println(Arrays.deepToString(meas));
        
        
        long mostMilkGallon = 0;
        long mostMilkId = 0;
        long curMilkGallon = 0;
        long curMilkId = 0;
        long cows[] = new long[100];
        
        for (int day = 0; day < numMeas; day++) {
        	// calc cur most milk
        	for (int i = 0; i < day; i++) {
        		
        	}
        }
        
        
        // save output
        printer.write("3\n");
        
        // closing
        reader.close();
        printer.close();
	}

}

class MyQuickSort {
    
    private long array[][];
    private int length;
 
    public void sort(long[][] inputArr) {
         
        if (inputArr == null || inputArr.length == 0) {
            return;
        }
        this.array = inputArr;
        length = inputArr.length;
        quickSort(0, length - 1);
    }
 
    private void quickSort(int lowerIndex, int higherIndex) {
         
        int i = lowerIndex;
        int j = higherIndex;
        // calculate pivot number, I am taking pivot as middle index number
        long pivot = array[lowerIndex+(higherIndex-lowerIndex)/2][0];
        // Divide into two arrays
        while (i <= j) {
            /**
             * In each iteration, we will identify a number from left side which 
             * is greater then the pivot value, and also we will identify a number 
             * from right side which is less then the pivot value. Once the search 
             * is done, then we exchange both numbers.
             */
            while (array[i][0] < pivot) {
                i++;
            }
            while (array[j][0] > pivot) {
                j--;
            }
            if (i <= j) {
                exchangeNumbers(i, j);
                //move index to next position on both sides
                i++;
                j--;
            }
        }
        // call quickSort() method recursively
        if (lowerIndex < j)
            quickSort(lowerIndex, j);
        if (i < higherIndex)
            quickSort(i, higherIndex);
    }
 
    private void exchangeNumbers(int i, int j) {
        long[] temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}