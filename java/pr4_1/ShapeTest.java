class Shape {
    public String getType() {
        return "Shape";
    }

    public double getArea() {
        return 0.0;
    }

    public double getPerimeter() {
        return 0.0;
    }

    @Override
    public String toString() {
        return "This is a " + getType();
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public String getType() {
        return "Circle";
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public String getType() {
        return "Rectangle";
    }

    @Override
    public double getArea() {
        return length * width;
    }

    @Override
    public double getPerimeter() {
        return 2 * (length + width);
    }
}

class Square extends Rectangle {
    public Square(double side) {
        super(side, side);
    }

    @Override
    public String getType() {
        return "Square";
    }
}

public class ShapeTest {
    public static void main(String[] args) {
        Shape shape1 = new Circle(5.0);
        Shape shape2 = new Rectangle(4.0, 6.0);
        Shape shape3 = new Square(3.0);

        System.out.println(shape1 + " Area: " + shape1.getArea() + " Perimeter: " + shape1.getPerimeter());
        System.out.println(shape2 + " Area: " + shape2.getArea() + " Perimeter: " + shape2.getPerimeter());
        System.out.println(shape3 + " Area: " + shape3.getArea() + " Perimeter: " + shape3.getPerimeter());
    }
}
