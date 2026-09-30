import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class GuessNumberGame extends JFrame {
    private int targetNumber;
    private int attemptsLeft;
    private JTextField guessField;
    private JLabel messageLabel;
    private JButton submitButton;

    public GuessNumberGame() {
        setTitle("Угадай число");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(320, 150);
        setLayout(new GridLayout(3, 1));

        Random random = new Random();
        targetNumber = random.nextInt(21);
        attemptsLeft = 3;

        guessField = new JTextField();
        messageLabel = new JLabel("Угадай число между 0 и 20. Попыток осталось: " + attemptsLeft);
        submitButton = new JButton("Попробовать угадать");

        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                checkGuess();
            }
        });

        add(messageLabel);
        add(guessField);
        add(submitButton);

        setVisible(true);
    }

    private void checkGuess() {
        try {
            int guess = Integer.parseInt(guessField.getText());
            attemptsLeft--;

            if (guess == targetNumber) {
                messageLabel.setText("Поздравляем! Вы угадали число.");
                guessField.setEnabled(false);
                submitButton.setEnabled(false);
            } else {
                if (attemptsLeft == 0) {
                    messageLabel.setText("Игра окончена. Вы исчерпали все попытки. Загаданное число было " + targetNumber + ".");
                    guessField.setEnabled(false);
                    submitButton.setEnabled(false);
                } else {
                    String message = "Неверно. ";
                    message += (guess < targetNumber) ? "Число больше." : "Число меньше.";
                    message += " Попыток осталось: " + attemptsLeft;
                    messageLabel.setText(message);
                }
            }
        } catch (NumberFormatException e) {
            messageLabel.setText("Введите корректное число.");
        }
        guessField.setText("");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new GuessNumberGame());
    }
}