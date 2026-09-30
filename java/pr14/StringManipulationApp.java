import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class StringManipulationApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите строку:");
        String input = scanner.nextLine();

        System.out.println("Выберите регулярное выражение для разбиения строки:");
        System.out.println("1. Разбиение по пробелам");
        System.out.println("2. Разбиение по запятым");
        System.out.println("3. Разбиение на слова");
        System.out.println("4. Разбиение по цифрам");
        System.out.print("Введите номер выбранного регулярного выражения: ");

        int choice = scanner.nextInt();
        scanner.nextLine();

        String regex = null;

        switch (choice) {
            case 1:
                regex = "\\s+";
                break;
            case 2:
                regex = ",";
                break;
            case 3:
                regex = "\\b\\w+\\b";
                break;
            case 4:
                regex = "\\d+";
                break;
            default:
                System.out.println("Неверный выбор.");
                break;
        }

        if (regex != null) {
            Pattern pattern = Pattern.compile(regex);
            Matcher matcher = pattern.matcher(input);

            int matchCount = 0;

            System.out.println("Результат:");

            while (matcher.find()) {
                matchCount++;
                String match = matcher.group();
                System.out.println("Элемент " + matchCount + ": " + match);
            }

            if (matchCount == 0) {
                System.out.println("Нет совпадений с регулярным выражением.");
            }
        }

        scanner.close();
    }
}