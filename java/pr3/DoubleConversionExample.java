public class DoubleConversionExample {
    public static void main(String[] args) {
        Double doubleObj1 = Double.valueOf(3.14);
        Double doubleObj2 = Double.valueOf("2.718");

        String strValue = "1.23";
        double doubleValue = Double.parseDouble(strValue);

        double primitiveDouble = doubleObj1.doubleValue();
        float primitiveFloat = doubleObj1.floatValue();
        int primitiveInt = doubleObj1.intValue();
        long primitiveLong = doubleObj1.longValue();
        short primitiveShort = doubleObj1.shortValue();
        byte primitiveByte = doubleObj1.byteValue();

        System.out.println("doubleObj1: " + doubleObj1);
        System.out.println("doubleObj2: " + doubleObj2);

        String d = Double.toString(3.14);

        System.out.println("doubleValue: " + doubleValue);
        System.out.println("primitiveDouble: " + primitiveDouble);
        System.out.println("primitiveFloat: " + primitiveFloat);
        System.out.println("primitiveInt: " + primitiveInt);
        System.out.println("primitiveLong: " + primitiveLong);
        System.out.println("primitiveShort: " + primitiveShort);
        System.out.println("primitiveByte: " + primitiveByte);
        System.out.println("d: " + d);
    }
}
