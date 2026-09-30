interface Nameable {
    String getName();
}

class Planet implements Nameable {
    private String name;
    public Planet(String name) { this.name = name; }
    @Override public String getName() { return name; }
}

class Car implements Nameable {
    private String name;
    public Car(String name) { this.name = name; }
    @Override public String getName() { return name; }
}

class Animal implements Nameable {
    private String name;
    public Animal(String name) { this.name = name; }
    @Override public String getName() { return name; }
}

public class NameableTest {
    public static void main(String[] args) {
        Nameable[] objects = {
                new Planet("Earth"),
                new Car("Toyota"),
                new Animal("Cat")
        };

        for (Nameable obj : objects) {
            System.out.println(obj.getName());
        }
    }
}