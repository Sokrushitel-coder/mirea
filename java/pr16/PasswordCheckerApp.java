import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PasswordCheckerApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> createAndShowGUI());
    }

    private static void createAndShowGUI() {
        JFrame frame = new JFrame("Password application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.insets = new Insets(5, 5, 5, 5);

        JLabel serviceLabel = new JLabel("Service:");
        JLabel usernameLabel = new JLabel("User name:");
        JLabel passwordLabel = new JLabel("Password:");

        JTextField serviceField = new JTextField(20);
        JTextField usernameField = new JTextField(20);
        JPasswordField passwordField = new JPasswordField(20);

        JButton checkButton = new JButton("Проверить");
        JLabel resultLabel = new JLabel();

        checkButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String password = new String(passwordField.getPassword());
                if (isValidPassword(password)) {
                    resultLabel.setText("Пароль верный!");
                } else {
                    resultLabel.setText("Пароль неверный!");
                }
            }
        });

        constraints.gridx = 0;
        constraints.gridy = 0;
        panel.add(serviceLabel, constraints);
        constraints.gridx = 1;
        panel.add(serviceField, constraints);

        constraints.gridx = 0;
        constraints.gridy = 1;
        panel.add(usernameLabel, constraints);
        constraints.gridx = 1;
        panel.add(usernameField, constraints);

        constraints.gridx = 0;
        constraints.gridy = 2;
        panel.add(passwordLabel, constraints);
        constraints.gridx = 1;
        panel.add(passwordField, constraints);

        constraints.gridx = 0;
        constraints.gridy = 3;
        constraints.gridwidth = 2;
        panel.add(checkButton, constraints);

        constraints.gridx = 0;
        constraints.gridy = 4;
        constraints.gridwidth = 2;
        panel.add(resultLabel, constraints);

        frame.add(panel);
        frame.pack();
        frame.setVisible(true);
    }

    private static boolean isValidPassword(String password) {
        return password.length() >= 8;
    }
}