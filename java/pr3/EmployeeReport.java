class Employee {
    private String fullName;
    private double salary;

    public Employee(String fullName, double salary) {
        this.fullName = fullName;
        this.salary = salary;
    }

    public String getFullName() { return fullName; }
    public double getSalary() { return salary; }
}

class Report {
    public static void generateReport(Employee[] employees) {
        System.out.println("Employee Report:");
        System.out.printf("%-20s %10s%n", "Full Name", "Salary");
        System.out.println("------------------------------");
        for (Employee employee : employees) {
            System.out.printf("%-20s $%,10.2f%n", employee.getFullName(), employee.getSalary());
        }
    }
}

public class EmployeeReport {
    public static void main(String[] args) {
        Employee[] employees = {
                new Employee("Rayan Gosling", 50000.50),
                new Employee("Gosling Rayan", 60000.75),
                new Employee("Keanu Reeves", 55000.25),
                new Employee("Christopher Nolan", 70000.00)
        };

        Report.generateReport(employees);
    }
}
