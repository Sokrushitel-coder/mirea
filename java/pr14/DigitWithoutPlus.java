import java.util.regex.*;

public class DigitWithoutPlus {
    public static void main(String[] args) {
        String text = "1 + 8 + 9 +4";
        boolean containsDigitWithoutPlus = containsDigitWithoutPlus(text);

        if (containsDigitWithoutPlus) {
            System.out.println("Текст содержит цифры без знака '+'");
        } else {
            System.out.println("Текст не содержит цифр без знака '+'");
        }
    }

    public static boolean containsDigitWithoutPlus(String text) {
        Pattern pattern = Pattern.compile("\\d(?![+])");
        Matcher matcher = pattern.matcher(text);
        return matcher.find();
    }
}