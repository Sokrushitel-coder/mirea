import java.util.Scanner;
import java.util.regex.*;

public class DateValidation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String datePattern = "^([0-9]{2})/([0-9]{2})/(19\\d{2}|[2-9]\\d{3})$";
        Pattern pattern = Pattern.compile(datePattern);

        while (true) {
            System.out.print("Введите дату в формате dd/mm/yyyy (или 'exit' для завершения): ");
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("exit")) {
                break;
            }

            if (pattern.matcher(input).matches()) {
                System.out.println("Правильная дата.");
            } else {
                System.out.println("Неправильная дата. Повторите ввод.");
            }
        }

        scanner.close();
    }
}