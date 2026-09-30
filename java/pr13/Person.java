public class Person {
    private String lastName;
    private String firstName;
    private String middleName;

    public Person(String lastName) {
        this.lastName = lastName;
    }

    public Person(String lastName, String firstName) {
        this(lastName);
        this.firstName = firstName;
    }

    public Person(String lastName, String firstName, String middleName) {
        this(lastName, firstName);
        this.middleName = middleName;
    }

    public String getFullName() {
        StringBuilder fullName = new StringBuilder(lastName);
        if (firstName != null && !firstName.isEmpty()) {
            fullName.append(" ").append(firstName.charAt(0)).append(".");
        }
        if (middleName != null && !middleName.isEmpty()) {
            fullName.append(" ").append(middleName.charAt(0)).append(".");
        }
        return fullName.toString();
    }

    public static void main(String[] args) {
        Person person1 = new Person("Каширский", "Герман", "Владимирович");
        Person person2 = new Person("Толмосов", "Давид");
        Person person3 = new Person("Двоергазов");

        System.out.println(person1.getFullName());
        System.out.println(person2.getFullName());
        System.out.println(person3.getFullName());
    }
}