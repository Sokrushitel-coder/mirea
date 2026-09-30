public class PhoneNumberFormatter {
    public static String formatPhoneNumber(String input) {
        input = input.replaceAll("[^0-9]+", "");

        if (input.startsWith("7") && input.length() == 11) {
            String phoneNumber = input.substring(1);
            return "+7-" + phoneNumber.substring(0, 3) + "-" + phoneNumber.substring(3, 6) + "-" + phoneNumber.substring(6);
        } else if (input.startsWith("8") && input.length() == 11) {
            String phoneNumber = input.substring(1);
            return "+7-" + phoneNumber.substring(0, 3) + "-" + phoneNumber.substring(3, 6) + "-" + phoneNumber.substring(6);
        } else if (input.length() == 12) {
            String countryCode = input.substring(0, 2);
            String phoneNumber = input.substring(2);
            return "+" + countryCode + "-" + phoneNumber.substring(0, 3) + "-" + phoneNumber.substring(3, 6) + "-" + phoneNumber.substring(6);
        } else {
            return "Неверный формат номера";
        }
    }

    public static void main(String[] args) {
        String phoneNumber1 = "+79175655655";
        String phoneNumber2 = "+104289652211";
        String phoneNumber3 = "89175655655";

        System.out.println(formatPhoneNumber(phoneNumber1));
        System.out.println(formatPhoneNumber(phoneNumber2));
        System.out.println(formatPhoneNumber(phoneNumber3));
   