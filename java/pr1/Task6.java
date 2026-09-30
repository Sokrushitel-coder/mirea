public class Task6 {
    public static void main(String[] args) {
        int n = 10;
        double sum = 0.0;
        System.out.println("Первые 10 чисел гармонического ряда: ");
        for (int i = 1; i <= n; i++) {
            sum += 1.0 / i;
            System.out.printf("1/%d = %.6f\n", i, 1.0 / i);
        }
    }
}
