import java.util.regex.*;
import java.util.Scanner;

public class PasswordChecker {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите пароль для проверки: ");
        String password = scanner.nextLine();

        if (isStrongPassword(password)) {
            System.out.println("Пароль надежный");
        } else {
            System.out.println("Пароль ненадежный");
        }

        scanner.close();
    }

    public static boolean isStrongPassword(String password) {
        if (password.length() < 8) {
            return false;
        }

        if (!Pattern.compile(".*[A-Z].*").matcher(password).find() ||
                !Pattern.compile(".*[a-z].*").matcher(password).find() ||
                !Pattern.compile(".*\\d.*").matcher(password).find()) {
            return false;
        }

        if (!Pattern.matches("[A-Za-z0-9_]+$", password)) {
            return false;
        }

        return true;
    }
}