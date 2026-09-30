public class Main {
    public static void main(String[] args) {
        Employee employee = new Employee("John Doe", 15.0, 40);
        EmployeeView view = new EmployeeView();
        EmployeeController controller = new EmployeeController(employee, view);

        controller.updateEmployeeView();
    }
}