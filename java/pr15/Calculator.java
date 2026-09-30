import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Calculator extends JFrame {
    JTextField jta1 = new JTextField(10);
    JTextField jta2 = new JTextField(10);
    JButton addButton = new JButton("Add");
    JButton subtractButton = new JButton("Subtract");
    JButton multiplyButton = new JButton("Multiply");
    JButton divideButton = new JButton("Divide");
    Font fnt = new Font("Times New Roman", Font.BOLD, 20);

    Calculator() {
        super("Calculator");
        setLayout(new FlowLayout());
        setSize(250, 200);

        add(new JLabel("1st Number"));
        add(jta1);
        add(new JLabel("2nd Number"));
        add(jta2);

        add(addButton);
        add(subtractButton);
        add(multiplyButton);
        add(divideButton);

        addButton.addActionListener(e -> performOperation("+"));
        subtractButton.addActionListener(e -> performOperation("-"));
        multiplyButton.addActionListener(e -> performOperation("*"));
        divideButton.addActionListener(e -> performOperation("/"));

        setVisible(true);
    }

    private void performOperation(String operation) {
        try {
            double x1 = Double.parseDouble(jta1.getText().trim());
            double x2 = Double.parseDouble(jta2.getText().trim());
            double result = 0;

            switch (operation) {
                case "+":
                    result = x1 + x2;
                    break;
                case "-":
                    result = x1 - x2;
                    break;
                case "*":
                    result = x1 * x2;
                    break;
                case "/":
                    if (x2 != 0) {
                        result = x1 / x2;
                    } else {
                        JOptionPane.showMessageDialog(null, "Cannot divide by zero!", "Alert", JOptionPane.ERROR_MESSAGE);
                        return;
                    }
                    break;
            }

            JOptionPane.showMessageDialog(null, "Result: " + result, "Result", JOptionPane.INFORMATION_MESSAGE);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Invalid input!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        new Calculator();
    }
}