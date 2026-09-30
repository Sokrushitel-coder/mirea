import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;
import java.awt.geom.Ellipse2D;

public class CountryInfoApp {
    private JFrame frame;
    private JComboBox<String> countryComboBox;
    private Map<String, String> countryInfoMap;

    public CountryInfoApp() {
        frame = new JFrame("Страны");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(230, 90);

        countryInfoMap = new HashMap<>();
        countryInfoMap.put("Россия", "Столица: Москва. Население: 146 миллионов. География: Россия - самая большая страна в мире. Язык: Русский.");
        countryInfoMap.put("США", "Столица: Вашингтон. Население: 331 миллион. География: США находится в Северной Америке. Язык: Английский.");
        countryInfoMap.put("Китай", "Столица: Пекин. Население: 1.4 миллиарда. География: Китай - крупнейшая страна в Восточной Азии. Язык: Китайский.");

        String[] countries = countryInfoMap.keySet().toArray(new String[0]);
        countryComboBox = new JComboBox<>(countries);

        countryComboBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedCountry = (String) countryComboBox.getSelectedItem();
                String countryInfo = countryInfoMap.get(selectedCountry);
                showCountryInfo(selectedCountry, countryInfo);
            }
        });

        JPanel titleBar = new JPanel(new FlowLayout(FlowLayout.LEFT, 4, 0));
        titleBar.add(createCircle(Color.RED));
        titleBar.add(Box.createRigidArea(new Dimension(0, 0)));
        titleBar.add(createCircle(Color.YELLOW));
        titleBar.add(Box.createRigidArea(new Dimension(0, 0)));
        titleBar.add(createCircle(Color.GREEN));
        titleBar.add(Box.createRigidArea(new Dimension(60, 0)));
        titleBar.add(new JLabel("Hello Swing"));

        frame.add(titleBar, BorderLayout.NORTH);
        frame.add(countryComboBox, BorderLayout.SOUTH);

        frame.setVisible(true);
    }

    private void showCountryInfo(String country, String info) {
        JFrame infoFrame = new JFrame(country);
        infoFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        infoFrame.setSize(1300, 90);

        JLabel infoLabel = new JLabel(info);
        infoLabel.setHorizontalAlignment(JLabel.CENTER);
        infoFrame.add(infoLabel);

        infoFrame.setVisible(true);
    }

    private JPanel createCircle(Color color) {
        JPanel circlePanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                int circleSize = 10;
                g2d.setColor(color);
                g2d.fill(new Ellipse2D.Double(0, 0, circleSize, circleSize));
            }
        };
        circlePanel.setPreferredSize(new Dimension(17, 17));
        return circlePanel;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new CountryInfoApp());
    }
}