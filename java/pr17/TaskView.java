import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class TaskView {
    private JFrame frame;
    private JList<String> taskList;
    private DefaultListModel<String> listModel;

    public TaskView() {
        frame = new JFrame("To-Do List");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 170);

        listModel = new DefaultListModel<>();
        taskList = new JList<>(listModel);

        JPanel panel = new JPanel();
        JTextField taskInput = new JTextField(20);
        JButton addButton = new JButton("Add Task");

        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String newTask = taskInput.getText();
                listModel.addElement(newTask);
                taskInput.setText("");
            }
        });

        panel.add(taskInput);
        panel.add(addButton);

        frame.add(taskList, BorderLayout.CENTER);
        frame.add(panel, BorderLayout.SOUTH);
        frame.setVisible(true);
    }

    public void updateTaskList(List<String> tasks) {
        listModel.clear();
        for (String task : tasks) {
            listModel.addElement(task);
        }
    }
}