public class StringManipulation {
    public static void main(String[] args) {
        String inputString = "I like Java!!!";

        char lastChar = inputString.charAt(inputString.length() - 1);
        System.out.println("Последний символ строки: " + lastChar);

        boolean endsWithExclamation = inputString.endsWith("!!!");
        System.out.println("Заканчивается ли строка на '!!!': " + endsWithExclamation);

        boolean startsWithILike = inputString.startsWith("I like");
        System.out.println("Начинается ли строка с 'I like': " + startsWithILike);

        boolean containsJava = inputString.contains("Java");
        System.out.println("Содержит ли строка 'Java': " + containsJava);

        int positionOfJava = inputString.indexOf("Java");
        if (positionOfJava != -1) {
            System.out.println("Позиция подстроки 'Java' в строке: " + positionOfJava);
        } else {
            System.out.println("Подстрока 'Java' не найдена в строке.");
        }

        String replacedString = inputString.replace('a', 'o');
        System.out.println("Строка после замены 'a' на 'o': " + replacedString);

        String uppercaseString = inputString.toUpperCase();
        System.out.println("Строка в верхнем регистре: " + uppercaseString);

        String lowercaseString = inputString.toLowerCase();
        System.out.println("Строка в нижнем регистре: " + lowercaseString);

        String substring = inputString.substring(inputString.indexOf("Java"), inputString.indexOf("Java") + "Java".length());
        System.out.println("Подстрока 'Java': " + substring);
    }
}