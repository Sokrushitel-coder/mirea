import java.util.Arrays;
import java.util.Random;

public class RandomNumberArraySort {
    public static void main(String[] args) {
        int arrayLength = 10;

        double[] randomArray1 = new double[arrayLength];
        for (int i = 0; i < arrayLength; i++) {
            randomArray1[i] = Math.random();
        }

        System.out.println("Array generated using Math.random():");
        displayArray(randomArray1);

        Arrays.sort(randomArray1);

        System.out.println("\nSorted array using Math.random():");
        displayArray(randomArray1);

        Random random = new Random();
        double[] randomArray2 = new double[arrayLength];
        for (int i = 0; i < arrayLength; i++) {
            randomArray2[i] = random.nextDouble();
        }

        System.out.println("\nArray generated using Random class:");
        displayArray(randomArray2);

        Arrays.sort(randomArray2);

        System.out.println("\nSorted array using Random class:");
        displayArray(randomArray2);
    }

    private static void displayArray(double[] arr) {
        for (double num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
