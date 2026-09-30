public class Task7 {
    public static void main(String[] args) {
        int number = 5;
        long fact = factorial(number);
        System.out.println("Факториал числа " + number + " = " + fact);
    }

    public static long factorial(int n) {
        long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
}
