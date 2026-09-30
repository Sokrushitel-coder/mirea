import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Work5 {
    public static void main(String[] args) {
        int n = 100000;

        List<Integer> arrayList = new ArrayList<>();
        long arrayListStartTime = System.nanoTime();
        for (int i = 0; i < n; i++) {
            arrayList.add(i);
        }
        long arrayListEndTime = System.nanoTime();
        long arrayListDuration = arrayListEndTime - arrayListStartTime;

        List<Integer> linkedList = new LinkedList<>();
        long linkedListStartTime = System.nanoTime();
        for (int i = 0; i < n; i++) {
            linkedList.add(i);
        }
        long linkedListEndTime = System.nanoTime();
        long linkedListDuration = linkedListEndTime - linkedListStartTime;

        System.out.println("Время выполнения для ArrayList (добавление " + n + " элементов): " + arrayListDuration + " наносекунд");
        System.out.println("Время выполнения для LinkedList (добавление " + n + " элементов): " + linkedListDuration + " наносекунд");
    }
}