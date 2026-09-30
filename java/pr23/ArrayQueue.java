public class ArrayQueue extends ArrayQueueADT {
    @Override
    public void enqueue(Object element) {
        ensureCapacity();
        elements[rear] = element;
        rear = (rear + 1) % elements.length;
        size++;
    }

    @Override
    public Object element() {
        if (isEmpty()) {
            throw new IllegalArgumentException("Queue is empty");
        }
        return elements[front];
    }

    @Override
    public Object dequeue() {
        if (isEmpty()) {
            throw new IllegalArgumentException("Queue is empty");
        }
        Object removedElement = elements[front];
        elements[front] = null;
        front = (front + 1) % elements.length;
        size--;
        return removedElement;
    }
}