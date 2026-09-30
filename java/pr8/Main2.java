import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        readAndPrintOddSequenceMembers();
    }

    public static void readAndPrintOddSequenceMembers() {
        Scanner scanner = new Scanner(System.in);
        int number;
        int index = 1;

        while (true) {
            number = scanner.nextInt();
            if (number == 0) {
                break;
            }
            if (index % 2 == 1) {
                System.out.println(number);
            }
            index++;
        }
        scanner.close();
    }
}