interface Convertable {
    double convert(double value);
}

class CelsiusToKelvin implements Convertable {
    @Override
    public double convert(double value) {
        return value + 273.15;
    }
}

class CelsiusToFahrenheit implements Convertable {
    @Override
    public double convert(double value) {
        return value * 9 / 5 + 32;
    }
}

public class ConvertableTest {
    public static void main(String[] args) {
        double celsius = 25.0;

        Convertable toKelvin = new CelsiusToKelvin();
        Convertable toFahrenheit = new CelsiusToFahrenheit();

        System.out.println(celsius + "°C = " + toKelvin.convert(celsius) + " K");
        System.out.println(celsius + "°C = " + toFahrenheit.convert(celsius) + " °F");
    }
}