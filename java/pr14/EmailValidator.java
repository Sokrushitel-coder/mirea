import java.util.Scanner;
import java.util.regex.*;

public class EmailValidator {
    public static boolean isValidEmail(String email) {
        String regex = "^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(email);
        return matcher.matches();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите email-адрес: ");
        String email = scanner.nextLine();

        if (isValidEmail(email)) {
            System.out.println(email + " является корректным email-адресом.");
        } else {
            System.out.println(email + " не является корректным email-адресом.");
        }

        scanner.close();
    }
}