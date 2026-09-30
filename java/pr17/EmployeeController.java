public class EmployeeController {
    private Employee model;
    private EmployeeView view;

    public EmployeeController(Employee model, EmployeeView view) {
        this.model = model;
        this.view = view;
    }

    public void updateEmployeeView() {
        view.printEmployeeDetails(model.getName(), model.calculateSalary());
    }
}