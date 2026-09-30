class Point {
    private double x;
    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() { return x; }
    public double getY() { return y; }
    public void setX(double x) { this.x = x; }
    public void setY(double y) { this.y = y; }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

class Circle {
    private Point center;
    private double radius;

    public Circle(Point center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public Point getCenter() { return center; }
    public double getRadius() { return radius; }
    public void setCenter(Point center) { this.center = center; }
    public void setRadius(double radius) { this.radius = radius; }

    @Override
    public String toString() {
        return "Circle [Center: " + center + ", Radius: " + radius + "]";
    }
}

class Tester {
    private Circle[] circles;
    private int count;

    public Tester(int capacity) {
        circles = new Circle[capacity];
        count = 0;
    }

    public void addCircle(Circle circle) {
        if (count < circles.length) {
            circles[count] = circle;
            count++;
        } else {
            System.out.println("Array is full. Cannot add more circles.");
        }
    }

    public void displayCircles() {
        System.out.println("Circles:");
        for (int i = 0; i < count; i++) {
            System.out.println(circles[i]);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Point point1 = new Point(2.0, 3.0);
        Point point2 = new Point(1.0, 4.0);

        Circle circle1 = new Circle(point1, 5.0);
        Circle circle2 = new Circle(point2, 3.0);

        Tester tester = new Tester(5);
        tester.addCircle(circle1);
        tester.addCircle(circle2);

        tester.displayCircles();
    }
}
