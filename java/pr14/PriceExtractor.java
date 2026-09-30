import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PriceExtractor {
    public static void main(String[] args) {
        String text = "Цены: 25.98 USD, 500 RUB, 12.34 EU. Неправильные: 44 ERR, 0.004 EU.";

        Pattern usdPattern = Pattern.compile("(\\d+\\.\\d+) USD");
        Pattern rubPattern = Pattern.compile("(\\d+) RUB");
        Pattern euPattern = Pattern.compile("(\\d+\\.\\d+) EU");

        Matcher usdMatcher = usdPattern.matcher(text);
        Matcher rubMatcher = rubPattern.matcher(text);
        Matcher euMatcher = euPattern.matcher(text);

        while (usdMatcher.find()) {
            System.out.println("USD: " + usdMatcher.group(1));
        }

        while (rubMatcher.find()) {
            System.out.println("RUB: " + rubMatcher.group(1));
        }

        while (euMatcher.find()) {
            System.out.println("EU: " + euMatcher.group(1));
        }
    }
}