import java.util.Scanner;

public class OnlinePurchase {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите ФИО: ");
        String fullName = scanner.nextLine();

        System.out.print("Введите ИНН: ");
        String inn = scanner.nextLine();

        try {
            validateINN(inn);
            System.out.println("Заказ успешно оформлен.");
            System.out.println("ФИО: " + fullName);
            System.out.println("ИНН: " + inn);
        } catch (InvalidINNException e) {
            System.out.println("Ошибка при вводе ИНН: " + e.getMessage());
        }

        scanner.close();
    }

    private static void validateINN(String inn) throws InvalidINNException {
        if (inn.length() != 12) {
            throw new InvalidINNException("Неверная длина ИНН. ИНН должен состоять из 12 цифр.");
        }

        if (!inn.matches("\\d+")) {
            throw new InvalidINNException("ИНН должен состоять только из цифр.");
        }
    }
}

class InvalidINNException extends Exception {
    public InvalidINNException(String message) {
        super(message);
    }
}