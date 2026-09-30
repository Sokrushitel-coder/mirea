public class Phone {
    private String number;
    private String model;
    private double weight;

    public Phone(String number, String model, double weight) {
        this.number = number;
        this.model = model;
        this.weight = weight;
    }

    public Phone(String number, String model) {
        this(number, model, 0.0);
    }

    public Phone() {
        this("N/A", "N/A");
    }

    public String getNumber() {
        return number;
    }

    public void receiveCall(String callerName) {
        System.out.println("Calling from " + callerName);
    }

    public void receiveCall(String callerName, String callerNumber) {
        System.out.println("Calling from " + callerName + " with number " + callerNumber);
    }

    public void sendMessage(String... numbers) {
        System.out.println("Sending a message to the following numbers:");
        for (String num : numbers) {
            System.out.println(num);
        }
    }

    public static void main(String[] args) {
        Phone phone1 = new Phone("123-456-789", "iPhone 15", 0.5);
        Phone phone2 = new Phone("987-654-321", "Samsung Galaxy S22");
        Phone phone3 = new Phone();

        System.out.println("Phone 1: Number - " + phone1.getNumber() + ", Model - " + phone1.model + ", Weight - " + phone1.weight);
        System.out.println("Phone 2: Number - " + phone2.getNumber() + ", Model - " + phone2.model + ", Weight - " + phone2.weight);
        System.out.println("Phone 3: Number - " + phone3.getNumber() + ", Model - " + phone
