import java.util.Arrays;

class Book {
    private String title;
    private String author;
    private int yearOfWriting;

    public Book(String title, String author, int yearOfWriting) {
        this.title = title;
        this.author = author;
        this.yearOfWriting = yearOfWriting;
    }

    public String getTitle() { return title; }
    public String getAuthor() { return author; }
    public int getYearOfWriting() { return yearOfWriting; }

    public void setTitle(String title) { this.title = title; }
    public void setAuthor(String author) { this.author = author; }
    public void setYearOfWriting(int yearOfWriting) { this.yearOfWriting = yearOfWriting; }

    @Override
    public String toString() {
        return "Book{" +
                "title='" + title + '\'' +
                ", author='" + author + '\'' +
                ", yearOfWriting=" + yearOfWriting +
                '}';
    }
}

class Bookshelf {
    private Book[] books;
    private int numOfBooks;

    public Bookshelf(int capacity) {
        books = new Book[capacity];
        numOfBooks = 0;
    }

    public void addBook(Book book) {
        if (numOfBooks < books.length) {
            books[numOfBooks] = book;
            numOfBooks++;
        } else {
            System.out.println("The bookshelf is full.");
        }
    }

    public Book getLatestBook() {
        if (numOfBooks == 0) return null;
        Book latestBook = books[0];
        for (int i = 1; i < numOfBooks; i++) {
            if (books[i].getYearOfWriting() > latestBook.getYearOfWriting()) {
                latestBook = books[i];
            }
        }
        return latestBook;
    }

    public Book getEarliestBook() {
        if (numOfBooks == 0) return null;
        Book earliestBook = books[0];
        for (int i = 1; i < numOfBooks; i++) {
            if (books[i].getYearOfWriting() < earliestBook.getYearOfWriting()) {
                earliestBook = books[i];
            }
        }
        return earliestBook;
    }

    public void sortBooksByYear() {
        Arrays.sort(books, 0, numOfBooks, (book1, book2) ->
                Integer.compare(book1.getYearOfWriting(), book2.getYearOfWriting()));
    }

    @Override
    public String toString() {
        return "Bookshelf{" +
                "books=" + Arrays.toString(books) +
                ", numOfBooks=" + numOfBooks +
                '}';
    }
}

public class BookTest {
    public static void main(String[] args) {
        Book book1 = new Book("Book 1", "Author 1", 2000);
        Book book2 = new Book("Book 2", "Author 2", 1995);
        Book book3 = new Book("Book 3", "Author 3", 2010);

        Bookshelf bookshelf = new Bookshelf(5);
        bookshelf.addBook(book1);
        bookshelf.addBook(book2);
        bookshelf.addBook(book3);

        System.out.println("Bookshelf contents:");
        System.out.println(bookshelf);

        System.out.println("Latest book:");
        System.out.println(bookshelf.getLatestBook());

        System.out.println("Earliest book:");
        System.out.println(bookshelf.getEarliestBook());

        bookshelf.sortBooksByYear();
        System.out.println("Books sorted by year:");
        System.out.println(bookshelf);
    }
}
