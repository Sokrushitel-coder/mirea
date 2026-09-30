import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MiniOnlineStore {
    public static void main(String[] args) {
        Map<String, Double> products = new HashMap<>();
        products.put("Playstation 5", 420.0);
        products.put("Xbox One S", 390.0);
        products.put("Nintendo Switch", 450.0);

        Map<String, Double> exchangeRates = new HashMap<>();
        exchangeRates.put("USD", 1.0);
        exchangeRates.put("EUR", 0.85);
        exchangeRates.put("GBP", 0.75);

        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the Mini Online Store!");
        System.out.println("Available products:");
        for (String product : products.keySet()) {
            System.out.println(product + ": $" + products.get(product));
        }

        System.out.print("Select a product: ");
        String selectedProduct = scanner.nextLine();

        if (!products.containsKey(selectedProduct)) {
            System.out.println("Invalid product selection.");
            return;
        }

        System.out.print("Enter the quantity: ");
        int quantity = scanner.nextInt();

        if (quantity <= 0) {
            System.out.println("Quantity must be greater than zero.");
            return;
        }

        System.out.print("Select currency (USD, EUR, GBP): ");
        String selectedCurrency = scanner.next();

        if (!exchangeRates.containsKey(selectedCurrency)) {
            System.out.println("Invalid currency selection.");
            return;
        }

        double priceInUSD = products.get(selectedProduct) * quantity;
        double priceInSelectedCurrency = priceInUSD * exchangeRates.get(selectedCurrency);

        System.out.println("Total price in " + selectedCurrency + ": " + priceInSelectedCurrency);
    }
}
