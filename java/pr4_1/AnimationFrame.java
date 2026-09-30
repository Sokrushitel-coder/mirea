import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AnimationFrame extends JFrame {
    private ImageIcon[] frames;
    private int currentFrame;
    private JLabel animationLabel;

    public AnimationFrame() {
        frames = new ImageIcon[9];
        frames[0] = new ImageIcon("1.jpg");
        frames[1] = new ImageIcon("2.jpg");
        frames[2] = new ImageIcon("3.jpg");
        frames[3] = new ImageIcon("4.jpg");
        frames[4] = new ImageIcon("5.jpg");
        frames[5] = new ImageIcon("6.jpg");
        frames[6] = new ImageIcon("7.jpg");
        frames[7] = new ImageIcon("8.jpg");
        frames[8] = new ImageIcon("9.jpg");

        currentFrame = 0;

        animationLabel = new JLabel(frames[currentFrame]);
        add(animationLabel);

        Timer timer = new Timer(350, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                currentFrame = (currentFrame + 1) % frames.length;
                animationLabel.setIcon(frames[currentFrame]);
            }
        });
        timer.start();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            AnimationFrame frame = new AnimationFrame();
            frame.setTitle("Простая анимация");
            frame.setSize(300, 300);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setVisible(true);
        });
    }
}