import java.util.*;

class Student {
    private String name;
    private double gpa;

    public Student(String name, double gpa) {
        this.name = name;
        this.gpa = gpa;
    }

    public String getName() { return name; }
    public double getGpa() { return gpa; }
}

class SortingStudentsByGPA implements Comparator<Student> {
    @Override
    public int compare(Student student1, Student student2) {
        return Double.compare(student2.getGpa(), student1.getGpa());
    }
}

public class Main {
    public static void main(String[] args) {
        List<Student> students = new ArrayList<>();
        students.add(new Student("Alice", 3.9));
        students.add(new Student("Bob", 3.7));
        students.add(new Student("Charlie", 4.0));
        students.add(new Student("David", 3.5));

        Collections.sort(students, new SortingStudentsByGPA());

        for (Student student : students) {
            System.out.println(student.getName() + " - GPA: " + student.getGpa());
        }
    }
}