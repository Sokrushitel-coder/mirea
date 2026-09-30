import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MenuExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Пример меню");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 140);

        JMenuBar menuBar = new JMenuBar();

        JMenu fileMenu = new JMenu("Файл");
        JMenuItem saveItem = new JMenuItem("Сохранить");
        JMenuItem exitItem = new JMenuItem("Выйти");

        JMenu editMenu = new JMenu("Правка");
        JMenuItem copyItem = new JMenuItem("Копировать");
        JMenuItem cutItem = new JMenuItem("Вырезать");
        JMenuItem pasteItem = new JMenuItem("Вставить");

        JMenu helpMenu = new JMenu("Справка");

        fileMenu.add(saveItem);
        fileMenu.add(exitItem);

        editMenu.add(copyItem);
        editMenu.add(cutItem);
        editMenu.add(pasteItem);

        menuBar.add(fileMenu);
        menuBar.add(editMenu);
        menuBar.add(helpMenu);

        JPanel buttonPanel = new JPanel();
        JButton button1 = createStyledButton("Кнопка 1");
        JButton button2 = createStyledButton("Кнопка 2");

        buttonPanel.add(button1);
        buttonPanel.add(button2);

        JTextField textField = new JTextField("Это область, в которой вы можете писать текст");
        textField.setPreferredSize(new Dimension(100, 40));

        frame.setJMenuBar(menuBar);
        frame.add(buttonPanel, BorderLayout.NORTH);
        frame.add(textField, BorderLayout.CENTER);

        frame.setVisible(true);
    }

    private static JButton createStyledButton(String text) {
        JButton button = new JButton(text);
        button.setBackground(Color.WHITE);
        button.setForeground(Color.DARK_GRAY);
        button.setPreferredSize(new Dimension(100, 40));
        button.setFocusPainted(false);
        button.setCursor(new Cursor(Cursor.HAND_CURSOR));
        return button;
    }
}