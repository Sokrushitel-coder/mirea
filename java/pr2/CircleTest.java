import java.lang.Math;

class Circle2 {
    private double radius;

    public Circle2(double radius) {
        if (radius < 0) {
            throw new IllegalArgumentException("Radius cannot be negative.");
        }
        this.radius = radius;
    }

    public double getRadius() { return radius; }

    public void setRadius(double radius) {
        if (radius < 0) {
            throw new IllegalArgumentException("Radius cannot be negative.");
        }
        this.radius = radius;
    }

    public double calculateArea() {
        return Math.PI * Math.pow(radius, 2);
    }

    public double calculateCircumference() {
        return 2 * Math.PI * radius;
    }

    public int compareCircle(Circle2 otherCircle) {
        double otherRadius = otherCircle.getRadius();
        if (this.radius < otherRadius) {
            return -1;
        } else if (this.radius > otherRadius) {
            return 1;
        } else {
            return 0;
        }
    }
}

public class CircleTest {
    public static void main(String[] args) {
        Circle2 circle1 = new Circle2(5.0);
        Circle2 circle2 = new Circle2(3.0);

        System.out.println("Circle 1 - Radius: " + circle1.getRadius());
        System.out.println("Area of Circle 1: " + circle1.calculateArea());
        System.out.println("Circumference of Circle 1: " + circle1.calculateCircumference());

        System.out.println("\nCircle 2 - Radius: " + circle2.getRadius());
        System.out.println("Area of Circle 2: " + circle2.calculateArea());
        System.out.println("Circumference of Circle 2: " + circle2.calculateCircumference());

        int result = circle1.compareCircle(circle2);
        if (result < 0) {
            System.out.println("\nCircle 1 is smaller than Circle 2.");
        } else if (result > 0) {
            System.out.println("\nCircle 1 is larger than Circle 2.");
        } else {
            System.out.println("\nCircle 1 and Circle 2 have the same radius.");
        }
    }
}
