class Student {
    private String name;
    private int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void study() {
        System.out.println(name + " is studying.");
    }

    public String getName() { return name; }
    public int getAge() { return age; }
}

class SchoolStudent extends Student {
    private int grade;

    public SchoolStudent(String name, int age, int grade) {
        super(name, age);
        this.grade = grade;
    }

    @Override
    public void study() {
        System.out.println(getName() + " is studying in grade " + grade + ".");
    }
}

class CollegeStudent extends Student {
    private String college;

    public CollegeStudent(String name, int age, String college) {
        super(name, age);
        this.college = college;
    }

    @Override
    public void study() {
        System.out.println(getName() + " is studying at " + college + " college.");
    }
}

public class StudentTest {
    public static void main(String[] args) {
        Student[] students = {
                new SchoolStudent("Ivan", 12, 6),
                new CollegeStudent("Anna", 18, "MIREA"),
                new SchoolStudent("Petr", 15, 9),
                new CollegeStudent("Maria", 20, "MSU")
        };

        System.out.println("School students:");
        for (Student s : students) {
            if (s instanceof SchoolStudent) {
                s.study();
            }
        }

        System.out.println("\nCollege students:");
        for (Student s : students) {
            if (s instanceof CollegeStudent) {
                s.study();
            }
        }
    }
}