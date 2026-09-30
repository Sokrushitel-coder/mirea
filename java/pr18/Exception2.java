import java.util.Scanner;

public class Exception2 {
    public void exceptionDemo() {
        Scanner myScanner = new Scanner(System.in);
        try {
            System.out.println("Enter an integer: ");
            String intString = myScanner.next();
            int i = Integer.parseInt(intString);
            System.out.println(400 / i);
        } catch (NumberFormatException e) {
            System.out.println("NumberFormatException: Please enter a valid integer.");
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException: Cannot divide by zero.");
        } catch (Exception e) {
            System.out.println("Exception: An unexpected error occurred.");
        } finally {
            System.out.println("This block is always executed, whether there is an exception or not.");
        }
    }

    public static void main(String[] args) {
        Exception2 exceptionExample = new Exception2();
        exceptionExample.exceptionDemo();
    }
}