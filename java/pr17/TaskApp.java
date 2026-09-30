public class TaskApp {
    public static void main(String[] args) {
        TaskModel model = new TaskModel();
        TaskView view = new TaskView();
        TaskController controller = new TaskController(model, view);

        controller.addTask("Постирать белье");
        controller.addTask("Сделать покупки");
        controller.addTask("Завершить проект");

        view.updateTaskList(model.getTasks());
    }
}