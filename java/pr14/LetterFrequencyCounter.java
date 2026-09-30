import java.util.HashMap;
import java.util.Map;

public class LetterFrequencyCounter {
    public static void main(String[] args) {
        String text = "This is a sample text. It contains letters, spaces, and punctuation marks.";
        text = text.toLowerCase();

        Map<Character, Integer> letterFrequency = new HashMap<>();

        for (char c : text.toCharArray()) {
            if (Character.isLetter(c)) {
                if (letterFrequency.containsKey(c)) {
                    letterFrequency.put(c, letterFrequency.get(c) + 1);
                } else {
                    letterFrequency.put(c, 1);
                }
            }
        }

        for (Map.Entry<Character, Integer> entry : letterFrequency.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }
    }
}