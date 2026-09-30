import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class PatternMatch {
    public static void main(String[] args) {
        String regex = "abcdefghijklmnopqrstuv18340";
        String input = "abcdefghijklmnopqrstuv18340";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(input);

        if (matcher.matches()) {
            System.out.println("Строка соответствует образцу.");
        } else {
            System.out.println("Строка не соответствует образцу.");
        }
    }
}