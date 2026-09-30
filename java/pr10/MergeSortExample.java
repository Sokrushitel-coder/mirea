import java.util.Arrays;

class Student {
    String name;
    int GPA;

    public Student(String name, int GPA) {
        this.name = name;
        this.GPA = GPA;
    }

    public int getGPA() { return GPA; }

    @Override
    public String toString() {
        return "Student [name=" + name + ", GPA=" + GPA + "]";
    }
}

public class MergeSortExample {
    public static void merge(Student[] students1, Student[] students2, Student[] result) {
        int i = 0, j = 0, k = 0;
        while (i < students1.length && j < students2.length) {
            if (students1[i].getGPA() > students2[j].getGPA()) {
                result[k++] = students1[i++];
            } else {
                result[k++] = students2[j++];
            }
        }
        while (i < students1.length) {
            result[k++] = students1[i++];
        }
        while (j < students2.length) {
            result[k++] = students2[j++];
        }
    }

    public static void main(String[] args) {
        Student[] students1 = new Student[]{
                new Student("Alice", 3),
                new Student("Bob", 5),
                new Student("Charlie", 4)
        };
        Student[] students2 = new Student[]{
                new Student("David", 2),
                new Student("Eve", 1)
        };

        Student[] mergedStudents = new Student[students1.length + students2.length];
        merge(students1, students2, mergedStudents);
        Arrays.sort(mergedStudents, (a, b) -> Integer.compare(b.getGPA(), a.getGPA()));

        System.out.println("Merged and Sorted Students by GPA (Descending Order):");
        for (Student student : mergedStudents) {
            System.out.println(student);
        }
    }
}