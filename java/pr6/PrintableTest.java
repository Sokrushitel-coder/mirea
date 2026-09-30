interface Printable {
    void print();
}

class Book implements Printable {
    private String title;

    public Book(String title) {
        this.title = title;
    }

    @Override
    public void print() {
        System.out.println("Book: " + title);
    }
}

class Shop implements Printable {
    private String name;

    public Shop(String name) {
        this.name = name;
    }

    @Override
    public void print() {
        System.out.println("Shop: " + name);
    }
}

public class PrintableTest {
    public static void main(String[] args) {
        Printable[] printables = {
                new Book("The Witcher"),
                new Book("Metro 2033"),
                new Shop("Chitai Gorod"),
                new Shop("Biblus")
        };

        for (Printable printable : printables) {
            printable.print();
        }
    }
}