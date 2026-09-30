import java.util.Scanner;

public class Task4 {
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
        int i = 0;
        do {
            sum += mas[i];
            i++;
        } while (i < size);

        int sum1 = 0;
        int i1 = 0;
        while (i1 < size) {
            sum1 += mas[i1];
            i1++;
        }

        int max = 0;
        int min = (int) Math.pow(10, 10);
        for (int ma : mas) {
            if (ma > max) {
                max = ma;
            }
            if (ma < min) {
                min = ma;
            }
        }

        System.out.println("Сумма элементов массива (do+while): " + sum);
        System.out.println("Сумма элементов массива (while): " + sum1);
        System.out.println("Максимальный элемент массива: " + max);
        System.out.println("Минимальный элемент массива: " + min);
    }
}
