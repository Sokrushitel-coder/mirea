public abstract class AbstractQueue<E> implements Queue<E> {
    protected int size;

    public AbstractQueue() { this.size = 0; }

    @Override
    public boolean isEmpty() { return size == 0; }

    @Override
    public int size() { return size; }

    @Override
    public void clear() { doClear(); }

    protected abstract void doEnqueue(E element);
    protected abstract E doDequeue();
    protected abstract E doElement();
    protected abstract void doClear();
}