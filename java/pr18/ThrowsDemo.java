import java.util.Scanner;

public class ThrowsDemo {
    public void getKey() {
        boolean validInput = false;
        Scanner myScanner = new Scanner(System.in);

        while (!validInput) {
            try {
                System.out.print("Введите значение ключа: ");
                String key = myScanner.next();
                printDetails(key);
                validInput = true;
            } catch (Exception e) {
                System.out.println("Исключение перехвачено в методе getKey: " + e);
                System.out.println("Пожалуйста, введите значение ключа еще раз.");
                myScanner.nextLine();
            }
        }
    }

    public void printDetails(String key) {
        try {
            String message = getDetails(key);
            System.out.println(message);
        } catch (Exception e) {
            System.out.println("Исключение перехвачено в методе printDetails: " + e);
            throw new RuntimeException("Обработка ошибки в методе printDetails", e);
        }
    }

    private String getDetails(String key) throws Exception {
        if (key.equals("")) {
            throw new Exception("Key set to an empty string");
        }
        return "data for " + key;
    }

    public static void main(String[] args) {
        ThrowsDemo throwsDemo = new ThrowsDemo();
        throwsDemo.getKey();
    }
}