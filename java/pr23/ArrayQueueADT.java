import java.util.Arrays;

public abstract class ArrayQueueADT implements Queue {
    protected Object[] elements = new Object[10];
    protected int size = 0;
    protected int front = 0;
    protected int rear = 0;

    public abstract void enqueue(Object element);
    public abstract Object element();
    public abstract Object dequeue();

    @Override
    public int size() { return size; }

    @Override
    public boolean isEmpty() { return size == 0; }

    @Override
    public void clear() {
        Arrays.fill(elements, null);
        size = 0;
        front = 0;
        rear = 0;
    }

    protected void ensureCapacity() {
        if (size == elements.length) {
            elements = Arrays.copyOf(elements, 2 * size);
        }
    }
}