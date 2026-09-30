interface Movable {
    void move(int deltaX, int deltaY);
}

class MovablePoint implements Movable {
    private int x;
    private int y;

    public MovablePoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public void move(int deltaX, int deltaY) {
        x += deltaX;
        y += deltaY;
    }

    @Override
    public String toString() {
        return "MovablePoint{" + "x=" + x + ", y=" + y + '}';
    }

    public String toFormattedString() {
        return "(" + x + ", " + y + ")";
    }

    public boolean speedTest(MovablePoint other) {
        return (x - other.x) == (y - other.y);
    }
}

class MovableRectangle implements Movable {
    private MovablePoint topLeft;
    private MovablePoint bottomRight;

    public MovableRectangle(int x1, int y1, int x2, int y2) {
        this.topLeft = new MovablePoint(x1, y1);
        this.bottomRight = new MovablePoint(x2, y2);
    }

    @Override
    public void move(int deltaX, int deltaY) {
        topLeft.move(deltaX, deltaY);
        bottomRight.move(deltaX, deltaY);
    }

    @Override
    public String toString() {
        return "MovableRectangle{" +
                "topLeft=" + topLeft.toFormattedString() +
                ", bottomRight=" + bottomRight.toFormattedString() +
                '}';
    }

    public boolean speedTest() {
        return topLeft.speedTest(bottomRight);
    }
}

public class MovableTest {
    public static void main(String[] args) {
        MovableRectangle rect = new MovableRectangle(0, 0, 10, 10);
        System.out.println(rect);
        rect.move(5, 5);
        System.out.println(rect);
        System.out.println("Speed test: " + rect.speedTest());
    }
}