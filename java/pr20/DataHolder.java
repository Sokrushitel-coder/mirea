public class DataHolder<T> {
    private T[] data;

    public DataHolder(T[] data) {
        this.data = data;
    }

    public T[] getData() { return data; }
    public void setData