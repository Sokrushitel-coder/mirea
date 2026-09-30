import java.util.Scanner;

enum Season {
    SPRING(19.0),
    SUMMER(36.0),
    AUTUMN(12.0),
    WINTER(0.0);

    private double averageTemperature;

    Season(double averageTemperature) {
        this.averageTemperature = averageTemperature;
    }

    public double getAverageTemperature() {
        return averageTemperature;
    }

    public String getDescription() {
        if (this == SUMMER) {
            return "Warm Season";
        } else {
            return "Cold Season";
        }
    }
}

public class Year {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your favorite season (SPRING, SUMMER, AUTUMN, or WINTER):");
        String userInput = scanner.nextLine().toUpperCase();

        try {
            Season favoriteSeason = Season.valueOf(userInput);
            System.out.println("Favorite Season: " + favoriteSeason);
            System.out.println("Average Temperature: " + favoriteSeason.getAverageTemperature() + "°C");
            System.out.println("Description: " + favoriteSeason.getDescription());

            switch (favoriteSeason) {
                case SUMMER:
                    System.out.println("I love summer");
                    break;
                case SPRING:
                    System.out.println("I enjoy spring");
                    break;
                case AUTUMN:
                    System.out.println("I like autumn");
                    break;
                case WINTER:
                    System.out.println("Winter is cozy");
                    break;
                default:
                    System.out.println("No specific preference");
            }
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid season entered. Please enter SPRING, SUMMER, AUTUMN, or WINTER.");
        } finally {
            scanner.close();
        }

        System.out.println("\nPrinting information for all seasons:");
        for (Season season : Season.values()) {
            System.out.println("Season: " + season);
            System.out.println("Average Temperature: " + season.getAverageTemperature() + "°C");
            System.out.println("Description: " + season.getDescription());
            System.out.println();
        }
    }
}
