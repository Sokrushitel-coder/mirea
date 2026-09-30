import java.util.InputMismatchException;
import java.util.Scanner;

public class ReverseNumber {
    public static int reverse(int n) {
        return reverseHelper(n, 0);
    }

    private static int reverseHelper(int n, int reversed) {
        if (n == 0) {
            return reversed;
        } else {
            int lastDigit = n % 10;
            return reverseHelper(n / 10, reversed * 10 + lastDigit);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        try {
            System.out.print("Введите число (без нулей): ");
            int number = scanner.nextInt();
            int reversedNumber = reverse(number);
            System.out.println("Разворот числа: " + reversedNumber);
        } catch (InputMismatchException e) {
            System.err.println("Ошибка: Введите корректное целое число.");
        } finally {
            scanner.close();
        }
    }
}