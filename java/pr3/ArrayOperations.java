import java.util.Scanner;
import java.util.Random;

public class ArrayOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        do {
            System.out.print("Enter the size of the array (a natural number larger than 0): ");
            while (!scanner.hasNextInt()) {
                System.out.println("Invalid input. Please enter a natural number: ");
                scanner.next();
            }
            n = scanner.nextInt();
        } while (n <= 0);

        Random random = new Random();
        int[] originalArray = new int[n];

        for (int i = 0; i < n; i++) {
            originalArray[i] = random.nextInt(n + 1);
        }

        System.out.println("Original Array:");
        displayArray(originalArray);

        int[] evenArray = getEvenElements(originalArray);
        System.out.println("Array with even elements:");
        displayArray(evenArray);
    }

    public static void displayArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static int[] getEvenElements(int[] arr) {
        int count = 0;
        for (int num : arr) {
            if (num % 2 == 0) {
                count++;
            }
        }

        int[] evenArray = new int[count];
        int index = 0;
        for (int num : arr) {
            if (num % 2 == 0) {
                evenArray[index] = num;
                index++;
            }
        }

        return evenArray;
    }
}
