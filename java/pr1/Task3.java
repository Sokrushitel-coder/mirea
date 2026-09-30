import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Введите размер массива: ");
        int size = sc.nextInt();
        int[] mas = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.print("Введите " + (i + 1) + " элемент: ");
            mas[i] = sc.nextInt();
        }

        int sum = 0;
        for (int ma : mas) {
            sum += ma;
        }
        double srzm = (double) sum / size;

        System.out.println("Сумма элементов: " + sum);
        System.out.println("Среднее арифметическое значение элементов массива: " + srzm);
    }
}
