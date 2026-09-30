import java.util.Scanner;

public enum ClothingSize {
    XXS(32),
    XS(34),
    S(36),
    M(38),
    L(40);

    private final int euroSize;

    ClothingSize(int euroSize) {
        this.euroSize = euroSize;
    }

    public String getDescription() {
        if (this == XXS) {
            return "Child size";
        }
        return "Adult size";
    }

    public int getEuroSize() {
        return euroSize;
    }
}

interface MenClothing {
    void dressMan();
}

interface WomenClothing {
    void dressWomen();
}

abstract class Clothes {
    private ClothingSize size;
    private double cost;
    private String color;

    public Clothes(ClothingSize size, double cost, String color) {
        this.size = size;
        this.cost = cost;
        this.color = color;
    }

    public ClothingSize getSize() { return size; }
    public double getCost() { return cost; }
    public String getColor() { return color; }

    public abstract void displayInformation();
}

class TShirt extends Clothes implements MenClothing, WomenClothing {
    public TShirt(ClothingSize size, double cost, String color) {
        super(size, cost, color);
    }

    @Override
    public void dressMan() {
        System.out.println("Man wears a T-shirt");
    }

    @Override
    public void dressWomen() {
        System.out.println("Woman wears a T-shirt");
    }

    @Override
    public void displayInformation() {
        System.out.println("T-Shirt: Size " + getSize() + ", Color " + getColor() + ", Cost " + getCost());
    }
}

class Pants extends Clothes implements MenClothing, WomenClothing {
    public Pants(ClothingSize size, double cost, String color) {
        super(size, cost, color);
    }

    @Override
    public void dressMan() {
        System.out.println("Man wears pants");
    }

    @Override
    public void dressWomen() {
        System.out.println("Woman wears pants");
    }

    @Override
    public void displayInformation() {
        System.out.println("Pants: Size " + getSize() + ", Color " + getColor() + ", Cost " + getCost());
    }
}

class Skirt extends Clothes implements WomenClothing {
    public Skirt(ClothingSize size, double cost, String color) {
        super(size, cost, color);
    }

    @Override
    public void dressWomen() {
        System.out.println("Woman wears a skirt");
    }

    @Override
    public void displayInformation() {
        System.out.println("Skirt: Size " + getSize() + ", Color " + getColor() + ", Cost " + getCost());
    }
}

class Tie extends Clothes implements MenClothing {
    public Tie(ClothingSize size, double cost, String color) {
        super(size, cost, color);
    }

    @Override
    public void dressMan() {
        System.out.println("Man wears a tie");
    }

    @Override
    public void displayInformation() {
        System.out.println("Tie: Size " + getSize() + ", Color " + getColor() + ", Cost " + getCost());
    }
}

class Atelier {
    public void dressMan(Clothes[] clothes) {
        System.out.println("Men's clothing:");
        for (Clothes item : clothes) {
            if (item instanceof MenClothing) {
                item.displayInformation();
                ((MenClothing) item).dressMan();
            }
        }
    }

    public void dressWomen(Clothes[] clothes) {
        System.out.println("Women's clothing:");
        for (Clothes item : clothes) {
            if (item instanceof WomenClothing) {
                item.displayInformation();
                ((WomenClothing) item).dressWomen();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter T-Shirt details:");
        ClothingSize tShirtSize = readClothingSize(scanner);
        double tShirtCost = readDouble(scanner, "Enter T-Shirt cost:");
        String tShirtColor = readString(scanner, "Enter T-Shirt color:");

        System.out.println("Enter Pants details:");
        ClothingSize pantsSize = readClothingSize(scanner);
        double pantsCost = readDouble(scanner, "Enter Pants cost:");
        String pantsColor = readString(scanner, "Enter Pants color:");

        System.out.println("Enter Skirt details:");
        ClothingSize skirtSize = readClothingSize(scanner);
        double skirtCost = readDouble(scanner, "Enter Skirt cost:");
        String skirtColor = readString(scanner, "Enter Skirt color:");

        System.out.println("Enter Tie details:");
        ClothingSize tieSize = readClothingSize(scanner);
        double tieCost = readDouble(scanner, "Enter Tie cost:");
        String tieColor = readString(scanner, "Enter Tie color:");

        Clothes[] clothes = {
                new TShirt(tShirtSize, tShirtCost, tShirtColor),
                new Pants(pantsSize, pantsCost, pantsColor),
                new Skirt(skirtSize, skirtCost, skirtColor),
                new Tie(tieSize, tieCost, tieColor)
        };

        Atelier atelier = new Atelier();
        atelier.dressMan(clothes);
        atelier.dressWomen(clothes);

        scanner.close();
    }

    private static ClothingSize readClothingSize(Scanner scanner) {
        while (true) {
            System.out.println("Available sizes: XXS, XS, S, M, L");
            System.out.print("Enter size: ");
            String input = scanner.nextLine().trim().toUpperCase();
            try {
                return ClothingSize.valueOf(input);
            } catch (IllegalArgumentException e) {
                System.out.println("Invalid size. Please enter a valid size.");
            }
        }
    }

    private static double readDouble(Scanner scanner, String prompt) {
        while (true) {
            try {
                System.out.print(prompt + " ");
                return Double.parseDouble(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a valid number.");
            }
        }
    }

    private static String readString(Scanner scanner, String prompt) {
        System.out.print(prompt + " ");
        return scanner.nextLine();
    }
}
